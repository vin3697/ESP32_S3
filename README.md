


### Creation of Project
```
- idf.py create-project -p . <name_of_project>			
  eg: idf.py create-project -p . blinking_LED
- idf.py menuconfig
- CmakeLists (Make the important changes : Include Libraries and Link the C files)
  /home/user/ESP32_S3/ESP32_S3/project_folder/main/CMakeLists.txt
```
PORT NAME
```
lsusb
dmesg | grep tty

PORT = /dev/ttyUSB0
- idf.py -p PORT flash
- idf.py -p /dev/ttyUSB0 flash
  
- idf.py -p /dev/ttyUSB0 flash monitor

```

### Build and Flash
```
- get_idf
- idf.py set-target esp32s3 
- idf.py menuconfig
- idf.py build
- idf.py monitor             //monitor the terminal
```







Monitor the terminal - [idf monitor](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/tools/idf-monitor.html)
```
- idf.py monitor          
```

#### Blink LED - [example](https://components.espressif.com/components/espressif/led_strip) : GPIO48

```
//Add this component to your project, run:

idf.py add-dependency "espressif/led_strip^2.5.3"
ESP-IDF >=4.4

//Create the project

idf.py create-project-from-example "espressif/led_strip^2.5.3:led_strip_rmt_ws2812"
```


#### ADC : GPIO3
| Attenuation| Measurable input voltage range |
|----------|----------|
| ADC1_CHANNEL_2 | GPIO3|
| ADC_ATTEN_DB_2_5 | 0 mV ~ 1250 mV|

```
#ADC1

10 channels: GPIO1 - GPIO10

ADC1_CHANNEL_2 -> ADC1 channel 2 is GPIO3

Formula to calculate Vout = Dout * Vmax / Dmax

```


### Issues
* https://esp32.com/viewtopic.php?t=1459
```
idf.py menuconfig

Component config -> FreeRTOS -> Kernel -> configTIMER_TASK_STACK_DEPTH
configTIMER_TASK_STACK_DEPTH = changed to 16384 

```
















































