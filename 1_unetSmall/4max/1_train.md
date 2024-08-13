# (1) Train

## env

```
(ai8x-training) 
ulimit -n 1048576
```

## largeUnet

* gpuEnv

    python train.py --deterministic --epochs 50 --optimizer Adam --lr 0.001 --wd 0 --model ai85unetlarge --out-fold-ratio 4 --use-bias --dataset CamVid_s352_c3 --device MAX78000 --batch-size 16 --qat-policy policies/qat_policy_camvid.yaml --compress policies/schedule-camvid.yaml --validation-split 0 --compiler-mode none 

```
see log at      2024.07.09-063349.log
-rw-rw-r-- 1 vlad vlad 3461339 Jul  9 14:37 best.pth.tar
-rw-rw-r-- 1 vlad vlad 3450464 Jul  9 14:37 best-q.pth.tar
-rw-rw-r-- 1 vlad vlad 3461339 Jul  9 14:37 checkpoint.pth.tar
```

##  myunetsmall

* gpuEnv

    python train.py --deterministic --epochs 50 --optimizer Adam --lr 0.001 --wd 0 --model myunetsmall --out-fold-ratio 4 --use-bias --dataset CamVid_s352_c3 --device MAX78000 --batch-size 16 --qat-policy policies/qat_policy_camvid.yaml --compress policies/schedule-camvid.yaml --validation-split 0 --compiler-mode none

```
==> Best [Top1: 77.720   Params: 40504 on epoch: 45]
Saving checkpoint to: logs/2024.07.13-062820/qat_checkpoint.pth.tar


Training epoch: 1200 samples (16 per mini-batch, world size: 1)
Epoch: [49][   10/   75]    Overall Loss 0.477306    Objective Loss 0.477306                                        LR 0.000500    Time 0.208016    
Epoch: [49][   20/   75]    Overall Loss 0.476641    Objective Loss 0.476641                                        LR 0.000500    Time 0.183441    
Epoch: [49][   30/   75]    Overall Loss 0.475061    Objective Loss 0.475061                                        LR 0.000500    Time 0.176507    
Epoch: [49][   40/   75]    Overall Loss 0.476233    Objective Loss 0.476233                                        LR 0.000500    Time 0.173755    
Epoch: [49][   50/   75]    Overall Loss 0.474764    Objective Loss 0.474764                                        LR 0.000500    Time 0.171731    
Epoch: [49][   60/   75]    Overall Loss 0.475396    Objective Loss 0.475396                                        LR 0.000500    Time 0.170385    
Epoch: [49][   70/   75]    Overall Loss 0.475214    Objective Loss 0.475214                                        LR 0.000500    Time 0.168431    
Epoch: [49][   75/   75]    Overall Loss 0.475768    Objective Loss 0.475768    Top1 92.631215    LR 0.000500    Time 0.169844    
--- validate (epoch=49)-----------
600 samples (16 per mini-batch)
Epoch: [49][   10/   38]    Loss 0.905984    Top1 67.193588    
Epoch: [49][   20/   38]    Loss 0.879343    Top1 68.750066    
Epoch: [49][   30/   38]    Loss 0.878949    Top1 68.715212    
Epoch: [49][   38/   38]    Loss 0.879342    Top1 68.697919    
==> Top1: 68.698    Loss: 0.879

==> Best [Top1: 77.720   Params: 40504 on epoch: 45]
Saving checkpoint to: logs/2024.07.13-062820/qat_checkpoint.pth.tar
--- test ---------------------
600 samples (16 per mini-batch)
Test: [   10/   38]    Loss 0.863710    Top1 69.603670    
Test: [   20/   38]    Loss 0.864482    Top1 69.490563    
Test: [   30/   38]    Loss 0.871459    Top1 69.198025    
Test: [   38/   38]    Loss 0.882090    Top1 68.698626    
==> Top1: 68.699    Loss: 0.882



├── [674K]  best.pth.tar


```