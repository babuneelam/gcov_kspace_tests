
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/mman.h>
#include <fcntl.h>
#include "../simple_lib_include/simple_inc.h"


static int simple_get_fd(void);

int main(int argc, char *argv[])
{
	simple_ioc_t ioc;
	int retval;

	memset(&ioc, 0, sizeof(simple_ioc_t));
        if (retval = ioctl(simple_get_fd(), SIMPLE_DEV_IOC_SAY_HELLO, &ioc))
		printf("ioctl failed, retval: %d \r\n", retval);

	memset(&ioc, 0, sizeof(simple_ioc_t));
        if (retval = ioctl(simple_get_fd(), SIMPLE_DEV_IOC_SAY_GOODBYE, &ioc))
		printf("ioctl failed, retval: %d \r\n", retval);
}


static int
simple_get_fd(void)
{
        static  int fd = -1;

        if (fd < 0) {
                if ((fd = open("/dev/simple_dev", O_RDWR)) < 0)
		{
			printf("/dev/simple_dev open failed \r\n");
                        return (-1);
		}
        }
        return (fd);
}

