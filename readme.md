# itaos

## Introduction

Basic project illustrating baremetal programming on the Raspberry Pi 4 Model B using C with an assembly language bootloader.

Includes code for utilisation of system timer, gpio (general purpose input output), mailbox and the gpu framebuffer.

Culminates with the implementation of a basic terminal with methods to allow printing of ascii strings to the screen. A couple of basic screensavers and a demo mode.

Please note that this has been written to help aid in the clarity of how the RPi works at baremetal level. It has not been written in the most performance efficient manner or best practice manner.

## How to use

A makefile is included such that running `sudo make install` will build the kernel binary and write it to your SD card for booting on the Raspberry Pi 4 Model B.

To be able to build this project, you will require a GNU build toolchain including the following.

- arm-none-eabi-as
- arm-none-eabi-ld
- arm-none-eabi-objcopy

To use the makefile, you must initially configure it as follows. Please note that sudo may be required for mounting and unmounting of the SD card.

- set INSTALL_DEVICE and INSTALL_PATH in makefile
    - INSTALL_DEVICE points to the SD card device e.g. /dev/sdb1
    - INSTALL_PATH points to the local mount point e.g. /media/robd/bootfs

You may also need to set LD_FLAGS to reference the local directory of your libgcc library.

- run `sudo make install` from the terminal