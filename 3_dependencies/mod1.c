

#include <linux/init.h>
#include <linux/module.h>
#include "add.h"

static int a=10;
static int b=20;

static int __init add_init(void)
{
	printk("init section:addition = %d\n",myadd(a,b));
	return 0;
}


static void __exit add_exit(void)
{
	printk("exit\n");
}

module_init(add_init);
module_exit(add_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION(" linux kerner module");
