CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb
CPPFLAGS= -DSTM32F446xx \
		-Ivendor/CMSIS_6/CMSIS/Core/Include \
		-Ivendor/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/STM32F4xx_StdPeriph_Driver/inc \
		-Ivendor/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/CMSIS/Device/ST/STM32F4xx/Include \
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

$(BUILD)/pwmTIM.o: drivers/pwmTIM.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/pwmGPIO.o: drivers/pwmGPIO.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/startup.o: startup/startup.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/stm32f4xx_rcc.o: vendor/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_rcc.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/stm32f4xx_gpio.o: vendor/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_gpio.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/stm32f4xx_tim.o: vendor/STM32F4xx_DSP_StdPeriph_Lib_V1.9.0/Libraries/STM32F4xx_StdPeriph_Driver/src/stm32f4xx_tim.c
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

$(BUILD)/blinky.elf: $(BUILD)/main.o $(BUILD)/startup.o $(BUILD)/systick.o $(BUILD)/gpio.o $(BUILD)/pwmTIM.o $(BUILD)/pwmGPIO.o \
                      $(BUILD)/stm32f4xx_rcc.o $(BUILD)/stm32f4xx_gpio.o $(BUILD)/stm32f4xx_tim.o 
	$(CC) $(LDFLAGS) $^ -o $@




clean:
	rm -r -i $(BUILD)/*.o $(BUILD)/*.elf $(BUILD)/*.map

load:
	openocd -f board/st_nucleo_f4.cfg

flash: $(BUILD)/blinky.elf
	openocd -f board/st_nucleo_f4.cfg -c "program $< verify reset exit" # Needed to add in the $< in order to appropriately address the blinky.elf file in the build folder.