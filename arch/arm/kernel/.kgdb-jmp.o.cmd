cmd_arch/arm/kernel/kgdb-jmp.o := arm-linux-gcc -Wp,-MD,arch/arm/kernel/.kgdb-jmp.o.d  -nostdinc -isystem /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -mlittle-endian -D__ASSEMBLY__ -mapcs-32 -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -msoft-float -gdwarf2    -c -o arch/arm/kernel/kgdb-jmp.o arch/arm/kernel/kgdb-jmp.S

deps_arch/arm/kernel/kgdb-jmp.o := \
  arch/arm/kernel/kgdb-jmp.S \
  include/linux/linkage.h \
  include/asm/linkage.h \

arch/arm/kernel/kgdb-jmp.o: $(deps_arch/arm/kernel/kgdb-jmp.o)

$(deps_arch/arm/kernel/kgdb-jmp.o):
