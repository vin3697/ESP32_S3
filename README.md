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

**#define COLOR_CHANGE TRUE** - uncomment this (26) line in LEDPotCtrl.c file to execute this functionality.

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
## Time profiling for read_adc() function

```
I (342) main_task: Returned from app_main()
I (442) example: Execution time in micro seconds: 221us
I (542) example: Execution time in micro seconds: 41us
I (642) example: Execution time in micro seconds: 40us
I (742) example: Execution time in micro seconds: 38us
I (842) example: Execution time in micro seconds: 38us
I (942) example: Execution time in micro seconds: 38us
I (1042) example: Execution time in micro seconds: 38us
I (1142) example: Execution time in micro seconds: 38us
I (1242) example: Execution time in micro seconds: 38us
I (1342) example: Execution time in micro seconds: 38us
I (1442) example: Execution time in micro seconds: 38us
I (1542) example: Execution time in micro seconds: 38us
I (1642) example: Execution time in micro seconds: 38us
I (1742) example: Execution time in micro seconds: 38us
I (1842) example: Execution time in micro seconds: 38us
I (1942) example: Execution time in micro seconds: 38us
I (2042) example: Execution time in micro seconds: 38us
I (2142) example: Execution time in micro seconds: 38us
I (2242) example: Execution time in micro seconds: 38us
I (2342) example: Execution time in micro seconds: 38us
I (2442) example: Execution time in micro seconds: 38us
I (2542) example: Execution time in micro seconds: 38us
```
---

---
## Time profiling for blink_LED() function with delay :: vTaskDelay(voltage*xDelay)
```
I (28913) example: Execution time of LED blink function in milli seconds: 20ms
I (29913) example: Frequency with LED is blinking : 1
I (29923) example: Execution time of LED blink function in milli seconds: 10ms
I (30923) example: Frequency with LED is blinking : 1
I (30933) example: Execution time of LED blink function in milli seconds: 10ms
I (31933) example: Frequency with LED is blinking : 2
I (31953) example: Execution time of LED blink function in milli seconds: 20ms
I (32953) example: Frequency with LED is blinking : 2
I (32973) example: Execution time of LED blink function in milli seconds: 20ms
I (33973) example: Frequency with LED is blinking : 2
I (33993) example: Execution time of LED blink function in milli seconds: 20ms
I (34993) example: Frequency with LED is blinking : 2
I (35013) example: Execution time of LED blink function in milli seconds: 20ms
I (36013) example: Frequency with LED is blinking : 3
I (36043) example: Execution time of LED blink function in milli seconds: 30ms
I (37043) example: Frequency with LED is blinking : 3
I (37073) example: Execution time of LED blink function in milli seconds: 30ms
I (38073) example: Frequency with LED is blinking : 3
I (38103) example: Execution time of LED blink function in milli seconds: 30ms
I (39103) example: Frequency with LED is blinking : 4
I (39143) example: Execution time of LED blink function in milli seconds: 40ms
I (40143) example: Frequency with LED is blinking : 5
I (40193) example: Execution time of LED blink function in milli seconds: 50ms
I (41193) example: Frequency with LED is blinking : 6
I (41253) example: Execution time of LED blink function in milli seconds: 60ms
I (42253) example: Frequency with LED is blinking : 7
I (42323) example: Execution time of LED blink function in milli seconds: 70ms
I (43323) example: Frequency with LED is blinking : 7
I (43393) example: Execution time of LED blink function in milli seconds: 70ms
I (44393) example: Frequency with LED is blinking : 7
I (44463) example: Execution time of LED blink function in milli seconds: 70ms
I (45463) example: Frequency with LED is blinking : 8
I (45543) example: Execution time of LED blink function in milli seconds: 80ms
I (46543) example: Frequency with LED is blinking : 8
I (46623) example: Execution time of LED blink function in milli seconds: 80ms
I (47623) example: Frequency with LED is blinking : 9
I (47713) example: Execution time of LED blink function in milli seconds: 90ms
I (48713) example: Frequency with LED is blinking : 10
I (48813) example: Execution time of LED blink function in milli seconds: 100ms
I (49813) example: Frequency with LED is blinking : 10
I (49913) example: Execution time of LED blink function in milli seconds: 100ms
I (50913) example: Frequency with LED is blinking : 10
I (51013) example: Execution time of LED blink function in milli seconds: 100ms
I (52013) example: Frequency with LED is blinking : 10
I (52113) example: Execution time of LED blink function in milli seconds: 100ms
I (53113) example: Frequency with LED is blinking : 10
I (53213) example: Execution time of LED blink function in milli seconds: 100ms
I (54213) example: Frequency with LED is blinking : 11
I (54213) example: Execution time of LED blink function in milli seconds: 0ms
I (55213) example: Frequency with LED is blinking : 11
I (55213) example: Execution time of LED blink function in milli seconds: 0ms
```

---
## Time profiling for chngLEDcolr() function

```
I (342) main_task: Returned from app_main()
I (1442) example: RGB pixel values are : Red 255 Green 238 Blue 18 
I (1442) example: Execution time in micro seconds: 742us
I (2442) example: RGB pixel values are : Red 255 Green 241 Blue 15 
I (2442) example: Execution time in micro seconds: 603us
I (3442) example: RGB pixel values are : Red 255 Green 241 Blue 15 
I (3442) example: Execution time in micro seconds: 598us
I (4442) example: RGB pixel values are : Red 255 Green 241 Blue 15 
I (4442) example: Execution time in micro seconds: 598us
I (5442) example: RGB pixel values are : Red 255 Green 241 Blue 15 
I (5442) example: Execution time in micro seconds: 598us
I (6442) example: RGB pixel values are : Red 255 Green 241 Blue 15 
I (6442) example: Execution time in micro seconds: 598us
I (7442) example: RGB pixel values are : Red 255 Green 241 Blue 15 
I (7442) example: Execution time in micro seconds: 598us
I (8442) example: RGB pixel values are : Red 255 Green 240 Blue 16 
I (8442) example: Execution time in micro seconds: 598us
I (9442) example: RGB pixel values are : Red 255 Green 240 Blue 16 
I (9442) example: Execution time in micro seconds: 598us
I (10442) example: RGB pixel values are : Red 255 Green 240 Blue 16 
I (10442) example: Execution time in micro seconds: 601us
I (11442) example: RGB pixel values are : Red 255 Green 240 Blue 16 
I (11442) example: Execution time in micro seconds: 601us
I (12442) example: RGB pixel values are : Red 255 Green 240 Blue 16 
I (12442) example: Execution time in micro seconds: 601us
I (13442) example: RGB pixel values are : Red 255 Green 245 Blue 11 
I (13442) example: Execution time in micro seconds: 601us
I (14442) example: RGB pixel values are : Red 67 Green 189 Blue 1 
I (14442) example: Execution time in micro seconds: 596us
I (15442) example: RGB pixel values are : Red 76 Green 180 Blue 1 
I (15442) example: Execution time in micro seconds: 594us
I (16442) example: RGB pixel values are : Red 137 Green 119 Blue 1 
I (16442) example: Execution time in micro seconds: 597us
I (17442) example: RGB pixel values are : Red 175 Green 81 Blue 1 
I (17442) example: Execution time in micro seconds: 594us
I (18442) example: RGB pixel values are : Red 206 Green 50 Blue 1 
I (18442) example: Execution time in micro seconds: 594us
I (19442) example: RGB pixel values are : Red 249 Green 7 Blue 1 
I (19442) example: Execution time in micro seconds: 590us
I (20442) example: RGB pixel values are : Red 256 Green 0 Blue 1 
```
---


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















































