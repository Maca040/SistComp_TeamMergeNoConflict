obj-m := TeamMergeNoConflict-driver.o
KDIR := $(HOME)/qemu-env/headers/linux-headers-arm64
PWD := $(shell pwd)
EXTRA_CFLAGS = -I$(KDIR)/include

ARCH_TARGET := arm64
CROSS_COMPILER := aarch64-linux-gnu-

all:
	$(MAKE) ARCH=$(ARCH_TARGET) CROSS_COMPILE=$(CROSS_COMPILER) -C $(KDIR) M=$(PWD) EXTRA_CFLAGS="$(EXTRA_CFLAGS)" modules

clean:
	$(MAKE) ARCH=$(ARCH_TARGET) CROSS_COMPILE=$(CROSS_COMPILER) -C $(KDIR) M=$(PWD) clean