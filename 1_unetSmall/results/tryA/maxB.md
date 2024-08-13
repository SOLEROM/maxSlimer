

# train

2024-07-13 06:44:10,682 - ==> Best [Top1: 77.720   Params: 40504 on epoch: 45]
2024-07-13 06:44:10,683 - Saving checkpoint to: logs/2024.07.13-062820/qat_checkpoint.pth.tar
2024-07-13 06:44:10,745 - --- test ---------------------
2024-07-13 06:44:10,746 - 600 samples (16 per mini-batch)
2024-07-13 06:44:13,510 - Test: [   10/   38]    Loss 0.863710    Top1 69.603670    
2024-07-13 06:44:15,139 - Test: [   20/   38]    Loss 0.864482    Top1 69.490563    
2024-07-13 06:44:16,781 - Test: [   30/   38]    Loss 0.871459    Top1 69.198025    
2024-07-13 06:44:17,915 - Test: [   38/   38]    Loss 0.882090    Top1 68.698626    
2024-07-13 06:44:18,025 - ==> Top1: 68.699    Loss: 0.882


## quant 

├── [674K]  qat_best.pth.tar
├── [655K]  best-q.pth.tar
├── [670K]  best-fakept-q.pth.tar


## sample

2.9M    ../testB_unet/sample_camvid_s352_c3.npy

## weights
