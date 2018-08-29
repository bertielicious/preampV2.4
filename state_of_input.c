#include "config.h"
#include <xc.h>
#include "write_character.h"
#include "clear_oled.h"

void state_of_input(int *c_state)
{
    switch (*c_state)
    {
        case STREAM:
       
              *c_state = STREAM;
              write_character(&s[0],0x0f,0xb0);  //write stream on oled
              write_character(&t[0],0x1f, 0xb0); 
              write_character(&r[0],0x2f, 0xb0);
              write_character(&e[0],0x3f,0xb0);  
              write_character(&a[0],0x4f,0xb0);
              write_character(&m[0],0x5f,0xb0);  
              break;
              
        case CD:
           
              *c_state = CD;
              write_character(&space[0],0x0f,0xb0);  //write cd on oled
              write_character(&space[0],0x1f,0xb0); 
              write_character(&c[0],0x2f, 0xb0);
              write_character(&d[0],0x3f,0xb0);  
              write_character(&space[0],0x4f,0xb0);
              write_character(&space[0],0x5f,0xb0);             
              break;
            
        case TUNER:
            *c_state = TUNER;
             write_character(&space[0],0x0f,0xb0);  //write tuner on oled
             write_character(&t[0],0x1f,0xb0); 
             write_character(&u[0],0x2f, 0xb0);
             write_character(&n[0],0x3f,0xb0);  
             write_character(&e[0],0x4f,0xb0);
             write_character(&r[0],0x5f,0xb0);
             break;
             
        case PHONO:
            *c_state = PHONO;
             write_character(&space[0],0x0f,0xb0);  //write phono on oled
             write_character(&p[0],0x1f, 0xb0); 
             write_character(&h[0],0x2f, 0xb0);
             write_character(&o[0],0x3f,0xb0);  
             write_character(&n[0],0x4f,0xb0);
             write_character(&o[0],0x5f,0xb0); 
             break;
             
        case DAC:
            *c_state = DAC;
             write_character(&space[0],0x0f,0xb0);  //write dac on oled
             write_character(&d[0],0x1f, 0xb0); 
             write_character(&a[0],0x2f, 0xb0);
             write_character(&c[0],0x3f,0xb0);  
             write_character(&space[0],0x4f,0xb0);
             write_character(&space[0],0x5f,0xb0); 
             break;
             
     /*   case MUTE:
            *c_state = MUTE;
            write_character(&space[0],0x0f,0xb3);
            write_character(&m[0],0x1f,0xb3);  //do this
            write_character(&u[0],0x2f, 0xb3); 
            write_character(&t[0],0x3f, 0xb3);
            write_character(&e[0],0x4f,0xb3);
            count = 0;
            break;*/
    } 
}
