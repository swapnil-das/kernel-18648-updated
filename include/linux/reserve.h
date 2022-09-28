#ifndef RESERVE_H
#define RESERVE_H

#include <linux/types.h>
#include <linux/sched.h>
#include <linux/kobject.h>


// mains truct that holds the rt task
struct active_task {
        char *buff;
        int file_created;
        int energy_track;
        unsigned int frequency;
        unsigned long long energy_consumed;
        pid_t pid;
	int cpu;
        struct rt_track rt;
        unsigned long size;
        unsigned long curr;
        unsigned long index;
        long t_ms;
	long c_ms;
        unsigned long last_read;
        struct kobject *pid_kobj;
        struct kobj_attribute energy_attr;
        struct kobj_attribute pid_attr;
        struct list_head link;
};

enum Policy {FF,NF,BF,WF};

struct work_wakeup {
        struct work_struct real_work;
        struct task_struct *task;
};

void clean_timers(void);

#endif



