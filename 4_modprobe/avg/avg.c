#include <linux/init.h>
#include <linux/module.h>
#include "head.h" //include own header

static int a=20;
static int b=20;
int avg;

static int __init avg_init(void) //module function initialized
{
	avg=myadd(a,b)/2; //calling shared object
	printk("welcome to average module: hello\n");
	printk("init section:Average = %d\n",avg);
	return 0;
}

static void __exit avg_exit(void) //module exit function
{
	printk("exit from average module:bye\n");
}

module_init(avg_init);
module_exit(avg_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION(" linux kerner module");
