# objective

Project dedicated to exploring and optimizing AI vision networks for edge devices. The primary goal of this project is to reduce the size of neural networks, enabling efficient deployment on resource-constrained hardware, targeting the MAX78000 microcontroller.


## References
* This project is part of a training program I completed on AI model development at the Technion. My notes and partial summaries from that training can be found [here](./https://solerom.github.io/solai/readme.html);
* I have also converted some of the source code from the training into an assistance library for training and evaluation, which I will continue to maintain [(aiArmory) here](https://github.com/SOLEROM/aiArmory);
* i maintain a repo of interested edge device; see notes about [max78000 here](https://github.com/SOLEROM/tinyai/blob/main/41_bords/max/readme.md);

![alt text](image.png)

## Project stages
* Conversion and Training: 
    * Converting large and small U-Net networks to run on an x86 machine with PyTorch. 
    * Training these networks to understand their structure and performance while gathering data on network size.
* Custom Network Design
    * Development of a custom, smaller U-Net variant named unetMySmall, designed to further reduce the model size while maintaining adequate performance.
    * model size and performance evaluation.
* Deployment to MAX78000: 
    * adapt selected networks to the MAX78000 platform. 
        * translating the networks into MAX-specific classes,
        * training and quantization tailored for the hardware.
        * Embedded Project Construction


## dev env
just a memo how to run local code on my remote gpu machine
![](../0_devEnv/image.png)

## db
* [CamVid](./db/readme.md)

## network
* [unetFlow](./networks/unetFlow.md)
* [param calc method](./networks/modelSizeParams.md)
* [reduceMethods](./networks/small1.md)
* [netStruct: unetLarge](./networks/summary_largeNet.md)
* [netStruct: unetSmall](./networks/summary_mysmall.md)
* [folding](./folding/readme.md)

## train and eval
* [lab1 unetLarge no fold 33 classes](./code86/run1.ipynb)
* [lab2 unetLarge no fold 3  classes](./code86/run2.ipynb)
* [lab3 smallNet  no fold 3  classes](./code86/run3.ipynb)
* [lab4 unteLarge addFold 3  classes](./code86/run4.ipynb)
* [lab5 mySmall with Fold 3  classes](./code86/run5.ipynb)
* [lab6 mySmall with Fold 33 classes](./code86/run6.ipynb)
* [results summary](./results/readme.md)


## Deployment

<table>
  <tr>
    <td>
      <ul>
        <li><a href="./4max/1_train.md">1_train</a></li>
        <li><a href="./4max/2_quant.md">2_quant</a></li>
        <li><a href="./4max/3_eval.md">3_eval</a></li>
        <li><a href="./4max/4_sample.md">4_sample</a></li>
        <li><a href="./4max/5_yml.md">5_yml</a></li>
        <li><a href="./4max/6_loader.md">6_loader</a></li>
        <li><a href="./4max/7_infer.md">7_infer</a></li>
        <li><a href="./4max/8_burn.md">8_burn</a></li>
      </ul>
    </td>
    <td>
      <img src="https://raw.githubusercontent.com/analogdevicesinc/ai8x-training/develop/docs/DevelopmentFlow.png" alt="alt text" width="500">
    </td>
  </tr>
</table>

## results

* [results summary](./results/readme.md)
* [synthesis model eval ](./code86/qNetEval.ipynb)
* [report](./results/report.md)