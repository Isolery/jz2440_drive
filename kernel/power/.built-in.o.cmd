cmd_kernel/power/built-in.o :=  arm-linux-ld -EL   -r -o kernel/power/built-in.o kernel/power/main.o kernel/power/process.o kernel/power/console.o kernel/power/poweroff.o
