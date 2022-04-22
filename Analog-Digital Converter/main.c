#include <main.h>
#include "lcd.c"

#INT_AD
void  AD_isr(void) 
{
   output_high(pin_c5);
   delay_ms(200);
   output_low(pin_c5);
}


int16 adcval1,adcval2;

void main()
{
   set_tris_c(0x00);
   set_tris_e(0x0f);


   setup_adc_ports(AN0_AN1_AN3);
   setup_adc(ADC_CLOCK_INTERNAL);

   enable_interrupts(INT_AD);
   enable_interrupts(GLOBAL);

   lcd_init();
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Tahsin Soytek");
   
   lcd_gotoxy(1,2);
   printf(lcd_putc,"ADC Sample");
   delay_ms(1500);
   
   while(TRUE)
   {
      set_adc_channel(0);
      delay_us(80);
      adcval1=read_adc();
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"AN0                               ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Value:%lu",adcval1);
      delay_ms(2000);
      
      
      set_adc_channel(1);
      delay_us(20);
      adcval2=read_adc();
      
      lcd_gotoxy(1,1);
      printf(lcd_putc,"AN1                               ");
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Value:%lu",adcval2);
      delay_ms(2000);
      
      
   }

}
