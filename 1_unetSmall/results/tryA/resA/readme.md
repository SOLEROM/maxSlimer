#  UNetLarge CamVid_80_c33 

```
trainning   : EPOCHS_TO_RUN=50 ; batch=8
model       : file=./unet_model_large_x80_c33_e50_A.pth
input data  : train_len =  369 ; test_len=100 ; val_len=232 
img data    : IMAGE_SIZE=(80, 80)
model       : NUM_CLASS=33 ; NUM_CHANN=3 ; FOLD_RATIO=4
score       : val_score=0.535404 ; loss_score 0.7445374798774719
Trainable parameters: 308924
parameters_size_in_megabytes : 1.1784515380859375
```

![alt text](image.png)
![alt text](image-1.png)
![alt text](image-2.png)


