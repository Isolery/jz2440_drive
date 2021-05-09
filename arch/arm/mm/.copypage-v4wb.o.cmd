cmd_arch/arm/mm/copypage-v4wb.o := arm-linux-gcc -Wp,-MD,arch/arm/mm/.copypage-v4wb.o.d  -nostdinc -isystem /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -mlittle-endian -D__ASSEMBLY__ -mapcs-32 -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -msoft-float -gdwarf2    -c -o arch/arm/mm/copypage-v4wb.o arch/arm/mm/copypage-v4wb.S

deps_arch/arm/mm/copypage-v4wb.o := \
  arch/arm/mm/copypage-v4wb.S \
  include/linux/linkage.h \
  include/asm/linkage.h \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/acpi/hotplug/memory.h) \
  include/linux/compiler.h \
    $(wildcard include/config/enable/must/check.h) \
  include/asm/asm-offsets.h \

arch/arm/mm/copypage-v4wb.o: $(deps_arch/arm/mm/copypage-v4wb.o)

$(deps_arch/arm/mm/copypage-v4wb.o):
