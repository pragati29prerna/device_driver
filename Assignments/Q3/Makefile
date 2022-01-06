obj-m:=dy_drive.o
KDIR=/lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o user user_space.c
clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf user
