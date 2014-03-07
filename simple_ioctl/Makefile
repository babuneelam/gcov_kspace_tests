
BUILDDIR=../bin

SUBDIRS = simple_krn_drv simple_test_app

all: 
	@for dir in $(SUBDIRS); \
        do \
            $(MAKE) -C $${dir} $@ || exit $$?; \
        done

clean:
	echo cleaning up in .
	@for dir in $(SUBDIRS); \
        do \
            $(MAKE) -C $${dir} clean || exit $$?; \
        done


