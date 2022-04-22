#include <main.h>

#include <LCD.C>

int sec,min,hour,x;
int16 counter_period;

#INT_RTCC
void  RTCC_isr(void) 
{  
   set_timer0(6);
   counter_period++;
   if(counter_period==2200)
   {
      sec++;
      if(sec==60)
      {
         sec=0;
         min++;
         if(min==60)
         {
            hour++;
            if(hour==24)
            {
               hour=0;
            }
         }
      }
      lcd_gotoxy(1,1);
      printf(lcd_putc,"%02d:%02d:%02d",hour,min,sec);
      counter_period=0;
   }
}

void main()
{
   lcd_init();
   printf(lcd_putc,"%02d:%02d:%02d",hour,min,sec);
   while(input(pin_b0))
   {
       if(input(pin_a0))
      {
         hour++;
         lcd_gotoxy(1,1);
         printf(lcd_putc,"%02d:%02d:%02d",hour,min,sec);
         while(input(pin_a0));
      }
      else if(input(pin_a1))
      {
         min++;
         lcd_gotoxy(1,1);
         printf(lcd_putc,"%02d:%02d:%02d",hour,min,sec);
         while(input(pin_a1));
      }
   }
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8|RTCC_8_bit); //409 us overflow
   
   

   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
   set_timer0(6);
   
   
   
   while(TRUE)
   {
     
   }
}
