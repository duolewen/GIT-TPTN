#include "tca9555.h"
#include "SimuIIC.h"

T_SIMU_I2C_DESC TCA9555 = {0};

// 静态变量：缓存当前输出值（用于单个引脚操作时保持其他引脚状态）
static uint8_t port0_output_cache = 0;
static uint8_t port1_output_cache = 0;

static uint8_t TCA9555_ReadReg(uint8_t reg)
{
    uint8_t data;
    
    // 1. 发送设备地址 + 写方向
    IIC_Start(&TCA9555);
    IIC_Send_Byte(&TCA9555,TCA9555_ADDR << 1);  // 7位地址左移1位 + 0（写）
    IIC_Send_Byte(&TCA9555,reg);                 // 发送寄存器地址
    
    // 2. 重新发起起始条件，切换为读
    IIC_Start(&TCA9555);
    IIC_Send_Byte(&TCA9555,(TCA9555_ADDR << 1) | 0x01);  // 设备地址 + 读方向
    data = IIC_Read_Byte(&TCA9555,0);                     // 读取数据，发送 NACK
    IIC_Stop(&TCA9555);
    
    return data;
}

static void TCA9555_WriteReg(uint8_t reg, uint8_t data)
{
    IIC_Start(&TCA9555);
    IIC_Send_Byte(&TCA9555,TCA9555_ADDR << 1);  // 设备地址 + 写
    IIC_Send_Byte(&TCA9555,reg);                 // 寄存器地址
    IIC_Send_Byte(&TCA9555,data);                // 写入数据
    IIC_Stop(&TCA9555);
}


// ============================================
// 公开 API 实现
// ============================================

uint8_t TCA9555_Init(void)
{
    // 默认配置：Port0 全部为输出，Port1 全部为输入
    TCA9555_SetPort0Direction(0x00);   // Port0: 全部输出
    TCA9555_SetPort1Direction(0xFF);   // Port1: 全部输入
    
    // 初始化输出缓存
    port0_output_cache = 0x00;
    port1_output_cache = 0x00;
    
    // 默认 Port0 全部输出低电平
    TCA9555_WritePort0(0x00);
	
	  return 1;
}

void TCA9555_WritePort0(uint8_t value)
{
    port0_output_cache = value;
    TCA9555_WriteReg(TCA9555_OUTPUT_PORT_0, value);
}

void TCA9555_WritePort1(uint8_t value)
{
    port1_output_cache = value;
    TCA9555_WriteReg(TCA9555_OUTPUT_PORT_1, value);
}

uint8_t TCA9555_ReadPort0(void)
{
    return TCA9555_ReadReg(TCA9555_INPUT_PORT_0);
}

uint8_t TCA9555_ReadPort1(void)
{
    return TCA9555_ReadReg(TCA9555_INPUT_PORT_1);
}

void TCA9555_SetPort0Direction(uint8_t dir_mask)
{
    // dir_mask: 某位为 0 表示输出，为 1 表示输入
    TCA9555_WriteReg(TCA9555_CONFIG_PORT_0, dir_mask);
}

void TCA9555_SetPort1Direction(uint8_t dir_mask)
{
    TCA9555_WriteReg(TCA9555_CONFIG_PORT_1, dir_mask);
}

void TCA9555_WritePin0(uint8_t pin, uint8_t level)
{
    if (pin > 7) return;
    
    if (level) {
        port0_output_cache |= (1 << pin);
    } else {
        port0_output_cache &= ~(1 << pin);
    }
    TCA9555_WriteReg(TCA9555_OUTPUT_PORT_0, port0_output_cache);
}

void TCA9555_WritePin1(uint8_t pin, uint8_t level)
{
    if (pin > 7) return;
    
    if (level) {
        port1_output_cache |= (1 << pin);
    } else {
        port1_output_cache &= ~(1 << pin);
    }
    TCA9555_WriteReg(TCA9555_OUTPUT_PORT_1, port1_output_cache);
}

uint8_t TCA9555_ReadPin0(uint8_t pin)
{
    if (pin > 7) return 0;
    uint8_t val = TCA9555_ReadReg(TCA9555_INPUT_PORT_0);
    return (val >> pin) & 0x01;
}

uint8_t TCA9555_ReadPin1(uint8_t pin)
{
    if (pin > 7) return 0;
    uint8_t val = TCA9555_ReadReg(TCA9555_INPUT_PORT_1);
    return (val >> pin) & 0x01;
}