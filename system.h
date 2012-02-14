#ifndef __SYSTEM_H
#define __SYSTEM_H

extern unsigned char *memcpy(void *dest,void *src, int count);
extern unsigned char *memset(unsigned char *dest, unsigned char val, int count);
extern unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
extern int strlen( char *str);
extern unsigned char inportb (unsigned short _port);
extern void outportb (unsigned short _port, unsigned char _data);

extern void cls();
extern void putch(unsigned char c);
extern void puts(char *str);
extern void settextcolor(unsigned char forecolor, unsigned char backcolor);
extern void init_video();

struct regs
{
    unsigned int gs, fs, es, ds;      /* pushed the segs last */
    unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    unsigned int int_no, err_code;    /* our 'push byte #' and ecodes do this */
    unsigned int eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

//gdt
extern void gdt_install();

//idt
extern void idt_install();
extern void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags);

//isr
extern void isr_install();

//irq
extern void irq_install();
extern void irq_handler(struct regs *r);
extern void irq_install_handler(int irq, void (*handler)(struct regs *r));
void irq_uninstall_handler(int irq);

//pit
extern void delay(int ticks);
extern void timer_handler(struct regs *r);
extern void timer_install();

//keyboard
extern void kb_install();

#endif
		
