/*
 * File:   init_TMR1.c
 * Author: Phil
 *
 * Created on 09 June 2018, 19:32
 */


#include <xc.h>

void init_TMR1(void) 
{
    
    INTCONbits.GIE = 1;  // global interrupt enable set
    TMR1H = 0x00;       // initialise values held in TMR1 H and L
    TMR1L = 0x00;
    T1CONbits.TMR1CS1 = 0;       // fosc/4 is the clock source
    T1CONbits.TMR1CS0 = 0;
    PIE1bits.TMR1IE = 1;        // TMR1 interrupt enabled
    INTCONbits.PEIE = 1;        // enable peripheral interrupts
    T1CONbits.T1CKPS1 = 0;      // 11 = 1:8, 10 = 1:4, 01 = 1:2, 00 = 1:1
    T1CONbits.T1CKPS0 = 0;      // 1:1 pre-scaler
    T1CONbits.TMR1ON = 0;       // disable counting
    PIR1bits.TMR1IF = 0;
}
