cmd_arch/arm/lib/clearbit.o := arm-linux-gcc -Wp,-MD,arch/arm/lib/.clearbit.o.d  -nostdinc -isystem /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -mlittle-endian -D__ASSEMBLY__ -mapcs-32 -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -msoft-float -gdwarf2    -c -o arch/arm/lib/clearbit.o arch/arm/lib/clearbit.S

deps_arch/arm/lib/clearbit.o := \
  arch/arm/lib/clearbit.S \
  include/linux/linkage.h \
  include/asm/linkage.h \
  include/asm/assembler.h \
  include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
    $(wildcard include/config/smp.h) \
  arch/arm/lib/bitops.h \
    $(wildcard include/config/cpu/32v6k.h) \

arch/arm/lib/clearbit.o: $(deps_arch/arm/lib/clearbit.o)

$(deps_arch/arm/lib/clearbit.o):
