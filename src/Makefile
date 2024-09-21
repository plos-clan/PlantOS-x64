default:
	make -r -C kernel
	qemu-system-x86_64 -pflash ../vm/EFI/OVMF.fd -net none -drive index=0,file=fat:rw:../vm,format=vvfat

clean:
	make -r -C kernel clean