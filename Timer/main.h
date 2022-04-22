#include <16F877A.h>
#device ADC=16

#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O

#use delay(crystal=20000000)
#use timer(timer=0,tick=100us,bits=32,NOISR)

#define TICK_TYPE unsigned int32
#define TICKS_PER_SECOND 10000
