
GCOV_PROFILE := y
GCOV_PROFILE_hello.o := y

CFLAGS=-ftest-coverage -fprofile-arcs  --disable-initfini-array
export CFLAGS
obj-m += hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD)/ modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
