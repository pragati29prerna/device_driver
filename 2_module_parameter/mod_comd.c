
#include <linux/init.h>
#include <linux/module.h>

static char *charvar="DEVICE DRIVER";
static int intvar=10;
module_param(charvar,charp,S_IRUGO);
module_param(intvar,int,S_IRUGO);

static int __init modparam_init(void)
{
	printk(KERN_ALERT "init section:welcome to my module\n");
	printk(KERN_ALERT "the value of character variable is: %s\n",charvar);
	return 0;
}

static void __exit modparam_exit(void)
{
	printk("exit :bye bye\n");
}
module_init(modparam_init);
module_exit(modparam_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("PRERNA");
MODULE_DESCRIPTION("Module command linux kerner module");
