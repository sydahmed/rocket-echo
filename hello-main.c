/**
 * @file    hello-main.c
 * @author  Nick Clark
 * @date    03-April-2017
 * @version 0.1
 * @brief  This is a simple printk-based kernel module.
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "dummy.h"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Nick Clark");
MODULE_DESCRIPTION("The GREATEST MODULE in the world");
MODULE_VERSION("0.1");

static char *name = "Mitten face";
module_param(name, charp, S_IRUGO); // IRUGO='read' for user, group, other
MODULE_PARM_DESC(name, "Your name, you heathen swine");

static int __init my_init(void) {
    printk(KERN_INFO "Hello, world %d\n", 2);
    printk(KERN_INFO "Dummy time: %d\n", dummy_function(54));
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdate-time"
    printk(KERN_INFO "Built on: " __DATE__ " at " __TIME__);
    #pragma GCC diagnostic pop
    printk("What's up, %s?", name);
    return 0;
}

static void __exit my_exit(void) {
    printk(KERN_INFO "Goodbye, world 2\n");
    return;
}

module_init(my_init);
module_exit(my_exit);
