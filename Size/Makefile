
build_path			:= Build

device     			:= atmega328p
f_cpu				:= 16000000UL

port				:= COM8
baudrata			:= 115200
program_type		:= arduino

cflags 				= -g -w -Wall -Os -mmcu=$(device) -DF_CPU=$(f_cpu)
cflags 				+= -Wl,-u,vfprintf -lprintf_flt

compile_path		:= C:\\avr-gcc-11.1.0-x64-windows\\bin\\

gcc_compile    		:= $(compile_path)avr-gcc
size_compile    	:= $(compile_path)avr-size
obj_copy_compile   	:= $(compile_path)avr-objcopy
obj_dump_compile   	:= $(compile_path)avr-objdump
readelf_compile		:= $(compile_path)avr-readelf
avrdude_compile		:= $(compile_path)avrdude


target 	= led

c_sources = \
Use/use.c \
Drivers/Src/serial.c \
Drivers/Src/main.c

h_sources = \
-IDrivers/Inc \
-IUse

all: clean $(build_path)/$(target).elf $(build_path)/$(target).hex size

objects	= $(addprefix $(build_path)/,$(notdir $(c_sources:.c=.o)))
vpath %.c $(sort $(dir $(c_sources)))

$(build_path)/%.o: %.c
	$(gcc_compile) $(cflags) $(h_sources) -c $< -o $@

$(build_path)/$(target).hex: $(build_path)/$(target).elf
	$(obj_copy_compile) -O ihex -R .eeprom $< $@

$(build_path)/$(target).elf: $(objects)
	$(gcc_compile) $(cflags) $(objects) -o $@

size:
	$(size_compile) -A $(build_path)/$(target).elf
	$(size_compile) $(build_path)/$(target).elf
	$(obj_dump_compile) -Pmem-usage $(build_path)/$(target).elf
	$(readelf_compile) -x .note.gnu.avr.deviceinfo $(build_path)/$(target).elf

push:
	$(avrdude_compile) -F -v -p $(device) -b $(baudrata) -c $(program_type) -P $(port) -D -U flash:w:$(build_path)/$(target).hex:i

clean:
	del -f $(build_path)\*.*


