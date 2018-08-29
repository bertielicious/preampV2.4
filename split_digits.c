/*
 * File:   split_digits.c
 * Author: philip
 *
 * Created on 08 February 2018, 14:51
 */


#include <xc.h>
#include "config.h"
void split_digits(void) 
{
    if (count >=0 && count <=95)
    {
        tens = (95 - count)/10;
        units = (95 - count)%10;
    }
    else
    {
        
        tens = (count - 95)/10;
        units = (count - 95)%10;
   }
}
