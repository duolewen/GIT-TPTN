#ifndef GLOBALDEF_H
#define GLOBALDEF_H

#include "stm32f4xx_hal.h"
#include "PinDef.h"
#include "stdbool.h"

typedef signed char         S8;
typedef signed short int    S16;
typedef signed int          S32;

typedef uint8_t INT8U;
typedef int8_t  INT8S;

typedef uint16_t INT16U;
typedef int16_t  INT16S;

typedef uint32_t INT32U;
typedef int32_t  INT32S;

typedef float  FLOAT;
typedef double DOUBLE;

typedef bool     BOOL;
typedef uint8_t  U8;
typedef uint16_t U16;
typedef uint32_t U32;

typedef int16_t                                 int16;
typedef int32_t                                 int32;
typedef uint8_t                                 Uint8;
typedef uint16_t                                Uint16;
typedef uint32_t                                Uint32;
typedef float                                   float32;
typedef long double                             float64;
typedef uint16_t                                BOOLEAN;

#if 0

#define SQRT2              1.41421356f

#define CONST_FREQ_60HZ    6000
#define CONST_FREQ_50HZ    5000
#define CONST_2PI          6.2831853f
#define CONST_PI           3.1415926f
#define CONST_PI_DIV2      CONST_PI/2.0
#define CONST_3PI_DIV2     CONST_PI*1.5
#define CONST_PI_DIV4      CONST_PI/4.0

#define E_USE_TESTMODE           0 //测试模式开关
#define E_WATCHDOG_ENABLE        1 //看门狗

#define DSPCOMM_BOUND 19200       //Pcs通信波特率

#define  SILMODE_POWER 150       //静音模式功率设定

#define LENGTH_DSPCOMM_TX  150
#define LENGTH_DSPCOMM_RX  150

#define LENGTH_MODBUS_TX  3000
#define LENGTH_MODBUS_RX  1500

#define LENGTH_BLE_TX    1000
#define LENGTH_BLE_RX    1500

#define DSPCOMM_RXDMA    DMA0
#define DSPCOMM_RXDMA_CH DMA_CH5

#define DSPCOMM_TXDMA    DMA0
#define DSPCOMM_TXDMA_CH DMA_CH6

#define USART2_PRE_PRI    8U
#define USART2_SUB_PRI    0U
 
#define USART1_PRE_PRI    9U
#define USART1_SUB_PRI    0U

#define USART0_PRE_PRI    4U
#define USART0_SUB_PRI    0U

#define E_SERIAL_485  USART0
#define E_SERIAL_AP   USART1

#define D_SIMU_BLE_MODBUS_FB 0x00000001 //Ble通信模拟套接字

enum //升级类型
{
    E_UPDATE_TYPE_NULL        = 0X00,  //保留
    E_UPDATE_TYPE_MASTER_COMM = 0X01, //主机COM
    E_UPDATE_TYPE_MASTER_DSP  = 0X02, //主机DSP
    E_UPDATE_TYPE_MASTER_IOT  = 0x07, //主机IOT 
};

enum
{
    E_APP_UPDAYE_SRC_NULL = 0,
    E_APP_UPDAYE_SRC_BLE,//来自蓝牙升级
    E_APP_UPDAYE_SRC_XMODEM//来自Xmodem升级
};

#pragma pack(1)
typedef union
{
    uint32_t Word;
    struct T_COMM_FAULT_BIT
    {
        uint32_t Fault_Dsp_Comm        :1;  //Dsp通信故障
        uint32_t Fault_AFE_Comm        :1;  //AFE通信故障
        uint32_t Fault_Pcs_Monitor     :1;  //Dsp监控故障
        uint32_t Fault_Eep_Comm        :1;  //Eeprom通信故障
        uint32_t Fault_Eep_CrcErr      :1;  //EepromCrc校验失败故障
        uint32_t Fault_Flash_CrcErr    :1;  //Flash数据校验失败故障
        uint32_t Res0_6                :1;  //预留
        uint32_t Res0_7                :1;  //预留
        
        uint32_t res2                  :8;  //预留
        uint32_t res3                  :8;  //预留
        uint32_t res4                  :8;  //预留
    }Bit;
}U_COMM_FAULT;
#pragma pack()

#pragma pack(1)
typedef union
{
    uint32_t Word;
    struct T_COMM_ALARM_BIT
    {
        uint32_t Alarm_Lcd_Comm          :1;     //显示屏通信告警
        uint32_t Alarm_BT_Comm           :1;     //BT通信告警
        uint32_t Alarm_UsbA_Comm         :1;     //USBA通信告警
        uint32_t Alarm_Typec_Comm       :1;     //TypeC通信告警
        uint32_t Alarm_Usb_Source_Err    :1;     //USB输入电压异常
        uint32_t res1_Bit5               :1;     //预留
        uint32_t res1_Bit6               :1;     //预留
        uint32_t res1_Bit7               :1;     //保留
        
        uint32_t res2               :8;  //预留
        uint32_t res3               :8;  //预留
        uint32_t res4               :8;  //预留
    }Bit;
}U_COMM_ALARM;
#pragma pack()

extern U_COMM_FAULT uCommFault;
extern U_COMM_ALARM uCommAlarm;

const uint8_t *GetSoftVer(void);
const uint8_t *GetHardtVer(void);
const uint8_t *GetDebugSoftVer(void);
#endif
#endif

