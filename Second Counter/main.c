#include <main.h>


#INT_RTCC
void  timer0_interrupt(void) 
{


}

void main()
{
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8|RTCC_8_bit);      
   
   set_tris_c(0x00);
   int mnts[6]={0b00000000,0b00010000,0b00100000,0b00110000,0b01000000,0b01010000};
   enable_interrupts(INT_RTCC);
   enable_interrupts(GLOBAL);
   int x,y,z;
   int32 ctr=0;
   x=0;
   output_c(0x00);
   while(TRUE)
   {
      for(y=0;y<6;)
      {
         while(ctr!=825)
         {
            if(get_timer0()==255)
            {
               ctr++;
            }
         }
         x++;
         if(x==10)
         {
            output_c(x);
            x=0;
            y++;
         }
         ctr=0;
         z=mnts[y]|x;
         output_c(z);
         
       }
    }
      
   }


