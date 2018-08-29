/*
 * File:   fsm.c
 * Author: Phil
 * Debouncing of rotary encoder outputs via a state machine
 * Created on 19 May 2018, 20:44
 */


#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#include "config.h"
#include "fsm.h"

bool fsm(unsigned char *state) 
{ 
    switch (*state)
    {
        case START:
            
            if (CLK == HI && DT == HI)
            {
                kurrent_state = START;
                CW_Flag = LO;
            }
            else if (CLK == LO && DT == HI)
            {
                kurrent_state = QCW;
                CW_Flag = LO;
            }
            if (CLK == HI && DT == 0)
            {
                kurrent_state = QACW;
                CW_Flag = LO;
            }
            else if (CLK == LO && DT == LO)
            {
                kurrent_state = START;
                CW_Flag = LO;
            }
            break;
            
            case QCW:
            
            if (CLK == HI && DT == HI)
            {
                kurrent_state = START;
                CW_Flag = LO;
            }
            else if (CLK == LO && DT == LO)
            {
                kurrent_state = HCW;
                CW_Flag = LO;
            }
            break;
            
            case HCW:
            
            if (CLK == LO && DT == HI)
            {
                kurrent_state = QCW;
                CW_Flag = LO;
            }
            else if (CLK == HI && DT == LO)
            {
                kurrent_state = TQCW;
                CW_Flag = LO;
            }
            break;
            
            case TQCW:
            
            if (CLK == LO && DT == LO)
            {
                kurrent_state = HCW;
                CW_Flag = LO;
            }
            else if (CLK == HI && DT == HI)
            {
                kurrent_state = FCW;                
                CW_Flag = HI;
            }
            break;
            
            case FCW:
            
            if (CLK == HI && DT == HI)
            {
                kurrent_state = START;
                CW_Flag = LO;
            }
            else if (CLK == HI && DT == LO)
            {
                kurrent_state = TQCW;
                CW_Flag = LO;
            }
            break;
            
            /*********************ANTI CLOCK WISE FSM*******************/
            
            case QACW:
            
            if (CLK == LO && DT == LO)
            {
                kurrent_state = HACW;
                ACW_Flag = LO;
            }
            else if (CLK == HI && DT == LO)
            {
                kurrent_state = QACW;
                ACW_Flag = LO;
            }
            break;
            
            case HACW:
            
            if (CLK == LO && DT == HI)
            {
                kurrent_state = TQACW;
                ACW_Flag = LO;
            }
            else if (CLK == LO && DT == LO)
            {
                kurrent_state = HACW;
                ACW_Flag = LO;
            }
            break;
            
            case TQACW:
            
            if (CLK == HI && DT == HI)
            {
                kurrent_state = FACW;
                ACW_Flag = HI;
                
            }
            else if (CLK == LO && DT == HI)
            {
                kurrent_state = TQACW;
                ACW_Flag = LO;
            }
            break;
            
            case FACW:
            
            if (CLK == HI && DT == HI)
            {
                kurrent_state = START;
                ACW_Flag = LO;
            }
            else if (CLK == LO && DT == HI)
            {
                kurrent_state = TQACW;
                ACW_Flag = LO;
            }
            break;
            
            default:
                ACW_Flag = LO;
            break;
    }
   
    return 0;
}
