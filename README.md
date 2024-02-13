## Output for LED blinking with different frequency

```
I (322) gpio: GPIO[48]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (332) EXAMPLE: calibration scheme version is Curve Fitting
I (342) EXAMPLE: Calibration Success
I (342) main_task: Returned from app_main()
I (1352) example: Frequency with LED is blinking : 11
I (2352) example: Frequency with LED is blinking : 11
I (3352) example: Frequency with LED is blinking : 11
I (4352) example: Frequency with LED is blinking : 11
I (5352) example: Frequency with LED is blinking : 11
I (6352) example: Frequency with LED is blinking : 11
I (7352) example: Frequency with LED is blinking : 9
I (9162) example: Frequency with LED is blinking : 8
I (10802) example: Frequency with LED is blinking : 6
I (12162) example: Frequency with LED is blinking : 3
I (13252) example: Frequency with LED is blinking : 2
I (14292) example: Frequency with LED is blinking : 2
I (15332) example: Frequency with LED is blinking : 2
I (16372) example: Frequency with LED is blinking : 1
I (17382) example: Frequency with LED is blinking : 2
I (18422) example: Frequency with LED is blinking : 2
I (19462) example: Frequency with LED is blinking : 3
I (20552) example: Frequency with LED is blinking : 3
I (21642) example: Frequency with LED is blinking : 3
I (22732) example: Frequency with LED is blinking : 3
I (23822) example: Frequency with LED is blinking : 3
I (24912) example: Frequency with LED is blinking : 3
```

---

## Output for color change for LED with different voltage values

```
I (322) gpio: GPIO[48]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0 
I (332) EXAMPLE: calibration scheme version is Curve Fitting
I (342) EXAMPLE: Calibration Success
I (342) main_task: Returned from app_main()
I (1352) example: RGB pixel values are : Red 55 Green 201 Blue 1 
I (2352) example: RGB pixel values are : Red 55 Green 201 Blue 1 
I (3352) example: RGB pixel values are : Red 54 Green 202 Blue 1 
I (4352) example: RGB pixel values are : Red 55 Green 201 Blue 1 
I (5352) example: RGB pixel values are : Red 33 Green 255 Blue 223 
I (6352) example: RGB pixel values are : Red 128 Green 255 Blue 128 
I (7352) example: RGB pixel values are : Red 183 Green 255 Blue 73 
I (8352) example: RGB pixel values are : Red 246 Green 255 Blue 10 
I (9352) example: RGB pixel values are : Red 255 Green 72 Blue 184 
I (10352) example: RGB pixel values are : Red 255 Green 144 Blue 112 
I (11352) example: RGB pixel values are : Red 255 Green 202 Blue 54 
I (12352) example: RGB pixel values are : Red 255 Green 245 Blue 11 
I (13352) example: RGB pixel values are : Red 255 Green 245 Blue 11 
I (14352) example: RGB pixel values are : Red 255 Green 246 Blue 10 
I (15352) example: RGB pixel values are : Red 255 Green 64 Blue 192 
I (16352) example: RGB pixel values are : Red 162 Green 255 Blue 94 
I (17352) example: RGB pixel values are : Red 48 Green 255 Blue 208 
I (18352) example: RGB pixel values are : Red 46 Green 210 Blue 1 
I (19352) example: RGB pixel values are : Red 73 Green 183 Blue 1 
I (20352) example: RGB pixel values are : Red 109 Green 147 Blue 1 
I (21352) example: RGB pixel values are : Red 129 Green 127 Blue 1 
I (22352) example: RGB pixel values are : Red 136 Green 120 Blue 1 
I (23352) example: RGB pixel values are : Red 74 Green 182 Blue 1 
I (24352) example: RGB pixel values are : Red 48 Green 208 Blue 1 
I (25352) example: RGB pixel values are : Red 140 Green 116 Blue 1 
I (26352) example: RGB pixel values are : Red 140 Green 116 Blue 1 
I (27352) example: RGB pixel values are : Red 140 Green 116 Blue 1 
I (28352) example: RGB pixel values are : Red 141 Green 115 Blue 1 
I (29352) example: RGB pixel values are : Red 140 Green 116 Blue 1 
```
---
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

```
---
### Build and Flash
```
- get_idf
- idf.py set-target esp32s3 
- idf.py menuconfig
- idf.py build
- idf.py -p /dev/ttyUSB0 flash monitor
- idf.py monitor             
```

---

#### Blink LED - [example](https://components.espressif.com/components/espressif/led_strip) : GPIO48

```
//Add this component to your project, run:

idf.py add-dependency "espressif/led_strip^2.5.3"
ESP-IDF >=4.4

//Create the project

idf.py create-project-from-example "espressif/led_strip^2.5.3:led_strip_rmt_ws2812"
```
---

#### ADC : GPIO3 [API reference](https://docs.espressif.com/projects/esp-idf/en/v4.4.3/esp32s3/api-reference/peripherals/adc.html)
| Attenuation| Measurable input voltage range |
|----------|----------|
| ADC1_CHANNEL_2 | GPIO3|
| ADC_ATTEN_DB_2_5 | 0 mV ~ 1250 mV|

```
#ADC1

10 channels: GPIO1 - GPIO10

ADC1_CHANNEL_2 -> ADC1 channel 2 is GPIO3

Formula to calculate Vout = Dout * Vmax / Dmax (Not used)

```
---
### Issues
* https://esp32.com/viewtopic.php?t=1459
```
idf.py menuconfig

Component config -> FreeRTOS -> Kernel -> configTIMER_TASK_STACK_DEPTH
configTIMER_TASK_STACK_DEPTH = changed to 16384 

```
---















































