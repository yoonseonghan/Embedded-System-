## Cross-compilation commands 
CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-gcc
AS      = arm-none-eabi-as
OBJCOPY = arm-none-eabi-objcopy
SIZE    = arm-none-eabi-size

OBJS  = main.o startup.o

## Platform and optimization options
CFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F411VETx -DSTM32F411E_DISCO 
CFLAGS += -DDEBUG -DSTM32F411xE -DUSE_STDPERIPH_DRIVER -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP
LFLAGS = -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"LinkerScript.ld" -Wl,-Map=out.map -Wl,--gc-sections

## Rules
all: out.elf out.bin size 

out.elf: $(OBJS) LinkerScript.ld
	$(LD) -specs=nano.specs -specs=nosys.specs $(LFLAGS) -o out.elf $(OBJS)

out.bin: out.elf
	$(OBJCOPY) -O binary "out.elf" "out.bin"

size: out.elf
	$(SIZE) $< 

qemu: 
	qemu-system-gnuarmeclipse -cpu cortex-m4 -machine STM32F4-Discovery -gdb tcp::3333 -kernel out.elf


ocd:
	openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg 


flash:
	openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg -c "program out.elf verify reset exit"


gdb:
	./run_gdb.sh

gdb_openocd:
	./run_gdb_ocd.sh

clean:
	rm *.o *.d *.elf *.bin *.map
