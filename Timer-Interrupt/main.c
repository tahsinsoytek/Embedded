#include <main.h>

#int_ext
void extint()
{
   output_toggle(pin_a0);
}


#int_rtcc
void timer0int()
{
   output_toggle(pin_a0);

}

#INT_TIMER1

void timer1_isr()
{
   output_toggle(pin_a0);
}


void main()
{
   setup_timer_0 (RTCC_DIV_256);
   
   setup_timer_1 (T1_EXTERNAL|T1_DIV_BY_1);
   
   enable_interrupts(GLOBAL);
   enable_interrupts(INT_rtcc);
   enable_interrupts(INT_ext);
   
   enable_interrupts(INT_TIMER1);
   
   set_tris_a(0x00);


   while(TRUE)
   {
      //TODO: User Code
   }

}
