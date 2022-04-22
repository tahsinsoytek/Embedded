#include <main.h>

TICK_TYPE GetTickDifference(TICK_TYPE currTick, TICK_TYPE prevTick)
{
   return(currTick-prevTick);
}

void timerint(void)
{
   output_toggle(pin_b1);
}

void main()
{
   TICK_TYPE CurrentTick,PreviousTick;


   //Example program using Tick Timer
   CurrentTick = PreviousTick = get_ticks();

   while(TRUE)
   {
      CurrentTick = get_ticks();

      if(GetTickDifference(CurrentTick, PreviousTick) >= (TICK_TYPE)TICKS_PER_SECOND)
      {
         timerint();
         PreviousTick = CurrentTick;
      }

      //TODO: User Code
   }

}
