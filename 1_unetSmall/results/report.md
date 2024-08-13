# report

* from x86   analysis largeNet 1.070 / mySmall 0.164 => ~~ 6.5x smaller
* from MAX78 analysis largeNet 1109 / mySmall 444 => ~~ 3.5x smaller


## results collection:

```
"largeUet"
==================

large_x88_c3_e50_F1 
                        val_loss 0.26
                        test_score=0.95
                        Trainable parameters: 273816
                        size_in_megabytes : 1.044

large_x88_c3_e50_F4
                        val_loss 1.33
                        test_score=0.95
                        Trainable parameters: 280716
                        size_in_megabytes : 1.070
  
largeUnet_MAX78
                RESOURCE USAGE on main
                    Weight memory:                          281,312 bytes
                    Bias memory:                            908 bytes 
                quantResultAnal :: Estimated model size:    1109.36 KB
                du testA_unet/best-fakept-q.pth.tar         3384





"mySmallUnet"
===================
mySmall_x88_c3_e50_F4
                        val_loss 1.41
                        test_score=0.928
                        Trainable parameters: 43056
                        size_in_megabytes : 0.164        

mySmallUnet_MAX78s
                quantResultAnal :: Estimated model size:    444.69 KB
                du  testB_unet/best-fakept-q.pth.tar        1480


```