
CC = gcc
CPP = g++
LD = ld
CC_FLAGS = -Wall -Wextra -ffreestanding -fno-stack-protector -fno-stack-check -fno-lto -fno-PIC -ffunction-sections -fdata-sections
OBJS_PACK = ../target/kernel.obj

default: $(OBJS_PACK)
	ld -T lds.ld $(OBJS_PACK) -o ../../vm/kernel.elf

../target/%.obj : %.c Makefile
	$(CC) -m64 $(CC_FLAGS) -c $*.c -o ../target/$*.obj
../target/%.obj : %.cpp Makefile
	$(CPP) -m64 $(CC_FLAGS) -c $*.cpp -o ../target/$*.obj
../target/%.obj : %.asm Makefile
	nasm -f elf $*.asm -o ../target/$*.obj
	
clean:
	rm ../target/*
	
	