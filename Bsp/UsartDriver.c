#include "UsartDriver.h"
#include "FreeRTOS.h"
#include "task.h"

#define USART3_RX_LEN  512

extern UART_HandleTypeDef huart3;


uint8_t BspUsart1_RxBuff[USART3_RX_LEN] = {0};


T_BSP_USART_DESC BspUsartDesc_Buff[] = 
{
	{USART3,&huart3,BspUsart1_RxBuff ,USART3_RX_LEN ,0},
};


uint8_t sbUsart_Init(void)
{
	 T_BSP_USART_DESC *pDesc = spGetUsarDesc(USART3);
	 
	 __HAL_UART_ENABLE_IT(pDesc->pUsartHandle, UART_IT_IDLE);  
	 HAL_UART_Receive_DMA(pDesc->pUsartHandle,  pDesc->pRxBuff, pDesc->uwRxBuffLen );
	
   return 1;
}

T_BSP_USART_DESC *spGetUsarDesc(USART_TypeDef *UsartX)
{
	for(uint32_t i = 0;i<sizeof(BspUsartDesc_Buff)/sizeof(T_BSP_USART_DESC) ; i++)
	{
	    if(BspUsartDesc_Buff[i].pUSARTx == UsartX)	
			{
				return  &BspUsartDesc_Buff[i];
			}
	}
	return 0;
	
}

void sBspUsart_SetCb(USART_TypeDef *UsartX,uint32_t CbFun)//设置回调函数
{
	 for(uint32_t i = 0;i<sizeof(BspUsartDesc_Buff)/sizeof(T_BSP_USART_DESC) ; i++)
	 {
	     if(BspUsartDesc_Buff[i].pUSARTx == UsartX)	
	 		{
	 			BspUsartDesc_Buff[i].CallBack = (pFunc_UsartCallBack)CbFun;
	 			return ;
	 		}
	 }
}
	
uint8_t UsartDriver_SendData(USART_TypeDef *UsartX,uint8_t *pData,uint32_t Len)
{
	 T_BSP_USART_DESC *pDesc = spGetUsarDesc( UsartX);
	 if(0 == pDesc)
	 {
		 return 0;
	 }
		HAL_UART_Transmit_DMA(pDesc->pUsartHandle , pData, Len);
		while(HAL_UART_GetState(pDesc->pUsartHandle) == HAL_UART_STATE_BUSY_TX_RX)
		{
		  vTaskDelay(1);
		}
		return 0;
}
