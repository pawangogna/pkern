#include "system.h"


unsigned char *memcpy(void *dest,void *src, int count)
{
     unsigned char *temp = (unsigned char *)src;
     unsigned char *temp2 = (unsigned char *)dest;
     for(;count!=0;count--)
		*temp2++ = *temp++;
	return dest;
}

unsigned char *memset(unsigned char *dest, unsigned char val, int count)
{
    for(;count!=0;count--)
		*dest++ = val;
	return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
    for(;count!=0;count--)
		*dest++ = val;
	return dest;
}

int strlen(char *str)
{
     char *temp = str;
    int i=0;
    while(*temp++ != '\0')
		i++;
	return i;
}

unsigned char inportb (unsigned short _port)
{
    unsigned char rv;
    __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
    return rv;
}

void outportb (unsigned short _port, unsigned char _data)
{
    __asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}


int main()
{
	init_video();
	gdt_install();
	idt_install();
	isr_install();
	char *st = "Hello World";
	puts(st);
	int i=5;
	putch(i/5);
	puts("bye");
    for (;;);
    return 0;
}
