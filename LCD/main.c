#include <main.h>
#include <lcd.c>

void main()
{
   lcd_init();
   
   int counter=2;
   lcd_gotoxy(1,1);
   lcd_putc("Nissan");
   lcd_gotoxy(1,2);
   lcd_putc("Skyline GT-R R3");
  
   
   while(TRUE)
   {
      lcd_gotoxy(16,2);
      if(counter==5)
      {
         counter=2;
      }
      printf(lcd_putc,"%d",counter);
      counter++;
      delay_ms(1000);
   }

}
