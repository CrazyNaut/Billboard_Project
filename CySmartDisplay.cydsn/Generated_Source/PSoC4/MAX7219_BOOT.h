/***************************************************************************//**
* \file MAX7219_BOOT.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values of the bootloader
*  communication APIs for the SCB Component.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2014-2017, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_BOOT_MAX7219_H)
#define CY_SCB_BOOT_MAX7219_H

#include "MAX7219_PVT.h"

#if (MAX7219_SCB_MODE_I2C_INC)
    #include "MAX7219_I2C.h"
#endif /* (MAX7219_SCB_MODE_I2C_INC) */

#if (MAX7219_SCB_MODE_EZI2C_INC)
    #include "MAX7219_EZI2C.h"
#endif /* (MAX7219_SCB_MODE_EZI2C_INC) */

#if (MAX7219_SCB_MODE_SPI_INC || MAX7219_SCB_MODE_UART_INC)
    #include "MAX7219_SPI_UART.h"
#endif /* (MAX7219_SCB_MODE_SPI_INC || MAX7219_SCB_MODE_UART_INC) */


/***************************************
*  Conditional Compilation Parameters
****************************************/

/* Bootloader communication interface enable */
#define MAX7219_BTLDR_COMM_ENABLED ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_MAX7219) || \
                                             (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/* Enable I2C bootloader communication */
#if (MAX7219_SCB_MODE_I2C_INC)
    #define MAX7219_I2C_BTLDR_COMM_ENABLED     (MAX7219_BTLDR_COMM_ENABLED && \
                                                            (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             MAX7219_I2C_SLAVE_CONST))
#else
     #define MAX7219_I2C_BTLDR_COMM_ENABLED    (0u)
#endif /* (MAX7219_SCB_MODE_I2C_INC) */

/* EZI2C does not support bootloader communication. Provide empty APIs */
#if (MAX7219_SCB_MODE_EZI2C_INC)
    #define MAX7219_EZI2C_BTLDR_COMM_ENABLED   (MAX7219_BTLDR_COMM_ENABLED && \
                                                         MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)
#else
    #define MAX7219_EZI2C_BTLDR_COMM_ENABLED   (0u)
#endif /* (MAX7219_EZI2C_BTLDR_COMM_ENABLED) */

/* Enable SPI bootloader communication */
#if (MAX7219_SCB_MODE_SPI_INC)
    #define MAX7219_SPI_BTLDR_COMM_ENABLED     (MAX7219_BTLDR_COMM_ENABLED && \
                                                            (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             MAX7219_SPI_SLAVE_CONST))
#else
        #define MAX7219_SPI_BTLDR_COMM_ENABLED (0u)
#endif /* (MAX7219_SPI_BTLDR_COMM_ENABLED) */

/* Enable UART bootloader communication */
#if (MAX7219_SCB_MODE_UART_INC)
       #define MAX7219_UART_BTLDR_COMM_ENABLED    (MAX7219_BTLDR_COMM_ENABLED && \
                                                            (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG || \
                                                             (MAX7219_UART_RX_DIRECTION && \
                                                              MAX7219_UART_TX_DIRECTION)))
#else
     #define MAX7219_UART_BTLDR_COMM_ENABLED   (0u)
#endif /* (MAX7219_UART_BTLDR_COMM_ENABLED) */

/* Enable bootloader communication */
#define MAX7219_BTLDR_COMM_MODE_ENABLED    (MAX7219_I2C_BTLDR_COMM_ENABLED   || \
                                                     MAX7219_SPI_BTLDR_COMM_ENABLED   || \
                                                     MAX7219_EZI2C_BTLDR_COMM_ENABLED || \
                                                     MAX7219_UART_BTLDR_COMM_ENABLED)


/***************************************
*        Function Prototypes
***************************************/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_I2C_BTLDR_COMM_ENABLED)
    /* I2C Bootloader physical layer functions */
    void MAX7219_I2CCyBtldrCommStart(void);
    void MAX7219_I2CCyBtldrCommStop (void);
    void MAX7219_I2CCyBtldrCommReset(void);
    cystatus MAX7219_I2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus MAX7219_I2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map I2C specific bootloader communication APIs to SCB specific APIs */
    #if (MAX7219_SCB_MODE_I2C_CONST_CFG)
        #define MAX7219_CyBtldrCommStart   MAX7219_I2CCyBtldrCommStart
        #define MAX7219_CyBtldrCommStop    MAX7219_I2CCyBtldrCommStop
        #define MAX7219_CyBtldrCommReset   MAX7219_I2CCyBtldrCommReset
        #define MAX7219_CyBtldrCommRead    MAX7219_I2CCyBtldrCommRead
        #define MAX7219_CyBtldrCommWrite   MAX7219_I2CCyBtldrCommWrite
    #endif /* (MAX7219_SCB_MODE_I2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_I2C_BTLDR_COMM_ENABLED) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_EZI2C_BTLDR_COMM_ENABLED)
    /* Bootloader physical layer functions */
    void MAX7219_EzI2CCyBtldrCommStart(void);
    void MAX7219_EzI2CCyBtldrCommStop (void);
    void MAX7219_EzI2CCyBtldrCommReset(void);
    cystatus MAX7219_EzI2CCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus MAX7219_EzI2CCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map EZI2C specific bootloader communication APIs to SCB specific APIs */
    #if (MAX7219_SCB_MODE_EZI2C_CONST_CFG)
        #define MAX7219_CyBtldrCommStart   MAX7219_EzI2CCyBtldrCommStart
        #define MAX7219_CyBtldrCommStop    MAX7219_EzI2CCyBtldrCommStop
        #define MAX7219_CyBtldrCommReset   MAX7219_EzI2CCyBtldrCommReset
        #define MAX7219_CyBtldrCommRead    MAX7219_EzI2CCyBtldrCommRead
        #define MAX7219_CyBtldrCommWrite   MAX7219_EzI2CCyBtldrCommWrite
    #endif /* (MAX7219_SCB_MODE_EZI2C_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_EZI2C_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_SPI_BTLDR_COMM_ENABLED)
    /* SPI Bootloader physical layer functions */
    void MAX7219_SpiCyBtldrCommStart(void);
    void MAX7219_SpiCyBtldrCommStop (void);
    void MAX7219_SpiCyBtldrCommReset(void);
    cystatus MAX7219_SpiCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus MAX7219_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map SPI specific bootloader communication APIs to SCB specific APIs */
    #if (MAX7219_SCB_MODE_SPI_CONST_CFG)
        #define MAX7219_CyBtldrCommStart   MAX7219_SpiCyBtldrCommStart
        #define MAX7219_CyBtldrCommStop    MAX7219_SpiCyBtldrCommStop
        #define MAX7219_CyBtldrCommReset   MAX7219_SpiCyBtldrCommReset
        #define MAX7219_CyBtldrCommRead    MAX7219_SpiCyBtldrCommRead
        #define MAX7219_CyBtldrCommWrite   MAX7219_SpiCyBtldrCommWrite
    #endif /* (MAX7219_SCB_MODE_SPI_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_SPI_BTLDR_COMM_ENABLED) */

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_UART_BTLDR_COMM_ENABLED)
    /* UART Bootloader physical layer functions */
    void MAX7219_UartCyBtldrCommStart(void);
    void MAX7219_UartCyBtldrCommStop (void);
    void MAX7219_UartCyBtldrCommReset(void);
    cystatus MAX7219_UartCyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    cystatus MAX7219_UartCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);

    /* Map UART specific bootloader communication APIs to SCB specific APIs */
    #if (MAX7219_SCB_MODE_UART_CONST_CFG)
        #define MAX7219_CyBtldrCommStart   MAX7219_UartCyBtldrCommStart
        #define MAX7219_CyBtldrCommStop    MAX7219_UartCyBtldrCommStop
        #define MAX7219_CyBtldrCommReset   MAX7219_UartCyBtldrCommReset
        #define MAX7219_CyBtldrCommRead    MAX7219_UartCyBtldrCommRead
        #define MAX7219_CyBtldrCommWrite   MAX7219_UartCyBtldrCommWrite
    #endif /* (MAX7219_SCB_MODE_UART_CONST_CFG) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_UART_BTLDR_COMM_ENABLED) */

/**
* \addtogroup group_bootloader
* @{
*/

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_BTLDR_COMM_ENABLED)
    #if (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Bootloader physical layer functions */
        void MAX7219_CyBtldrCommStart(void);
        void MAX7219_CyBtldrCommStop (void);
        void MAX7219_CyBtldrCommReset(void);
        cystatus MAX7219_CyBtldrCommRead       (uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
        cystatus MAX7219_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut);
    #endif /* (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Map SCB specific bootloader communication APIs to common APIs */
    #if (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_MAX7219)
        #define CyBtldrCommStart    MAX7219_CyBtldrCommStart
        #define CyBtldrCommStop     MAX7219_CyBtldrCommStop
        #define CyBtldrCommReset    MAX7219_CyBtldrCommReset
        #define CyBtldrCommWrite    MAX7219_CyBtldrCommWrite
        #define CyBtldrCommRead     MAX7219_CyBtldrCommRead
    #endif /* (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_MAX7219) */

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_BTLDR_COMM_ENABLED) */

/** @} group_bootloader */

/***************************************
*           API Constants
***************************************/

/* Timeout unit in milliseconds */
#define MAX7219_WAIT_1_MS  (1u)

/* Return number of bytes to copy into bootloader buffer */
#define MAX7219_BYTES_TO_COPY(actBufSize, bufSize) \
                            ( ((uint32)(actBufSize) < (uint32)(bufSize)) ? \
                                ((uint32) (actBufSize)) : ((uint32) (bufSize)) )

/* Size of Read/Write buffers for I2C bootloader  */
#define MAX7219_I2C_BTLDR_SIZEOF_READ_BUFFER   (64u)
#define MAX7219_I2C_BTLDR_SIZEOF_WRITE_BUFFER  (64u)

/* Byte to byte time interval: calculated basing on current component
* data rate configuration, can be defined in project if required.
*/
#ifndef MAX7219_SPI_BYTE_TO_BYTE
    #define MAX7219_SPI_BYTE_TO_BYTE   (32u)
#endif

/* Byte to byte time interval: calculated basing on current component
* baud rate configuration, can be defined in the project if required.
*/
#ifndef MAX7219_UART_BYTE_TO_BYTE
    #define MAX7219_UART_BYTE_TO_BYTE  (2500u)
#endif /* MAX7219_UART_BYTE_TO_BYTE */

#endif /* (CY_SCB_BOOT_MAX7219_H) */


/* [] END OF FILE */
