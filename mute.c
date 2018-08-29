/*
 * File:   mute.c
 * Author: philip
 *
 * Created on 26 February 2018, 18:52
 */


#include <xc.h>
#include "config.h"
#include "write_character.h"
#include "clear_oled.h"
#include "update_PGA2311.h"


void mute(void) 
{           
            write_character(&space[0],0x0f,0xb3);  //write "mute" to oled on first line of display
            write_character(&m[0],0x1f,0xb3);  
            write_character(&u[0],0x2f, 0xb3); 
            write_character(&t[0],0x3f, 0xb3);
            write_character(&e[0],0x4f,0xb3);  
             count = 0;
            update_PGA2311(count);  
}
