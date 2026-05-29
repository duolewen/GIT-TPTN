#ifndef _TCA9555_H
#define _TCA9555_H

#include "main.h"  // 根据你的实际工程修改，或直接包含 stm32f4xx_hal.h

// ============================================
// 寄存器地址定义（8个寄存器）
// ============================================
#define TCA9555_INPUT_PORT_0     0x00  // 读取 P00-P07 输入值
#define TCA9555_INPUT_PORT_1     0x01  // 读取 P10-P17 输入值
#define TCA9555_OUTPUT_PORT_0    0x02  // 设置 P00-P07 输出值
#define TCA9555_OUTPUT_PORT_1    0x03  // 设置 P10-P17 输出值
#define TCA9555_POLARITY_PORT_0  0x04  // 极性反转配置
#define TCA9555_POLARITY_PORT_1  0x05  // 极性反转配置
#define TCA9555_CONFIG_PORT_0    0x06  // 方向配置：0=输出，1=输入
#define TCA9555_CONFIG_PORT_1    0x07  // 方向配置：0=输出，1=输入

// ============================================
// TCA9555 设备地址
// ============================================
// 7位地址（A0/A1/A2 全部接地时 = 0x20）
#define TCA9555_ADDR_7BIT        0x20
// HAL库需要左移1位，实际传参用这个
#define TCA9555_ADDR             (TCA9555_ADDR_7BIT << 1)

// ============================================
// API 函数声明
// ============================================

/**
 * @brief 初始化 TCA9555
 * @param hi2c I2C句柄指针
 * @note  默认配置：Port0 全部为输出，Port1 全部为输入
 */
uint8_t TCA9555_Init(void);

/**
 * @brief 写入 Port0 输出值
 * @param value 8位输出值，bit0对应P00，bit7对应P07
 */
void TCA9555_WritePort0(uint8_t value);

/**
 * @brief 写入 Port1 输出值
 * @param value 8位输出值，bit0对应P10，bit7对应P17
 */
void TCA9555_WritePort1(uint8_t value);

/**
 * @brief 读取 Port0 输入值
 * @return 8位输入值，bit0对应P00，bit7对应P07
 */
uint8_t TCA9555_ReadPort0(void);

/**
 * @brief 读取 Port1 输入值
 * @return 8位输入值，bit0对应P10，bit7对应P17
 */
uint8_t TCA9555_ReadPort1(void);

/**
 * @brief 设置 Port0 引脚方向
 * @param dir_mask 某位为 0 表示输出，为 1 表示输入
 * @example TCA9555_SetPort0Direction(0x00)  // 全部为输出
 *          TCA9555_SetPort0Direction(0x0F)  // 低4位输入，高4位输出
 */
void TCA9555_SetPort0Direction(uint8_t dir_mask);

/**
 * @brief 设置 Port1 引脚方向
 * @param dir_mask 某位为 0 表示输出，为 1 表示输入
 */
void TCA9555_SetPort1Direction(uint8_t dir_mask);

/**
 * @brief 设置 Port0 的单个引脚输出电平
 * @param pin 引脚号 (0~7)
 * @param level 电平 (0=低电平, 1=高电平)
 */
void TCA9555_WritePin0(uint8_t pin, uint8_t level);

/**
 * @brief 设置 Port1 的单个引脚输出电平
 * @param pin 引脚号 (0~7)
 * @param level 电平 (0=低电平, 1=高电平)
 */
void TCA9555_WritePin1(uint8_t pin, uint8_t level);

/**
 * @brief 读取 Port0 的单个引脚输入电平
 * @param pin 引脚号 (0~7)
 * @return 0=低电平, 1=高电平
 */
uint8_t TCA9555_ReadPin0(uint8_t pin);

/**
 * @brief 读取 Port1 的单个引脚输入电平
 * @param pin 引脚号 (0~7)
 * @return 0=低电平, 1=高电平
 */
uint8_t TCA9555_ReadPin1(uint8_t pin);

#endif /* _TCA9555_H */