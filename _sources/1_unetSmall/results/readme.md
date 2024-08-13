# trainSummary

## run1 unet_model_large_x88_c33_e50_F1

```
trainning   : EPOCHS_TO_RUN=50 ; batch=8
model       : file=./unet_model_large_x88_c33_e50_F1.pt
input data  : train_len =  100 ; test_len=100 ; val_len=100 
img data    : IMAGE_SIZE=(88, 88)
model       : NUM_CLASS=32 ; NUM_CHANN=3 ; FOLD_RATIO=1
score       : val_score=0.839478305785124 ; val_loss 0.8006125020980835
            : test_score=0.8491412706611571
Trainable parameters: 275692
parameters_size_in_megabytes : 1.0516815185546875
```

![alt text](image-2.png)
![alt text](image-1.png)
![alt text](image.png)


## run2 unet_model_large_x88_c3_e50_F1.pt


```
trainning   : EPOCHS_TO_RUN=50 ; batch=8
model       : file=./unet_model_large_x88_c3_e50_F1.pt
input data  : train_len =  100 ; test_len=100 ; val_len=100 
img data    : IMAGE_SIZE=(88, 88)
model       : NUM_CLASS=4 ; NUM_CHANN=3 ; FOLD_RATIO=1
score       : val_score=0.9455318021516101 ; val_loss 0.26375798521370725
            : test_score=0.9548645601557533
Trainable parameters: 273816
parameters_size_in_megabytes : 1.044525146484375
```


![alt text](image-3.png)
![alt text](image-4.png)
![alt text](image-5.png)


## run3 unet_model_small_x88_c3_e50_F1.pt

```
trainning   : EPOCHS_TO_RUN=50 ; batch=8
model       : file=/tmp/unet_model_small_x88_c3_e50_F1.pt
input data  : train_len =  369 ; test_len=232 ; val_len=100 
img data    : IMAGE_SIZE=(88, 88)
model       : NUM_CLASS=4 ; NUM_CHANN=3 ; FOLD_RATIO=1
score       : val_score=0.9170481262467941 ; val_loss 0.2111915853516809
            : test_score=0.9269707565162112
Trainable parameters: 63496
parameters_size_in_megabytes : 0.242218017578125
```

![alt text](image-6.png)
![alt text](image-7.png)
![alt text](image-8.png)

## run4 unet_model_large_x88_c3_e50_F4.pt

```
trainning   : EPOCHS_TO_RUN=50 ; batch=8
model       : file=./unet_model_large_x88_c3_e50_F4.pt
input data  : train_len =  100 ; test_len=100 ; val_len=100 
img input   : INPUT_SIZE=(352, 352)
model       : NUM_CLASS=4 ; NUM_CHANN=48 ; FOLD_RATIO=4
score       : val_score=0.9470986436662867 ; val_loss 1.3370693099909816
            : test_score=0.9537334114748888
Trainable parameters: 280716
parameters_size_in_megabytes : 1.0708465576171875
```

![alt text](image-9.png)
![alt text](image-10.png)
![alt text](image-11.png)


## run5 unet_model_mySmall_x88_c3_e50_F4.pt

```
trainning   : EPOCHS_TO_RUN=50 ; batch=8
model       : file=./unet_model_mySmall_x88_c3_e50_F4.pt
input data  : train_len =  100 ; test_len=100 ; val_len=100 
img input   : INPUT_SIZE=(352, 352)
model       : NUM_CLASS=4 ; NUM_CHANN=48 ; FOLD_RATIO=4
score       : val_score=0.9131630272157311 ; val_loss 1.4180119119841477
            : test_score=0.9289164315797839
Trainable parameters: 43056
parameters_size_in_megabytes : 0.16424560546875
```

![alt text](image-12.png)
![alt text](image-13.png)
![alt text](image-14.png)

## run6 unet_model_mySmall_x88_c33_e50_F4
 
```
trainning   : EPOCHS_TO_RUN=50 ; batch=8
model       : file=./unet_model_mySmall_x88_c33_e50_F4.pt
input data  : train_len =  100 ; test_len=100 ; val_len=100 
img input   : INPUT_SIZE=(352, 352)
model       : NUM_CLASS=4 ; NUM_CHANN=48 ; FOLD_RATIO=4
score       : val_score=0.7386213353163297 ; val_loss 1.444872669104872
            : test_score=0.8002150548315322
Trainable parameters: 43056
parameters_size_in_megabytes : 0.16424560546875
```

![alt text](image-15.png)
![alt text](image-16.png)
![alt text](image-17.png)