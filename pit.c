#include "system.h"



void timer_phase(int hertz)
{
	int div = 1193180 / hertz;
	outportb(0x43,0x36); //square wave, lsb first and then msb
	outportb(0x40, div & 0xFF);  
    outportb(0x40, div >> 8);    
}
unsigned char ab = 48;
unsigned char ab1 = 48;
unsigned long timer_ticks = 0;
unsigned long seconds=0;
void timer_handler(struct regs *r)
{
    timer_ticks++;
    if (timer_ticks % 18 == 0)
    {
			seconds++;
			ab++;
			timer_ticks = 0;
    }
}
void timer_install()
{
	//timer_phase(500);
    irq_install_handler(0, timer_handler);
}
void delay(int ticks)
{
	ab = 0;
    
    while( ab != ticks )
    {
		putch(ab);		
	}
}
