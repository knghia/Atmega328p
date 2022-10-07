
# Size

![image info](./Image/memory.png)

+ text (Code segment ~ Text segment)
+ data (Data segment)
+ .bss (BSS segment ~ uninitialized data segment)


## CMD

```sh
    $(size_compile) $(build_path)/$(target).elf
```

## OUTPUT

+ Don't create the parameter

```sh
C:\\avr-gcc-12.1.0-x64-windows\\bin\\avr-size Build/led.elf
   text    data     bss     dec     hex filename
   3158       0       0    3158     c56 Build/led.elf
```

+ Create some parameter

```sh
#include "use.h"
uint8_t i = 1;
uint8_t k = 0;
uint8_t j;
uint8_t a[10];
extern void setup(void){
}
extern void loop(void){
}
```
```sh
C:\\avr-gcc-11.1.0-x64-windows\\bin\\avr-size Build/led.elf
   text    data     bss     dec     hex filename
   3074       2      12    3088     c10 Build/led.elf
```
The size of memory depend the number of parameters


```sh
$(size_compile) -A $(build_path)/$(target).elf

Build/led.elf  :
section                    size      addr
.data                         2   8388864
.text                      3064         0
.bss                          1   8388866
.comment                     18         0
.note.gnu.avr.deviceinfo     64         0
.debug_aranges              224         0
.debug_info                2047         0
.debug_abbrev              1770         0
.debug_line                1046         0
.debug_frame                 88         0
.debug_str                  753         0
.debug_line_str             184         0
.debug_rnglists              19         0
Total                      9280
```

```sh
$(obj_dump_compile) -Pmem-usage $(build_path)/$(target).elf

Build/led.elf:     file format elf32-avr
AVR Memory Usage
----------------
Device: atmega328p

Program:    3066 bytes (9.4% Full)
(.text + .data + .bootloader)

Data:          3 bytes (0.1% Full)
(.data + .bss + .noinit)
```

```sh
$(readelf_compile) -x .note.gnu.avr.deviceinfo $(build_path)/$(target).elf

Hex dump of section '.note.gnu.avr.deviceinfo':
  0x00000000 04000000 2d000000 01000000 41565200 ....-.......AVR.
  0x00000010 00000000 00800000 00010000 00080000 ................
  0x00000020 00000000 00040000 08000000 01000000 ................
  0x00000030 0061746d 65676133 32387000 00000000 .atmega328p.....
```