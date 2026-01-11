CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb
CPPFLAGS= -DSTM32F446xx \
		-Ivendor/cmsis-device-f4/Include \
		-Ivendor/CMSIS_6/CMSIS/Core/Include \
		-Idrivers/include
LDFLAGS= -nostdlib -T linker.ld -Wl,-Map=blinky.map
BUILD= build

all: $(BUILD)/blinky.elf

$(BUILD)/main.o: app/main.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/systick.o: drivers/systick.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/gpio.o: drivers/gpio.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/tim.o: drivers/tim.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/startup.o: startup/startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@


$(BUILD)/blinky.elf: $(BUILD)/main.o $(BUILD)/startup.o $(BUILD)/systick.o $(BUILD)/gpio.o $(BUILD)/tim.o
	$(CC) $(LDFLAGS) $^ -o $@

clean:
	rm -r -i $(BUILD)/*.o $(BUILD)/*.elf $(BUILD)/*.map

load:
	openocd -f board/st_nucleo_f4.cfg

flash: $(BUILD)/blinky.elf
	openocd -f board/st_nucleo_f4.cfg -c "program $< verify reset exit" # Needed to add in the $< in order to appropriately address the blinky.elf file in the build folder.