INSTALL_DEVICE = /dev/sda1
INSTALL_PATH = /media/robd/bootfs

GCC_FLAGS = -Wall -O2 -ffreestanding -nostdlib -nostartfiles -Iinclude
LD_FLAGS = -L/usr/lib/gcc/arm-none-eabi/14.2.1/ -lgcc

all: clean kernel.img

boot.o: src/boot.s
	arm-none-eabi-as -o boot.o src/boot.s

kernel.o: src/kernel.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

colour.o: src/colour.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

demo.o: src/demo.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

drawing.o: src/drawing.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

font.o: src/font.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

framebuffer.o: src/framebuffer.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

gpio.o: src/gpio.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

led.o: src/led.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

mailbox.o: src/mailbox.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

random.o: src/random.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@

screensaver.o: src/screensaver.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@	

terminal.o: src/terminal.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@	

timer.o: src/timer.c
	arm-none-eabi-gcc $(GCC_FLAGS) -c $< -o $@	

kernel.img: boot.o kernel.o colour.o demo.o drawing.o font.o framebuffer.o gpio.o led.o mailbox.o random.o screensaver.o terminal.o timer.o
	arm-none-eabi-ld boot.o kernel.o colour.o demo.o drawing.o font.o framebuffer.o gpio.o led.o mailbox.o random.o screensaver.o terminal.o timer.o $(LD_FLAGS) -T kernel.ld -o kernel.elf
	arm-none-eabi-objcopy -O binary kernel.elf boot/kernel.img

clean:
	rm -rf *.elf *.o boot/*.img

install: all
	mkdir -p $(INSTALL_PATH)
	mount $(INSTALL_DEVICE) $(INSTALL_PATH)
	rm -rf $(INSTALL_PATH)/*
	cp boot/* $(INSTALL_PATH)
	umount $(INSTALL_DEVICE)
	rm -rf $(INSTALL_PATH)