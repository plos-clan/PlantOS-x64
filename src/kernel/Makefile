build:
	gcc -m64 \
    -Wall \
    -Wextra \
    -ffreestanding \
    -fno-stack-protector \
    -fno-stack-check \
    -fno-lto \
    -fno-PIC \
    -ffunction-sections \
    -fdata-sections \
	./kernel.c -c kernel.o
	ld  -T lds.ld kernel.o -o kernel.elf
	