/***************************************************************************//**
* \file MAX7219_SPI.c
* \version 4.0
*
* \brief
*  This file provides the source code to the API for the SCB Component in
*  SPI mode.
*
* Note:
*
*******************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "MAX7219_PVT.h"
#include "MAX7219_SPI_UART_PVT.h"

#if(MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Configuration Structure Initialization
    ***************************************/

    const MAX7219_SPI_INIT_STRUCT MAX7219_configSpi =
    {
        MAX7219_SPI_MODE,
        MAX7219_SPI_SUB_MODE,
        MAX7219_SPI_CLOCK_MODE,
        MAX7219_SPI_OVS_FACTOR,
        MAX7219_SPI_MEDIAN_FILTER_ENABLE,
        MAX7219_SPI_LATE_MISO_SAMPLE_ENABLE,
        MAX7219_SPI_WAKE_ENABLE,
        MAX7219_SPI_RX_DATA_BITS_NUM,
        MAX7219_SPI_TX_DATA_BITS_NUM,
        MAX7219_SPI_BITS_ORDER,
        MAX7219_SPI_TRANSFER_SEPARATION,
        0u,
        NULL,
        0u,
        NULL,
        (uint32) MAX7219_SCB_IRQ_INTERNAL,
        MAX7219_SPI_INTR_RX_MASK,
        MAX7219_SPI_RX_TRIGGER_LEVEL,
        MAX7219_SPI_INTR_TX_MASK,
        MAX7219_SPI_TX_TRIGGER_LEVEL,
        (uint8) MAX7219_SPI_BYTE_MODE_ENABLE,
        (uint8) MAX7219_SPI_FREE_RUN_SCLK_ENABLE,
        (uint8) MAX7219_SPI_SS_POLARITY
    };


    /*******************************************************************************
    * Function Name: MAX7219_SpiInit
    ****************************************************************************//**
    *
    *  Configures the MAX7219 for SPI operation.
    *
    *  This function is intended specifically to be used when the MAX7219 
    *  configuration is set to “Unconfigured MAX7219” in the customizer. 
    *  After initializing the MAX7219 in SPI mode using this function, 
    *  the component can be enabled using the MAX7219_Start() or 
    * MAX7219_Enable() function.
    *  This function uses a pointer to a structure that provides the configuration 
    *  settings. This structure contains the same information that would otherwise 
    *  be provided by the customizer settings.
    *
    *  \param config: pointer to a structure that contains the following list of 
    *   fields. These fields match the selections available in the customizer. 
    *   Refer to the customizer for further description of the settings.
    *
    *******************************************************************************/
    void MAX7219_SpiInit(const MAX7219_SPI_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due to bad function parameter */
        }
        else
        {
            /* Configure pins */
            MAX7219_SetPins(MAX7219_SCB_MODE_SPI, config->mode, MAX7219_DUMMY_PARAM);

            /* Store internal configuration */
            MAX7219_scbMode       = (uint8) MAX7219_SCB_MODE_SPI;
            MAX7219_scbEnableWake = (uint8) config->enableWake;
            MAX7219_scbEnableIntr = (uint8) config->enableInterrupt;

            /* Set RX direction internal variables */
            MAX7219_rxBuffer      =         config->rxBuffer;
            MAX7219_rxDataBits    = (uint8) config->rxDataBits;
            MAX7219_rxBufferSize  =         config->rxBufferSize;

            /* Set TX direction internal variables */
            MAX7219_txBuffer      =         config->txBuffer;
            MAX7219_txDataBits    = (uint8) config->txDataBits;
            MAX7219_txBufferSize  =         config->txBufferSize;

            /* Configure SPI interface */
            MAX7219_CTRL_REG     = MAX7219_GET_CTRL_OVS(config->oversample)           |
                                            MAX7219_GET_CTRL_BYTE_MODE(config->enableByteMode) |
                                            MAX7219_GET_CTRL_EC_AM_MODE(config->enableWake)    |
                                            MAX7219_CTRL_SPI;

            MAX7219_SPI_CTRL_REG = MAX7219_GET_SPI_CTRL_CONTINUOUS    (config->transferSeperation)  |
                                            MAX7219_GET_SPI_CTRL_SELECT_PRECEDE(config->submode &
                                                                          MAX7219_SPI_MODE_TI_PRECEDES_MASK) |
                                            MAX7219_GET_SPI_CTRL_SCLK_MODE     (config->sclkMode)            |
                                            MAX7219_GET_SPI_CTRL_LATE_MISO_SAMPLE(config->enableLateSampling)|
                                            MAX7219_GET_SPI_CTRL_SCLK_CONTINUOUS(config->enableFreeRunSclk)  |
                                            MAX7219_GET_SPI_CTRL_SSEL_POLARITY (config->polaritySs)          |
                                            MAX7219_GET_SPI_CTRL_SUB_MODE      (config->submode)             |
                                            MAX7219_GET_SPI_CTRL_MASTER_MODE   (config->mode);

            /* Configure RX direction */
            MAX7219_RX_CTRL_REG     =  MAX7219_GET_RX_CTRL_DATA_WIDTH(config->rxDataBits)         |
                                                MAX7219_GET_RX_CTRL_BIT_ORDER (config->bitOrder)           |
                                                MAX7219_GET_RX_CTRL_MEDIAN    (config->enableMedianFilter) |
                                                MAX7219_SPI_RX_CTRL;

            MAX7219_RX_FIFO_CTRL_REG = MAX7219_GET_RX_FIFO_CTRL_TRIGGER_LEVEL(config->rxTriggerLevel);

            /* Configure TX direction */
            MAX7219_TX_CTRL_REG      = MAX7219_GET_TX_CTRL_DATA_WIDTH(config->txDataBits) |
                                                MAX7219_GET_TX_CTRL_BIT_ORDER (config->bitOrder)   |
                                                MAX7219_SPI_TX_CTRL;

            MAX7219_TX_FIFO_CTRL_REG = MAX7219_GET_TX_FIFO_CTRL_TRIGGER_LEVEL(config->txTriggerLevel);

            /* Configure interrupt with SPI handler but do not enable it */
            CyIntDisable    (MAX7219_ISR_NUMBER);
            CyIntSetPriority(MAX7219_ISR_NUMBER, MAX7219_ISR_PRIORITY);
            (void) CyIntSetVector(MAX7219_ISR_NUMBER, &MAX7219_SPI_UART_ISR);

            /* Configure interrupt sources */
            MAX7219_INTR_I2C_EC_MASK_REG = MAX7219_NO_INTR_SOURCES;
            MAX7219_INTR_SPI_EC_MASK_REG = MAX7219_NO_INTR_SOURCES;
            MAX7219_INTR_SLAVE_MASK_REG  = MAX7219_GET_SPI_INTR_SLAVE_MASK(config->rxInterruptMask);
            MAX7219_INTR_MASTER_MASK_REG = MAX7219_GET_SPI_INTR_MASTER_MASK(config->txInterruptMask);
            MAX7219_INTR_RX_MASK_REG     = MAX7219_GET_SPI_INTR_RX_MASK(config->rxInterruptMask);
            MAX7219_INTR_TX_MASK_REG     = MAX7219_GET_SPI_INTR_TX_MASK(config->txInterruptMask);
            
            /* Configure TX interrupt sources to restore. */
            MAX7219_IntrTxMask = LO16(MAX7219_INTR_TX_MASK_REG);

            /* Set active SS0 */
            MAX7219_SpiSetActiveSlaveSelect(MAX7219_SPI_SLAVE_SELECT0);

            /* Clear RX buffer indexes */
            MAX7219_rxBufferHead     = 0u;
            MAX7219_rxBufferTail     = 0u;
            MAX7219_rxBufferOverflow = 0u;

            /* Clear TX buffer indexes */
            MAX7219_txBufferHead = 0u;
            MAX7219_txBufferTail = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: MAX7219_SpiInit
    ****************************************************************************//**
    *
    *  Configures the SCB for the SPI operation.
    *
    *******************************************************************************/
    void MAX7219_SpiInit(void)
    {
        /* Configure SPI interface */
        MAX7219_CTRL_REG     = MAX7219_SPI_DEFAULT_CTRL;
        MAX7219_SPI_CTRL_REG = MAX7219_SPI_DEFAULT_SPI_CTRL;

        /* Configure TX and RX direction */
        MAX7219_RX_CTRL_REG      = MAX7219_SPI_DEFAULT_RX_CTRL;
        MAX7219_RX_FIFO_CTRL_REG = MAX7219_SPI_DEFAULT_RX_FIFO_CTRL;

        /* Configure TX and RX direction */
        MAX7219_TX_CTRL_REG      = MAX7219_SPI_DEFAULT_TX_CTRL;
        MAX7219_TX_FIFO_CTRL_REG = MAX7219_SPI_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with SPI handler but do not enable it */
    #if(MAX7219_SCB_IRQ_INTERNAL)
            CyIntDisable    (MAX7219_ISR_NUMBER);
            CyIntSetPriority(MAX7219_ISR_NUMBER, MAX7219_ISR_PRIORITY);
            (void) CyIntSetVector(MAX7219_ISR_NUMBER, &MAX7219_SPI_UART_ISR);
    #endif /* (MAX7219_SCB_IRQ_INTERNAL) */

        /* Configure interrupt sources */
        MAX7219_INTR_I2C_EC_MASK_REG = MAX7219_SPI_DEFAULT_INTR_I2C_EC_MASK;
        MAX7219_INTR_SPI_EC_MASK_REG = MAX7219_SPI_DEFAULT_INTR_SPI_EC_MASK;
        MAX7219_INTR_SLAVE_MASK_REG  = MAX7219_SPI_DEFAULT_INTR_SLAVE_MASK;
        MAX7219_INTR_MASTER_MASK_REG = MAX7219_SPI_DEFAULT_INTR_MASTER_MASK;
        MAX7219_INTR_RX_MASK_REG     = MAX7219_SPI_DEFAULT_INTR_RX_MASK;
        MAX7219_INTR_TX_MASK_REG     = MAX7219_SPI_DEFAULT_INTR_TX_MASK;

        /* Configure TX interrupt sources to restore. */
        MAX7219_IntrTxMask = LO16(MAX7219_INTR_TX_MASK_REG);
            
        /* Set active SS0 for master */
    #if (MAX7219_SPI_MASTER_CONST)
        MAX7219_SpiSetActiveSlaveSelect(MAX7219_SPI_SLAVE_SELECT0);
    #endif /* (MAX7219_SPI_MASTER_CONST) */

    #if(MAX7219_INTERNAL_RX_SW_BUFFER_CONST)
        MAX7219_rxBufferHead     = 0u;
        MAX7219_rxBufferTail     = 0u;
        MAX7219_rxBufferOverflow = 0u;
    #endif /* (MAX7219_INTERNAL_RX_SW_BUFFER_CONST) */

    #if(MAX7219_INTERNAL_TX_SW_BUFFER_CONST)
        MAX7219_txBufferHead = 0u;
        MAX7219_txBufferTail = 0u;
    #endif /* (MAX7219_INTERNAL_TX_SW_BUFFER_CONST) */
    }
#endif /* (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: MAX7219_SpiPostEnable
****************************************************************************//**
*
*  Restores HSIOM settings for the SPI master output pins (SCLK and/or SS0-SS3) 
*  to be controlled by the SCB SPI.
*
*******************************************************************************/
void MAX7219_SpiPostEnable(void)
{
#if(MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)

    if (MAX7219_CHECK_SPI_MASTER)
    {
    #if (MAX7219_CTS_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_CTS_SCLK_HSIOM_REG, MAX7219_CTS_SCLK_HSIOM_MASK,
                                       MAX7219_CTS_SCLK_HSIOM_POS, MAX7219_CTS_SCLK_HSIOM_SEL_SPI);
    #endif /* (MAX7219_CTS_SCLK_PIN) */

    #if (MAX7219_RTS_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_RTS_SS0_HSIOM_REG, MAX7219_RTS_SS0_HSIOM_MASK,
                                       MAX7219_RTS_SS0_HSIOM_POS, MAX7219_RTS_SS0_HSIOM_SEL_SPI);
    #endif /* (MAX7219_RTS_SS0_PIN) */

    #if (MAX7219_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS1_HSIOM_REG, MAX7219_SS1_HSIOM_MASK,
                                       MAX7219_SS1_HSIOM_POS, MAX7219_SS1_HSIOM_SEL_SPI);
    #endif /* (MAX7219_SS1_PIN) */

    #if (MAX7219_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS2_HSIOM_REG, MAX7219_SS2_HSIOM_MASK,
                                       MAX7219_SS2_HSIOM_POS, MAX7219_SS2_HSIOM_SEL_SPI);
    #endif /* (MAX7219_SS2_PIN) */

    #if (MAX7219_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS3_HSIOM_REG, MAX7219_SS3_HSIOM_MASK,
                                       MAX7219_SS3_HSIOM_POS, MAX7219_SS3_HSIOM_SEL_SPI);
    #endif /* (MAX7219_SS3_PIN) */
    }

#else

    #if (MAX7219_SPI_MASTER_SCLK_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SCLK_M_HSIOM_REG, MAX7219_SCLK_M_HSIOM_MASK,
                                       MAX7219_SCLK_M_HSIOM_POS, MAX7219_SCLK_M_HSIOM_SEL_SPI);
    #endif /* (MAX7219_MISO_SDA_TX_PIN_PIN) */

    #if (MAX7219_SPI_MASTER_SS0_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS0_M_HSIOM_REG, MAX7219_SS0_M_HSIOM_MASK,
                                       MAX7219_SS0_M_HSIOM_POS, MAX7219_SS0_M_HSIOM_SEL_SPI);
    #endif /* (MAX7219_SPI_MASTER_SS0_PIN) */

    #if (MAX7219_SPI_MASTER_SS1_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS1_M_HSIOM_REG, MAX7219_SS1_M_HSIOM_MASK,
                                       MAX7219_SS1_M_HSIOM_POS, MAX7219_SS1_M_HSIOM_SEL_SPI);
    #endif /* (MAX7219_SPI_MASTER_SS1_PIN) */

    #if (MAX7219_SPI_MASTER_SS2_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS2_M_HSIOM_REG, MAX7219_SS2_M_HSIOM_MASK,
                                       MAX7219_SS2_M_HSIOM_POS, MAX7219_SS2_M_HSIOM_SEL_SPI);
    #endif /* (MAX7219_SPI_MASTER_SS2_PIN) */

    #if (MAX7219_SPI_MASTER_SS3_PIN)
        /* Set SCB SPI to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS3_M_HSIOM_REG, MAX7219_SS3_M_HSIOM_MASK,
                                       MAX7219_SS3_M_HSIOM_POS, MAX7219_SS3_M_HSIOM_SEL_SPI);
    #endif /* (MAX7219_SPI_MASTER_SS3_PIN) */

#endif /* (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG) */

    /* Restore TX interrupt sources. */
    MAX7219_SetTxInterruptMode(MAX7219_IntrTxMask);
}


/*******************************************************************************
* Function Name: MAX7219_SpiStop
****************************************************************************//**
*
*  Changes the HSIOM settings for the SPI master output pins 
*  (SCLK and/or SS0-SS3) to keep them inactive after the block is disabled. 
*  The output pins are controlled by the GPIO data register.
*
*******************************************************************************/
void MAX7219_SpiStop(void)
{
#if(MAX7219_SCB_MODE_UNCONFIG_CONST_CFG)

    if (MAX7219_CHECK_SPI_MASTER)
    {
    #if (MAX7219_CTS_SCLK_PIN)
        /* Set output pin state after block is disabled */
        MAX7219_uart_cts_spi_sclk_Write(MAX7219_GET_SPI_SCLK_INACTIVE);

        /* Set GPIO to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_CTS_SCLK_HSIOM_REG, MAX7219_CTS_SCLK_HSIOM_MASK,
                                       MAX7219_CTS_SCLK_HSIOM_POS, MAX7219_CTS_SCLK_HSIOM_SEL_GPIO);
    #endif /* (MAX7219_uart_cts_spi_sclk_PIN) */

    #if (MAX7219_RTS_SS0_PIN)
        /* Set output pin state after block is disabled */
        MAX7219_uart_rts_spi_ss0_Write(MAX7219_GET_SPI_SS0_INACTIVE);

        /* Set GPIO to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_RTS_SS0_HSIOM_REG, MAX7219_RTS_SS0_HSIOM_MASK,
                                       MAX7219_RTS_SS0_HSIOM_POS, MAX7219_RTS_SS0_HSIOM_SEL_GPIO);
    #endif /* (MAX7219_uart_rts_spi_ss0_PIN) */

    #if (MAX7219_SS1_PIN)
        /* Set output pin state after block is disabled */
        MAX7219_spi_ss1_Write(MAX7219_GET_SPI_SS1_INACTIVE);

        /* Set GPIO to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS1_HSIOM_REG, MAX7219_SS1_HSIOM_MASK,
                                       MAX7219_SS1_HSIOM_POS, MAX7219_SS1_HSIOM_SEL_GPIO);
    #endif /* (MAX7219_SS1_PIN) */

    #if (MAX7219_SS2_PIN)
        /* Set output pin state after block is disabled */
        MAX7219_spi_ss2_Write(MAX7219_GET_SPI_SS2_INACTIVE);

        /* Set GPIO to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS2_HSIOM_REG, MAX7219_SS2_HSIOM_MASK,
                                       MAX7219_SS2_HSIOM_POS, MAX7219_SS2_HSIOM_SEL_GPIO);
    #endif /* (MAX7219_SS2_PIN) */

    #if (MAX7219_SS3_PIN)
        /* Set output pin state after block is disabled */
        MAX7219_spi_ss3_Write(MAX7219_GET_SPI_SS3_INACTIVE);

        /* Set GPIO to drive output pin */
        MAX7219_SET_HSIOM_SEL(MAX7219_SS3_HSIOM_REG, MAX7219_SS3_HSIOM_MASK,
                                       MAX7219_SS3_HSIOM_POS, MAX7219_SS3_HSIOM_SEL_GPIO);
    #endif /* (MAX7219_SS3_PIN) */
    
        /* Store TX interrupt sources (exclude level triggered) for master. */
        MAX7219_IntrTxMask = LO16(MAX7219_GetTxInterruptMode() & MAX7219_INTR_SPIM_TX_RESTORE);
    }
    else
    {
        /* Store TX interrupt sources (exclude level triggered) for slave. */
        MAX7219_IntrTxMask = LO16(MAX7219_GetTxInterruptMode() & MAX7219_INTR_SPIS_TX_RESTORE);
    }

#else

#if (MAX7219_SPI_MASTER_SCLK_PIN)
    /* Set output pin state after block is disabled */
    MAX7219_sclk_m_Write(MAX7219_GET_SPI_SCLK_INACTIVE);

    /* Set GPIO to drive output pin */
    MAX7219_SET_HSIOM_SEL(MAX7219_SCLK_M_HSIOM_REG, MAX7219_SCLK_M_HSIOM_MASK,
                                   MAX7219_SCLK_M_HSIOM_POS, MAX7219_SCLK_M_HSIOM_SEL_GPIO);
#endif /* (MAX7219_MISO_SDA_TX_PIN_PIN) */

#if (MAX7219_SPI_MASTER_SS0_PIN)
    /* Set output pin state after block is disabled */
    MAX7219_ss0_m_Write(MAX7219_GET_SPI_SS0_INACTIVE);

    /* Set GPIO to drive output pin */
    MAX7219_SET_HSIOM_SEL(MAX7219_SS0_M_HSIOM_REG, MAX7219_SS0_M_HSIOM_MASK,
                                   MAX7219_SS0_M_HSIOM_POS, MAX7219_SS0_M_HSIOM_SEL_GPIO);
#endif /* (MAX7219_SPI_MASTER_SS0_PIN) */

#if (MAX7219_SPI_MASTER_SS1_PIN)
    /* Set output pin state after block is disabled */
    MAX7219_ss1_m_Write(MAX7219_GET_SPI_SS1_INACTIVE);

    /* Set GPIO to drive output pin */
    MAX7219_SET_HSIOM_SEL(MAX7219_SS1_M_HSIOM_REG, MAX7219_SS1_M_HSIOM_MASK,
                                   MAX7219_SS1_M_HSIOM_POS, MAX7219_SS1_M_HSIOM_SEL_GPIO);
#endif /* (MAX7219_SPI_MASTER_SS1_PIN) */

#if (MAX7219_SPI_MASTER_SS2_PIN)
    /* Set output pin state after block is disabled */
    MAX7219_ss2_m_Write(MAX7219_GET_SPI_SS2_INACTIVE);

    /* Set GPIO to drive output pin */
    MAX7219_SET_HSIOM_SEL(MAX7219_SS2_M_HSIOM_REG, MAX7219_SS2_M_HSIOM_MASK,
                                   MAX7219_SS2_M_HSIOM_POS, MAX7219_SS2_M_HSIOM_SEL_GPIO);
#endif /* (MAX7219_SPI_MASTER_SS2_PIN) */

#if (MAX7219_SPI_MASTER_SS3_PIN)
    /* Set output pin state after block is disabled */
    MAX7219_ss3_m_Write(MAX7219_GET_SPI_SS3_INACTIVE);

    /* Set GPIO to drive output pin */
    MAX7219_SET_HSIOM_SEL(MAX7219_SS3_M_HSIOM_REG, MAX7219_SS3_M_HSIOM_MASK,
                                   MAX7219_SS3_M_HSIOM_POS, MAX7219_SS3_M_HSIOM_SEL_GPIO);
#endif /* (MAX7219_SPI_MASTER_SS3_PIN) */

    #if (MAX7219_SPI_MASTER_CONST)
        /* Store TX interrupt sources (exclude level triggered). */
        MAX7219_IntrTxMask = LO16(MAX7219_GetTxInterruptMode() & MAX7219_INTR_SPIM_TX_RESTORE);
    #else
        /* Store TX interrupt sources (exclude level triggered). */
        MAX7219_IntrTxMask = LO16(MAX7219_GetTxInterruptMode() & MAX7219_INTR_SPIS_TX_RESTORE);
    #endif /* (MAX7219_SPI_MASTER_CONST) */

#endif /* (MAX7219_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if (MAX7219_SPI_MASTER_CONST)
    /*******************************************************************************
    * Function Name: MAX7219_SetActiveSlaveSelect
    ****************************************************************************//**
    *
    *  Selects one of the four slave select lines to be active during the transfer.
    *  After initialization the active slave select line is 0.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer (TX FIFO is empty and the
    *     SCB_INTR_MASTER_SPI_DONE status is set).
    *
    *  This function does not check that these conditions are met.
    *  This function is only applicable to SPI Master mode of operation.
    *
    *  \param slaveSelect: slave select line which will be active while the following
    *   transfer.
    *   - MAX7219_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - MAX7219_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - MAX7219_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - MAX7219_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *******************************************************************************/
    void MAX7219_SpiSetActiveSlaveSelect(uint32 slaveSelect)
    {
        uint32 spiCtrl;

        spiCtrl = MAX7219_SPI_CTRL_REG;

        spiCtrl &= (uint32) ~MAX7219_SPI_CTRL_SLAVE_SELECT_MASK;
        spiCtrl |= (uint32)  MAX7219_GET_SPI_CTRL_SS(slaveSelect);

        MAX7219_SPI_CTRL_REG = spiCtrl;
    }
#endif /* (MAX7219_SPI_MASTER_CONST) */


#if !(MAX7219_CY_SCBIP_V0 || MAX7219_CY_SCBIP_V1)
    /*******************************************************************************
    * Function Name: MAX7219_SpiSetSlaveSelectPolarity
    ****************************************************************************//**
    *
    *  Sets active polarity for slave select line.
    *  The component should be in one of the following states to change the active
    *  slave select signal source correctly:
    *   - The component is disabled.
    *   - The component has completed transfer.
    *  
    *  This function does not check that these conditions are met.
    *
    *  \param slaveSelect: slave select line to change active polarity.
    *   - MAX7219_SPI_SLAVE_SELECT0 - Slave select 0.
    *   - MAX7219_SPI_SLAVE_SELECT1 - Slave select 1.
    *   - MAX7219_SPI_SLAVE_SELECT2 - Slave select 2.
    *   - MAX7219_SPI_SLAVE_SELECT3 - Slave select 3.
    *
    *  \param polarity: active polarity of slave select line.
    *   - MAX7219_SPI_SS_ACTIVE_LOW  - Slave select is active low.
    *   - MAX7219_SPI_SS_ACTIVE_HIGH - Slave select is active high.
    *
    *******************************************************************************/
    void MAX7219_SpiSetSlaveSelectPolarity(uint32 slaveSelect, uint32 polarity)
    {
        uint32 ssPolarity;

        /* Get position of the polarity bit associated with slave select line */
        ssPolarity = MAX7219_GET_SPI_CTRL_SSEL_POLARITY((uint32) 1u << slaveSelect);

        if (0u != polarity)
        {
            MAX7219_SPI_CTRL_REG |= (uint32)  ssPolarity;
        }
        else
        {
            MAX7219_SPI_CTRL_REG &= (uint32) ~ssPolarity;
        }
    }
#endif /* !(MAX7219_CY_SCBIP_V0 || MAX7219_CY_SCBIP_V1) */


#if(MAX7219_SPI_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: MAX7219_SpiSaveConfig
    ****************************************************************************//**
    *
    *  Clears INTR_SPI_EC.WAKE_UP and enables it. This interrupt
    *  source triggers when the master assigns the SS line and wakes up the device.
    *
    *******************************************************************************/
    void MAX7219_SpiSaveConfig(void)
    {
        /* Clear and enable SPI wakeup interrupt source */
        MAX7219_ClearSpiExtClkInterruptSource(MAX7219_INTR_SPI_EC_WAKE_UP);
        MAX7219_SetSpiExtClkInterruptMode(MAX7219_INTR_SPI_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: MAX7219_SpiRestoreConfig
    ****************************************************************************//**
    *
    *  Disables the INTR_SPI_EC.WAKE_UP interrupt source. After wakeup
    *  slave does not drive the MISO line and the master receives 0xFF.
    *
    *******************************************************************************/
    void MAX7219_SpiRestoreConfig(void)
    {
        /* Disable SPI wakeup interrupt source */
        MAX7219_SetSpiExtClkInterruptMode(MAX7219_NO_INTR_SOURCES);
    }
#endif /* (MAX7219_SPI_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
