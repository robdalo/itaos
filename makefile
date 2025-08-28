INSTALL_DEVICE = /dev/sda1
INSTALL_PATH = /media/robd/bootfs

GCCFLAGS = -Wall -O2 -ffreestanding -nostartfiles -Iinclude

all: clean kernel.img

boot.o: src/boot.s
	arm-none-eabi-as -o boot.o src/boot.s

kernel.o: src/kernel.c
	arm-none-eabi-gcc $(GCCFLAGS) -c $< -o $@

framebuffer.o: src/framebuffer.c
	arm-none-eabi-gcc $(GCCFLAGS) -c $< -o $@

gpio.o: src/gpio.c
	arm-none-eabi-gcc $(GCCFLAGS) -c $< -o $@

led.o: src/led.c
	arm-none-eabi-gcc $(GCCFLAGS) -c $< -o $@

mailbox.o: src/mailbox.c
	arm-none-eabi-gcc $(GCCFLAGS) -c $< -o $@	

timer.o: src/timer.c
	arm-none-eabi-gcc $(GCCFLAGS) -c $< -o $@	

kernel.img: boot.o kernel.o framebuffer.o gpio.o led.o mailbox.o timer.o
	arm-none-eabi-ld -nostdlib boot.o kernel.o framebuffer.o gpio.o led.o mailbox.o timer.o -T kernel.ld -o kernel.elf
	arm-none-eabi-objcopy -O binary kernel.elf boot/kernel.img

clean:
	rm -rf *.elf *.o boot/*.img

install: all
	mkdir -p $(INSTALL_PATH)
	mount $(INSTALL_DEVICE) $(INSTALL_PATH)
	rm -rf $(INSTALL_PATH)/*
	cp boot/* $(INSTALL_PATH)
	umount $(INSTALL_DEVICE)
