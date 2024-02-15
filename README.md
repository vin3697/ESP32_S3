## Output for LED blinking for 11 different frequencies.

```
I (11441) example: Frequency with LED is blinking : 0
I (11541) example: Frequency with LED is blinking : 0
I (11941) example: Frequency with LED is blinking : 0
I (12131) example: Frequency with LED is blinking : 1
I (12231) example: Frequency with LED is blinking : 1
I (12331) example: Frequency with LED is blinking : 1
I (13221) example: Frequency with LED is blinking : 2
I (14221) example: Frequency with LED is blinking : 2
I (14321) example: Frequency with LED is blinking : 2
I (14411) example: Frequency with LED is blinking : 3
I (14511) example: Frequency with LED is blinking : 3
I (14911) example: Frequency with LED is blinking : 3
I (15101) example: Frequency with LED is blinking : 4
I (15201) example: Frequency with LED is blinking : 4
I (15291) example: Frequency with LED is blinking : 5
I (15391) example: Frequency with LED is blinking : 5
I (15991) example: Frequency with LED is blinking : 5
I (16091) example: Frequency with LED is blinking : 5
I (16191) example: Frequency with LED is blinking : 5
I (16281) example: Frequency with LED is blinking : 6
I (16881) example: Frequency with LED is blinking : 6
I (16981) example: Frequency with LED is blinking : 6
I (17071) example: Frequency with LED is blinking : 7
I (17171) example: Frequency with LED is blinking : 7
I (17271) example: Frequency with LED is blinking : 7
I (17361) example: Frequency with LED is blinking : 8
I (17461) example: Frequency with LED is blinking : 8
I (17661) example: Frequency with LED is blinking : 8
I (18151) example: Frequency with LED is blinking : 9
I (18251) example: Frequency with LED is blinking : 9
I (18841) example: Frequency with LED is blinking : 10
I (18941) example: Frequency with LED is blinking : 10
```

---

## Output for LED color change - 11 frequencies. 

**#define COLOR_CHANGE TRUE** - uncomment line number 26, in LEDPotCtrl.c file to execute this functionality.

```
I (6042) example: RGB pixel values are : Red 255 Green 140 Blue 0 
I (6142) example: RGB pixel values are : Red 255 Green 140 Blue 0 
I (6242) example: RGB pixel values are : Red 0 Green 128 Blue 0 
I (6342) example: RGB pixel values are : Red 0 Green 128 Blue 0 
I (6442) example: RGB pixel values are : Red 255 Green 192 Blue 203 
I (6542) example: RGB pixel values are : Red 255 Green 192 Blue 203 
I (6642) example: RGB pixel values are : Red 255 Green 165 Blue 0 
I (6742) example: RGB pixel values are : Red 255 Green 165 Blue 0 
I (6842) example: RGB pixel values are : Red 128 Green 0 Blue 128 
I (7042) example: RGB pixel values are : Red 128 Green 0 Blue 128 
I (7142) example: RGB pixel values are : Red 128 Green 0 Blue 128 
I (7242) example: RGB pixel values are : Red 0 Green 255 Blue 255 
I (7342) example: RGB pixel values are : Red 255 Green 0 Blue 255 
I (7442) example: RGB pixel values are : Red 255 Green 0 Blue 255 
```

---
## Time profiling for read_adc() function.

```
I (1242) example: Execution time in micro seconds: 38us
I (1342) example: Execution time in micro seconds: 38us
I (1442) example: Execution time in micro seconds: 38us
I (1542) example: Execution time in micro seconds: 38us
I (1642) example: Execution time in micro seconds: 38us
I (1742) example: Execution time in micro seconds: 38us
I (1842) example: Execution time in micro seconds: 38us
I (1942) example: Execution time in micro seconds: 38us
```
---

---
## Time profiling for blink_LED() function with delay :: vTaskDelay(voltage*xDelay)
### Max. Delay is 97ms and Min. is 0ms
```
I (5143) example: Frequency with LED is blinking : 1
I (5143) example: Execution time of LED blink function in milli seconds: 97ms
I (5243) example: Frequency with LED is blinking : 1
I (5243) example: Execution time of LED blink function in milli seconds: 97ms
I (5343) example: Frequency with LED is blinking : 1
I (6043) example: Execution time of LED blink function in milli seconds: 97ms
I (6143) example: Frequency with LED is blinking : 1
I (6433) example: Execution time of LED blink function in milli seconds: 87ms
I (6533) example: Frequency with LED is blinking : 2
I (6533) example: Execution time of LED blink function in milli seconds: 90ms
I (6633) example: Frequency with LED is blinking : 2
I (6633) example: Execution time of LED blink function in milli seconds: 90ms
I (6733) example: Frequency with LED is blinking : 2
I (6733) example: Execution time of LED blink function in milli seconds: 90ms
I (6833) example: Frequency with LED is blinking : 2
I (6833) example: Execution time of LED blink function in milli seconds: 90ms
I (6933) example: Frequency with LED is blinking : 2
I (6933) example: Execution time of LED blink function in milli seconds: 90ms
I (7033) example: Frequency with LED is blinking : 2
I (7033) example: Execution time of LED blink function in milli seconds: 90ms
I (7133) example: Frequency with LED is blinking : 2
I (7133) example: Execution time of LED blink function in milli seconds: 90ms
I (7633) example: Frequency with LED is blinking : 2
I (7633) example: Execution time of LED blink function in milli seconds: 90ms
I (7723) example: Frequency with LED is blinking : 3
I (7723) example: Execution time of LED blink function in milli seconds: 80ms
I (7823) example: Frequency with LED is blinking : 3
I (7823) example: Execution time of LED blink function in milli seconds: 80ms
I (7923) example: Frequency with LED is blinking : 3
I (8123) example: Execution time of LED blink function in milli seconds: 80ms
I (8423) example: Frequency with LED is blinking : 3
I (8423) example: Execution time of LED blink function in milli seconds: 80ms
I (8513) example: Frequency with LED is blinking : 4
I (8513) example: Execution time of LED blink function in milli seconds: 70ms
I (8613) example: Frequency with LED is blinking : 4
I (8613) example: Execution time of LED blink function in milli seconds: 70ms
I (8713) example: Frequency with LED is blinking : 4
I (8713) example: Execution time of LED blink function in milli seconds: 70ms
I (8803) example: Frequency with LED is blinking : 5
I (8803) example: Execution time of LED blink function in milli seconds: 60ms
I (8903) example: Frequency with LED is blinking : 5
I (8903) example: Execution time of LED blink function in milli seconds: 60ms
I (9003) example: Frequency with LED is blinking : 5
I (9003) example: Execution time of LED blink function in milli seconds: 60ms
I (9103) example: Frequency with LED is blinking : 5
I (9103) example: Execution time of LED blink function in milli seconds: 60ms
I (9193) example: Frequency with LED is blinking : 6
I (9193) example: Execution time of LED blink function in milli seconds: 50ms
I (9283) example: Frequency with LED is blinking : 7
I (9283) example: Execution time of LED blink function in milli seconds: 40ms
I (9383) example: Frequency with LED is blinking : 7
I (9383) example: Execution time of LED blink function in milli seconds: 40ms
I (9483) example: Frequency with LED is blinking : 7
I (9483) example: Execution time of LED blink function in milli seconds: 40ms
I (9583) example: Frequency with LED is blinking : 7
I (9583) example: Execution time of LED blink function in milli seconds: 40ms
I (9673) example: Frequency with LED is blinking : 8
I (9673) example: Execution time of LED blink function in milli seconds: 30ms
I (9773) example: Frequency with LED is blinking : 8
I (9773) example: Execution time of LED blink function in milli seconds: 30ms
I (9873) example: Frequency with LED is blinking : 8
I (9873) example: Execution time of LED blink function in milli seconds: 30ms
I (9963) example: Frequency with LED is blinking : 9
I (10263) example: Frequency with LED is blinking : 9
I (10263) example: Execution time of LED blink function in milli seconds: 20ms
I (10353) example: Frequency with LED is blinking : 10
I (10353) example: Execution time of LED blink function in milli seconds: 10ms
I (10453) example: Frequency with LED is blinking : 10
I (10453) example: Execution time of LED blink function in milli seconds: 10ms
I (10553) example: Frequency with LED is blinking : 10
```

---
## Time profiling for chngLEDcolr() function.

```
I (1442) example: Execution time in micro seconds: 362us
I (1542) example: Execution time in micro seconds: 359us
I (1642) example: Execution time in micro seconds: 362us
I (1742) example: Execution time in micro seconds: 359us
I (1842) example: Execution time in micro seconds: 362us
I (1942) example: Execution time in micro seconds: 359us
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















































