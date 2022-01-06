//Write a character driver with open and close functionality

//header for character device
#include <linux/cdev.h>
//header for unregistering device
#include <linux/fs.h>
//headers for device number
#include <linux/kdev_t.h>
#include <linux/types.h>
//header for modules
#include <linux/init.h>
#include <linux/module.h>
//header for accessing user buffer
#include <linux/uaccess.h>

//function prototype

int myopen(struct inode *inode,struct file *filp);
int myrelease(struct inode *inode,struct file *filp);

//file operation structure

struct file_operations fops=
{
	.open = myopen,
	.release=myrelease,
};

//open system call
int myopen(struct inode *inode,struct file *filp)
{
	printk("In kernel: open call system\n");
	return 0;
}

//close system call
int myrelease(struct inode *inode,struct file *filp)
{
        printk("In kernel: close call system\n");
        return 0;
}

struct cdev *mycdev; //

//init module
static int __init chardevice_init(void)
{
	dev_t mydev; //opaque datatype holds the device no.
	int result;
	int MAJOR,MINOR;

	mydev=MKDEV(002,0); //to create device no.
	MAJOR=MAJOR(mydev);// macros holds major no. and minor no.
	MINOR=MINOR(mydev);

	printk(" major=%d and minor= %d\n",MAJOR,MINOR);
	result= register_chrdev_region(mydev,1,"MyCharacterDevice"); //static method of registering device number
	if(result<0)
	{
		printk(KERN_ALERT "not registerd\n"); // return -1 if not registered
		return(-1);
	}

//device registration

mycdev = cdev_alloc(); //kernel allocate memory
mycdev->ops = &fops;
result=cdev_add(mycdev,mydev,1);// connects cdev structure and device no.
	if(result<0)
        {
                printk("not created\n");
                unregister_chrdev_region(mydev,1); //if not created deregister and return -1 
		return(-1);
        }

	return 0;
}

//cleanup module

static void __exit chardevice_exit(void)
{
	dev_t mydev;
        int MAJOR,MINOR;

        mydev=MKDEV(255,0);
        MAJOR=MAJOR(mydev);
        MINOR=MINOR(mydev);

        printk(" major=%d and minor= %d\n",MAJOR,MINOR);
        unregister_chrdev_region(mydev,1); //for deregistering the device
	cdev_del(mycdev); //deleting device no.
	printk("unregistered\n");	 
}

module_init(chardevice_init);
module_exit(chardevice_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION("character driver linux kerner module");
