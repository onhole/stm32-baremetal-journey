# Minimal Blinky


## 📦 Technologies
- `C`
- `Linker Script`
- `Makefile`
- `GNU Toolchain`
- `OpenOCD`
- `STM32 Nucleo-F446RE Development Board`

## ⚙️ How to Use
1. Execute `git clone --branch minimalBlinky --single-branch https://github.com/onhole/stm32-baremetal-journey` in Git Bash.
2. Execute `make all`. This will create the final executable to be flashed to the ROM.
3. Execute `make flash`. This will start OpenOCD and flash the blinky.elf to the ROM. LED 2 should now be flashing!