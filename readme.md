uart_polling_transmit_receive
---


## Project Description

This example is a demo project for UART module.

You can change `main.h` about `CFG_USE_UARTx` value is true or false to control code work on `UART0/UART1/UART2/UART3` module.

+ Control code use UART module

    ```
    #define CFG_USE_UART0                       false
    #define CFG_USE_UART1                       true
    #define CFG_USE_UART2                       false
    #define CFG_USE_UART3                       false
    ```

You can change `UARTx_xxx` to  control UART configuration.

+ Control UART configuration

    ```
    #define UARTx_BAUDRATE                      115200
    #define UARTx_BAUDDOUBLE                    UART_BAUDDOUBLE_DISABLE
    #define UARTx_WORDLENTH                     UART_WORDLENGTH_8B
    #define UARTx_PARITY                        UART_PARITY_NONE
    ```

+ Control TXD and RXD pin configuration

    ```
    #define UARTx_TXD_GPIO                      GPIOA
    #define UARTx_TXD_PIN                       GPIO_PIN_14
    #define UARTx_TXD_AF                        GPIO_AF_MODE_1
    #define __HAL_RCC_UARTx_TXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()

    #define UARTx_RXD_GPIO                      GPIOA
    #define UARTx_RXD_PIN                       GPIO_PIN_3
    #define UARTx_RXD_AF                        GPIO_AF_MODE_1
    #define __HAL_RCC_UARTx_RXD_CLK_ENABLE()    __HAL_RCC_GPIOA_CLK_ENABLE()
    ```

After burning the compiled bin file to the MCU, make sure that the communication pins of the sending and receiving data modules of the UART are properly connected `（TXD-> other module RXD, RXD-> other module TXD, GND->GND）`.

The maximum baud rate of the UART module is about 1/64 of the HRC frequency. When setting the communication baud rate, do not set the baud rate higher than this value.

In addition to ensuring the same baud rate of the data sending module and the data receiving module, if there is a large difference in the operating frequency (HRC value) of the two MCUS, the value of the data amount of sending or receiving data by calling API function in a single time is best selected as 1.


## Log

Because the log information is based on the UART module output, in order to avoid module usage conflicts, the printf function is not used in this demo to output experimental results.

The use of `LED lights` on and off two states to indicate the results of the experiment.

If the `LED is on`, it means that the two UART modules have `no problem` sending and receiving data to each other. If the `LED lights go off`, it means that the UART module is `not working` properly or the received data is not as expected. If the LED lights go out for more than 5000ms, it is recommended to check whether the clocks of the two UART modules are working properly, or whether the MCU has a hardware error.

This project file sends data first and receives it later.
