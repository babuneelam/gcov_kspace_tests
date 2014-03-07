

GCOV_PROFILE := y

CFLAGS=-ftest-coverage -fprofile-arcs  --disable-initfini-array 
export CFLAGS
obj-m += simple_dev.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean



