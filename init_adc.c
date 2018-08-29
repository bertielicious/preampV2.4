
#include <pic16f1459.h>

void init_adc(void)             // 10-bit resolution ADC to detect which push button has been pressed from 6 push buttons
{                               // stream   cd  tuner   phono   dac     mute
    /* ENABLE ADC ON RB4 (pin 13) [AN10]*/
    TRISBbits.TRISB4 = 1;   // input pin 13
    ANSELBbits.ANSB4 = 1;   // make RB4 (pin 13) AN10 an analogue input
    ADCON0bits.CHS = 0b00001010;// AN10 channel selected (RB4 pin 13) 
    ADCON1bits.ADCS2 = 1;   //set ADC conversion clock to 4us
    ADCON1bits.ADCS1 = 1;
    ADCON1bits.ADCS0 = 0;
    FVRCONbits.ADFVR1 = 0;  // set voltage reference to 1.024V
    FVRCONbits.ADFVR0 = 1;
    ADCON0bits.ADON = 1;    // turn the ADC on
    PIR1bits.ADIF = 0;      // clear the ADC interrupt flag to allow any future interrupts
    PIE1bits.ADIE = 1;      // enable the ADC interrupt
    INTCONbits.GIE = 1;     // enable global interrupts
    ADCON1bits.ADFM = 1;    // logical OR ADRESH<<6 with ADRESL to get 10-bit ACD result
    ADRESH = 0x00;
    ADRESL = 0x00;
}
