#include <main.h>

void main()
{
   int digits[10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
   set_tris_b(0x00);
   output_b(0);
   int i=0;
   int j=0;
   int x=1;
   while(j<6)
   {
      output_b(x);
      x*=2;
      delay_ms(100);
      j++;
   }
   output_b(digits[8]);
   delay_ms(450);
   output_b(0);
   delay_ms(450);
   output_b(digits[8]);
   delay_ms(450);
   output_b(0);
   delay_ms(450);
   while(TRUE)
   {
      if(i==10)
      i=0;
      else if(i==-1)
      i=9;
      if(input(pin_a0))
      {
         i++;
         while(input(pin_a0));
      }
      else if(input(pin_a1))
      {
         i--;
         while(input(pin_a1));
      }
      output_b(digits[i]);
   }

}
