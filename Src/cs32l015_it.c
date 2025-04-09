/**
 ******************************************************************************
 * @file    cs32l015_it.c
 * @author  MCU Software Team
 * @Version V1.0.0
 * @Date    2022/01/19
 * @brief   Interrupt Service Routines.
 ******************************************************************************
 */


#include "main.h"
//=============================================================================
//                  Constant Definition
//=============================================================================

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

/******************************************************************************
 *           Cortex-M0+ Processor Interruption and Exception Handlers         *
 ******************************************************************************/
/**
 * @brief This function handles Non maskable interrupt.
 */
 
 
 
void NMI_Handler(void)
{
    /* USER CODE BEGIN NonMaskableInt_IRQn 0 */
    /* USER CODE END NonMaskableInt_IRQn 0 */
}

/**
 * @brief This function handles Hard fault interrupt.
 */
void HardFault_Handler(void)
{
    /* USER CODE BEGIN HardFault_IRQn 0 */
    /* USER CODE END HardFault_IRQn 0 */

    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    __BKPT(0);
    /* USER CODE END W1_HardFault_IRQn 0 */

}

/**
 * @brief This function handles System service call via SWI instruction.
 */
void SVC_Handler(void)
{
    /* USER CODE BEGIN SVCall_IRQn 0 */
    /* USER CODE END SVCall_IRQn 0 */
}

/**
 * @brief This function handles Pendable request for system service.
 */
void PendSV_Handler(void)
{
    /* USER CODE BEGIN PendSV_IRQn 0 */
    /* USER CODE END PendSV_IRQn 0 */
}

/**
 * @brief This function handles System tick timer.
 */
void SysTick_Handler(void)
{
    /* USER CODE BEGIN SysTick_IRQn 0 */
    /* USER CODE END SysTick_IRQn 0 */

    HAL_IncTick();

    /* USER CODE BEGIN SysTick_IRQn 1 */
    /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* CS32L015 Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_cs32l015.s).                    */
/******************************************************************************/

