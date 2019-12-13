/***************************************************************************//**
* \file MAX7219_SPI_BOOT.c
* \version 4.0
*
* \brief
*  This file provides the source code of the bootloader communication APIs
*  for the SCB Component SPI mode.
*
* Note:
*
********************************************************************************
* \copyright
* Copyright 2013-2017, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "MAX7219_BOOT.h"
#include "MAX7219_SPI_UART.h"

#if defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_SPI_BTLDR_COMM_ENABLED)

/*******************************************************************************
* Function Name: MAX7219_SpiCyBtldrCommStart
****************************************************************************//**
*
*  Starts the SPI component.
*
*******************************************************************************/
void MAX7219_SpiCyBtldrCommStart(void)
{
    MAX7219_Start();
}


/*******************************************************************************
* Function Name: MAX7219_SpiCyBtldrCommStop
****************************************************************************//**
*
*  Disables the SPI component.
*
*******************************************************************************/
void MAX7219_SpiCyBtldrCommStop(void)
{
    MAX7219_Stop();
}


/*******************************************************************************
* Function Name: MAX7219_SpiCyBtldrCommReset
****************************************************************************//**
*
*  Resets the receive and transmit communication buffers.
*
*******************************************************************************/
void MAX7219_SpiCyBtldrCommReset(void)
{
    /* Clear RX and TX buffers */
    MAX7219_SpiUartClearRxBuffer();
    MAX7219_SpiUartClearTxBuffer();
}


/*******************************************************************************
* Function Name: MAX7219_SpiCyBtldrCommRead
****************************************************************************//**
*
*  Allows the caller to read data from the bootloader host (the host writes the
*  data). The function handles polling to allow a block of data to be completely
*  received from the host device.
*
*  \param pData: Pointer to storage for the block of data to be read from the
*   bootloader host
*  \param size: Number of bytes to be read.
*  \param count: Pointer to the variable to write the number of bytes actually
*   read.
*  \param timeOut: Number of units in 10 ms to wait before returning
*   because of a timeout.
*
* \return
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem. For more information refer to the
*  "Return Codes" section of the System Reference Guide.
*
*******************************************************************************/
cystatus MAX7219_SpiCyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 byteCount;
    uint32 timeoutMs;
    uint32 i;

    status = CYRET_BAD_PARAM;

    if ((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS check to 1mS checks */

        /* Wait with timeout 1mS for packet start */
        byteCount = 0u;
        do
        {
            /* Check packet start */
            if (0u != MAX7219_SpiUartGetRxBufferSize())
            {
                /* Wait for packet end */
                do
                {
                    byteCount = MAX7219_SpiUartGetRxBufferSize();
                    CyDelayUs(MAX7219_SPI_BYTE_TO_BYTE);
                }
                while (byteCount != MAX7219_SpiUartGetRxBufferSize());

                /* Disable data reception into RX FIFO */
                MAX7219_RX_FIFO_CTRL_REG |= MAX7219_RX_FIFO_CTRL_FREEZE;

                byteCount = MAX7219_BYTES_TO_COPY(byteCount, size);
                *count = (uint16) byteCount;
                status = CYRET_SUCCESS;

                break;
            }

            CyDelay(MAX7219_WAIT_1_MS);
            --timeoutMs;
        }
        while (0u != timeoutMs);

        /* Get data from the RX buffer into bootloader buffer */
        for (i = 0u; i < byteCount; ++i)
        {
            pData[i] = (uint8) MAX7219_SpiUartReadRxData();
        }
    }

    return (status);
}


/*******************************************************************************
* Function Name: MAX7219_SpiCyBtldrCommWrite
****************************************************************************//**
*
*  Allows the caller to read data from the bootloader host (the host writes the
*  data). The function handles polling to allow a block of data to be completely
*  received from the host device.
*
*  \param pData: Pointer to the block of data to be written to the bootloader
*   host.
*  \param size: Number of bytes to be written.
*  \param count: Pointer to the variable to write the number of bytes actually
*   written.
*  \param timeOut: Number of units in 10 ms to wait before returning
*   because of a timeout.
*
*  \return
*   Returns CYRET_SUCCESS if no problem was encountered or returns the value
*   that best describes the problem. For more information refer to the
*   "Return Codes" section of the System Reference Guide.
*
*******************************************************************************/
cystatus MAX7219_SpiCyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;
    uint32 timeoutMs;

    status = CYRET_BAD_PARAM;

    if ((NULL != pData) && (size > 0u))
    {
        status = CYRET_TIMEOUT;
        timeoutMs = ((uint32) 10u * timeOut); /* Convert from 10mS check to 1mS checks */

        /* Put data into TX buffer */
        MAX7219_SpiUartPutArray(pData, (uint32) size);

        /* Wait with timeout 1mS for packet end */
        do
        {
            /* Check for packet end */
            if ((0u == MAX7219_SpiUartGetTxBufferSize()) &&
                (0u == (MAX7219_SPI_STATUS_REG & MAX7219_SPI_STATUS_BUS_BUSY)) &&
                (0u == (MAX7219_TX_FIFO_STATUS_REG & MAX7219_TX_FIFO_SR_VALID)))
            {
                *count = size;
                status = CYRET_SUCCESS;

                break;
            }

            CyDelay(MAX7219_WAIT_1_MS);
            --timeoutMs;
        }
        while (0u != timeoutMs);

        /* Enable data reception into RX FIFO */
        MAX7219_SpiUartClearRxBuffer();
        MAX7219_RX_FIFO_CTRL_REG &= (uint32) ~MAX7219_RX_FIFO_CTRL_FREEZE;
    }

    return (status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && (MAX7219_SPI_BTLDR_COMM_ENABLED) */


/* [] END OF FILE */
