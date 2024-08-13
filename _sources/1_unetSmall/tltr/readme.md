# TLTR


my target hw is max78000, a low power AI chip.

![alt text](image.png)

it can work on battery, so I need to optimize the model size and performance.

![alt text](image-1.png)

the objective is to compare the performance and model size of a large network with a small custom networks. [see models here](../results/readme.md)

![alt text](image-2.png)

my starting point is a large network that I will convert to run on an x86 machine with PyTorch. I will train this network to understand its structure and performance while gathering data on network size. For exmaple undestand how the [foldings](../folding/readme.md) work to make use of the parrallelism of the MAX78000.

![alt text](image-3.png)

my input data is from the [CamVid](../db/readme.md) dataset, which contains 32 classes. I will use a U-Net network to segment the images.

![alt text](image-4.png)

I will then develop a [custom](../networks/small1.md), smaller U-Net variant named [unetMySmall](../networks/summary_mysmall.md), designed to further reduce the model size while maintaining adequate performance. I will evaluate the model size and performance.

![alt text](image-5.png)

we can use hooks to visualize the model structure and the size of the tensors at each layer.

![alt text](image-6.png)

one way to evaluate the model is using the [evulation process](../4max/readme.md) that can store samples and create embedded project to run on the MAX78000 with evidence of the model size and performance.

![alt text](image-7.png)

we can compare the bin quantization results 

![alt text](image-8.png)

or just load the quantization results and analyze the model size directly [by counting param](../code86/qNetEval.ipynb).

### results
* [results summary](../results/readme.md)
* [report summary](../results/report.md)


## references
* This project is part of a training program I completed on AI model development at the Technion. My notes and partial summaries from that training can be found [here](./https://solerom.github.io/solai/readme.html);
* I have also converted some of the source code from the training into an assistance library for training and evaluation, which I will continue to maintain [(aiArmory) here](https://github.com/SOLEROM/aiArmory);
* i maintain a repo of interested edge device; see notes about [max78000 here](https://github.com/SOLEROM/tinyai/blob/main/41_bords/max/readme.md);