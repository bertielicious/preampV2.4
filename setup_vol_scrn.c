/*
 * File:   setup_vol_scrn.c
 * Author: philip
 *
 * Created on 18 February 2018, 18:45
 */


#include <xc.h>
#include "config.h"
#include "setup_vol_scrn.h"
#include "write_character.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"


void setup_vol_scrn(void) 
{
        unsigned char col = 0;
        set_page(0x20,0x00,0xb6);   // draw top line of box enclosing bar graph
        set_columns(0x21, 0x00,0x7f);       // columns 0 to 127
        for(col=0;col<=126;col++)   
        {
            write_data(0x01);       //msb = 1, rest are 0's
        }
        
        set_page(0x20,0x00,0xb7);   // draw bottom line of box enclosing bar graph
        set_columns(0x21, 0x00,0x7f);
        for(col=0;col<=126;col++)   
        {
            write_data(0x80);       // draw bottom line of page b7 to create a container for bar graph
        }
        
        set_page(0x20,0x00,0xb6);   // draw LHS vertical end on row b6
        set_columns(0x21, 0x00,0x01);
        write_data(0xff); 
        
        set_page(0x20,0x00,0xb7);   // draw LHS vertical end on row b7
        set_columns(0x21, 0x00,0x01);
        write_data(0xff);           
    
        set_page(0x20,0x00,0xb6);   // 
        set_columns(0x21, 0x7e,0x7f);
        write_data(0xff);           // draw RHS vertical end on row b6
        
        set_page(0x20,0x00,0xb7);
        set_columns(0x21, 0x7e,0x7f);
        write_data(0xff);           // draw RHS vertical end on row b7
        
        write_character(&d[0],0x3f,0xb3);   // write dB
        write_character(&B[0],0x4f,0xb3);
       // return;
}
