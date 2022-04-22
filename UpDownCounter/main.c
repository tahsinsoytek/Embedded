#include <main.h>

void main()
{
   int i=0;
   set_tris_a(0x03);
   set_tris_b(0x00);
   output_b(i);

   while(TRUE)
   {
      if(input(pin_a0))
      {
         i++;
         if(i==10)
         i=0;
         output_b(i);
         delay_ms(200);
         while(input(pin_a0));
      }
      if(input(pin_a1))
      {
         i--;
         if(i==-1)
         i=9;
         output_b(i);
         delay_ms(200);
         while(input(pin_a1));
      }
   }

}
