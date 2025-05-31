# === CONFIGURATION ===
TARGET = examples_main
CPU = -mcpu=cortex-m4 -mthumb -mfpu=fpv4-sp-d16 -mfloat-abi=hard
CFLAGS = -Wall -O2 -ffreestanding $(CPU)
LDFLAGS = -T ../linker/STM32F446RETX_FLASH.ld -nostartfiles $(CPU)

# === INCLUDE DIRECTORIES ===
INCLUDES = \
	-I../api/include \
	-I../core/include \
	-I../core_registers \
	-I../core_bare_metal_addresses

# === SOURCE FILES ===
SRC = \
	$(wildcard ../api/src/*.c) \
	$(wildcard ../core/src/*.c) \
	$(wildcard *.c) \
	../startup/startup_stm32f446retx.s

OBJ = $(SRC:.c=.o)
OBJ := $(OBJ:.s=.o)

# === TOOLCHAIN ===
CC = arm-none-eabi-gcc
AS = arm-none-eabi-as
LD = arm-none-eabi-ld
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE = arm-none-eabi-size

# === BUILD TARGETS ===
all: $(TARGET).bin

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

%.o: %.s
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET).elf: $(OBJ)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

$(TARGET).bin: $(TARGET).elf
	$(OBJCOPY) -O binary $< $@
	$(OBJDUMP) -D $< > $(TARGET).lst
	$(SIZE) $<

flash: examples_main.elf
	openocd -f interface/stlink.cfg -f target/stm32f4x.cfg \
		-c "program examples_main.elf verify reset exit"

clean:
	rm -f *.o ../api/src/*.o ../core/src/*.o
	rm -f $(TARGET).elf $(TARGET).bin $(TARGET).lst
