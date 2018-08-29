/*
 * File:   set_page.c
 * Author: philip
 *
 * Created on 04 February 2018, 19:44
 */


#include <xc.h>
//#include "definitions.h"
#include "config.h"
#include "write_command.h"
#include "set_page.h"

void set_page(unsigned char memory_mode, unsigned char page_mode, unsigned char page_addr)
{
    write_command(memory_mode);    // set memory addressing mode
    write_command(page_mode);    // enter page addressing mode
    write_command(page_addr);    // set page address to page 0
}
