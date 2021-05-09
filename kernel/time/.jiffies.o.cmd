cmd_kernel/time/jiffies.o := arm-linux-gcc -Wp,-MD,kernel/time/.jiffies.o.d  -nostdinc -isystem /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include -D__KERNEL__ -Iinclude  -include include/linux/autoconf.h -mlittle-endian -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Os -marm -fno-omit-frame-pointer -mapcs -mno-sched-prolog -mapcs-32 -mno-thumb-interwork -D__LINUX_ARM_ARCH__=4 -march=armv4t -mtune=arm9tdmi -malignment-traps -msoft-float -Uarm -fno-omit-frame-pointer -fno-optimize-sibling-calls -g  -Wdeclaration-after-statement     -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(jiffies)"  -D"KBUILD_MODNAME=KBUILD_STR(jiffies)" -c -o kernel/time/jiffies.o kernel/time/jiffies.c

deps_kernel/time/jiffies.o := \
  kernel/time/jiffies.c \
  include/linux/clocksource.h \
    $(wildcard include/config/clocksource/watchdog.h) \
    $(wildcard include/config/generic/time/vsyscall.h) \
  include/linux/types.h \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbd.h) \
    $(wildcard include/config/lsf.h) \
    $(wildcard include/config/resources/64bit.h) \
  include/linux/posix_types.h \
  include/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/enable/must/check.h) \
  include/linux/compiler-gcc3.h \
  include/linux/compiler-gcc.h \
  include/asm/posix_types.h \
  include/asm/types.h \
  include/linux/timex.h \
    $(wildcard include/config/time/interpolation.h) \
    $(wildcard include/config/no/hz.h) \
  include/linux/time.h \
  include/linux/seqlock.h \
  include/linux/spinlock.h \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
  include/linux/thread_info.h \
  include/linux/bitops.h \
  include/asm/bitops.h \
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
  include/linux/linkage.h \
  include/asm/linkage.h \
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
  include/asm/thread_info.h \
    $(wildcard include/config/debug/stack/usage.h) \
  include/asm/fpstate.h \
    $(wildcard include/config/iwmmxt.h) \
  include/asm/domain.h \
    $(wildcard include/config/io/36.h) \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/spinlock/sleep.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/numa.h) \
  /home/book/jz2440/gcc-3.4.5-glibc-2.3.6/bin/../lib/gcc/arm-linux/3.4.5/include/stdarg.h \
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
  include/linux/stringify.h \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/generic/hardirqs.h) \
    $(wildcard include/config/prove/locking.h) \
  include/linux/spinlock_types_up.h \
  include/linux/spinlock_up.h \
  include/linux/spinlock_api_up.h \
  include/asm/atomic.h \
  include/asm-generic/atomic.h \
  include/asm/param.h \
    $(wildcard include/config/hz.h) \
  include/asm/timex.h \
  include/asm/arch/timex.h \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
  include/linux/poison.h \
  include/linux/prefetch.h \
  include/asm/processor.h \
  include/asm/cache.h \
  include/linux/cache.h \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/jiffies.h \
  include/linux/calc64.h \
  include/asm/div64.h \
  include/asm/io.h \
  include/asm/arch/io.h \
  include/asm/hardware.h \
  include/asm/arch/hardware.h \
    $(wildcard include/config/cpu/s3c2440.h) \
    $(wildcard include/config/no/multiword/io.h) \
  include/asm/arch/map.h \
    $(wildcard include/config/cpu/s3c2412.h) \
    $(wildcard include/config/cpu/s3c2413.h) \
    $(wildcard include/config/cpu/s3c2412/only.h) \
  include/linux/init.h \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/hotplug.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/acpi/hotplug/memory.h) \

kernel/time/jiffies.o: $(deps_kernel/time/jiffies.o)

$(deps_kernel/time/jiffies.o):
