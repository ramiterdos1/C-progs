#include <linux/init.h>
#include <linux/module.h>
MODULE_LICENSE("GPL");
static int abc(void)
{
 printk(KERN_ALERT "..<1>..Hello World!!!! :)");
 return 0; 
}
static void abc1(void)
{
 printk(KERN_ALERT "..<1>..Adios thou!!! :)");
}
module_init(abc);
module_exit(abc1);
