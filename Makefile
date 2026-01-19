CC = i686-elf-gcc
LD = i686-elf-ld
AS = i686-elf-as

CCF = -ffreestanding -c -m32 -O2 -Iinc/

all:
	mkdir obj/
	$(CC) $(CCF) kernel/kernel.c -o obj/kernel.o
	$(CC) $(CCF) drivers/vga.c -o obj/vga.o
	$(CC) $(CCF) hal/cpu.c -o obj/cpu.o
	$(CC) $(CCF) klibs/klib.c -o obj/klib.o
	$(CC) $(CCF) klibs/kstd.c -o obj/kstd.o
	$(CC) $(CCF) klibs/kstr.c -o obj/kstr.o

	$(AS) -32 boot/boot.s -o obj/boot.o

	$(LD) -m elf_i386 -T linker.ld obj/boot.o obj/kernel.o obj/vga.o obj/cpu.o obj/kstd.o obj/klib.o obj/kstr.o -o nyoskrnl.bin

	mkdir -p isodir/boot/grub
	mkdir -p isodir/System/
	cp nyoskrnl.bin isodir/System
	cp boot/grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o nyos.iso isodir
	qemu-system-i386 -cdrom nyos.iso

clean:
	rm -rf obj/* *.bin *.iso