/*
 * File:   splash_screen.c
 * Author: philip
 *
 * Created on 22 February 2018, 17:58
 */

#include "splash_screen.h"
#include <xc.h>
#include "config.h"
#include "write_character.h"

void splash_screen(void) 
{
    unsigned char col;
    unsigned char inc = 0x07;
    write_character(&m[0],0x00+inc,0xb0);  //do this
    write_character(&i[0],0x0f+inc, 0xb0); 
    write_character(&n[0],0x1f+inc, 0xb0);
    write_character(&i[0],0x2f+inc,0xb0);  
    write_character(&p[0],0x3f+inc,0xb0);
    write_character(&r[0],0x4f+inc,0xb0);
    write_character(&e[0],0x5f+inc,0xb0);
    write_character(&l[0],0x00,0xb3);//l
    write_character(&i[0],0x0f,0xb3);//i
    write_character(&t[0],0x1f,0xb3);//t
    write_character(&t[0],0x2f,0xb3);//t
    write_character(&l[0],0x3f,0xb3);//l
    write_character(&e[0],0x4f,0xb3);//e
    write_character(&h[0],0x17,0xb5);//h
    write_character(&e[0],0x27,0xb5);//e
    write_character(&a[0],0x37,0xb5);//a
    write_character(&d[0],0x47,0xb5);//d
    write_character(&V[0],0x57,0xb5);//V
    write_character(&dos[0],0x67,0xb5);//2
}
