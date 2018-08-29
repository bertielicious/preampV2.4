/*
 * File:   main.c
 * Author: Phil
 *
 * Created on 05 August 2018, 17:41
 */


#include <xc.h>
#include <stdio.h>
#include "main.h"
#include "config.h"
#include "init_ports.h"
#include "init_TMR0.h"
#include "init_TMR1.h"
#include "init_TMR2.h"
#include "init_adc.h"
#include "config_osc.h"
#include "set_usart.h"
#include "config_oled.h"
#include "clear_oled.h"
#include "splash_screen.h"
#include "setup_vol_scrn.h"
#include "putch.h"
#include "resetRc5.h"
#include "initIOCir.h"
#include "stateMachine.h"
#include "bar_graph.h"
#include "split_digits.h"
#include "update_PGA2311.h"
#include "get_digit.h"
#include "write_character.h"
#include "fsm.h"
#include "state_of_input.h"
void main(void) 
{
    init_ports();
    config_osc();
    clear_oled();
    init_TMR0();
    init_TMR1();
    init_TMR2();
    init_adc();
    initIOCir();
    set_usart();
    config_oled();      // oled now talking to PIC, but with garbage pixels illuminated on oled
    splash_screen();
    __delay_ms(2000);
    clear_oled();
    setup_vol_scrn();
    printf("preampV2 14/08/2018\n");
    write_character(&minus[0], 0x0f,0xb3);
    split_digits();
    get_digit(tens, 0x1f);
    get_digit(units, 0x2f);
    write_character(&s[0],0x0f,0xb0);  //write stream on oled
    write_character(&t[0],0x1f, 0xb0); 
    write_character(&r[0],0x2f, 0xb0);
    write_character(&e[0],0x3f,0xb0);  
    write_character(&a[0],0x4f,0xb0);
    write_character(&m[0],0x5f,0xb0);  
    
    while(1)                                    // IR sensor active low code
    {   
            while(IR == HI && has_run !=1);    // wait for first button press on RC5 handset
            while(IR == LO && has_run !=1);
            if(IR == HI && has_run !=1)
            {
                bits--;
                has_run = 1;                // this block only runs once until system is reset
                INTCONbits.IOCIE = 0;       // master switch disable for interrupt on change   
                RC5_code = RC5_code | 1<<bits; // generates initial RC5 code S1 of 0x2000
                bits--;
                RC5_code = RC5_code | 1<<bits; // generates initial RC5 code S2 of 0x1000
                bits--;                        // keep track of how many of the 14 RC5 bits have been consumed
                state = MID1;
                TMR1H = 0x00;
                TMR1L = 0x00;
                INTCONbits.IOCIE = 1;       // master switch enable for interrupt on change     
                IOCBPbits.IOCBP5 = 0;       // disable interrupt on rising edge
                IOCBNbits.IOCBN5 = 1;       // enable interrupt on falling edge
            }   
            
            else if(IOCIF !=1 && (bits + 1) == 0)  // if no interrupt and all 14 RC5 bits have been consumed by state machine
            {
                printf("RC5 code = %x\n", RC5_code);
            
        ADCON0bits.GO_nDONE = 1;    // start ADC conversion
        if(adc_result > 185 && adc_result < 240)
        {
            current_state = STREAM;
        }
        else if(adc_result >150 && adc_result < 185)
        {   
            current_state = CD;
        }
        else if(adc_result >110 && adc_result < 150)
        {   
            current_state = TUNER;
        }
        else if(adc_result >70 && adc_result < 110)
        {   
            current_state = PHONO;
        }
        else if(adc_result >20 && adc_result < 70)
        {   
            current_state = DAC;
        }
                if(RC5_code == 0x3c10 || RC5_code == 0x3410)
                {
                    if (count >=0 && count <123)
                    
                    {
                        count++;
                    }
                    bar_graph();
                    update_PGA2311(count * 2);
                    split_digits();
                    
                        if(count >=0 && count <95)
                    {
                        write_character(&minus[0], 0x0f,0xb3);
                    }
                    
                    else
                    {
                        write_character(&space[0],0x0f,0xb3);
                    }   
                        get_digit(tens, 0x1f);
                        get_digit(units, 0x2f);
                    }
                
                else if (RC5_code == 0x3c11 || RC5_code == 0x3411)
                {
                    if(count > 0 && count <= 124)
                    {
                        count--;
                    }
                    bar_graph();
                    update_PGA2311(count * 2);
                    split_digits();
                    
                    if(count >=0 && count <95)
                    {
                        write_character(&minus[0], 0x0f,0xb3);
                    }
                    else
                    {
                        write_character(&space[0],0x0f,0xb3);
                    }   
                        get_digit(tens, 0x1f);
                        get_digit(units, 0x2f);
                    }
                
            
                resetRc5();
                INTCONbits.IOCIE = 1; 
                T1CONbits.TMR1ON = 0;
            }        
    }
}
    
    
        
    

