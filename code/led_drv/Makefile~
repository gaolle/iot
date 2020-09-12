obj-m += led_drv.o

KERN_DIR=/home/gec/kernel/linux-3.0.8
PWD := $(shell pwd)
modules:
	$(MAKE) -C $(KERN_DIR) M=$(PWD) modules
clean:
	$(MAKE) -C $(KERN_DIR) M=$(PWD) modules clean

