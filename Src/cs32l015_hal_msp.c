/**
 ******************************************************************************
 * @file    cs32l015_hal_msp.c
 * @author  MCU Software Team
 * @Version V1.0.0
 * @Date    2022/04/19
 * @brief   This file provides code for the MSP Initialization
 *          and de-Initialization codes.
 ******************************************************************************
 */


#include "main.h"






//    #define UARTx                               UART1
//    #define __HAL_RCC_UARTx_CLK_ENABLE()        __HAL_RCC_UART1_CLK_ENABLE()
//    #define __HAL_RCC_UARTx_CLK_DISABLE()       __HAL_RCC_UART1_CLK_DISABLE()

//    #define UARTx_TXD_GPIO                      GPIOA
//    #define UARTx_TXD_PIN                       GPIO_PIN_4
//    #define UARTx_TXD_AF                        GPIO_AF_MODE_1
//    #define __HAL_RCC_UARTx_TXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

//    #define UARTx_RXD_GPIO                      GPIOA
//    #define UARTx_RXD_PIN                       GPIO_PIN_3
//    #define UARTx_RXD_AF                        GPIO_AF_MODE_1
//    #define __HAL_RCC_UARTx_RXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()


/**
 * Initializes the Global MSP.
 */
void HAL_MspInit(void)
{
    /* USER CODE BEGIN MspInit 0 */

    /* USER CODE END MspInit 0 */
}

/**
 * @brief  UART MSP Init.
 * @param  huart: pointer to a UART_HandleTypeDef structure that contains
 *                the configuration information for the specified UART module.
 * @retval None
 */
    GPIO_InitTypeDef    GPIO_InitStruct = {0};

void HAL_UART_MspInit(UART_HandleTypeDef *huart)
{
   // GPIO_InitTypeDef    GPIO_InitStruct = {0};
__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
    if(huart->Instance == UART3)
    {
	

        __HAL_RCC_UART3_CLK_ENABLE();
//       __HAL_RCC_UARTx_TXD_CLK_ENABLE();
//       __HAL_RCC_UARTx_RXD_CLK_ENABLE();

        /*TXD*/
        GPIO_InitStruct.Pin             = UARTx_TXD_PIN;
        GPIO_InitStruct.Mode            = GPIO_MODE_AF;
        GPIO_InitStruct.OpenDrain       = GPIO_PUSHPULL;
        GPIO_InitStruct.Debounce.Enable = GPIO_DEBOUNCE_DISABLE;
        GPIO_InitStruct.SlewRate        = GPIO_SLEW_RATE_HIGH;
        GPIO_InitStruct.DrvStrength     = GPIO_DRV_STRENGTH_HIGH;
        GPIO_InitStruct.Pull            = GPIO_PULLUP;
        GPIO_InitStruct.Alternate       = UARTx_TXD_AF;
        HAL_GPIO_Init(UARTx_TXD_GPIO, &GPIO_InitStruct);

        /*RXD*/
        GPIO_InitStruct.Pin             = UARTx_RXD_PIN;
        GPIO_InitStruct.Mode            = GPIO_MODE_AF;
        GPIO_InitStruct.OpenDrain       = GPIO_PUSHPULL;
        GPIO_InitStruct.Debounce.Enable = GPIO_DEBOUNCE_DISABLE;
        GPIO_InitStruct.SlewRate        = GPIO_SLEW_RATE_HIGH;
        GPIO_InitStruct.DrvStrength     = GPIO_DRV_STRENGTH_HIGH;
        GPIO_InitStruct.Pull            = GPIO_NOPULL;
        GPIO_InitStruct.Alternate       = UARTx_RXD_AF;
        HAL_GPIO_Init(UARTx_RXD_GPIO, &GPIO_InitStruct);
				
				
				
				
				        /*TXD*/
//        GPIO_InitStruct.Pin             = GPIO_PIN_4;

//        GPIO_InitStruct.Debounce.Enable = GPIO_DEBOUNCE_DISABLE;
//        GPIO_InitStruct.SlewRate        = GPIO_SLEW_RATE_HIGH;
//        GPIO_InitStruct.DrvStrength     = GPIO_DRV_STRENGTH_HIGH;
//        GPIO_InitStruct.Pull            = GPIO_PULLUP;
//        GPIO_InitStruct.Alternate       = GPIO_AF_MODE_1;
//        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//        /*RXD*/
//        GPIO_InitStruct.Pin             = GPIO_PIN_3;
//        GPIO_InitStruct.Mode            = GPIO_MODE_AF;
//        GPIO_InitStruct.OpenDrain       = GPIO_PUSHPULL;
//        GPIO_InitStruct.Debounce.Enable = GPIO_DEBOUNCE_DISABLE;
//        GPIO_InitStruct.SlewRate        = GPIO_SLEW_RATE_HIGH;
//        GPIO_InitStruct.DrvStrength     = GPIO_DRV_STRENGTH_HIGH;
//        GPIO_InitStruct.Pull            = GPIO_NOPULL;
//        GPIO_InitStruct.Alternate       = GPIO_AF_MODE_1;
//        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
				
//				    #define UARTx                               UART1
//    #define __HAL_RCC_UARTx_CLK_ENABLE()        __HAL_RCC_UART1_CLK_ENABLE()
//    #define __HAL_RCC_UARTx_CLK_DISABLE()       __HAL_RCC_UART1_CLK_DISABLE()

//    #define UARTx_TXD_GPIO                      GPIOA
//    #define UARTx_TXD_PIN                       GPIO_PIN_4
//    #define UARTx_TXD_AF                        GPIO_AF_MODE_1
//    #define __HAL_RCC_UARTx_TXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

//    #define UARTx_RXD_GPIO                      GPIOA
//    #define UARTx_RXD_PIN                       GPIO_PIN_3
//    #define UARTx_RXD_AF                        GPIO_AF_MODE_1
//    #define __HAL_RCC_UARTx_RXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
//    #define UARTx_IRQn                          UART1_IRQn
				
    }
		else if(huart->Instance == UART1)
		{
		   __HAL_RCC_UART1_CLK_ENABLE();
      // __HAL_RCC_GPIOA_CLK_ENABLE();
      // __HAL_RCC_GPIOA_CLK_ENABLE();

        /*TXD*/
			
      GPIO_InitTypeDef    GPIO_InitStruct = {0};

        GPIO_InitStruct.Pin             = GPIO_PIN_4;
        GPIO_InitStruct.Mode            = GPIO_MODE_AF;
        GPIO_InitStruct.OpenDrain       = GPIO_PUSHPULL;
        GPIO_InitStruct.Debounce.Enable = GPIO_DEBOUNCE_DISABLE;
        GPIO_InitStruct.SlewRate        = GPIO_SLEW_RATE_HIGH;
        GPIO_InitStruct.DrvStrength     = GPIO_DRV_STRENGTH_HIGH;
        GPIO_InitStruct.Pull            = GPIO_PULLUP;
        GPIO_InitStruct.Alternate       = GPIO_AF_MODE_1;
        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//        /*RXD*/
        GPIO_InitStruct.Pin             = GPIO_PIN_3;
        GPIO_InitStruct.Mode            = GPIO_MODE_AF;
        GPIO_InitStruct.OpenDrain       = GPIO_PUSHPULL;
        GPIO_InitStruct.Debounce.Enable = GPIO_DEBOUNCE_DISABLE;
        GPIO_InitStruct.SlewRate        = GPIO_SLEW_RATE_HIGH;
        GPIO_InitStruct.DrvStrength     = GPIO_DRV_STRENGTH_HIGH;
        GPIO_InitStruct.Pull            = GPIO_NOPULL;
        GPIO_InitStruct.Alternate       = GPIO_AF_MODE_1;
       HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		
		}
			
}

/**
 * @brief  UART MSP DeInit.
 * @param  huart: pointer to a UART_HandleTypeDef structure that contains
 *                the configuration information for the specified UART module.
 * @retval None
 */
void HAL_UART_MspDeInit(UART_HandleTypeDef *huart)
{
    if(huart->Instance == UART3)
    {
        __HAL_RCC_UART3_CLK_DISABLE();

        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_7);
        HAL_GPIO_DeInit(GPIOB, GPIO_PIN_0);
    }
		else if(huart->Instance == UART1)
    {
        __HAL_RCC_UART1_CLK_DISABLE();

        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_4);
        HAL_GPIO_DeInit(GPIOA, GPIO_PIN_3);
    }
}

