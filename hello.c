/*
 * First program for LKM
 * Hello World
 * */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

/*Some important LKM information are here*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hemant Kapoor");
MODULE_DESCRIPTION("Simple Hello World LKM");
MODULE_VERSION("0.1");

//Lets expose some variable
static char* name ="World";
module_param(name,charp,S_IRUGO);
MODULE_PARM_DESC(name,"Exposed character pointer name");

static int __init hello_init(void)
{
	printk(KERN_INFO "Hello %s from LKM\n", name);
	return 0;
}


static void __exit hello_exit(void)
{
	printk(KERN_INFO "Good Bye %s from LKM\n", name);
}

module_init(hello_init);
module_exit(hello_exit);
