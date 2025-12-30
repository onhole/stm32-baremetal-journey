CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb

main.o : main.c
	$(CC) $(CFLAGS) $^ -o $@