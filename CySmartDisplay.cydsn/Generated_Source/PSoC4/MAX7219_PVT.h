/***************************************************************************//**
* \file .h
* \version 4.0
*
* \brief
*  This private file provides constants and parameter values for the
*  SCB Component.
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

#if !defined(CY_SCB_PVT_MAX7219_H)
#define CY_SCB_PVT_MAX7219_H

#include "MAX7219.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define MAX7219_SetI2CExtClkInterruptMode(interruptMask) MAX7219_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define MAX7219_ClearI2CExtClkInterruptSource(interruptMask) MAX7219_CLEAR_INTR_I2C_EC(interruptMask)
#define MAX7219_GetI2CExtClkInterruptSource()                (MAX7219_INTR_I2C_EC_REG)
#define MAX7219_GetI2CExtClkInterruptMode()                  (MAX7219_INTR_I2C_EC_MASK_REG)
#define MAX7219_GetI2CExtClkInterruptSourceMasked()          (MAX7219_INTR_I2C_EC_MASKED_REG)

#if (!MAX7219_CY_SCBIP_V1)
    /* APIs to service INTR_SPI_EC register */
    #define MAX7219_SetSpiExtClkInterruptMode(interruptMask) \
                                                                MAX7219_WRITE_INTR_SPI_EC_MASK(interruptMask)
    #define MAX7219_ClearSpiExtClkInterruptSource(interruptMask) \
                                                                MAX7219_CLEAR_INTR_SPI_EC(interruptMask)
    #define MAX7219_GetExtSpiClkInterruptSource()                 (MAX7219_INTR_SPI_EC_REG)
    #define MAX7219_GetExtSpiClkInterruptMode()                   (MAX7219_INTR_SPI_EC_MASK_REG)
    #define MAX7219_GetExtSpiClkInterruptSourceMasked()           (MAX7219_INTR_SPI_EC_MASKED_REG)
#endif /* (!MAX7219_CY_SCBIP_V1) */

#if(MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void MAX7219_SetPins(uint32 mode, uint32 subMode, uint32 uartEnableMask);
#endif /* (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG) */


/***************************************
*     Vars with External Linkage
***************************************/

#if (MAX7219_SCB_IRQ_INTERNAL)
#if !defined (CY_REMOVE_MAX7219_CUSTOM_INTR_HANDLER)
    extern cyisraddress MAX7219_customIntrHandler;
#endif /* !defined (CY_REMOVE_MAX7219_CUSTOM_INTR_HANDLER) */
#endif /* (MAX7219_SCB_IRQ_INTERNAL) */

extern MAX7219_BACKUP_STRUCT MAX7219_backup;

#if(MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common configuration variables */
    extern uint8 MAX7219_scbMode;
    extern uint8 MAX7219_scbEnableWake;
    extern uint8 MAX7219_scbEnableIntr;

    /* I2C configuration variables */
    extern uint8 MAX7219_mode;
    extern uint8 MAX7219_acceptAddr;

    /* SPI/UART configuration variables */
    extern volatile uint8 * MAX7219_rxBuffer;
    extern uint8   MAX7219_rxDataBits;
    extern uint32  MAX7219_rxBufferSize;

    extern volatile uint8 * MAX7219_txBuffer;
    extern uint8   MAX7219_txDataBits;
    extern uint32  MAX7219_txBufferSize;

    /* EZI2C configuration variables */
    extern uint8 MAX7219_numberOfAddr;
    extern uint8 MAX7219_subAddrSize;
#endif /* (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG) */

#if (! (MAX7219_SCB_MODE_I2C_CONST_CFG || \
        MAX7219_SCB_MODE_EZI2C_CONST_CFG))
    extern uint16 MAX7219_IntrTxMask;
#endif /* (! (MAX7219_SCB_MODE_I2C_CONST_CFG || \
              MAX7219_SCB_MODE_EZI2C_CONST_CFG)) */


/***************************************
*        Conditional Macro
****************************************/

#if(MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Defines run time operation mode */
    #define MAX7219_SCB_MODE_I2C_RUNTM_CFG     (MAX7219_SCB_MODE_I2C      == MAX7219_scbMode)
    #define MAX7219_SCB_MODE_SPI_RUNTM_CFG     (MAX7219_SCB_MODE_SPI      == MAX7219_scbMode)
    #define MAX7219_SCB_MODE_UART_RUNTM_CFG    (MAX7219_SCB_MODE_UART     == MAX7219_scbMode)
    #define MAX7219_SCB_MODE_EZI2C_RUNTM_CFG   (MAX7219_SCB_MODE_EZI2C    == MAX7219_scbMode)
    #define MAX7219_SCB_MODE_UNCONFIG_RUNTM_CFG \
                                                        (MAX7219_SCB_MODE_UNCONFIG == MAX7219_scbMode)

    /* Defines wakeup enable */
    #define MAX7219_SCB_WAKE_ENABLE_CHECK       (0u != MAX7219_scbEnableWake)
#endif /* (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG) */

/* Defines maximum number of SCB pins */
#if (!MAX7219_CY_SCBIP_V1)
    #define MAX7219_SCB_PINS_NUMBER    (7u)
#else
    #define MAX7219_SCB_PINS_NUMBER    (2u)
#endif /* (!MAX7219_CY_SCBIP_V1) */

#endif /* (CY_SCB_PVT_MAX7219_H) */


/* [] END OF FILE */
