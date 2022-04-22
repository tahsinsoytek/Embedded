#include <main.h>

int16 counter_period;
int sec,digit1,digit10;

#INT_RTCC
void  RTCC_isr(void) 
{
   set_timer0(6);
   counter_period++;
   if(counter_period==2500)
   {
      sec++;
      digit1=sec%10;
      digit10=sec/10;
      output_c(digit10<<4 | digit1);
      counter_period=0;
   }
}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8|RTCC_8_bit);      //409 us overflow
   
   set_tris_c(0x00);
   output_c(0);
   
   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
   
   set_timer0(6);
   
   while(TRUE)
   {
      //TODO: User Code
   }

}
