#include "ApptempHmi.h"
#include "driver_sht31_basic.h"

sht31_address_t addr = SHT31_ADDRESS_1;
		
float temperature;
float humidity;
			
uint8_t sbAppTemoHmi_Init(void)
{
    return 1;
}

void sAppTemoHmi_Poll(void)//1s 间隔进入
{
    static uint8_t ubstep = 0;
	  switch(ubstep)
		{
			case 0:
			{
				 uint8_t res = sht31_basic_init(addr);
         if (res != 0)
         {
             ;//报故障
					   ubstep = 0xFF;
         } 
         else
				 {           
             ubstep += 1;
				 }					 
			}
			    break;
			case 1:
			{
          uint8_t res = sht31_basic_read((float *)&temperature, (float *)&humidity);
          if (res != 0)
          {
              sht31_basic_deinit();
              ;//报故障
              ubstep = 0xFF;
          }
			}
			    break;
			case 0xFF:
			{
				  if(0)//清除故障
					{
						   ubstep = 0;
					}
			}
			     break;
			default:
				  break;
		}
}