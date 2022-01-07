//Write a calculator driver with open,read,write and close functionalities

#include <linux/cdev.h>
#include <linux/fs.h>
#include <linux/kdev_t.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/uaccess.h>

//**************************************************function prototype of addition***************************************************

int open_add(struct inode *inode,struct file *filp);
ssize_t read_add(struct file *filp,char __user *Ubuff, size_t count,loff_t *offp);
ssize_t write_add(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp);
int release_add(struct inode *inode,struct file *filp);

struct file_operations fops_add=
{
	.open = open_add,
	.read = read_add,
	.write = write_add,
	.release = release_add,
};

static int add_result;
static int sub_result;
static int mul_result;
static int div_result;

//open system call
int open_add(struct inode *inode,struct file *filp)
{
	printk("In kernel: open call system\n");
	return 0;
}
//read system call

ssize_t read_add(struct file *filp, char __user *Ubuff, size_t count,loff_t *offp)
{
int result;
ssize_t sdata;
const int *res=&add_result;
result=copy_to_user((char*)Ubuff,(char*)res,sizeof(add_result));

if(result>=0)
{
printk("......successfully send the result to user.......\n");
sdata=count;

return sdata;
}

else 
{
printk(".......error while sending data....\n");
return -1;
}
}
// write system call

ssize_t write_add(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp)
{

int Kbuff[2];
int result;
ssize_t rdata;

result=copy_from_user((char*)Kbuff,(char *)Ubuff,count);

if(result>=0)
{
printk(".......successfully read....\n");
printk("The values are %d and %d\n",(int)Kbuff[0],(int)Kbuff[1]);
add_result=Kbuff[0]+Kbuff[1];

printk("The addition is %d\n",add_result);
rdata=count;
return rdata;
}
else 
{
printk(".......error while reading data....\n");
return -1;
}
}

//close system call
int release_add(struct inode *inode,struct file *filp)
{
        printk("In kernel: close call system\n");
        return 0;
}
//**************************************************function prototype of substraction*************************************************

int open_sub(struct inode *inode,struct file *filp);
ssize_t read_sub(struct file *filp,char __user *Ubuff, size_t count,loff_t *offp);
ssize_t write_sub(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp);
int release_sub(struct inode *inode,struct file *filp);

struct file_operations fops_sub=
{
	.open = open_sub,
	.read = read_sub,
	.write = write_sub,
	.release = release_sub,
};

//open system call
int open_sub(struct inode *inode,struct file *filp)
{
	printk("In kernel: open call system\n");
	return 0;
}
//read system call

ssize_t read_sub(struct file *filp, char __user *Ubuff, size_t count,loff_t *offp)
{
int result;
ssize_t sdata;
const int *res=&sub_result;
result=copy_to_user((char*)Ubuff,(char*)res,sizeof(sub_result));
;

if(result>=0)
{
printk("......successfully send the result to user.......\n");
sdata= sizeof(sub_result);

return sdata;
}

else 
{
printk(".......error while sending data....\n");
return -1;
}
}
// write system call

ssize_t write_sub(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp)
{

int Kbuff[2];
int result;
ssize_t rdata;

result=copy_from_user((char*)Kbuff,(char *)Ubuff,count);

if(result>=0)
{
printk(".......successfully read....\n");
printk("The values are %d and %d\n",(int)Kbuff[0],(int)Kbuff[1]);
sub_result=Kbuff[0]-Kbuff[1];

printk("The substraction is %d\n",sub_result);
rdata=count;
return rdata;
}
else 
{
printk(".......error while reading data....\n");
return -1;
}
}

//close system call
int release_sub(struct inode *inode,struct file *filp)
{
        printk("In kernel: close call system\n");
        return 0;
}

//**************************************************function prototype of multiplication************************************************

int open_mul(struct inode *inode,struct file *filp);
ssize_t read_mul(struct file *filp,char __user *Ubuff, size_t count,loff_t *offp);
ssize_t write_mul(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp);
int release_mul(struct inode *inode,struct file *filp);

struct file_operations fops_mul=
{
	.open = open_mul,
	.read = read_mul,
	.write = write_mul,
	.release = release_mul,
};

//open system call
int open_mul(struct inode *inode,struct file *filp)
{
	printk("In kernel: open call system\n");
	return 0;
}
//read system call

ssize_t read_mul(struct file *filp, char __user *Ubuff, size_t count,loff_t *offp)
{
int result;
ssize_t sdata;
const int *res=&mul_result;
printk("value of mul_result %d\n",mul_result);
result=copy_to_user((char*)Ubuff,(char*)res,sizeof(mul_result));


if(result>=0)
{
printk("......successfully send the result to user.......\n");
sdata= count;

return count;
}

else 
{
printk(".......error while sending data....\n");
return -1;
}
}
// write system call

ssize_t write_mul(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp)
{

int Kbuff[2];
int result;
ssize_t rdata;

result=copy_from_user((char*)Kbuff,(char *)Ubuff,count);

if(result>=0)
{
printk(".......successfully read....\n");
printk("The values are %d and %d\n",(int)Kbuff[0],(int)Kbuff[1]);
mul_result=Kbuff[0]*Kbuff[1];

printk("The multiplication is %d\n",mul_result);
rdata=count;
return rdata;
}
else 
{
printk(".......error while reading data....\n");
return -1;
}
}

//close system call
int release_mul(struct inode *inode,struct file *filp)
{
        printk("In kernel: close call system\n");
        return 0;
}

//**************************************************function prototype of division*************************************************//

int open_div(struct inode *inode,struct file *filp);
ssize_t read_div(struct file *filp,char __user *Ubuff, size_t count,loff_t *offp);
ssize_t write_div(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp);
int release_div(struct inode *inode,struct file *filp);

struct file_operations fops_div=
{
	.open = open_div,
	.read = read_div,
	.write = write_div,
	.release = release_div,
};

//open system call
int open_div(struct inode *inode,struct file *filp)
{
	printk("In kernel: open call system\n");
	return 0;
}
//read system call

ssize_t read_div(struct file *filp, char __user *Ubuff, size_t count,loff_t *offp)
{
int result;
ssize_t sdata;
const int *res=&div_result;
result=copy_to_user((char*)Ubuff,(char*)res,sizeof(div_result));


if(result>=0)
{
printk("......successfully send the result to user.......\n");
sdata=count;

return count;
}

else 
{
printk(".......error while sending data....\n");
return -1;
}
}
// write system call

ssize_t write_div(struct file *filp,const char __user *Ubuff, size_t count,loff_t *offp)
{

int Kbuff[2];
int result;
ssize_t rdata;

result=copy_from_user((char*)Kbuff,(char *)Ubuff,count);

if(result>=0)
{
printk(".......successfully read....\n");
printk("The values are %d and %d\n",(int)Kbuff[0],(int)Kbuff[1]);
div_result=Kbuff[0]/Kbuff[1];

printk("The division is %d\n",div_result);
rdata=count;
return rdata;
}
else 
{
printk(".......error while reading data....\n");
return -1;
}
}

//close system call
int release_div(struct inode *inode,struct file *filp)
{
        printk("In kernel: close call system\n");
        return 0;
}

//character device initilization

struct cdev *mycdev_add;
struct cdev *mycdev_sub;
struct cdev *mycdev_mul;
struct cdev *mycdev_div;

dev_t add_dev;
dev_t sub_dev;
dev_t mul_dev;
dev_t div_dev;
dev_t mydev;

int re_add,re_sub,re_mul,re_div;
int res1,res2,res3,res4;

//***********************************************init module*************************************************************************

static int __init chardevice_init(void)
{
	
	int result;
	int MAJOR,MINOR;

       result= alloc_chrdev_region(&mydev,0,4,"Mycal");
	
	if(result<0)
	{
		printk(KERN_ALERT "not registerd\n");
		return(-1);
	}

	MAJOR=MAJOR(mydev);
	add_dev=MKDEV(MAJOR,0);
	sub_dev=MKDEV(MAJOR,1);
	mul_dev=MKDEV(MAJOR,2);
	div_dev=MKDEV(MAJOR,3);

        printk(" major=%d and minor= %d\n",MAJOR,MINOR);
				

mycdev_add = cdev_alloc();
mycdev_add->ops = &fops_add;
res1=cdev_add(mycdev_add,add_dev,1);

mycdev_sub = cdev_alloc();
mycdev_sub->ops = &fops_sub;
res2=cdev_add(mycdev_sub,sub_dev,1);

mycdev_mul = cdev_alloc();
mycdev_mul->ops = &fops_mul;
res3=cdev_add(mycdev_mul,mul_dev,1);

mycdev_div = cdev_alloc();
mycdev_div->ops = &fops_div;
res4=cdev_add(mycdev_div,div_dev,1);

	if(res1<0||res2<0||res3<0||res4<0)
        {
                printk("not created by kernel\n");
           
		return(-1);
        }

	return 0;
}

//*************************************************************cleanup module**********************************************************

static void __exit chardevice_exit(void)
{
	
        //int MAJOR,MINOR;
        
       // printk(" major=%d and minor= %d\n",MAJOR,MINOR);
        unregister_chrdev_region(add_dev,1);
        unregister_chrdev_region(sub_dev,1);
        unregister_chrdev_region(mul_dev,1);
        unregister_chrdev_region(div_dev,1);
	
	cdev_del(mycdev_add);
	cdev_del(mycdev_sub);
	cdev_del(mycdev_mul);
	cdev_del(mycdev_div);
	printk("unregistered\n");	 
}

module_init(chardevice_init);
module_exit(chardevice_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION("calculator character driver linux kerner module");

