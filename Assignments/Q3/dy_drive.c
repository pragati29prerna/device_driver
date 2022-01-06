//Write a character driver with open,read,write and close functionalities

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
ssize_t myread(struct file *filp,char __user *Ubuff, size_t count,loff_t *offp);
ssize_t mywrite(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp);
int myrelease(struct inode *inode,struct file *filp);

struct file_operations fops=
{
	.open = myopen,
	.read = myread,
	.write = mywrite,
	.release = myrelease,
};

//open system call
int myopen(struct inode *inode,struct file *filp)
{
	printk("In kernel: open call system\n");
	return 0;
}

// read system call

ssize_t myread(struct file *filp,char __user *Ubuff, size_t count,loff_t *offp)
{

const char *Kbuff="HAY USER";
int result,i=0;
ssize_t ret_val;
while(Kbuff[i] != '\0') 
	{
		i++;
	}
result=copy_to_user(Ubuff,Kbuff,i);

if(result>=0)
{
printk("In read: successfully read is....%s\n",Kbuff);
ret_val=sizeof(Kbuff);
return ret_val;
}
else 
{
printk(".......error while reading data....\n");
return -1;
}
}
//write system call
ssize_t mywrite(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp)
{
char Kbuff[100];
int result;
ssize_t ret_val;

result=copy_from_user((char *)Kbuff,Ubuff,count);

if(result==0)
{
printk("In write: Message from user is.... %s\n",Kbuff);
printk(".......successfully written.....\n");
ret_val=count;
return ret_val;
}

else if(result>0)
{
printk("...In write: part of data written is..... %s\n",Kbuff);
printk("...........\n");
ret_val=(count-result);
return ret_val;
}
else 
{
printk(".......error while writing data....\n");
return -1;
}
}
//close system call
int myrelease(struct inode *inode,struct file *filp)
{
        printk("In kernel: close call system\n");
        return 0;
}

struct cdev *mycdev;

//init module
static int __init chardevice_init(void)
{
	dev_t mydev;
	int result;
	int MAJOR,MINOR;

	int res= alloc_chrdev_region(&mydev,0,1,"CharDev"); //allocating dynamically
	MAJOR=MAJOR(mydev);
	MINOR=MINOR(mydev);

	printk(KERN_ALERT" major=%d and minor= %d\n",MAJOR,MINOR);
	
	if(res<0)
	{
		printk(KERN_ALERT "not registerd\n");
		return(-1);
	}

mycdev = cdev_alloc();
mycdev->ops = &fops;
result=cdev_add(mycdev,mydev,1);
	if(result<0)
        {
                printk("not created\n");
                unregister_chrdev_region(mydev,1);
		return(-1);
        }

	return 0;
}

//cleanup module

static void __exit chardevice_exit(void)
{
	dev_t mydev;
       
        unregister_chrdev_region(mydev,1);
	cdev_del(mycdev);
	printk("unregistered\n");	 
}

module_init(chardevice_init);
module_exit(chardevice_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION("character driver linux kerner module");

