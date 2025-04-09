/**
 ******************************************************************************
 * @file    main.h
 * @author  Application Team
 * @Version V1.0.0
 * @Date    2022/04/17
 * @brief   Header for main.c file.
 *          This file contains the common defines of the application.
 ******************************************************************************
 */

#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

#include "cs32l015_hal.h"
#include "cs32l015_starterkit.h"

#include "io_mapping.h"
#include "log.h"
#include "util.h"
#include <stdbool.h>
//=============================================================================
//                  Constant Definition
//=============================================================================
	#define CFG_USE_UART3                       1

#define CFG_USE_UART0                       0
#define CFG_USE_UART1                       0
#define CFG_USE_UART2                       0

#define CONFIG_UART_BAUDRATE                115200    //Set the working baud rate

#if defined(CFG_USE_UART0) && (CFG_USE_UART0)
    /* UART 0 */
    #define UARTx                               UART0
    #define __HAL_RCC_UARTx_CLK_ENABLE()        __HAL_RCC_UART0_CLK_ENABLE()
    #define __HAL_RCC_UARTx_CLK_DISABLE()       __HAL_RCC_UART0_CLK_DISABLE()

    #define UARTx_TXD_GPIO                      GPIOA
    #define UARTx_TXD_PIN                       GPIO_PIN_8
    #define UARTx_TXD_AF                        GPIO_AF_MODE_1
    #define __HAL_RCC_UARTx_TXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

    #define UARTx_RXD_GPIO                      GPIOA
    #define UARTx_RXD_PIN                       GPIO_PIN_10
    #define UARTx_RXD_AF                        GPIO_AF_MODE_1
    #define __HAL_RCC_UARTx_RXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

#elif defined(CFG_USE_UART1) && (CFG_USE_UART1)
    /* UART 1 */
    #define UARTx                               UART1
    #define __HAL_RCC_UARTx_CLK_ENABLE()        __HAL_RCC_UART1_CLK_ENABLE()
    #define __HAL_RCC_UARTx_CLK_DISABLE()       __HAL_RCC_UART1_CLK_DISABLE()

    #define UARTx_TXD_GPIO                      GPIOA
    #define UARTx_TXD_PIN                       GPIO_PIN_4
    #define UARTx_TXD_AF                        GPIO_AF_MODE_1
    #define __HAL_RCC_UARTx_TXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

    #define UARTx_RXD_GPIO                      GPIOA
    #define UARTx_RXD_PIN                       GPIO_PIN_3
    #define UARTx_RXD_AF                        GPIO_AF_MODE_1
    #define __HAL_RCC_UARTx_RXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
    #define UARTx_IRQn                          UART1_IRQn

#elif defined(CFG_USE_UART2) && (CFG_USE_UART2)
    /* UART 2 */
    #define UARTx                               UART2
    #define __HAL_RCC_UARTx_CLK_ENABLE()        __HAL_RCC_UART2_CLK_ENABLE()
    #define __HAL_RCC_UARTx_CLK_DISABLE()       __HAL_RCC_UART2_CLK_DISABLE()

    #define UARTx_TXD_GPIO                      GPIOB
    #define UARTx_TXD_PIN                       GPIO_PIN_12
    #define UARTx_TXD_AF                        GPIO_AF_MODE_8
    #define __HAL_RCC_UARTx_TXD_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()

    #define UARTx_RXD_GPIO                      GPIOB
    #define UARTx_RXD_PIN                       GPIO_PIN_13
    #define UARTx_RXD_AF                        GPIO_AF_MODE_8
    #define __HAL_RCC_UARTx_RXD_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()

#elif defined(CFG_USE_UART3) && (CFG_USE_UART3)
    /* UART 3 */
    #define UARTx                               UART3
    #define __HAL_RCC_UARTx_CLK_ENABLE()        __HAL_RCC_UART3_CLK_ENABLE()
    #define __HAL_RCC_UARTx_CLK_DISABLE()       __HAL_RCC_UART3_CLK_DISABLE()

    #define UARTx_TXD_GPIO                      GPIOA
    #define UARTx_TXD_PIN                       GPIO_PIN_7
    #define UARTx_TXD_AF                        GPIO_AF_MODE_8
    #define __HAL_RCC_UARTx_TXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

    #define UARTx_RXD_GPIO                      GPIOB
    #define UARTx_RXD_PIN                       GPIO_PIN_0
    #define UARTx_RXD_AF                        GPIO_AF_MODE_8
    #define __HAL_RCC_UARTx_RXD_CLK_ENABLE()    __HAL_RCC_GPIOB_CLK_ENABLE()
#endif

//=============================================================================
//                  Macro Definition
//=============================================================================

//=============================================================================
//                  Structure Definition
//=============================================================================

//=============================================================================
//                  Global Data Definition
//=============================================================================

//=============================================================================
//                  Private Function Definition
//=============================================================================

//=============================================================================
//                  Public Function Definition
//=============================================================================
void Error_Handler(void);


#ifdef __cplusplus
}
#endif

#endif  /* __MAIN_H */

