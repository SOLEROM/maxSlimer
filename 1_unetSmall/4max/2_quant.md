# (2) Quantization

env:    (ai8x-synthesis)

## largeNet

* gpuDev

    python quantize.py ../test2_unet/best.pth.tar ../test2_unet/best-q.pth.tar --device MAX78000 -v 

    python izer/add_fake_passthrough.py --input-checkpoint-path ../test2_unet/best-q.pth.tar --output-checkpoint-path ../test2_unet/best-fakept-q.pth.tar --layer-name pt --layer-depth 56 --layer-name-after-pt upconv3

```
Configuring device: MAX78000
Converting checkpoint file ../test2_unet/latest_log_dir/best.pth.tar to ../test2_unet/latest_log_dir/best-q.pth.tar

Model keys (state_dict):
prep0.output_shift, prep0.weight_bits, prep0.bias_bits, prep0.quantize_activation, prep0.adjust_output_shift, prep0.shift_quantile, prep0.op.weight, prep0.op.bias, prep0.bn.running_mean, prep0.bn.running_var, prep0.bn.num_batches_tracked, prep1.output_shift, prep1.weight_bits, prep1.bias_bits, prep1.quantize_activation, prep1.adjust_output_shift, prep1.shift_quantile, prep1.op.weight, prep1.op.bias, prep1.bn.running_mean, prep1.bn.running_var, prep1.bn.num_batches_tracked, prep2.output_shift, prep2.weight_bits, prep2.bias_bits, prep2.quantize_activation, prep2.adjust_output_shift, prep2.shift_quantile, prep2.op.weight, prep2.op.bias, prep2.bn.running_mean, prep2.bn.running_var, prep2.bn.num_batches_tracked, enc1.output_shift, enc1.weight_bits, enc1.bias_bits, enc1.quantize_activation, enc1.adjust_output_shift, enc1.shift_quantile, enc1.op.weight, enc1.op.bias, enc1.bn.running_mean, enc1.bn.running_var, enc1.bn.num_batches_tracked, enc2.output_shift, enc2.weight_bits, enc2.bias_bits, enc2.quantize_activation, enc2.adjust_output_shift, enc2.shift_quantile, enc2.op.weight, enc2.op.bias, enc2.bn.running_mean, enc2.bn.running_var, enc2.bn.num_batches_tracked, enc3.output_shift, enc3.weight_bits, enc3.bias_bits, enc3.quantize_activation, enc3.adjust_output_shift, enc3.shift_quantile, enc3.op.weight, enc3.op.bias, enc3.bn.running_mean, enc3.bn.running_var, enc3.bn.num_batches_tracked, bneck.output_shift, bneck.weight_bits, bneck.bias_bits, bneck.quantize_activation, bneck.adjust_output_shift, bneck.shift_quantile, bneck.op.weight, bneck.op.bias, bneck.bn.running_mean, bneck.bn.running_var, bneck.bn.num_batches_tracked, upconv3.output_shift, upconv3.weight_bits, upconv3.bias_bits, upconv3.quantize_activation, upconv3.adjust_output_shift, upconv3.shift_quantile, upconv3.op.weight, upconv3.op.bias, dec3.output_shift, dec3.weight_bits, dec3.bias_bits, dec3.quantize_activation, dec3.adjust_output_shift, dec3.shift_quantile, dec3.op.weight, dec3.op.bias, dec3.bn.running_mean, dec3.bn.running_var, dec3.bn.num_batches_tracked, upconv2.output_shift, upconv2.weight_bits, upconv2.bias_bits, upconv2.quantize_activation, upconv2.adjust_output_shift, upconv2.shift_quantile, upconv2.op.weight, upconv2.op.bias, dec2.output_shift, dec2.weight_bits, dec2.bias_bits, dec2.quantize_activation, dec2.adjust_output_shift, dec2.shift_quantile, dec2.op.weight, dec2.op.bias, dec2.bn.running_mean, dec2.bn.running_var, dec2.bn.num_batches_tracked, upconv1.output_shift, upconv1.weight_bits, upconv1.bias_bits, upconv1.quantize_activation, upconv1.adjust_output_shift, upconv1.shift_quantile, upconv1.op.weight, upconv1.op.bias, dec1.output_shift, dec1.weight_bits, dec1.bias_bits, dec1.quantize_activation, dec1.adjust_output_shift, dec1.shift_quantile, dec1.op.weight, dec1.op.bias, dec1.bn.running_mean, dec1.bn.running_var, dec1.bn.num_batches_tracked, dec0.output_shift, dec0.weight_bits, dec0.bias_bits, dec0.quantize_activation, dec0.adjust_output_shift, dec0.shift_quantile, dec0.op.weight, dec0.op.bias, dec0.bn.running_mean, dec0.bn.running_var, dec0.bn.num_batches_tracked, conv_p1.output_shift, conv_p1.weight_bits, conv_p1.bias_bits, conv_p1.quantize_activation, conv_p1.adjust_output_shift, conv_p1.shift_quantile, conv_p1.op.weight, conv_p1.op.bias, conv_p1.bn.running_mean, conv_p1.bn.running_var, conv_p1.bn.num_batches_tracked, conv_p2.output_shift, conv_p2.weight_bits, conv_p2.bias_bits, conv_p2.quantize_activation, conv_p2.adjust_output_shift, conv_p2.shift_quantile, conv_p2.op.weight, conv_p2.op.bias, conv_p2.bn.running_mean, conv_p2.bn.running_var, conv_p2.bn.num_batches_tracked, conv_p3.output_shift, conv_p3.weight_bits, conv_p3.bias_bits, conv_p3.quantize_activation, conv_p3.adjust_output_shift, conv_p3.shift_quantile, conv_p3.op.weight, conv_p3.op.bias, conv_p3.bn.running_mean, conv_p3.bn.running_var, conv_p3.bn.num_batches_tracked, conv.output_shift, conv.weight_bits, conv.bias_bits, conv.quantize_activation, conv.adjust_output_shift, conv.shift_quantile, conv.op.weight, conv.op.bias, conv.bn.running_mean, conv.bn.running_var, conv.bn.num_batches_tracked
prep0.op.weight avg_max: 0.16757546 max: 0.30142492 mean: -0.0006143188 factor: [256.] bits: 8
prep0.op.bias avg_max: 0.0061272127 max: 0.15662155 mean: 0.0061272127 factor: [256.] bits: 8
prep1.op.weight avg_max: 0.1536274 max: 0.20351806 mean: 0.0018452407 factor: [512.] bits: 8
prep1.op.bias avg_max: 0.003851723 max: 0.122388765 mean: 0.003851723 factor: [512.] bits: 8
prep2.op.weight avg_max: 0.1573544 max: 0.20137125 mean: 0.005014088 factor: [512.] bits: 8
prep2.op.bias avg_max: 0.018478112 max: 0.13619702 mean: 0.018478112 factor: [512.] bits: 8
enc1.op.weight avg_max: 0.1360186 max: 0.17525977 mean: -0.003604618 factor: [512.] bits: 8
enc1.op.bias avg_max: 0.0019015446 max: 0.054848447 mean: -0.0019015446 factor: [512.] bits: 8
enc2.op.weight avg_max: 0.16144161 max: 0.23188451 mean: 0.0025451884 factor: [512.] bits: 8
enc2.op.bias avg_max: 0.019566251 max: 0.11476405 mean: 0.019566251 factor: [512.] bits: 8
enc3.op.weight avg_max: 0.14334366 max: 0.20458835 mean: 0.0005331211 factor: [512.] bits: 8
enc3.op.bias avg_max: 0.0029098396 max: 0.064218685 mean: 0.0029098396 factor: [512.] bits: 8
bneck.op.weight avg_max: 0.1446258 max: 0.2391926 mean: -0.0023027635 factor: [512.] bits: 8
bneck.op.bias avg_max: 0.0012667204 max: 0.04412031 mean: 0.0012667204 factor: [512.] bits: 8
upconv3.op.weight avg_max: 0.13282582 max: 0.2134163 mean: -0.0001200413 factor: [512.] bits: 8
upconv3.op.bias avg_max: 0.01114581 max: 0.09948499 mean: -0.01114581 factor: [512.] bits: 8
dec3.op.weight avg_max: 0.1350102 max: 0.20486073 mean: -0.0008861224 factor: [512.] bits: 8
dec3.op.bias avg_max: 0.00028921157 max: 0.031276356 mean: 0.00028921157 factor: [512.] bits: 8
upconv2.op.weight avg_max: 0.12573925 max: 0.26317453 mean: -2.1935295e-05 factor: [256.] bits: 8
upconv2.op.bias avg_max: 0.01174769 max: 0.21593487 mean: -0.01174769 factor: [256.] bits: 8
dec2.op.weight avg_max: 0.13144444 max: 0.19111434 mean: -0.00018098645 factor: [512.] bits: 8
dec2.op.bias avg_max: 0.00010488595 max: 0.042222552 mean: -0.00010488595 factor: [512.] bits: 8
upconv1.op.weight avg_max: 0.14801283 max: 0.19591732 mean: 0.0027924029 factor: [256.] bits: 8
upconv1.op.bias avg_max: 0.039980046 max: 0.2564446 mean: 0.039980046 factor: [256.] bits: 8
dec1.op.weight avg_max: 0.13615334 max: 0.20037416 mean: -0.0013962963 factor: [512.] bits: 8
dec1.op.bias avg_max: 0.004520297 max: 0.08354962 mean: 0.004520297 factor: [512.] bits: 8
dec0.op.weight avg_max: 0.10433777 max: 0.18131892 mean: -0.0031632094 factor: [512.] bits: 8
dec0.op.bias avg_max: 0.0018524065 max: 0.04761465 mean: 0.0018524065 factor: [512.] bits: 8
conv_p1.op.weight avg_max: 0.16169755 max: 0.24874495 mean: -0.004506783 factor: [512.] bits: 8
conv_p1.op.bias avg_max: 0.008325463 max: 0.12763931 mean: 0.008325463 factor: [512.] bits: 8
conv_p2.op.weight avg_max: 0.1698544 max: 0.24311289 mean: -0.008754979 factor: [512.] bits: 8
conv_p2.op.bias avg_max: 0.0073006516 max: 0.12935476 mean: -0.0073006516 factor: [512.] bits: 8
conv_p3.op.weight avg_max: 0.15325087 max: 0.21896724 mean: 0.00041198975 factor: [512.] bits: 8
conv_p3.op.bias avg_max: 0.0051961937 max: 0.14337529 mean: -0.0051961937 factor: [512.] bits: 8
conv.op.weight avg_max: 0.15948808 max: 0.24737687 mean: -0.0006630631 factor: [128.] bits: 8
conv.op.bias avg_max: 0.02047737 max: 0.53769076 mean: -0.02047737 factor: [128.] bits: 8

```

```

-rw-rw-r-- 1 vlad vlad 3465183 Jul  9 05:51 best-fakept-q.pth.tar
-rw-rw-r-- 1 vlad vlad 3450464 Jul  9 05:51 best-q.pth.tar
```


## myNet

python quantize.py ../testB_unet/best.pth.tar ../testB_unet/best-q.pth.tar --device MAX78000 -v 

python izer/add_fake_passthrough.py --input-checkpoint-path ../testB_unet/best-q.pth.tar --output-checkpoint-path ../testB_unet/best-fakept-q.pth.tar --layer-name pt --layer-depth 32 --layer-name-after-pt upconv3


```
Converting checkpoint file ../testB_unet/best.pth.tar to ../testB_unet/best-q.pth.tar

Model keys (state_dict):
prep0.0.output_shift, prep0.0.weight_bits, prep0.0.bias_bits, prep0.0.quantize_activation, prep0.0.adjust_output_shift, prep0.0.shift_quantile, prep0.0.op.weight, prep0.0.op.bias, prep0.0.bn.running_mean, prep0.0.bn.running_var, prep0.0.bn.num_batches_tracked, prep0.1.output_shift, prep0.1.weight_bits, prep0.1.bias_bits, prep0.1.quantize_activation, prep0.1.adjust_output_shift, prep0.1.shift_quantile, prep0.1.op.weight, prep0.1.op.bias, prep0.1.bn.running_mean, prep0.1.bn.running_var, prep0.1.bn.num_batches_tracked, prep1.0.output_shift, prep1.0.weight_bits, prep1.0.bias_bits, prep1.0.quantize_activation, prep1.0.adjust_output_shift, prep1.0.shift_quantile, prep1.0.op.weight, prep1.0.op.bias, prep1.0.bn.running_mean, prep1.0.bn.running_var, prep1.0.bn.num_batches_tracked, prep1.1.output_shift, prep1.1.weight_bits, prep1.1.bias_bits, prep1.1.quantize_activation, prep1.1.adjust_output_shift, prep1.1.shift_quantile, prep1.1.op.weight, prep1.1.op.bias, prep1.1.bn.running_mean, prep1.1.bn.running_var, prep1.1.bn.num_batches_tracked, prep2.0.output_shift, prep2.0.weight_bits, prep2.0.bias_bits, prep2.0.quantize_activation, prep2.0.adjust_output_shift, prep2.0.shift_quantile, prep2.0.op.weight, prep2.0.op.bias, prep2.0.bn.running_mean, prep2.0.bn.running_var, prep2.0.bn.num_batches_tracked, prep2.1.output_shift, prep2.1.weight_bits, prep2.1.bias_bits, prep2.1.quantize_activation, prep2.1.adjust_output_shift, prep2.1.shift_quantile, prep2.1.op.weight, prep2.1.op.bias, prep2.1.bn.running_mean, prep2.1.bn.running_var, prep2.1.bn.num_batches_tracked, enc1.0.output_shift, enc1.0.weight_bits, enc1.0.bias_bits, enc1.0.quantize_activation, enc1.0.adjust_output_shift, enc1.0.shift_quantile, enc1.0.op.weight, enc1.0.op.bias, enc1.0.bn.running_mean, enc1.0.bn.running_var, enc1.0.bn.num_batches_tracked, enc1.1.output_shift, enc1.1.weight_bits, enc1.1.bias_bits, enc1.1.quantize_activation, enc1.1.adjust_output_shift, enc1.1.shift_quantile, enc1.1.op.weight, enc1.1.op.bias, enc1.1.bn.running_mean, enc1.1.bn.running_var, enc1.1.bn.num_batches_tracked, enc2.1.output_shift, enc2.1.weight_bits, enc2.1.bias_bits, enc2.1.quantize_activation, enc2.1.adjust_output_shift, enc2.1.shift_quantile, enc2.1.op.weight, enc2.1.op.bias, enc2.1.bn.running_mean, enc2.1.bn.running_var, enc2.1.bn.num_batches_tracked, enc2.2.output_shift, enc2.2.weight_bits, enc2.2.bias_bits, enc2.2.quantize_activation, enc2.2.adjust_output_shift, enc2.2.shift_quantile, enc2.2.op.weight, enc2.2.op.bias, enc2.2.bn.running_mean, enc2.2.bn.running_var, enc2.2.bn.num_batches_tracked, enc3.1.output_shift, enc3.1.weight_bits, enc3.1.bias_bits, enc3.1.quantize_activation, enc3.1.adjust_output_shift, enc3.1.shift_quantile, enc3.1.op.weight, enc3.1.op.bias, enc3.1.bn.running_mean, enc3.1.bn.running_var, enc3.1.bn.num_batches_tracked, enc3.2.output_shift, enc3.2.weight_bits, enc3.2.bias_bits, enc3.2.quantize_activation, enc3.2.adjust_output_shift, enc3.2.shift_quantile, enc3.2.op.weight, enc3.2.op.bias, enc3.2.bn.running_mean, enc3.2.bn.running_var, enc3.2.bn.num_batches_tracked, bneck.1.output_shift, bneck.1.weight_bits, bneck.1.bias_bits, bneck.1.quantize_activation, bneck.1.adjust_output_shift, bneck.1.shift_quantile, bneck.1.op.weight, bneck.1.op.bias, bneck.1.bn.running_mean, bneck.1.bn.running_var, bneck.1.bn.num_batches_tracked, bneck.2.output_shift, bneck.2.weight_bits, bneck.2.bias_bits, bneck.2.quantize_activation, bneck.2.adjust_output_shift, bneck.2.shift_quantile, bneck.2.op.weight, bneck.2.op.bias, bneck.2.bn.running_mean, bneck.2.bn.running_var, bneck.2.bn.num_batches_tracked, upconv3.output_shift, upconv3.weight_bits, upconv3.bias_bits, upconv3.quantize_activation, upconv3.adjust_output_shift, upconv3.shift_quantile, upconv3.op.weight, upconv3.op.bias, dec3.0.output_shift, dec3.0.weight_bits, dec3.0.bias_bits, dec3.0.quantize_activation, dec3.0.adjust_output_shift, dec3.0.shift_quantile, dec3.0.op.weight, dec3.0.op.bias, dec3.0.bn.running_mean, dec3.0.bn.running_var, dec3.0.bn.num_batches_tracked, dec3.1.output_shift, dec3.1.weight_bits, dec3.1.bias_bits, dec3.1.quantize_activation, dec3.1.adjust_output_shift, dec3.1.shift_quantile, dec3.1.op.weight, dec3.1.op.bias, dec3.1.bn.running_mean, dec3.1.bn.running_var, dec3.1.bn.num_batches_tracked, upconv2.output_shift, upconv2.weight_bits, upconv2.bias_bits, upconv2.quantize_activation, upconv2.adjust_output_shift, upconv2.shift_quantile, upconv2.op.weight, upconv2.op.bias, dec2.0.output_shift, dec2.0.weight_bits, dec2.0.bias_bits, dec2.0.quantize_activation, dec2.0.adjust_output_shift, dec2.0.shift_quantile, dec2.0.op.weight, dec2.0.op.bias, dec2.0.bn.running_mean, dec2.0.bn.running_var, dec2.0.bn.num_batches_tracked, dec2.1.output_shift, dec2.1.weight_bits, dec2.1.bias_bits, dec2.1.quantize_activation, dec2.1.adjust_output_shift, dec2.1.shift_quantile, dec2.1.op.weight, dec2.1.op.bias, dec2.1.bn.running_mean, dec2.1.bn.running_var, dec2.1.bn.num_batches_tracked, upconv1.output_shift, upconv1.weight_bits, upconv1.bias_bits, upconv1.quantize_activation, upconv1.adjust_output_shift, upconv1.shift_quantile, upconv1.op.weight, upconv1.op.bias, dec1.0.output_shift, dec1.0.weight_bits, dec1.0.bias_bits, dec1.0.quantize_activation, dec1.0.adjust_output_shift, dec1.0.shift_quantile, dec1.0.op.weight, dec1.0.op.bias, dec1.0.bn.running_mean, dec1.0.bn.running_var, dec1.0.bn.num_batches_tracked, dec1.1.output_shift, dec1.1.weight_bits, dec1.1.bias_bits, dec1.1.quantize_activation, dec1.1.adjust_output_shift, dec1.1.shift_quantile, dec1.1.op.weight, dec1.1.op.bias, dec1.1.bn.running_mean, dec1.1.bn.running_var, dec1.1.bn.num_batches_tracked, dec0.0.output_shift, dec0.0.weight_bits, dec0.0.bias_bits, dec0.0.quantize_activation, dec0.0.adjust_output_shift, dec0.0.shift_quantile, dec0.0.op.weight, dec0.0.op.bias, dec0.0.bn.running_mean, dec0.0.bn.running_var, dec0.0.bn.num_batches_tracked, dec0.1.output_shift, dec0.1.weight_bits, dec0.1.bias_bits, dec0.1.quantize_activation, dec0.1.adjust_output_shift, dec0.1.shift_quantile, dec0.1.op.weight, dec0.1.op.bias, dec0.1.bn.running_mean, dec0.1.bn.running_var, dec0.1.bn.num_batches_tracked, conv_p1.0.output_shift, conv_p1.0.weight_bits, conv_p1.0.bias_bits, conv_p1.0.quantize_activation, conv_p1.0.adjust_output_shift, conv_p1.0.shift_quantile, conv_p1.0.op.weight, conv_p1.0.op.bias, conv_p1.0.bn.running_mean, conv_p1.0.bn.running_var, conv_p1.0.bn.num_batches_tracked, conv_p1.1.output_shift, conv_p1.1.weight_bits, conv_p1.1.bias_bits, conv_p1.1.quantize_activation, conv_p1.1.adjust_output_shift, conv_p1.1.shift_quantile, conv_p1.1.op.weight, conv_p1.1.op.bias, conv_p1.1.bn.running_mean, conv_p1.1.bn.running_var, conv_p1.1.bn.num_batches_tracked, conv_p2.0.output_shift, conv_p2.0.weight_bits, conv_p2.0.bias_bits, conv_p2.0.quantize_activation, conv_p2.0.adjust_output_shift, conv_p2.0.shift_quantile, conv_p2.0.op.weight, conv_p2.0.op.bias, conv_p2.0.bn.running_mean, conv_p2.0.bn.running_var, conv_p2.0.bn.num_batches_tracked, conv_p2.1.output_shift, conv_p2.1.weight_bits, conv_p2.1.bias_bits, conv_p2.1.quantize_activation, conv_p2.1.adjust_output_shift, conv_p2.1.shift_quantile, conv_p2.1.op.weight, conv_p2.1.op.bias, conv_p2.1.bn.running_mean, conv_p2.1.bn.running_var, conv_p2.1.bn.num_batches_tracked, conv_p3.output_shift, conv_p3.weight_bits, conv_p3.bias_bits, conv_p3.quantize_activation, conv_p3.adjust_output_shift, conv_p3.shift_quantile, conv_p3.op.weight, conv_p3.op.bias, conv_p3.bn.running_mean, conv_p3.bn.running_var, conv_p3.bn.num_batches_tracked, conv.output_shift, conv.weight_bits, conv.bias_bits, conv.quantize_activation, conv.adjust_output_shift, conv.shift_quantile, conv.op.weight, conv.op.bias, conv.bn.running_mean, conv.bn.running_var, conv.bn.num_batches_tracked
prep0.0.op.weight avg_max: 0.101445794 max: 0.9486769 mean: -0.101445794 factor: [64.] bits: 8
prep0.0.op.bias avg_max: 0.057132024 max: 1.011574 mean: 0.057132024 factor: [64.] bits: 8
prep0.1.op.weight avg_max: 0.17263398 max: 0.21306998 mean: 0.0017821183 factor: [512.] bits: 8
prep0.1.op.bias avg_max: 0.0056085708 max: 0.18745908 mean: -0.0056085708 factor: [512.] bits: 8
prep1.0.op.weight avg_max: 0.034286775 max: 1.0128323 mean: 0.034286775 factor: [64.] bits: 8
prep1.0.op.bias avg_max: 0.03181064 max: 0.98227745 mean: 0.03181064 factor: [64.] bits: 8
prep1.1.op.weight avg_max: 0.2011425 max: 0.27172115 mean: 1.7536891e-05 factor: [256.] bits: 8
prep1.1.op.bias avg_max: 0.013324186 max: 0.2348506 mean: 0.013324186 factor: [256.] bits: 8
prep2.0.op.weight avg_max: 0.06436809 max: 1.0113795 mean: -0.06436809 factor: [64.] bits: 8
prep2.0.op.bias avg_max: 0.09267063 max: 0.9229071 mean: -0.09267063 factor: [64.] bits: 8
prep2.1.op.weight avg_max: 0.21448633 max: 0.28181568 mean: 0.0034600103 factor: [256.] bits: 8
prep2.1.op.bias avg_max: 0.057658486 max: 0.16573724 mean: -0.057658486 factor: [256.] bits: 8
enc1.0.op.weight avg_max: 0.28746343 max: 0.41962057 mean: -0.00854009 factor: [256.] bits: 8
enc1.0.op.bias avg_max: 0.039127193 max: 0.39330006 mean: -0.039127193 factor: [256.] bits: 8
enc1.1.op.weight avg_max: 0.29817197 max: 0.35716856 mean: -0.028404154 factor: [256.] bits: 8
enc1.1.op.bias avg_max: 0.018160496 max: 0.17386946 mean: 0.018160496 factor: [256.] bits: 8
enc2.1.op.weight avg_max: 0.3019154 max: 0.41128322 mean: 0.045145962 factor: [256.] bits: 8
enc2.1.op.bias avg_max: 0.0032114023 max: 0.228109 mean: -0.0032114023 factor: [256.] bits: 8
enc2.2.op.weight avg_max: 0.32869497 max: 0.47566393 mean: 0.007589888 factor: [256.] bits: 8
enc2.2.op.bias avg_max: 0.023817522 max: 0.3444644 mean: 0.023817522 factor: [256.] bits: 8
enc3.1.op.weight avg_max: 0.30027345 max: 0.4593183 mean: -0.017056206 factor: [256.] bits: 8
enc3.1.op.bias avg_max: 0.035631903 max: 0.2995042 mean: -0.035631903 factor: [256.] bits: 8
enc3.2.op.weight avg_max: 0.2627229 max: 0.40085286 mean: 0.004028636 factor: [256.] bits: 8
enc3.2.op.bias avg_max: 0.033126846 max: 0.25358856 mean: -0.033126846 factor: [256.] bits: 8
bneck.1.op.weight avg_max: 0.2932636 max: 0.47352424 mean: -0.013528546 factor: [256.] bits: 8
bneck.1.op.bias avg_max: 0.09015298 max: 0.34654185 mean: -0.09015298 factor: [256.] bits: 8
bneck.2.op.weight avg_max: 0.23127869 max: 0.40879747 mean: -0.0016288743 factor: [256.] bits: 8
bneck.2.op.bias avg_max: 0.020926975 max: 0.17784375 mean: 0.020926975 factor: [256.] bits: 8
upconv3.op.weight avg_max: 0.15848508 max: 0.23356129 mean: -0.0012607755 factor: [512.] bits: 8
upconv3.op.bias avg_max: 0.0053083478 max: 0.13488525 mean: 0.0053083478 factor: [512.] bits: 8
dec3.0.op.weight avg_max: 0.29065338 max: 0.5506051 mean: 0.011322412 factor: [128.] bits: 8
dec3.0.op.bias avg_max: 0.02214118 max: 0.32495847 mean: -0.02214118 factor: [128.] bits: 8
dec3.1.op.weight avg_max: 0.19761264 max: 0.28130797 mean: 0.001720945 factor: [256.] bits: 8
dec3.1.op.bias avg_max: 0.002876725 max: 0.113577366 mean: -0.002876725 factor: [256.] bits: 8
upconv2.op.weight avg_max: 0.15669641 max: 0.23107317 mean: 0.0002845118 factor: [512.] bits: 8
upconv2.op.bias avg_max: 0.023656815 max: 0.20256957 mean: -0.023656815 factor: [512.] bits: 8
dec2.0.op.weight avg_max: 0.26786536 max: 0.5582866 mean: 0.017097091 factor: [128.] bits: 8
dec2.0.op.bias avg_max: 0.023254363 max: 0.32912728 mean: -0.023254363 factor: [128.] bits: 8
dec2.1.op.weight avg_max: 0.22519475 max: 0.30480343 mean: 0.021297935 factor: [256.] bits: 8
dec2.1.op.bias avg_max: 0.013157662 max: 0.16395171 mean: -0.013157662 factor: [256.] bits: 8
upconv1.op.weight avg_max: 0.18297432 max: 0.33664858 mean: -0.0077659744 factor: [256.] bits: 8
upconv1.op.bias avg_max: 0.034723677 max: 0.21211866 mean: -0.034723677 factor: [256.] bits: 8
dec1.0.op.weight avg_max: 0.27701733 max: 0.51042485 mean: -0.0026966443 factor: [128.] bits: 8
dec1.0.op.bias avg_max: 0.018614449 max: 0.27273116 mean: 0.018614449 factor: [128.] bits: 8
dec1.1.op.weight avg_max: 0.2671455 max: 0.36486876 mean: 0.0064216135 factor: [256.] bits: 8
dec1.1.op.bias avg_max: 0.060460422 max: 0.23919268 mean: 0.060460422 factor: [256.] bits: 8
dec0.0.op.weight avg_max: 0.28857255 max: 0.5697948 mean: -0.044073306 factor: [128.] bits: 8
dec0.0.op.bias avg_max: 0.14155991 max: 0.2925284 mean: 0.14155991 factor: [128.] bits: 8
dec0.1.op.weight avg_max: 0.26738364 max: 0.43663412 mean: -0.0077206716 factor: [256.] bits: 8
dec0.1.op.bias avg_max: 0.022154339 max: 0.24891786 mean: -0.022154339 factor: [256.] bits: 8
conv_p1.0.op.weight avg_max: 0.19179733 max: 0.97314334 mean: 0.19179733 factor: [128.] bits: 8
conv_p1.0.op.bias avg_max: 0.09037826 max: 0.9703222 mean: 0.09037826 factor: [128.] bits: 8
conv_p1.1.op.weight avg_max: 0.24289772 max: 0.3625851 mean: -0.008473791 factor: [256.] bits: 8
conv_p1.1.op.bias avg_max: 0.0021491928 max: 0.17409024 mean: 0.0021491928 factor: [256.] bits: 8
conv_p2.0.op.weight avg_max: 0.027482104 max: 1.0430726 mean: -0.027482104 factor: [64.] bits: 8
conv_p2.0.op.bias avg_max: 0.08499319 max: 0.9644634 mean: -0.08499319 factor: [64.] bits: 8
conv_p2.1.op.weight avg_max: 0.24696009 max: 0.3569141 mean: -0.005061689 factor: [256.] bits: 8
conv_p2.1.op.bias avg_max: 0.009791306 max: 0.16718528 mean: -0.009791306 factor: [256.] bits: 8
conv_p3.op.weight avg_max: 0.21944836 max: 0.31760135 mean: 0.0006763115 factor: [256.] bits: 8
conv_p3.op.bias avg_max: 0.0050081746 max: 0.18458153 mean: 0.0050081746 factor: [256.] bits: 8
conv.op.weight avg_max: 0.21759033 max: 0.27810836 mean: 0.0001901798 factor: [64.] bits: 8
conv.op.bias avg_max: 0.035311587 max: 1.2892337 mean: -0.035311587 factor: [64.] bits: 8
```