#include "AppEeprom.h"
#include "driver_at24cxx.h"
#include "driver_at24cxx_basic.h"

at24cxx_t         at24cxx_chip_type      = AT24C01;
at24cxx_address_t at24cxx_chip_addr      = AT24CXX_ADDRESS_A000;

uint8_t sbAppEeprom_Init(void)
{
	
}

void  sAppEeprom_Poll(void)
{
//     uint8_t res;
//	
//     /* basic init */
//     res = at24cxx_basic_init(chip_type, addr);
//     if (res != 0)
//     {
//         return ;
//     }
//     /* read data */
//     //res = at24cxx_basic_read(0x11, (uint8_t *)&data, 1);
//     if (res != 0)
//     {
//         (void)at24cxx_basic_deinit();
//         return ;
//     }
//     else
//     {
//         at24cxx_interface_debug_print("at24cxx: read 0x%04x is 0x%02X.\n", reg, data);
//     }

//     /* deinit */
//     (void)at24cxx_basic_deinit();
}

