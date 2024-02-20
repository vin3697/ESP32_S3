
## Creation of Project
```
// creation of the project
- idf.py create-project -p . <name_of_project>			
  eg: idf.py create-project -p . blinking_LED

```

PORT NAME
```
// detect and get the USB port 
lsusb
dmesg | grep tty

PORT = /dev/ttyUSB0

```

## Linking of Modules (.c and .h files)
```
- CMakeLists.txt (important changes : include libraries and linked the C files)
  /ESP32_S3/LEDPot_Task/main/CMakeLists.txt
```

## Build and Flash
```
// get the IDF environment
- get_idf

// configuration of Environment
- idf.py set-target esp32s3 
- idf.py menuconfig

// Build the Project
- idf.py build

// Flash the application on Target
- idf.py -p /dev/ttyUSB0 flash
- idf.py monitor              
                  OR 
- idf.py -p /dev/ttyUSB0 flash monitor

```

## LEDPotCtrl.c

The file has two functionalities :

1. Blinking the LED with 11 frequencies
2. Changing the color depending upon these 11 frequencies.

and its controlled with the help of COLOR_CHANGE macro defined at line 26 in LEDPotCtrl.c file located at "LEDPot_Task/main/LEDPotCtrl.c "

# References
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

# [Issues Link](https://github.com/vin3697/ESP32_S3/issues)
* https://esp32.com/viewtopic.php?t=1459
```
idf.py menuconfig

Component config -> FreeRTOS -> Kernel -> configTIMER_TASK_STACK_DEPTH
configTIMER_TASK_STACK_DEPTH = changed to 16384 

```

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


## Output for LED color change - 11 frequencies. 

**#define COLOR_CHANGE TRUE** - uncomment line number 28, in LEDPotCtrl.c file to execute this functionality.

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

## Time profiling for blink_LED() function with delay :: vTaskDelay(voltage*xDelay) || Max. Delay is 97ms and Min. is 0ms ||
```
I (15442) example: Frequency with LED is blinking : 10
I (15442) example: Execution time of LED blink function in milli seconds: 0ms
I (15542) example: Frequency with LED is blinking : 10
I (15542) example: Execution time of LED blink function in milli seconds: 0ms
I (15642) example: Frequency with LED is blinking : 10
I (15642) example: Execution time of LED blink function in milli seconds: 0ms
I (15742) example: Frequency with LED is blinking : 10
I (15742) example: Execution time of LED blink function in milli seconds: 0ms
I (15842) example: Frequency with LED is blinking : 10
I (15842) example: Execution time of LED blink function in milli seconds: 0ms
I (15942) example: Frequency with LED is blinking : 10
I (15942) example: Execution time of LED blink function in milli seconds: 0ms
I (16042) example: Frequency with LED is blinking : 10
I (16042) example: Execution time of LED blink function in milli seconds: 0ms
I (16142) example: Frequency with LED is blinking : 10
I (16142) example: Execution time of LED blink function in milli seconds: 0ms
I (16242) example: Frequency with LED is blinking : 10
I (16242) example: Execution time of LED blink function in milli seconds: 0ms
I (16342) example: Frequency with LED is blinking : 10
I (16342) example: Execution time of LED blink function in milli seconds: 0ms
I (16452) example: Frequency with LED is blinking : 9
I (16452) example: Execution time of LED blink function in milli seconds: 10ms
I (16552) example: Frequency with LED is blinking : 9
I (16552) example: Execution time of LED blink function in milli seconds: 10ms
I (16652) example: Frequency with LED is blinking : 9
I (16652) example: Execution time of LED blink function in milli seconds: 10ms
I (16752) example: Frequency with LED is blinking : 9
I (16752) example: Execution time of LED blink function in milli seconds: 10ms
I (16852) example: Frequency with LED is blinking : 9
I (16852) example: Execution time of LED blink function in milli seconds: 10ms
I (16952) example: Frequency with LED is blinking : 9
I (16952) example: Execution time of LED blink function in milli seconds: 10ms
I (17052) example: Frequency with LED is blinking : 9
I (17052) example: Execution time of LED blink function in milli seconds: 10ms
I (17152) example: Frequency with LED is blinking : 9
I (17152) example: Execution time of LED blink function in milli seconds: 10ms
I (17252) example: Frequency with LED is blinking : 9
I (17252) example: Execution time of LED blink function in milli seconds: 10ms
I (17362) example: Frequency with LED is blinking : 8
I (17362) example: Execution time of LED blink function in milli seconds: 20ms
I (17462) example: Frequency with LED is blinking : 8
I (17462) example: Execution time of LED blink function in milli seconds: 20ms
I (17562) example: Frequency with LED is blinking : 8
I (17562) example: Execution time of LED blink function in milli seconds: 20ms
I (17662) example: Frequency with LED is blinking : 8
I (17662) example: Execution time of LED blink function in milli seconds: 20ms
I (17762) example: Frequency with LED is blinking : 8
I (17762) example: Execution time of LED blink function in milli seconds: 20ms
I (17862) example: Frequency with LED is blinking : 8
I (17862) example: Execution time of LED blink function in milli seconds: 20ms
I (17962) example: Frequency with LED is blinking : 8
I (17962) example: Execution time of LED blink function in milli seconds: 20ms
I (18062) example: Frequency with LED is blinking : 8
I (18062) example: Execution time of LED blink function in milli seconds: 20ms
I (18162) example: Frequency with LED is blinking : 8
I (18162) example: Execution time of LED blink function in milli seconds: 20ms
I (18272) example: Frequency with LED is blinking : 7
I (18272) example: Execution time of LED blink function in milli seconds: 30ms
I (18372) example: Frequency with LED is blinking : 7
I (18372) example: Execution time of LED blink function in milli seconds: 30ms
I (18472) example: Frequency with LED is blinking : 7
I (18472) example: Execution time of LED blink function in milli seconds: 30ms
I (18572) example: Frequency with LED is blinking : 7
I (18572) example: Execution time of LED blink function in milli seconds: 30ms
I (18672) example: Frequency with LED is blinking : 7
I (18672) example: Execution time of LED blink function in milli seconds: 30ms
I (18772) example: Frequency with LED is blinking : 7
I (18772) example: Execution time of LED blink function in milli seconds: 30ms
I (18872) example: Frequency with LED is blinking : 7
I (18872) example: Execution time of LED blink function in milli seconds: 30ms
I (18972) example: Frequency with LED is blinking : 7
I (18972) example: Execution time of LED blink function in milli seconds: 30ms
I (19082) example: Frequency with LED is blinking : 6
I (19082) example: Execution time of LED blink function in milli seconds: 40ms
I (19182) example: Frequency with LED is blinking : 6
I (19182) example: Execution time of LED blink function in milli seconds: 40ms
I (19282) example: Frequency with LED is blinking : 6
I (19282) example: Execution time of LED blink function in milli seconds: 40ms
I (19382) example: Frequency with LED is blinking : 6
I (19382) example: Execution time of LED blink function in milli seconds: 40ms
I (19482) example: Frequency with LED is blinking : 6
I (19482) example: Execution time of LED blink function in milli seconds: 40ms
I (19582) example: Frequency with LED is blinking : 6
I (19582) example: Execution time of LED blink function in milli seconds: 40ms
I (19682) example: Frequency with LED is blinking : 6
I (19682) example: Execution time of LED blink function in milli seconds: 40ms
I (19792) example: Frequency with LED is blinking : 5
I (19792) example: Execution time of LED blink function in milli seconds: 50ms
I (19892) example: Frequency with LED is blinking : 5
I (19892) example: Execution time of LED blink function in milli seconds: 50ms
I (19992) example: Frequency with LED is blinking : 5
I (19992) example: Execution time of LED blink function in milli seconds: 50ms
I (20092) example: Frequency with LED is blinking : 5
I (20092) example: Execution time of LED blink function in milli seconds: 50ms
I (20192) example: Frequency with LED is blinking : 5
I (20192) example: Execution time of LED blink function in milli seconds: 50ms
I (20292) example: Frequency with LED is blinking : 5
I (20292) example: Execution time of LED blink function in milli seconds: 50ms
I (20392) example: Frequency with LED is blinking : 5
I (20392) example: Execution time of LED blink function in milli seconds: 50ms
I (20502) example: Frequency with LED is blinking : 4
I (20502) example: Execution time of LED blink function in milli seconds: 60ms
I (20602) example: Frequency with LED is blinking : 4
I (20602) example: Execution time of LED blink function in milli seconds: 60ms
I (20702) example: Frequency with LED is blinking : 4
I (20702) example: Execution time of LED blink function in milli seconds: 60ms
I (20802) example: Frequency with LED is blinking : 4
I (20802) example: Execution time of LED blink function in milli seconds: 60ms
I (20902) example: Frequency with LED is blinking : 4
I (20902) example: Execution time of LED blink function in milli seconds: 60ms
I (21002) example: Frequency with LED is blinking : 4
I (21002) example: Execution time of LED blink function in milli seconds: 60ms
I (21102) example: Frequency with LED is blinking : 4
I (21102) example: Execution time of LED blink function in milli seconds: 60ms
I (21212) example: Frequency with LED is blinking : 3
I (21212) example: Execution time of LED blink function in milli seconds: 70ms
I (21312) example: Frequency with LED is blinking : 3
I (21312) example: Execution time of LED blink function in milli seconds: 70ms
I (21412) example: Frequency with LED is blinking : 3
I (21412) example: Execution time of LED blink function in milli seconds: 70ms
I (22622) example: Frequency with LED is blinking : 2
I (22622) example: Execution time of LED blink function in milli seconds: 80ms
I (22722) example: Frequency with LED is blinking : 2
I (22722) example: Execution time of LED blink function in milli seconds: 80ms
I (22822) example: Frequency with LED is blinking : 2
I (22822) example: Execution time of LED blink function in milli seconds: 80ms
I (22922) example: Frequency with LED is blinking : 2
I (22922) example: Execution time of LED blink function in milli seconds: 80ms
I (23022) example: Frequency with LED is blinking : 2
I (23022) example: Execution time of LED blink function in milli seconds: 80ms
I (24522) example: Frequency with LED is blinking : 2
I (24522) example: Execution time of LED blink function in milli seconds: 80ms
I (24622) example: Frequency with LED is blinking : 2
I (24622) example: Execution time of LED blink function in milli seconds: 80ms
I (24722) example: Frequency with LED is blinking : 2
I (24722) example: Execution time of LED blink function in milli seconds: 80ms
I (24822) example: Frequency with LED is blinking : 2
I (24822) example: Execution time of LED blink function in milli seconds: 80ms
I (24922) example: Frequency with LED is blinking : 2
I (24922) example: Execution time of LED blink function in milli seconds: 80ms
I (25022) example: Frequency with LED is blinking : 2
I (25022) example: Execution time of LED blink function in milli seconds: 80ms
I (25132) example: Frequency with LED is blinking : 1
I (25132) example: Execution time of LED blink function in milli seconds: 90ms
I (25232) example: Frequency with LED is blinking : 1
I (25232) example: Execution time of LED blink function in milli seconds: 90ms
I (25332) example: Frequency with LED is blinking : 1
I (25332) example: Execution time of LED blink function in milli seconds: 90ms
I (25432) example: Frequency with LED is blinking : 1
I (25432) example: Execution time of LED blink function in milli seconds: 90ms
I (27032) example: Frequency with LED is blinking : 1
I (27032) example: Execution time of LED blink function in milli seconds: 90ms
I (27142) example: Frequency with LED is blinking : 0
I (27142) example: Execution time of LED blink function in milli seconds: 100ms
I (27242) example: Frequency with LED is blinking : 0
I (27242) example: Execution time of LED blink function in milli seconds: 97ms
I (27342) example: Frequency with LED is blinking : 0
I (27342) example: Execution time of LED blink function in milli seconds: 97ms
I (27442) example: Frequency with LED is blinking : 0

```

## Time profiling for chngLEDcolr() function.

#### Using Switch Case
```
I (1442) example: Execution time in micro seconds: 362us
I (1542) example: Execution time in micro seconds: 359us
I (1642) example: Execution time in micro seconds: 362us
I (1742) example: Execution time in micro seconds: 359us
I (1842) example: Execution time in micro seconds: 362us
I (1942) example: Execution time in micro seconds: 359us
```

#### Using Array of Structures
```
I (54542) example: Execution time in micro seconds: 364us
I (54642) example: Execution time in micro seconds: 364us
I (54742) example: Execution time in micro seconds: 364us
I (54842) example: Execution time in micro seconds: 364us
I (54942) example: Execution time in micro seconds: 364us
I (55042) example: Execution time in micro seconds: 364us
I (55142) example: Execution time in micro seconds: 364us
```
---














































