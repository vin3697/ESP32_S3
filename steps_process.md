

# PORT NAME
lsusb
dmesg | grep tty

#Creation of Project
- idf.py create-project -p . <name_of_project>			eg: idf.py create-project -p . blinking_LED
- CmakeLists (imp)
- idf.py menuconfig


# BUILD AND FLASN PROCESS

- get_idf
- idf.py set-target esp32s3 
- idf.py menuconfig
- idf.py build
- idf.py monitor             //monitor the terminal

PORT = /dev/ttyUSB0
- idf.py -p PORT flash
  idf.py -p /dev/ttyUSB0 flash
  
  idf.py -p /dev/ttyUSB0 flash monitor





--------------------------------------------------------------------------------------------------------
										Monitor the terminal

[LINK](https://docs.espressif.com/projects/esp-idf/en/stable/esp32/api-guides/tools/idf-monitor.html)
- idf.py monitor          

--------------------------------------------------------------------------------------------------------
										Blink_LED
[Link](https://components.espressif.com/components/espressif/led_strip)

#Add this component to your project, run:
**idf.py add-dependency "espressif/led_strip^2.5.3"**
ESP-IDF >=4.4

#Create the project
idf.py create-project-from-example "espressif/led_strip^2.5.3:led_strip_rmt_ws2812"

--------------------------------------------------------------------------------------------------------
										ADC

#ADC1

```
10 channels: GPIO1 - GPIO10

enumerator ADC1_CHANNEL_2 -> ADC1 channel 2 is GPIO3

ADC_ATTEN_DB_12 - 0 mV ~ 3100 mV

Vout = Dout * Vmax / Dmax

```



















































