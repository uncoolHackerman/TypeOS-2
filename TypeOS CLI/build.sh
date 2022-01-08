i386-elf-gcc -ffreestanding -m32 -g -c "kernel.c" -o "kernel.o"
nasm "kernel_start.asm" -f elf -o "kernel_start.o"
i386-elf-ld -o "kernel.bin" -Ttext 0x1000 "kernel_start.o" "kernel.o" --oformat binary
nasm -f bin -o boot.bin boot.asm
nasm -f bin -o zeroes.bin loadsofzeroes.asm
cat "boot.bin" "kernel.bin" "zeroes.bin" > OS.dsk
rm kernel.o
rm kernel.bin
rm kernel_start.o
rm boot.bin
rm zeroes.bin
qemu-system-i386 -fda OS.dsk