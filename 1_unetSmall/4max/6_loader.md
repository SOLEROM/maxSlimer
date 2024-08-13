# (6) loader


env: (ai8x-synthesize)

## largeUnet

* cpuHost:

    python ai8xize.py --verbose --test-dir ../test2_unet/demo --prefix ai85-unet --checkpoint-file  trained/ai85-camvid-unet-large-fakept-q.pth.tar --config-file networks/camvid-unet-large-fakept.yaml --device MAX78000  --overlap-data --mlator --no-unload --max-checklines 8192 --new-kernel-loader --overwrite 

* gpuHost

    python ai8xize.py --verbose --test-dir ../test2_unet/demo --prefix ai85-unet --checkpoint-file ../test2_unet/best-fakept-q.pth.tar --config-file  ../test2_unet/camvid-unet-large-fakept.yaml --device MAX78000  --overlap-data --mlator --no-unload --max-checklines 8192 --new-kernel-loader --overwrite

* with unload

    python ai8xize.py --verbose --test-dir ../test2_unet/demo --prefix ai85-unet --checkpoint-file ../test2_unet/best-fakept-q.pth.tar --config-file  ../test2_unet/camvid-unet-large-fakept.yaml --device MAX78000  --overlap-data --mlator --max-checklines 8192 --new-kernel-loader --overwrite


```
Configuring device: MAX78000
Reading ../test2_unet/camvid-unet-large-fakept.yaml to configure network...
Reading ../test2_unet/best-fakept-q.pth.tar to configure network weights...
Configuring data set: CamVid_s352_c3_reduced.
ai85-unet...
Arranging weights... ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 100%
Storing weights...   ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 100%
Creating network...  ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━ 100%
```


### result struct

```
ai85-unet 
-rw-rw-r-- 1 vlad vlad    14264 Jul  9 11:26 Makefile
-rw-rw-r-- 1 vlad vlad     5663 Jul  9 11:26 ai85-unet.launch
-rw-rw-r-- 1 vlad vlad    72981 Jul  9 11:26 cnn.c
-rw-rw-r-- 1 vlad vlad     4356 Jul  9 11:26 cnn.h
-rw-rw-r-- 1 vlad vlad 26797050 Jul  9 11:26 log.txt
-rw-rw-r-- 1 vlad vlad     8152 Jul  9 11:26 main.c
-rw-rw-r-- 1 vlad vlad      361 Jul  9 11:26 project.mk
-rw-rw-r-- 1 vlad vlad   345988 Jul  9 11:26 sampledata.h
-rw-rw-r-- 1 vlad vlad   102646 Jul  9 11:26 sampleoutput.h
-rw-rw-r-- 1 vlad vlad     4230 Jul  9 11:26 softmax.c
-rw-rw-r-- 1 vlad vlad   901236 Jul  9 11:26 weights.h

├── ai85-unet.launch
├── cnn.c
├── cnn.h
├── log.txt
├── main.c
├── Makefile
├── project.mk
├── sampledata.h
├── sampleoutput.h
├── softmax.c
└── weights.h
```


## mysmallnet


* cpuHost:

python ai8xize.py --verbose --test-dir ../testB_unet/demo --prefix my_small_unet --checkpoint-file  trained/ai85-camvid-unet-large-fakept-q.pth.tar --config-file networks/camvid-unet-large-fakept.yaml --device MAX78000  --overlap-data --mlator --no-unload --max-checklines 8192 --new-kernel-loader --overwrite 

python ai8xize.py --verbose --test-dir ../testB_unet/demo --prefix my_small_unet --checkpoint-file  ../testB_unet/best-q.pth.tar --config-file ../testB_unet/camvid-unet-large.yaml --device MAX78000  --overlap-data --mlator --no-unload --max-checklines 8192 --new-kernel-loader --overwrite