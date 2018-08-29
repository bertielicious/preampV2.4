/*
 * File:   clear_oled.c
 * Author: philip
 *
 * Created on 04 February 2018, 21:02
 */


#include "config.h"
#include "clear_oled.h"
#include "set_page.h"
#include "set_columns.h"
#include "write_data.h"

void clear_oled(void)
{
    unsigned char rows, cols;
    for(rows = 0; rows < 8; rows++)
    {
        set_page(0x20, 0x00, 0xb0|rows);    // memory mode = 0x20, row_mode = 0x00, row_address = 0b00|row
        set_columns(0x21, 0x00, 0x7f);      // column mode = 0x21, lo_col_addr = 0, hi_col_addr = 127
        for(cols = 0; cols < 128; cols++)
        {
            write_data(0x00);               // write zeros to every 8 bit column on every row (8 pages)
        }                                   // of the oled screen i.e clear the oled screen
    }
}
