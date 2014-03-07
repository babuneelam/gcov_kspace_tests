
/*
 *    Description:
 *      Sample Character driver to say hello & good bye though ioctls
 *    Author: Babu Neelam
 *
 */

#ifndef _SIMPLE_IOC_H
#define _SIMPLE_IOC_H

#include <linux/ioctl.h>

#define SIMPLE_DEV_MAGIC                   (('S' + 'I' + 'M' + 'P') & _IOC_TYPEMASK)
#define SIMPLE_DEV_IOC_SAY_HELLO           _IOW(SIMPLE_DEV_MAGIC, 1, int)
#define SIMPLE_DEV_IOC_SAY_GOODBYE         _IOW(SIMPLE_DEV_MAGIC, 2, int)

enum {
        SIMPLE_SUCCESS=0,
        SIMPLE_FAIL
};

typedef struct  {
        bool hello;
        int RetVal;
} simple_ioc_t;


#endif



