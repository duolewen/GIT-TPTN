#ifndef  USART_DRIVER_H_
#define  USART_DRIVER_H_

#include "stdio.h"
#include "stm32f4xx_hal.h"


typedef void (*pFunc_UsartCallBack)(uint32_t UsartX,uint8_t *pBuff,uint32_t Len);

typedef struct
{
	USART_TypeDef       *pUSARTx;
	UART_HandleTypeDef  *pUsartHandle;
	uint8_t *pRxBuff;
	uint32_t uwRxBuffLen;
	pFunc_UsartCallBack CallBack;
}T_BSP_USART_DESC;

uint8_t sbUsart_Init(void);
T_BSP_USART_DESC *spGetUsarDesc(USART_TypeDef *UsartX);
void sBspUsart_SetCb(USART_TypeDef *UsartX,uint32_t CbFun);//设置回调函数
uint8_t UsartDriver_SendData(USART_TypeDef *UsartX,uint8_t *pData,uint32_t Len);

#endif

