
compile_path		:= C:\\avr-gcc-12.1.0-x64-windows\\bin\\

gcc_compile    		:= $(compile_path)avr-gcc
size_compile    	:= $(compile_path)avr-size
obj_copy_compile   	:= $(compile_path)avr-objcopy
avrdude_compile		:= $(compile_path)avrdude
asm_compile    		:= $(compile_path)avr-as

push:
	$(asm_compile) Led.S
clean:
	del -f $(build_path)\*.*


