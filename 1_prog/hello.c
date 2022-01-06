//include section//

#include<linux/init.h>
#include<linux/module.h>
#include<linux/kernel.h>


MODULE_LICENSE("GPL");//license
MODULE_AUTHOR("Prerna");//author

//init section
static int __init hello_init(void)
{
	printk(KERN_ALERT "\n HELLO");
	return 0;

}

//cleanup section
static void __exit hello_exit(void)
{
        printk(KERN_ALERT "\n BYE");
}
module_init(hello_init);
module_exit(hello_exit);


