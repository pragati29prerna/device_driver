obj-m:=mydrive.o
KDIR=/lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o user user.c
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf user
	
