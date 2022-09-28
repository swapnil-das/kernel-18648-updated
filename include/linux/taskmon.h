#ifndef TASKMON_H
#define TASKMON_H

#include <linux/kobject.h>
#include <linux/list.h>

#define QUANTUM 1000


struct file_data {

	int pid;
	long size;
	char buff[QUANTUM];
	struct kobj_attribute file_attr;
	struct list_head link;
};

#endif
