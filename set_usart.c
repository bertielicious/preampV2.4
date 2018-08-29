/*
 * File:   set_usart.c
 * Author: philip
 *
 * Created on 01 January 2018, 16:48
 */
#include "config.h"
#include <xc.h>
#include "set_usart.h"



void set_usart(void) 
{
    CM1CON0 = 0x00;         // comparators off
    CM2CON0 = 0x00;
    TRISBbits.TRISB7 = 0;   // TX pin is an output
    TXSTAbits.TXEN = 1;     // enable transmitter. TXIF is now set
    TXSTAbits.SYNC = 0;     // configure for asynchronous operation
    RCSTAbits.SPEN = 1;     // enables EUSART and configures TX pin as output
    SPBRG = 0x19;           // baud set to 2400
}
