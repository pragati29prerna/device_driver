#include <linux/init.h>
#include <linux/module.h>
#include "head.h"

static int myadd(int a, int b) //add function
{
	return(a+b);
}

EXPORT_SYMBOL_GPL(myadd); // export add function as shared object

static int __init add_init(void) //initialize module
{
	printk("init section of add : hello\n");
	return 0;
}


static void __exit add_exit(void) //exit module
{
	printk("exit from the add module \n");
}


module_init(add_init);
module_exit(add_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION("Dependency linux kerner module");
