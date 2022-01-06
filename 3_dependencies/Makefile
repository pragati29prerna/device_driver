obj-m:=add.o mod1.o
KDIR=/lib/modules/$(shell uname -r)/build/
all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	make -C $(KDIR) M=$(PWD) clean
