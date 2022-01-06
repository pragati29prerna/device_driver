

#include <linux/init.h>
#include <linux/module.h>
#include "add.h"

static int myadd(int a, int b)
{
	return(a+b);
}

EXPORT_SYMBOL_GPL(myadd);
static int __init add_init(void)
{
	printk("init section : hello\n");
	return 0;
}


static void __exit add_exit(void)
{
	printk("exit from the module \n");
}


module_init(add_init);
module_exit(add_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION("Dependency linux kerner module");
