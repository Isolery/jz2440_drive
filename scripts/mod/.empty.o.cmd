cmd_scripts/mod/empty.o := arm-linux-gcc -Wp,-MD,scripts/mod/.empty.o.d  -nostdinc -isystem /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Os -marm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mapcs-32 -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -malignment-traps -msoft-float -Uarm -fno-omit-frame-pointer -fno-optimize-sibling-calls -g  -Wdeclaration-after-statement     -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(empty)"  -D"KBUILD_MODNAME=KBUILD_STR(empty)" -c -o scripts/mod/empty.o scripts/mod/empty.c

deps_scripts/mod/empty.o := \
  scripts/mod/empty.c \

scripts/mod/empty.o: $(deps_scripts/mod/empty.o)

$(deps_scripts/mod/empty.o):
