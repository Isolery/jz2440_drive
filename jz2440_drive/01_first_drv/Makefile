KERN_DIR = /home/book/jz2440/linux/linux-2.6/linux-2.6.22.6

all:
	make -C $(KERN_DIR) M=`pwd` modules

clean:
	rm -f *.o *.ko *.mod.o *.mod.c *.symvers modul* .first*
	rm -rf .tmp_versions

obj-m += first_drv.o