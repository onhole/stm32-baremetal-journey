CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=blinky.map

all: startup.o main.o blinky.elf

main.o: main.c
	$(CC) $(CFLAGS) $^ -o $@

startup.o: startup.c
	$(CC) $(CFLAGS) $^ -o $@

blinky.elf: main.o startup.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -r -i *.o *.elf *.map

load:
	openocd -f board\st_nucleo_f4.cfg