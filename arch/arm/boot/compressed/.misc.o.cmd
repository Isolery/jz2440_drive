cmd_arch/arm/boot/compressed/misc.o := arm-linux-gcc -Wp,-MD,arch/arm/boot/compressed/.misc.o.d  -nostdinc -isystem /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Os -marm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mapcs-32 -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -malignment-traps -msoft-float -Uarm -fno-omit-frame-pointer -fno-optimize-sibling-calls -g  -Wdeclaration-after-statement  -fpic -Dstatic=  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(misc)"  -D"KBUILD_MODNAME=KBUILD_STR(misc)" -c -o arch/arm/boot/compressed/misc.o arch/arm/boot/compressed/misc.c

deps_arch/arm/boot/compressed/misc.o := \
  arch/arm/boot/compressed/misc.c \
    $(wildcard include/config/debug/icedcc.h) \
    $(wildcard include/config/cpu/v6.h) \
  include/linux/string.h \
  include/linux/compiler.h \
    $(wildcard include/config/enable/must/check.h) \
  include/linux/compiler-gcc3.h \
  include/linux/compiler-gcc.h \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbd.h) \
    $(wildcard include/config/lsf.h) \
    $(wildcard include/config/resources/64bit.h) \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/asm/posix_types.h \
  include/asm/types.h \
  include/asm/string.h \
  include/asm/arch/uncompress.h \
    $(wildcard include/config/s3c2410/lowlevel/uart/port.h) \
    $(wildcard include/config/cpu/s3c2400.h) \
    $(wildcard include/config/s3c2410/boot/watchdog.h) \
    $(wildcard include/config/s3c2410/boot/error/reset.h) \
  include/asm/arch/regs-serial.h \
  include/asm/arch/regs-gpio.h \
  include/asm/arch/regs-watchdog.h \
  include/asm/arch/map.h \
    $(wildcard include/config/cpu/s3c2412.h) \
    $(wildcard include/config/cpu/s3c2413.h) \
    $(wildcard include/config/cpu/s3c2412/only.h) \
  arch/arm/boot/compressed/../../../../lib/inflate.c \

arch/arm/boot/compressed/misc.o: $(deps_arch/arm/boot/compressed/misc.o)

$(deps_arch/arm/boot/compressed/misc.o):
