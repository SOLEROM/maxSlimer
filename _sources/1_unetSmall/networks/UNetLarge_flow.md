# UNetLarge Network

**Overview of UNetLarge Architecture:**

* designed for image segmentation tasks.
* classic UNet architecture with an encoder-decoder structure


## Flow:

1. **Input Preparation Layers:**
   - **prep0, prep1, prep2**: These initial layers sequentially transform the input image (3 channels) through a series of convolutional operations:
     - **Conv2d + BatchNorm + ReLU**: Convert the input to higher dimensions (64 -> 64 -> 32 channels).

2. **Encoder Path:**
   - **enc1**: Applies convolution to reduce dimensions (32 to 8 channels).
   - **enc2**: MaxPooling followed by convolution (8 to 28 channels).
   - **enc3**: Another MaxPooling and convolution step (28 to 56 channels).

3. **Bottleneck Layer:**
   - **bneck**: Central part of the network, combining MaxPooling and convolution (56 to 112 channels).

4. **Decoder Path:**
   - **upconv3**: Upsampling (deconvolution) layer increasing dimensions (112 to 56 channels).
   - **dec3**: Combines features from encoder (concatenation) and applies convolution (56 channels).
   - **upconv2**: Further upsampling (56 to 28 channels).
   - **dec2**: Applies convolution after concatenation (28 channels).
   - **upconv1**: Final upsampling layer (28 to 8 channels).
   - **dec1**: Final set of convolutional operations after concatenation (16 to 48 channels).
   - **dec0**: Final convolution operations (48 to 64 channels).

5. **Final Convolution Layers:**
   - **conv_p1, conv_p2, conv_p3**: Further refine the output with convolutional layers (64 channels each).
   - **conv**: Final layer, converting the refined output to the final desired output (64 to 256 channels).


## struct

```

UNetSmall(
  (enc1): Sequential(
    (0): Conv2d(3, 4, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1))
    (1): BatchNorm2d(4, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
    (2): ReLU(inplace=True)
  )
  (enc2): Sequential(
    (0): MaxPool2d(kernel_size=2, stride=2, padding=0, dilation=1, ceil_mode=False)
    (1): Conv2d(4, 8, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1))
    (2): BatchNorm2d(8, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
    (3): ReLU(inplace=True)
  )
  (enc3): Sequential(
    (0): MaxPool2d(kernel_size=2, stride=2, padding=0, dilation=1, ceil_mode=False)
    (1): Conv2d(8, 32, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1))
    (2): BatchNorm2d(32, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
    (3): ReLU(inplace=True)
  )
  (bneck): Sequential(
    (0): MaxPool2d(kernel_size=2, stride=2, padding=0, dilation=1, ceil_mode=False)
    (1): Conv2d(32, 64, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1))
    (2): BatchNorm2d(64, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
    (3): ReLU(inplace=True)
  )
  (upconv3): ConvTranspose2d(64, 32, kernel_size=(3, 3), stride=(2, 2), padding=(1, 1), output_padding=(1, 1))
  (dec3): Sequential(
    (0): Conv2d(64, 32, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1))
    (1): BatchNorm2d(32, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
    (2): ReLU(inplace=True)
  )
  (upconv2): ConvTranspose2d(32, 8, kernel_size=(3, 3), stride=(2, 2), padding=(1, 1), output_padding=(1, 1))
  (dec2): Sequential(
    (0): Conv2d(16, 8, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1))
    (1): BatchNorm2d(8, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
    (2): ReLU(inplace=True)
  )
  (upconv1): ConvTranspose2d(8, 4, kernel_size=(3, 3), stride=(2, 2), padding=(1, 1), output_padding=(1, 1))
  (dec1): Sequential(
    (0): Conv2d(8, 16, kernel_size=(3, 3), stride=(1, 1), padding=(1, 1))
    (1): BatchNorm2d(16, eps=1e-05, momentum=0.1, affine=True, track_running_stats=True)
    (2): ReLU(inplace=True)
  )
  (conv): Conv2d(16, 32, kernel_size=(1, 1), stride=(1, 1))
)
----------------------------------------------------------------
        Layer (type)               Output Shape         Param #
================================================================
            Conv2d-1          [-1, 4, 128, 128]             112
       BatchNorm2d-2          [-1, 4, 128, 128]               8
              ReLU-3          [-1, 4, 128, 128]               0
         MaxPool2d-4            [-1, 4, 64, 64]               0
            Conv2d-5            [-1, 8, 64, 64]             296
       BatchNorm2d-6            [-1, 8, 64, 64]              16
              ReLU-7            [-1, 8, 64, 64]               0
         MaxPool2d-8            [-1, 8, 32, 32]               0
            Conv2d-9           [-1, 32, 32, 32]           2,336
      BatchNorm2d-10           [-1, 32, 32, 32]              64
             ReLU-11           [-1, 32, 32, 32]               0
        MaxPool2d-12           [-1, 32, 16, 16]               0
           Conv2d-13           [-1, 64, 16, 16]          18,496
      BatchNorm2d-14           [-1, 64, 16, 16]             128
             ReLU-15           [-1, 64, 16, 16]               0
  ConvTranspose2d-16           [-1, 32, 32, 32]          18,464
           Conv2d-17           [-1, 32, 32, 32]          18,464
      BatchNorm2d-18           [-1, 32, 32, 32]              64
             ReLU-19           [-1, 32, 32, 32]               0
  ConvTranspose2d-20            [-1, 8, 64, 64]           2,312
           Conv2d-21            [-1, 8, 64, 64]           1,160
      BatchNorm2d-22            [-1, 8, 64, 64]              16
             ReLU-23            [-1, 8, 64, 64]               0
  ConvTranspose2d-24          [-1, 4, 128, 128]             292
           Conv2d-25         [-1, 16, 128, 128]           1,168
      BatchNorm2d-26         [-1, 16, 128, 128]              32
             ReLU-27         [-1, 16, 128, 128]               0
           Conv2d-28         [-1, 32, 128, 128]             544
====================================================

```