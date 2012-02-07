echo Started
nasm -f aout -o start.o start.asm
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin  -c -o main.o main.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin  -c -o screen.o screen.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin  -c -o gdt.o gdt.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin  -c -o idt.o idt.c
gcc -Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -nostdinc -fno-builtin  -c -o isr.o isr.c
ld -T link.ld -o kernel.bin start.o main.o screen.o gdt.o idt.o isr.o
echo Done!
