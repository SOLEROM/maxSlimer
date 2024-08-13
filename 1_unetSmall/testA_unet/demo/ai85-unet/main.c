/*******************************************************************************
* Copyright (C) 2019-2023 Maxim Integrated Products, Inc., All rights Reserved.
*
* This software is protected by copyright laws of the United States and
* of foreign countries. This material may also be protected by patent laws
* and technology transfer regulations of the United States and of foreign
* countries. This software is furnished under a license agreement and/or a
* nondisclosure agreement and may only be used or reproduced in accordance
* with the terms of those agreements. Dissemination of this information to
* any party or parties not specified in the license agreement and/or
* nondisclosure agreement is expressly prohibited.
*
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
* OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
* IN NO EVENT SHALL MAXIM INTEGRATED BE LIABLE FOR ANY CLAIM, DAMAGES
* OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
* OTHER DEALINGS IN THE SOFTWARE.
*
* Except as contained in this notice, the name of Maxim Integrated
* Products, Inc. shall not be used except as stated in the Maxim Integrated
* Products, Inc. Branding Policy.
*
* The mere transfer of this software does not imply any licenses
* of trade secrets, proprietary technology, copyrights, patents,
* trademarks, maskwork rights, or any other form of intellectual
* property whatsoever. Maxim Integrated Products, Inc. retains all
* ownership rights.
*******************************************************************************/

// ai85-unet
// This file was @generated by ai8xize.py --verbose --test-dir ../test2_unet/demo --prefix ai85-unet --checkpoint-file ../test2_unet/best-fakept-q.pth.tar --config-file ../test2_unet/camvid-unet-large-fakept.yaml --device MAX78000 --overlap-data --mlator --no-unload --max-checklines 8192 --new-kernel-loader --overwrite

#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include "mxc.h"
#include "cnn.h"
#include "sampledata.h"
#include "sampleoutput.h"
#include "mxc_errors.h"
#include "camera.h"
#include "dma.h"
#include "pb.h"
#include "weights.h"
#include "led.h"



volatile uint32_t cnn_time; // Stopwatch

// #define CAMERA_FREQ (5 * 1000 * 1000)
#define CAMERA_FREQ (10 * 1000 * 1000)

#define IMAGE_SIZE_X (80)
#define IMAGE_SIZE_Y (80)

static int32_t ml_data32[(CNN_NUM_OUTPUTS + 3) / 4];

static uint32_t input_buffer[IMAGE_SIZE_X * IMAGE_SIZE_Y];
uint32_t *input = input_buffer;
uint8_t *rx_data = (uint8_t *)input_buffer; //[IMAGE_SIZE_X*IMAGE_SIZE_Y*3];

void fail(void)
{
  printf("\n*** FAIL ***\n\n");
  while (1);
}

int8_t unsigned_to_signed(uint8_t val)
{
    return val - 128;
}


void load_input(void)
{
  // This function loads the sample data input -- replace with actual data
    
  uint8_t *frame_buffer;
  uint8_t *buffer;
  uint32_t imgLen;
  uint32_t w, h, x, y;
  uint8_t r, g, b;
  int i = 0;

  camera_start_capture_image();

  printf("camera_start_capture_image end...\n");
  while (!camera_is_image_rcv()) {}
  printf("camera_is_image_rcv end...\n");

  camera_get_image(&frame_buffer, &imgLen, &w, &h);
  buffer = frame_buffer;

  for (y = 0; y < h; y++) {
      for (x = 0; x < w; x++) {
          r = unsigned_to_signed(*buffer);
          buffer++;
          g = unsigned_to_signed(*buffer);
          buffer++;
          b = unsigned_to_signed(*buffer);
          buffer++;
          buffer++; // skip msb=0x00

          input[i] = r | (g << 8) | (b << 16);

          i++;
      }
  }

  // printf("r:%d g:%d b:%d  input:%x\r\n",r,g,b, input[i-1]);

  memcpy32((uint32_t *)0x50408000, input, 6400);


}




int main(void)
{
  int ret = 0;
  int id;
  int error = 0;
  int dma_channel;
  int slaveAddress;


  MXC_ICC_Enable(MXC_ICC0); // Enable cache

  /* Enable camera power */
  Camera_Power(POWER_ON);

  // Switch to 100 MHz clock
  MXC_SYS_Clock_Select(MXC_SYS_CLOCK_IPO);
  SystemCoreClockUpdate();

  printf("(max) Waiting...\n");

  // DO NOT DELETE THIS LINE:
  MXC_Delay(SEC(2)); // Let debugger interrupt if needed

  printf("Initializing DMA\n");
  MXC_DMA_Init();
  dma_channel = MXC_DMA_AcquireChannel();

  // Initialize the camera driver.
  printf("Initializing camera start\n");
  camera_init(CAMERA_FREQ);
  printf("Initializing camera end\n");
    
  printf("camera_setup start\n");
  ret = camera_setup(IMAGE_SIZE_X, IMAGE_SIZE_Y, PIXFORMAT_RGB565, FIFO_THREE_BYTE, USE_DMA,
                 dma_channel);
  if (ret != E_NO_ERROR) {
      printf("Failed to setup camera!\n");
      return -1;
  }
  printf("camera_setup end\n");

  // Enable peripheral, enable CNN interrupt, turn on CNN clock
  // CNN clock: 50 MHz div 1
  cnn_enable(MXC_S_GCR_PCLKDIV_CNNCLKSEL_PCLK, MXC_S_GCR_PCLKDIV_CNNCLKDIV_DIV1);

  // Obtain the I2C slave address of the camera.
  printf("camera_get_slave_address start\n");
  slaveAddress = camera_get_slave_address();
  printf("Camera I2C slave address is %02x", slaveAddress);
  // Obtain the product ID of the camera.
  error = camera_get_product_id(&id);
  if (error) {
      printf("Error returned from reading camera id. Error %d", error);
      return error;
  }
  printf("Camera Product ID is %04x", id);
  // Obtain the manufacture ID of the camera.
  error = camera_get_manufacture_id(&id);
  if (error) {
      printf("Error returned from reading camera id. Error %d", error);
      return error;
  }



  cnn_init(); // Bring state machine into consistent state
  printf("(max) cnn_init end...\n");
  cnn_load_weights(); // Load kernels
  printf("(max) cnn_load_weights end...\n");
  cnn_load_bias();
  printf("(max) cnn_load_bias end...\n");
  cnn_configure(); // Configure state machine
  printf("(max) cnn_configure end...\n");
 


  printf("load_input.............\n");
  load_input(); // Load data input
  
  LED_On(LED1);
  printf("cnn_start.............\n");
  cnn_start(); // Start CNN processing
  while (cnn_time == 0) __WFI(); // Wait for CNN
  LED_Off(LED1);
  // cnn_unload((uint32_t *)ml_data32);
  printf("cnn_unload.............\n");


  cnn_stop();









  // while(1)
  // {
  //   LED_On(1);


  // }
  




  printf("\n*** end of main ***\n\n");

#ifdef CNN_INFERENCE_TIMER
  printf("Approximate inference time: %u us\n\n", cnn_time);
#endif
 
  printf("...cnn_disable ; shut down.\n");
  cnn_disable(); // Shut down CNN clock, disable peripheral


  return 0;
}

/*
  SUMMARY OF OPS
  Hardware: 187,788,096 ops (186,753,024 macc; 1,035,072 comp; 0 add; 0 mul; 0 bitwise)
    Layer 0: 7,225,344 ops (7,077,888 macc; 147,456 comp; 0 add; 0 mul; 0 bitwise)
    Layer 1: 9,584,640 ops (9,437,184 macc; 147,456 comp; 0 add; 0 mul; 0 bitwise)
    Layer 2: 4,792,320 ops (4,718,592 macc; 73,728 comp; 0 add; 0 mul; 0 bitwise)
    Layer 3: 5,326,848 ops (5,308,416 macc; 18,432 comp; 0 add; 0 mul; 0 bitwise)
    Layer 4: 1,195,776 ops (1,161,216 macc; 34,560 comp; 0 add; 0 mul; 0 bitwise)
    Layer 5: 2,056,320 ops (2,032,128 macc; 24,192 comp; 0 add; 0 mul; 0 bitwise)
    Layer 6: 2,044,224 ops (2,032,128 macc; 12,096 comp; 0 add; 0 mul; 0 bitwise)
    Layer 7: 451,584 ops (451,584 macc; 0 comp; 0 add; 0 mul; 0 bitwise)
    Layer 8: 8,128,512 ops (8,128,512 macc; 0 comp; 0 add; 0 mul; 0 bitwise)
    Layer 9: 8,136,576 ops (8,128,512 macc; 8,064 comp; 0 add; 0 mul; 0 bitwise)
    Layer 10: 8,128,512 ops (8,128,512 macc; 0 comp; 0 add; 0 mul; 0 bitwise)
    Layer 11: 8,144,640 ops (8,128,512 macc; 16,128 comp; 0 add; 0 mul; 0 bitwise)
    Layer 12: 4,644,864 ops (4,644,864 macc; 0 comp; 0 add; 0 mul; 0 bitwise)
    Layer 13: 16,035,840 ops (15,925,248 macc; 110,592 comp; 0 add; 0 mul; 0 bitwise)
    Layer 14: 63,848,448 ops (63,700,992 macc; 147,456 comp; 0 add; 0 mul; 0 bitwise)
    Layer 15: 9,584,640 ops (9,437,184 macc; 147,456 comp; 0 add; 0 mul; 0 bitwise)
    Layer 16: 9,584,640 ops (9,437,184 macc; 147,456 comp; 0 add; 0 mul; 0 bitwise)
    Layer 17: 9,437,184 ops (9,437,184 macc; 0 comp; 0 add; 0 mul; 0 bitwise)
    Layer 18: 9,437,184 ops (9,437,184 macc; 0 comp; 0 add; 0 mul; 0 bitwise)

  RESOURCE USAGE
  Weight memory: 281,312 bytes out of 442,368 bytes total (63.6%)
  Bias memory:   908 bytes out of 2,048 bytes total (44.3%)
*/

