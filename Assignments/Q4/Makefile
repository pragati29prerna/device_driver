obj-m:=cal_driver.o
KDIR=/lib/modules/$(shell uname -r)/build
all:
	make -C $(KDIR) M=$(PWD) modules
	gcc -o add add.c
	gcc -o sub sub.c
	gcc -o mul mul.c
	gcc -o div div.c

clean:
	make -C $(KDIR) M=$(PWD) clean
	rm -rf add
	rm -rf sub
	rm -rf mul
	rm -rf div
