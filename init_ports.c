#include <xc.h>
#include "config.h"
void init_ports(void) 
{
    //********TURN OFF ANALOGUE INPUTS**********************
    ANSELA = 0x00;                  // turn off all ADC inputs on PORTA
    ANSELB = 0x00;                  // turn off all ADC inputs on PORTB
    ANSELC = 0x00;                  // turn off all ADC inputs on PORTC
    
    /* SET DATA DIRECTION FOR GENERAL I/O PINS************************/
    TRISBbits.TRISB5 = 1;           // IR IOC input pin 12
    TRISCbits.TRISC0 = 0;           // diagnostic RED led pin 16
    TRISCbits.TRISC4 = 0;           // diagnostic GREEN led pin 6
    PORTCbits.RC0 = 0; 
    PORTCbits.RC4 = 0;
    /*SET DATA DIRECTION FOR SPI PINS***********************/
    TRISBbits.TRISB6 = 0;           // SCK (oled module) pin 11
    TRISCbits.TRISC7 = 0;           // SDO/ SDA pin 9
    TRISCbits.TRISC5 = 0;           // RES pin 5
    TRISCbits.TRISC6 = 0;           // DC pin 8
    TRISAbits.TRISA5 = 0;           // CS OLED pin 2
    TRISCbits.TRISC1 = 0;           // CS_PGA2311 pin 15
    PORTAbits.RA5 = 0;              // CS = 0
    PORTCbits.RC1 = 1;              // CS_PGA2311 = 1  set so that there is no conflict with CS OLED
    /*SET DATA DIRECTION FOR ROTARY ENCODER AND SWITCH*******/
    /*RA0, RA1 no TRIS needed as these pins only function as inputs*/
    /* RA0 = SWIP pin 19*/
    /* RA1 = CLK pin 18*/
    TRISAbits.TRISA4 = 1;           // DT pin 3
    
    /*SET DATA DIRECTION FOR UART*******************/
    PORTBbits.RB7 = 0;              // TX pin 10
    

//***********************CONFIG SPI SSPCONbits*****************************
 SSPCONbits.SSPM = 0001; // SPI Master mode, clock = Fosc/4 = 1MHz
 SSPCONbits.CKP = 0; // idle state for clock is low
 SSPCONbits.SSPEN = 1;  // enables serial port and configures SCK, SDO
                        //and SDI pins as serial port pins
 SSPCONbits.SSPOV = 0;  // no overflow allowed as we are in Master mode
 SSPCONbits.WCOL = 0;   // no collision
//***********************SSPSTATbits****************************************
 SSPSTATbits.CKE = 1;   // data transmitted on rising edge of clock
 SSPSTATbits.SMP = 1;   // input data sampled at end of output data
 CS = 1;                // Disable Chip Select
/**************************************************************************/
}