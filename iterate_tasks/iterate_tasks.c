#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DemonLord");
MODULE_DESCRIPTION("Iterating over tasks using DFS");

// Recursive DFS function
void dfs(struct task_struct *task) {
    struct task_struct *child;
    struct list_head *list;

    // Print the current task details
    // task->comm: name of the program
    // task->pid: process ID
    // task->state: state of the process (-1 unrunnable, 0 runnable, >0 stopped)
    printk(KERN_INFO "Name: %-20s PID: %d State: %ld\n", task->comm, task->pid, task->state);

    // Iterate over the children of the current task
    list_for_each(list, &task->children) {
        // Retrieve the task_struct from the list_head
        child = list_entry(list, struct task_struct, sibling);
        
        // Recursively call dfs on the child
        dfs(child);
    }
}

// Module Entry Point
int simple_init(void) {
    printk(KERN_INFO "Loading Module... DFS Iteration Started\n");
    
    // Start DFS from init_task (the root of the process tree)
    dfs(&init_task);
    
    return 0;
}

// Module Exit Point
void simple_exit(void) {
    printk(KERN_INFO "Removing Module... DFS Iteration Ended\n");
}

module_init(simple_init);
module_exit(simple_exit);


