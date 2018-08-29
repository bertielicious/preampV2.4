/*
 * File:   bar_graph.c
 * Author: philip
 *
 * Created on 09 February 2018, 20:00
 */


#include <xc.h>
#include "bar_graph.h"
#include "config.h"
#include "set_columns.h"
#include "set_page.h"
#include "write_data.h"
#include "write_command.h"
void bar_graph(void) 
{
    
    unsigned int col = 0;
    write_command(0xb6);            // write upper bar graph line b6
    write_command(0x21);            // set vertical address mode
    write_command(0x01);
    write_command(0x7e);
    if(CW_Flag == HI)                // if clockwise rotation detected
    {
        for(col = 0; col <= count; col++)   
        {
            write_data(0xff);      // write a bar graph representation of the value of count 
        }     
    }
    else if(CW_Flag == LO)                           // if anti-clockwise rotation detected
        {
            for(col = 0; col <= count ; col++)   // write a bar graph representation of count-1
            {   
                write_data(0xff);
            }
            write_data(0x01);
        }
    
    write_command(0xb7);            // write lower bar graph line b7
    write_command(0x21);            // set vertical address mode
    write_command(0x01);
    write_command(0x7e);
  
    if(CW_Flag == HI)  
    {
        for(col = 0; col<= count; col++)   
        {
            write_data(0xff);       
        }     
    }
    //else
    else if(CW_Flag == LO)  
        {
            for(col = 0; col <= count ; col++)
            {   
                write_data(0xff);
            }
            write_data(0x80);
        }
}
