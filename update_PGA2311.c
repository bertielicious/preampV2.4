#include "config.h"
#include "send_spi_byte.h"
#include "update_PGA2311.h"
void update_PGA2311(unsigned char volume)
{
    CS_PGA2311 = 0;
    send_spi_byte(volume);           //update vol on RH channel
   // send_spi_byte(volume);           //update vol on LH channel
    CS_PGA2311 = 1;
}
