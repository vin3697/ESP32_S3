# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/home/vin8/ESP32_S3/esp-idf/components/bootloader/subproject"
  "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader"
  "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader-prefix"
  "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader-prefix/tmp"
  "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader-prefix/src/bootloader-stamp"
  "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader-prefix/src"
  "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader-prefix/src/bootloader-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader-prefix/src/bootloader-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/home/vin8/ESP32_S3/ESP32_S3/sample_project/build/bootloader-prefix/src/bootloader-stamp${cfgdir}") # cfgdir has leading slash
endif()
