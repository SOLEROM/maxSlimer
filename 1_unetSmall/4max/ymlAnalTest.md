# yaml anal for large net

input

```
    num_classes=4,
    num_channels=48,
    dimensions=(88, 88)

```

#### processors
```

0x  ffff    ffff    ffff    ffff
    16      16      16      16      == 64
    
    ffff....ffff    ffff....ffff
        32              32          == 64
    
    ff
    8
    
    f
    4

```


## layer0

```
        self.prep0 = ai8x.FusedConv2dBNReLU(num_channels, 64, 1, stride=1, padding=0,
                                            bias=bias, batchnorm='NoAffine', **kwargs)


```

```
  # Layer 0: prep0
  - out_offset: 0x0600
    in_offset: 0x0700
    processors: 0x0000ffffffffffff              =48
    output_processors: 0xffffffffffffffff       
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    activate: ReLU

```


```
num_channels=48
48/64 ~ 1
48/1/4*4 =48

processors: 0x0000 ffff ffff ffff = 48

```




## layer1

```
        self.prep1 = ai8x.FusedConv2dBNReLU(64, 64, 1, stride=1, padding=0,
                                            bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 1: prep1
  - out_offset: 0x0400
    processors: 0xffffffffffffffff          =64
    output_processors: 0xffffffffffffffff       
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    activate: ReLU
```

```
64/64 ~ 1
64/1/4*4 = 64

    processors: 0xffff ffff ffff ffff
```



## layer2

```
        self.prep2 = ai8x.FusedConv2dBNReLU(64, 32, 1, stride=1, padding=0,
                                            bias=bias, batchnorm='NoAffine', **kwargs)
```

```
  # Layer 2: prep2
  - out_offset: 0x0200
    processors: 0xffffffffffffffff              =64
    output_processors: 0x00000000ffffffff      
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    activate: ReLU

```


## layer3

```
        self.enc1 = ai8x.FusedConv2dBNReLU(32, 8, 3, stride=1, padding=1,
                                           bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 3: enc1
  - out_offset: 0x0000
    processors: 0x00000000ffffffff              =32
    output_processors: 0xff00000000000000
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    activate: ReLU

```

## layer4

```
        self.enc2 = ai8x.FusedMaxPoolConv2dBNReLU(8, 28, 3, stride=1, padding=1,
                                                  bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 4: enc2
  - out_offset: 0x0000
    processors: 0xff00000000000000              ==8
    output_processors: 0x00fffffff0000000
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    max_pool: 2
    pool_stride: 2                  ???
    activate: ReLU

```



## layer5

```
        self.enc3 = ai8x.FusedMaxPoolConv2dBNReLU(28, 56, 3, stride=1, padding=1,
                                                  bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 5: enc3
  - out_offset: 0x5000
    processors: 0x 00ff ffff f000 0000
                    8     16  4 = 28

    output_processors: 0x00ffffffffffffff
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    max_pool: 2
    pool_stride: 2              ????
    activate: ReLU

```

## layer6

```
        self.bneck = ai8x.FusedMaxPoolConv2dBNReLU(56, 112, 3, stride=1, padding=1,
                                                   bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 6: bneck
  - out_offset: 0x6000
    processors: 0x00ffffffffffffff
    output_processors: 0x00ffffffffffffff
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    max_pool: 2
    pool_stride: 2          ????
    activate: ReLU

```


## layer ???????????

```
  # Layer 7: pt
  - in_offset: 0x5000
    out_offset: 0x4004
    processors: 0x00ffffffffffffff
    output_processors: 0x00ffffffffffffff
    operation: None
    write_gap: 1
    in_sequences: [5]
```

** on unet large fake we got (the only diffs) ???

```
  # Layer 7: pt
  - in_offset: 0x5000
    out_offset: 0x4004
    processors: 0x00ffffffffffffff
    output_processors: 0x00ffffffffffffff
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    write_gap: 1
    in_sequences: [5]
    activate: None

```


## layer7

```
        self.upconv3 = ai8x.ConvTranspose2d(112, 56, 3, stride=2, padding=1)
```


```
  # Layer 8: upconv3
  - in_offset: 0x6000
    out_offset: 0x4000
    processors: 0x00 ff ffff ffff ffff

                    8 +16 +16 +16 = 56
112/64 ~ 2
112/2/4*4= 56

    output_processors: 0x00ffffffffffffff
    operation: convtranspose2d
    kernel_size: 3x3
    pad: 1
    activate: None              
    write_gap: 1                ???
    in_sequences: [6]           ???

```



## layer8

```
       
        self.dec3 = ai8x.FusedConv2dBNReLU(112, 56, 3, stride=1, padding=1,
                                           bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 9: dec3
  - out_offset: 0x2000
    in_offset: 0x4000
    processors: 0x00ffffffffffffff
    output_processors: 0x00ffffffffffffff
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    activate: ReLU
    in_sequences: [8, 7]            ???

```


## layer9

```
        self.upconv2 = ai8x.ConvTranspose2d(56, 28, 3, stride=2, padding=1)
```

```
  # Layer 10: upconv2
  - out_offset: 0x0000
    in_offset: 0x2000
    processors: 0x00ffffffffffffff
    output_processors: 0x000000000fffffff
    operation: convtranspose2d
    kernel_size: 3x3
    pad: 1
    activate: None
```


## layer10


```
        self.dec2 = ai8x.FusedConv2dBNReLU(56, 28, 3, stride=1, padding=1,
                                           bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 11: dec2
  - out_offset: 0x2000
    in_offset: 0x0000
    processors: 0x00ff ffff ffff ffff
    output_processors: 0x000000000fffffff
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    activate: ReLU
    in_sequences: [10, 4]           ???


```

## layer11

```
        self.upconv1 = ai8x.ConvTranspose2d(28, 8, 3, stride=2, padding=1)
```

```
  # Layer 12: upconv1
  - out_offset: 0x0000
    processors: 0x000000000fffffff
    output_processors: 0x00ff000000000000
    operation: convtranspose2d
    kernel_size: 3x3
    pad: 1
    activate: None

```

## layer12

```
        self.dec1 = ai8x.FusedConv2dBNReLU(16, 48, 3, stride=1, padding=1,
                                           bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 13: dec1
  - out_offset: 0x0700
    in_offset: 0x0000
    processors: 0xffff000000000000
    output_processors: 0x0000ffffffffffff
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    activate: ReLU
    in_sequences: [12, 3]           ????

```


## layer13

```
        self.dec0 = ai8x.FusedConv2dBNReLU(48, 64, 3, stride=1, padding=1,
                                           bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 14: dec0
  - out_offset: 0x0550
    processors: 0x0000ffffffffffff
    output_processors: 0xffffffffffffffff
    operation: conv2d
    kernel_size: 3x3
    pad: 1
    activate: ReLU

```

## layer14

```
        self.conv_p1 = ai8x.FusedConv2dBNReLU(64, 64, 1, stride=1, padding=0,
                                              bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 15: conv_p1
  - out_offset: 0x0400
    processors: 0xffffffffffffffff
    output_processors: 0xffffffffffffffff
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    activate: ReLU

```

## layer15

```
        self.conv_p2 = ai8x.FusedConv2dBNReLU(64, 64, 1, stride=1, padding=0,
                                              bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 16: conv_p2
  - out_offset: 0x0250
    processors: 0xffffffffffffffff
    output_processors: 0xffffffffffffffff
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    activate: ReLU
```


## layer16

```
        self.conv_p3 = ai8x.FusedConv2dBN(64, 64, 1, stride=1, padding=0,
                                          bias=bias, batchnorm='NoAffine', **kwargs)

```


```
  # Layer 17: conv_p3
  - out_offset: 0x0100
    processors: 0xffffffffffffffff
    output_processors: 0xffffffffffffffff
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    activate: None

```

## layer17

```
        self.conv = ai8x.FusedConv2dBN(64, self.num_final_channels, 1, stride=1, padding=0,
                                       bias=bias, batchnorm='NoAffine', **kwargs)

```

```
  # Layer 18: conv
  - out_offset: 0x0000
    processors: 0xffffffffffffffff
    output_processors: 0xffffffffffffffff
    operation: conv2d
    kernel_size: 1x1
    pad: 0
    activate: None
```