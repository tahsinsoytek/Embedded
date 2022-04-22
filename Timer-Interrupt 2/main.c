#include <main.h>

#INT_RTCC
void  RTCC_isr(void) 
{

}

#INT_TIMER1
void  TIMER1_isr(void) 
{

}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //51,2 us overflow
   
   
   setup_timer_1(T1_INTERNAL|T1_DIV_BY_8);
   
   int sayac;
   
   enable_interrupts(INT_RTCC);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(GLOBAL);
   


   while(TRUE)
   {
      if(input(pin_b2))
      {
         sayac=get_timer1();
         
         output_c(sayac);

         while(input(pin_b2));
      }
      if(input(pin_b3))
      {
      
         set_timer1(125);
         
         while(input(pin_b3));
      }
   }

}
