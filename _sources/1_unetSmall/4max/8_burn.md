# (8) burn


* burn

		openocd -s /data/tinyai/maxCNN/sdk/Tools/OpenOCD/scripts -f interface/cmsis-dap.cfg -f target/max78000.cfg  -c "program build/max78000.elf verify reset exit"

* serial

		sudo minicom -wD /dev/ttyACM0



###   RESOURCE USAGE

* for the build src code we can find resource usage evidence in main.c:

```
  
  ....
  .......

  RESOURCE USAGE
  Weight memory: 281,312 bytes out of 442,368 bytes total (63.6%)
  Bias memory:   908 bytes out of 2,048 bytes total (44.3%)

```
