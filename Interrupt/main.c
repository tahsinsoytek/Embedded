#include <main.h>

int count_period;

#INT_RTCC

void  timer0_interrupt(void) 
{
   count_period++;
   if(count_period==76)
   {
       output_toggle(pin_a0);
       count_period=0;
   }
}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256|RTCC_8_bit);      //51,2 us overflow


   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);

   while(TRUE)
   {
      //TODO: User Code
   }

}
