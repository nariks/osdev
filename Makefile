CROSS = riscv64-unknown-elf
CC    = $(CROSS)-gcc
LD    = $(CROSS)-ld
OBJCOPY = $(CROSS)-objcopy

CFLAGS = -march=rv64imac_zicsr -mabi=lp64 -mcmodel=medany \
         -ffreestanding -nostdlib -nostdinc \
         -Wall -Wextra -g

SRCS = kernel/entry.S kernel/main.c kernel/uart.c
OBJS = $(SRCS:.c=.o)
OBJS := $(OBJS:.S=.o)

LDFLAGS = -T linker.ld

all: kernel.elf

kernel.elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.S
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean qemu

clean:
	rm -f $(OBJS) kernel.elf

qemu: kernel.elf
	qemu-system-riscv64 -machine virt -bios default -kernel kernel.elf \
	-nographic
