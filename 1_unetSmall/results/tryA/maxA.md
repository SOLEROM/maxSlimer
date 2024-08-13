



# train

2024-07-09 06:50:24,177 - ==> Best [Top1: 80.296   Params: 278176 on epoch: 48]
2024-07-09 06:50:24,177 - Saving checkpoint to: logs/2024.07.09-063349/qat_checkpoint.pth.tar
2024-07-09 06:50:24,228 - --- test ---------------------
2024-07-09 06:50:24,228 - 600 samples (16 per mini-batch)
2024-07-09 06:50:26,400 - Test: [   10/   38]    Loss 0.675823    Top1 79.704277    
2024-07-09 06:50:28,607 - Test: [   20/   38]    Loss 0.673408    Top1 79.728353    
2024-07-09 06:50:30,235 - Test: [   30/   38]    Loss 0.689856    Top1 78.895035    
2024-07-09 06:50:31,204 - Test: [   38/   38]    Loss 0.694540    Top1 78.687414    
2024-07-09 06:50:31,331 - ==> Top1: 78.687    Loss: 0.695



## quant 

3.3M  qat_best.pth.tar
3.4M  best-q.pth.tar
3.4M  best-fakept-q.pth.tar


## sample

2.9M  sample_camvid_s352_c3.npy

## weights

884K    weights.h

2.4M    /data/tinyai/maxCNN/test2_unet/demo/ai85-unet/build/max78000.elf


  RESOURCE USAGE
  Weight memory: 281,312 bytes out of 442,368 bytes total (63.6%)
  Bias memory:   908 bytes out of 2,048 bytes total (44.3%)