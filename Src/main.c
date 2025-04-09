/**
 ******************************************************************************
 * @file    main.c
 * @author  MCU Team
 * @Version V1.0.0
 * @Date    2022/04/19
 * @brief   main function
 ******************************************************************************
 */

#include <stdio.h>
#include <string.h>
#include "main.h"
#include "log.h"
//=============================================================================
//                  Constant Definition
//=============================================================================
#define LENGTH                      10                    //The number of bytes of data per communication
#define COMMUNICATION_TIME_MAX      0x7530                      //30s
#define COMMUNICATION_TIME_MIN      0x3a98                      //15s

//=============================================================================
//                  Macro Definition
//=============================================================================

//=============================================================================
//                  Structure Definition
//=============================================================================

//=============================================================================
//                  Global Data Definition
//=============================================================================
UART_HandleTypeDef  g_hUart;
UART_HandleTypeDef  g_hUart1;

static uint8_t sendData[LENGTH] = {'a','b','t','d','e','f','g','6','\n'};
static uint8_t receData[LENGTH] = {0};
static uint8_t  TxFlag = 0;
static uint8_t  RxFlag = 0;

//=============================================================================
//                  Private Function Definition
//=============================================================================
/**
 * @brief System Clock Configuration
 * @retval None
 */

#define KEY_PIN           GPIO_PIN_0
#define KEY_PORT          GPIOD
#define RES_PIN           GPIO_PIN_0
#define RES_PORT          GPIOA
#define POWER_BUTTON_PIN	GPIO_PIN_15
#define POWER_BUTTON_PORT GPIOC
#define CHILD_LOCK_PIN    GPIO_PIN_15
#define CHILD_LOCK_PORT   GPIOA
#define LAMP_PIN 					GPIO_PIN_3
#define LAMP_PORT         GPIOB


static void _SystemClock_Config(void)
{
    RCC_OscInitTypeDef  RCC_OscInitStruct = {0};
    RCC_ClkInitTypeDef  RCC_ClkInitStruct = {0};

    RCC_OscInitStruct.OscillatorType       = RCC_OSCILLATORTYPE_HRC;
    RCC_OscInitStruct.HRCState            = RCC_HRC_ON;
    RCC_OscInitStruct.HRCCalibrationValue = RCC_HRCCALIBRATION_24M;

    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
    {
        Error_Handler();
    }

    /* Initializes the CPU, AHB and APB buses clocks */
    RCC_ClkInitStruct.ClockType     = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK;
    RCC_ClkInitStruct.SYSCLKSource  = RCC_SYSCLKSOURCE_HRC;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APBCLKDivider = RCC_PCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct) != HAL_OK)
    {
        Error_Handler();
    }
    return;
}


#define UART_BUFFER_SIZE  10  
static uint8_t rxIndex;  
//uint8_t txData[UART_BUFFER_SIZE] = "HELLO_UART";  

//=============================================================================
//                  Public Function Definition
//=============================================================================
/**
 * @brief  The application entry point.
 * @retval int
 */uint8_t txData[UART_BUFFER_SIZE] = {'a','b','v'};  // Ð?nh nghia m?ng d? li?u trong RAM

    uint8_t rxData[256];
		uint8_t receivedByte ;
    uint8_t ErrorNum = 0;
 
 //UART_HandleTypeDef g_hUart3 = {0};
 
 
 
static void UART_SetConfig(UART_HandleTypeDef *huart)
{
    /*------- UART-associated registers setting : SCON Configuration ------*/
    /* Configure the UART Word Length and mode:
        Set the DBAUD bits according to huart->Init.BaudDouble value
        Set the SM bits according to huart->Init.WordLength value
        Set REN bits according to huart->Init.Mode value */
    MODIFY_REG(huart->Instance->SCON,
               (UART_SCON_DBAUD | UART_SCON_SM0_SM1 | UART_SCON_REN),
               huart->Init.BaudDouble | huart->Init.WordLength | huart->Init.Mode);

    {   // UART BAUDCR Configuration
        uint32_t    bardrate = ((((huart->Init.BaudDouble >> UART_SCON_DBAUD_Pos) + 1) * HAL_RCC_GetPCLKFreq()) / (32 * (huart->Init.BaudRate))) - 1;

        WRITE_REG_MASK(huart->Instance->BAUDCR,
                       UART_BAUDCR_BRG_Msk | UART_BAUDCR_SELF_BRG_Msk,
                       bardrate | UART_BAUDCR_SELF_BRG);
    }

    __HAL_UART_ENABLE_IT(huart, UART_IT_TC | UART_IT_RXNE);
}

// void uart3_init(uint32_t baud_rate)
//{
//    g_hUart3.Instance        = UART3;
//    g_hUart3.Init.BaudRate   = baud_rate;
//    g_hUart3.Init.BaudDouble = UART_BAUDDOUBLE_ENABLE;
//    g_hUart3.Init.WordLength = UART_WORDLENGTH_8B;
//    g_hUart3.Init.Parity     = UART_PARITY_NONE;
//    g_hUart3.Init.Mode       = UART_MODE_TX_RX;


//	
////    if(g_hUart3.gState == HAL_UART_STATE_RESET)
////    {
//        GPIO_InitTypeDef    GPIO_InitStruct = {0};

//        /* Allocate lock resource and initialize it */
//       // g_hUart3.Lock = HAL_UNLOCKED;

//        /* Peripheral clock enable */
//        __HAL_RCC_UART3_CLK_ENABLE();

//        __HAL_RCC_GPIOA_CLK_ENABLE();
//        __HAL_RCC_GPIOB_CLK_ENABLE();
//        /**
//         *  UART2 GPIO Configuration
//         *  PB12     ------> UART2_TXD A7
//         *  PB13     ------> UART2_RXD B8
//         */
//        GPIO_InitStruct.Pin             = GPIO_PIN_7;
//        GPIO_InitStruct.Mode            = GPIO_MODE_AF;
//        GPIO_InitStruct.OpenDrain       = GPIO_PUSHPULL;
//        GPIO_InitStruct.Debounce.Enable = GPIO_DEBOUNCE_ENABLE;
//        GPIO_InitStruct.SlewRate        = GPIO_SLEW_RATE_HIGH;
//        GPIO_InitStruct.DrvStrength     = GPIO_DRV_STRENGTH_HIGH;
//        GPIO_InitStruct.Pull            = GPIO_PULLUP;
//        GPIO_InitStruct.Alternate       = GPIO_AF_MODE_8;
//        HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

//        GPIO_InitStruct.Pin       = GPIO_PIN_0;
//        GPIO_InitStruct.Mode      = GPIO_MODE_AF;
//        GPIO_InitStruct.Alternate = GPIO_AF_MODE_8;
//        HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

//    return;
//}
 

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


void clock_gpio(){
	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();
}

void gpio_update_UI(){
	clock_gpio();
	
	__HAL_GPIO_SET_OUTPUT(RES_PORT, RES_PIN);
  __HAL_GPIO_SET_OUTPUT(KEY_PORT, KEY_PIN);
			
	HAL_GPIO_WritePin(KEY_PORT, KEY_PIN, 0);
	HAL_GPIO_WritePin(RES_PORT, RES_PIN, 1);
	HAL_Delay(50);
	HAL_GPIO_WritePin(RES_PORT, RES_PIN, 0);
	HAL_Delay(2000);
	HAL_GPIO_WritePin(KEY_PORT, KEY_PIN, 1);

  __HAL_GPIO_SET_INPUT(KEY_PORT, KEY_PIN);	
}
 

int main(void)
{
    /**heap variables*/
    uint8_t SendNum = 0;

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* Configure the system clock to HRC 24MHz*/
    _SystemClock_Config();
//gpio_update_UI();
	//clock_gpio();
	//Init_gpio();

    //BSP_LED_Init(LED1);
    /* UART module init.*/
    g_hUart.Instance               = UART3;
    g_hUart.Init.BaudRate          = 9600;
   // g_hUart.Init.BaudDouble        = UART_BAUDDOUBLE_ENABLE;
    g_hUart.Init.WordLength        = UART_WORDLENGTH_8B;
    g_hUart.Init.Parity            = UART_PARITY_NONE;
    g_hUart.Init.Mode              = UART_MODE_TX_RX;
    HAL_UART_Init(&g_hUart);
	
	
	    g_hUart1.Instance               = UART1;
  g_hUart1.Init.BaudRate          = 9600;
	//g_hUart1.Init.BaudDouble        = UART_BAUDDOUBLE_ENABLE;
    g_hUart1.Init.WordLength        = UART_WORDLENGTH_8B;
    g_hUart1.Init.Parity            = UART_PARITY_NONE;
    g_hUart1.Init.Mode              = UART_MODE_TX_RX;
    HAL_UART_Init(&g_hUart1);

		NVIC_EnableIRQ(UART2_3_IRQn);  
		HAL_UART_Receive_IT(&g_hUart, &rxData[rxIndex], 1);
//		__HAL_UART_ENABLE_IT(&g_hUart, UART_IT_RXNE);
    __HAL_UART_DISABLE_IT(&g_hUart, UART_IT_TC);
//		NVIC_SetPriority(UART2_3_IRQn, 0); 
	 //   __HAL_UART_DISABLE_IT(&g_hUart1, UART_IT_TC);

		NVIC_EnableIRQ(UART1_IRQn);  
		HAL_UART_Receive_IT(&g_hUart1, &rxData[rxIndex], 1);
//		__HAL_UART_ENABLE_IT(&g_hUart1, UART_IT_RXNE);

	
	
//	  g_hUart1.Instance               = UART1;
//    g_hUart1.Init.BaudRate          = 9600;
//    g_hUart1.Init.BaudDouble        = UART_BAUDDOUBLE_ENABLE;
//    g_hUart1.Init.WordLength        = UART_WORDLENGTH_8B;
//    g_hUart1.Init.Parity            = UART_PARITY_NONE;
//    g_hUart1.Init.Mode              = UART_MODE_TX_RX;
//	  g_hUart1.Init.Parity =UART_PARITY_NONE;
//	
	
//	      config.Pin             = GPIO_PIN_14;
//			config.Pin             = GPIO_PIN_3;
//        config.Mode            = GPIO_MODE_AF;
//        config.OpenDrain       = GPIO_PUSHPULL;
//	        config.Alternate       = GPIO_AF_MODE_1;
//        HAL_GPIO_Init(GPIOA, &config);

	//__HAL_RCC_UART1_CLK_ENABLE();
	
	//Config UART 1
//	    g_hUart1.Instance               = UART1;
//    g_hUart1.Init.BaudRate          = CONFIG_UART_BAUDRATE;
//    g_hUart1.Init.BaudDouble        = UART_BAUDDOUBLE_ENABLE;
//    g_hUart1.Init.WordLength        = UART_WORDLENGTH_8B;
//    g_hUart1.Init.Parity            = UART_PARITY_NONE;
//    g_hUart1.Init.Mode              = UART_MODE_TX_RX;
//	  g_hUart1.Init.Parity =UART_PARITY_NONE;
//			
//				   HAL_UART_Init(&g_hUart1);

    
//		   HAL_UART_Init(&g_hUart);
//		 //  HAL_UART_Init(&g_hUart1);
//  //  NVIC_EnableIRQ(UARTx_IRQn);

//NVIC_EnableIRQ(UART2_3_IRQn);  
////NVIC_EnableIRQ(UART1_IRQn);  
//    //HAL_UART_Receive_IT(&g_hUart1, &rece1Data[0], 1);

//HAL_UART_Receive_IT(&g_hUart, &rxData[rxIndex], 1);
//__HAL_UART_ENABLE_IT(&g_hUart, UART_IT_RXNE);
//__HAL_UART_ENABLE_IT(&g_hUart, UART_IT_TC);

////				HAL_UART_Receive_IT(&g_hUart1, &rxData[rxIndex], 1);
////__HAL_UART_ENABLE_IT(&g_hUart1, UART_IT_RXNE);
////__HAL_UART_ENABLE_IT(&g_hUart1, UART_IT_TC);

//NVIC_SetPriority(UART2_3_IRQn, 0);  
////NVIC_SetPriority(UART1_IRQn, 0);  

    while(1)
    {
//			BSP_LED_On(LED1);


//		//	receivedByte = (g_hUart.Instance->SBUF);
//	     // g_hUart.gState = HAL_UART_STATE_READY;
//			//__HAL_UART_CLEAR_FLAG(&g_hUart, UART_FLAG_TC);
////receivedByte = (g_hUart.Instance->SBUF);
//			//HAL_UART_Receive_IT(&g_hUart, &receivedByte, 1);
//			
//			
//		//	Tranfer_data();
//		//	printf("AAAA");
//	//		g_hUart.gState = HAL_UART_STATE_READY;
//			        // HAL_UART_Transmit_IT(&g_hUart, &sendData[SendNum], 1);
//								//			SendNum++;
//		//	HAL_delay(100);
// //


			if(rxIndex)
			{
				rxIndex--;
				
				    if(SendNum < 8)
            {
							__HAL_UART_ENABLE_IT(&g_hUart, UART_IT_TC);
						//	__HAL_UART_ENABLE_IT(&g_hUart1, UART_IT_TC);

					     // HAL_UART_Transmit_IT(&g_hUart1, &sendData[SendNum], 7);
								HAL_UART_Transmit_IT(&g_hUart, &receivedByte, 7);
								SendNum++;
            }
            else
            {
                SendNum = 0;
            }
       g_hUart.gState = HAL_UART_STATE_READY;
//			__HAL_UART_CLEAR_FLAG(&g_hUart, UART_FLAG_TC);
//      receivedByte = (g_hUart.Instance->SBUF);
//			HAL_UART_Receive_IT(&g_hUart, &receivedByte, 1);
			}
	   // HAL_Delay(10);		

    }
}

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */

// ============================ INTERRUPT HANDLER ============================
void UART2_3_IRQHandler(void)
{
	    if (__HAL_UART_GET_FLAG(&g_hUart, UART_FLAG_RXNE)) 
			{
								 HAL_UART_Transmit_IT(&g_hUart, & receivedByte, 2);  

				rxIndex++;
      receivedByte = (g_hUart.Instance->SBUF);
     __HAL_UART_CLEAR_FLAG(&g_hUart, UART_FLAG_RXNE | UART_FLAG_FE);
     __HAL_UART_ENABLE_IT(&g_hUart, UART_IT_RXNE);
		 __HAL_UART_CLEAR_FLAG(&g_hUart, UART_FLAG_TC);
		}
}

//UART1
//// ============================ CALLBACK FUNCTION ============================

void UART1_IRQHandler(void)
{
	    if (__HAL_UART_GET_FLAG(&g_hUart1, UART_FLAG_RXNE)) 
			{
								 HAL_UART_Transmit_IT(&g_hUart, &receivedByte, 2);  

				rxIndex++;
      receivedByte = (g_hUart1.Instance->SBUF);
     __HAL_UART_CLEAR_FLAG(&g_hUart1, UART_FLAG_RXNE | UART_FLAG_FE);
     __HAL_UART_ENABLE_IT(&g_hUart1, UART_IT_RXNE);
		 __HAL_UART_CLEAR_FLAG(&g_hUart, UART_FLAG_TC);
		}
}


void Error_Handler(void)
{
    __BKPT(1);
}

#ifdef  USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */

//void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart)
//{
//    if (huart->Instance == UART3) 
//    {
//   //    HAL_UART_Transmit(&g_hUart, &rxData, 3, 100);  
//        HAL_UART_Transmit_IT(&g_hUart, "ABC", 3);  
//    }
//}

//void UART2_3_IRQHandler(void)
//{
//    HAL_UART_IRQHandler(&g_hUart);
//}



void assert_failed(const char *func_name, uint32_t line)
{
    /* USER CODE BEGIN 6 */
    /**
     *  User can add his own implementation to report the file name and line number,
     * e.g. printf("Wrong parameters value: func %s on line %d\n", file, line)
     */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */


