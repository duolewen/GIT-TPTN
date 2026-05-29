#include "AppDgtPt1000.h"
#include "driver_max31865_basic.h"

uint8_t wire = 0;

uint8_t sbAppDgtPt1000_Init(void)
{
	   return 1;
}

void sAppDgtPt1000_Poll(void)
{
//    uint8_t res;
//    uint32_t i;
//    float temp;
//        
//    /* basic init */
//    res = max31865_basic_init(wire, chip_type, r);
//    if (res != 0)
//    {
//        return 1;
//    }
//        
//        /* loop */
//        for (i = 0; i < times; i++)
//        {
//            /* read data */
//            res = max31865_basic_read((float *)&temp);
//            if (res != 0)
//            {
//                (void)max31865_basic_deinit();
//                
//                return 1;
//            }
//            
//            /* output */
//            max31865_interface_debug_print("max31865: %d/%d.\n", i + 1, times);
//            max31865_interface_debug_print("max31865: temperature is %0.4fC.\n", temp);
//            
//            /* delay 1000ms */
//            max31865_interface_delay_ms(1000);
//        }
//        
//        /* basic deinit */
//        (void)max31865_basic_deinit();
//        
//        return 0;
}