/*init_TMR2.h
 date: 2nd August 2018
 frequency of interrupt 60Hz
 author: PG
 ****************/

#include <xc.h>
void init_TMR2(void)
{
   PIE1bits.TMR2IE = 1;    // TMR2 interrupts are enabled
   T2CONbits.TMR2ON = 1;    // TMR2 is on 
   T2CONbits.T2OUTPS0 = 1;
   T2CONbits.T2OUTPS1 = 1;
  // T2CONbits.T2OUTPS2 = 0;
  // T2CONbits.T2OUTPS3 = 0;  // postscaler is 1:4
   T2CONbits.T2OUTPS2 = 1;
   T2CONbits.T2OUTPS3 = 1;  // postscaler is 1:4
   T2CONbits.T2CKPS0 = 1;
   T2CONbits.T2CKPS1 = 1;   // prescaler is 1:16
   PR2 = 0xff;              // interrupt generated when TMR2 = PR2
   PIR1bits.TMR2IF = 0;
}
