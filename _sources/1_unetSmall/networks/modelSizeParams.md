# paramCalcMethods


## Torchsummary

Forward/backward pass size (MB):

    This is the amount of memory required to store the intermediate activations (outputs of each layer) and gradients during the forward and backward passes of the model. This memory is needed for computing gradients during the backpropagation step.


Params size (MB): 

    This is the memory required to store the parameters (weights and biases) of the model. This size is computed based on the total number of parameters and their data type (usually float32).

Estimated Total Size:
    
    total memory needed to train the model


## Parameter Calculation

* Total parameters: 

```
total_params = sum(p.numel() for p in model.parameters())
```

This is the total number of parameters in the model, which includes all weights and biases across all layers.

* Trainable parameters:

```
trainable_params = sum(p.numel() for p in model.parameters() if p.requires_grad)
```
number of parameters that are being updated during training. 


## Model Size on Disk

the actual size of the model file saved on disk. This size can be slightly different from the in-memory params size because of file formatting, metadata, and possibly some compression
