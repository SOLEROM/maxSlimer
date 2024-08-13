# (7) make

* src to embeded code:

```
(venv) (base) (main)vlad@vladis:maxCNN/sdk ‹main*›$ source envME        
(venv) (base) (main)vlad@vladis:demo/ai85-unet $ make
```

### output:

```
/demo/ai85-unet/build    
board.d   camera.o  _empty_tmp_file.c  hm01b0.d  led.o        main.o        pb.d               sccb.d     softmax.o           stdio.d            system_max78000.o  tsc2046.d
board.o   cnn.d     heap.d             hm01b0.o  ln_args.txt  max78000.elf  pb.o               sccb.o     startup_max78000.d  stdio.o            tft_ssd2119.d      tsc2046.o
camera.d  cnn.o     heap.o             led.d     main.d       max78000.map  project_defines.h  softmax.d  startup_max78000.o  system_max78000.d  tft_ssd2119.o

```
