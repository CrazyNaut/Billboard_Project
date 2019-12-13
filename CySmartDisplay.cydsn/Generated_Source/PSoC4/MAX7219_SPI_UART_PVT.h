/***************************************************************************//**
* \file MAX7219_SPI_UART_PVT.h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component in SPI and UART modes.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_SPI_UART_PVT_MAX7219_H)
#define CY_SCB_SPI_UART_PVT_MAX7219_H

#include "MAX7219_SPI_UART.h"


/***************************************
*     Internal Global Vars
***************************************/

#if (MAX7219_INTERNAL_RX_SW_BUFFER_CONST)
    extern volatile uint32  MAX7219_rxBufferHead;
    extern volatile uint32  MAX7219_rxBufferTail;
    
    /**
    * \addtogroup group_globals
    * @{
    */
    
    /** Sets when internal software receive buffer overflow
     *  was occurred.
    */  
    extern volatile uint8   MAX7219_rxBufferOverflow;
    /** @} globals */
#endif /* (MAX7219_INTERNAL_RX_SW_BUFFER_CONST) */

#if (MAX7219_INTERNAL_TX_SW_BUFFER_CONST)
    extern volatile uint32  MAX7219_txBufferHead;
    extern volatile uint32  MAX7219_txBufferTail;
#endif /* (MAX7219_INTERNAL_TX_SW_BUFFER_CONST) */

#if (MAX7219_INTERNAL_RX_SW_BUFFER)
    extern volatile uint8 MAX7219_rxBufferInternal[MAX7219_INTERNAL_RX_BUFFER_SIZE];
#endif /* (MAX7219_INTERNAL_RX_SW_BUFFER) */

#if (MAX7219_INTERNAL_TX_SW_BUFFER)
    extern volatile uint8 MAX7219_txBufferInternal[MAX7219_TX_BUFFER_SIZE];
#endif /* (MAX7219_INTERNAL_TX_SW_BUFFER) */


/***************************************
*     Private Function Prototypes
***************************************/

void MAX7219_SpiPostEnable(void);
void MAX7219_SpiStop(void);

#if (MAX7219_SCB_MODE_SPI_CONST_CFG)
    void MAX7219_SpiInit(void);
#endif /* (MAX7219_SCB_MODE_SPI_CONST_CFG) */

#if (MAX7219_SPI_WAKE_ENABLE_CONST)
    void MAX7219_SpiSaveConfig(void);
    void MAX7219_SpiRestoreConfig(void);
#endif /* (MAX7219_SPI_WAKE_ENABLE_CONST) */

void MAX7219_UartPostEnable(void);
void MAX7219_UartStop(void);

#if (MAX7219_SCB_MODE_UART_CONST_CFG)
    void MAX7219_UartInit(void);
#endif /* (MAX7219_SCB_MODE_UART_CONST_CFG) */

#if (MAX7219_UART_WAKE_ENABLE_CONST)
    void MAX7219_UartSaveConfig(void);
    void MAX7219_UartRestoreConfig(void);
#endif /* (MAX7219_UART_WAKE_ENABLE_CONST) */


/***************************************
*         UART API Constants
***************************************/

/* UART RX and TX position to be used in MAX7219_SetPins() */
#define MAX7219_UART_RX_PIN_ENABLE    (MAX7219_UART_RX)
#define MAX7219_UART_TX_PIN_ENABLE    (MAX7219_UART_TX)

/* UART RTS and CTS position to be used in  MAX7219_SetPins() */
#define MAX7219_UART_RTS_PIN_ENABLE    (0x10u)
#define MAX7219_UART_CTS_PIN_ENABLE    (0x20u)


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Interrupt processing */
#define MAX7219_SpiUartEnableIntRx(intSourceMask)  MAX7219_SetRxInterruptMode(intSourceMask)
#define MAX7219_SpiUartEnableIntTx(intSourceMask)  MAX7219_SetTxInterruptMode(intSourceMask)
uint32  MAX7219_SpiUartDisableIntRx(void);
uint32  MAX7219_SpiUartDisableIntTx(void);


#endif /* (CY_SCB_SPI_UART_PVT_MAX7219_H) */


/* [] END OF FILE */
