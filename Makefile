CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb
CPPFLAGS= -DSTM32F446xx \
		-Ivendor/cmsis-device-f4/Include \
		-Ivendor/CMSIS_6/CMSIS/Core/Include
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=blinky.map

all: blinky.elf

main.o: main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

startup.o: startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

blinky.elf: main.o startup.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -r -i *.o *.elf *.map

load:
	openocd -f board/st_nucleo_f4.cfg

flash: blinky.elf
	openocd -f board/st_nucleo_f4.cfg -c "program blinky.elf verify reset exit"