cmd_lib/zlib_inflate/inflate.o := arm-linux-gcc -Wp,-MD,lib/zlib_inflate/.inflate.o.d  -nostdinc -isystem /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Os -marm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mapcs-32 -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -malignment-traps -msoft-float -Uarm -fno-omit-frame-pointer -fno-optimize-sibling-calls -g  -Wdeclaration-after-statement     -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(inflate)"  -D"KBUILD_MODNAME=KBUILD_STR(zlib_inflate)" -c -o lib/zlib_inflate/inflate.o lib/zlib_inflate/inflate.c

deps_lib/zlib_inflate/inflate.o := \
  lib/zlib_inflate/inflate.c \
  include/linux/zutil.h \
  include/linux/zlib.h \
  include/linux/zconf.h \
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
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/numa.h) \
  /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include/stdarg.h \
  include/linux/linkage.h \
  include/asm/linkage.h \
  include/linux/bitops.h \
  include/asm/bitops.h \
    $(wildcard include/config/smp.h) \
  include/asm/system.h \
    $(wildcard include/config/cpu/cp15.h) \
    $(wildcard include/config/cpu/xsc3.h) \
    $(wildcard include/config/cpu/xscale.h) \
    $(wildcard include/config/cpu/sa1100.h) \
    $(wildcard include/config/cpu/sa110.h) \
  include/asm/memory.h \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/dram/size.h) \
    $(wildcard include/config/dram/base.h) \
    $(wildcard include/config/discontigmem.h) \
  include/asm/arch/memory.h \
    $(wildcard include/config/cpu/s3c2400.h) \
  include/asm/sizes.h \
  include/asm-generic/memory_model.h \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/out/of/line/pfn/to/page.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
    $(wildcard include/config/x86.h) \
  include/asm/irqflags.h \
  include/asm/ptrace.h \
    $(wildcard include/config/arm/thumb.h) \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/ffz.h \
  include/asm-generic/bitops/__ffs.h \
  include/asm-generic/bitops/fls.h \
  include/asm-generic/bitops/ffs.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/sched.h \
  include/asm-generic/bitops/hweight.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/asm/byteorder.h \
  include/linux/byteorder/little_endian.h \
  include/linux/byteorder/swab.h \
  include/linux/byteorder/generic.h \
  include/asm/bug.h \
    $(wildcard include/config/bug.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug.h) \
  lib/zlib_inflate/inftrees.h \
  lib/zlib_inflate/inflate.h \
  lib/zlib_inflate/inffast.h \
  lib/zlib_inflate/infutil.h \
  lib/zlib_inflate/inffixed.h \

lib/zlib_inflate/inflate.o: $(deps_lib/zlib_inflate/inflate.o)

$(deps_lib/zlib_inflate/inflate.o):
