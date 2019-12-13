/***************************************************************************//**
* \file MAX7219_PINS.h
* \version 4.0
*
* \brief
*  This file provides constants and parameter values for the pin components
*  buried into SCB Component.
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

#if !defined(CY_SCB_PINS_MAX7219_H)
#define CY_SCB_PINS_MAX7219_H

#include "cydevice_trm.h"
#include "cyfitter.h"
#include "cytypes.h"


/***************************************
*   Conditional Compilation Parameters
****************************************/

/* Unconfigured pins */
#define MAX7219_REMOVE_RX_WAKE_SDA_MOSI_PIN  (1u)
#define MAX7219_REMOVE_RX_SDA_MOSI_PIN      (1u)
#define MAX7219_REMOVE_TX_SCL_MISO_PIN      (1u)
#define MAX7219_REMOVE_CTS_SCLK_PIN      (1u)
#define MAX7219_REMOVE_RTS_SS0_PIN      (1u)
#define MAX7219_REMOVE_SS1_PIN                 (1u)
#define MAX7219_REMOVE_SS2_PIN                 (1u)
#define MAX7219_REMOVE_SS3_PIN                 (1u)

/* Mode defined pins */
#define MAX7219_REMOVE_I2C_PINS                (1u)
#define MAX7219_REMOVE_SPI_MASTER_PINS         (0u)
#define MAX7219_REMOVE_SPI_MASTER_SCLK_PIN     (0u)
#define MAX7219_REMOVE_SPI_MASTER_MOSI_PIN     (0u)
#define MAX7219_REMOVE_SPI_MASTER_MISO_PIN     (0u)
#define MAX7219_REMOVE_SPI_MASTER_SS0_PIN      (1u)
#define MAX7219_REMOVE_SPI_MASTER_SS1_PIN      (1u)
#define MAX7219_REMOVE_SPI_MASTER_SS2_PIN      (1u)
#define MAX7219_REMOVE_SPI_MASTER_SS3_PIN      (1u)
#define MAX7219_REMOVE_SPI_SLAVE_PINS          (1u)
#define MAX7219_REMOVE_SPI_SLAVE_MOSI_PIN      (1u)
#define MAX7219_REMOVE_SPI_SLAVE_MISO_PIN      (1u)
#define MAX7219_REMOVE_UART_TX_PIN             (1u)
#define MAX7219_REMOVE_UART_RX_TX_PIN          (1u)
#define MAX7219_REMOVE_UART_RX_PIN             (1u)
#define MAX7219_REMOVE_UART_RX_WAKE_PIN        (1u)
#define MAX7219_REMOVE_UART_RTS_PIN            (1u)
#define MAX7219_REMOVE_UART_CTS_PIN            (1u)

/* Unconfigured pins */
#define MAX7219_RX_WAKE_SDA_MOSI_PIN (0u == MAX7219_REMOVE_RX_WAKE_SDA_MOSI_PIN)
#define MAX7219_RX_SDA_MOSI_PIN     (0u == MAX7219_REMOVE_RX_SDA_MOSI_PIN)
#define MAX7219_TX_SCL_MISO_PIN     (0u == MAX7219_REMOVE_TX_SCL_MISO_PIN)
#define MAX7219_CTS_SCLK_PIN     (0u == MAX7219_REMOVE_CTS_SCLK_PIN)
#define MAX7219_RTS_SS0_PIN     (0u == MAX7219_REMOVE_RTS_SS0_PIN)
#define MAX7219_SS1_PIN                (0u == MAX7219_REMOVE_SS1_PIN)
#define MAX7219_SS2_PIN                (0u == MAX7219_REMOVE_SS2_PIN)
#define MAX7219_SS3_PIN                (0u == MAX7219_REMOVE_SS3_PIN)

/* Mode defined pins */
#define MAX7219_I2C_PINS               (0u == MAX7219_REMOVE_I2C_PINS)
#define MAX7219_SPI_MASTER_PINS        (0u == MAX7219_REMOVE_SPI_MASTER_PINS)
#define MAX7219_SPI_MASTER_SCLK_PIN    (0u == MAX7219_REMOVE_SPI_MASTER_SCLK_PIN)
#define MAX7219_SPI_MASTER_MOSI_PIN    (0u == MAX7219_REMOVE_SPI_MASTER_MOSI_PIN)
#define MAX7219_SPI_MASTER_MISO_PIN    (0u == MAX7219_REMOVE_SPI_MASTER_MISO_PIN)
#define MAX7219_SPI_MASTER_SS0_PIN     (0u == MAX7219_REMOVE_SPI_MASTER_SS0_PIN)
#define MAX7219_SPI_MASTER_SS1_PIN     (0u == MAX7219_REMOVE_SPI_MASTER_SS1_PIN)
#define MAX7219_SPI_MASTER_SS2_PIN     (0u == MAX7219_REMOVE_SPI_MASTER_SS2_PIN)
#define MAX7219_SPI_MASTER_SS3_PIN     (0u == MAX7219_REMOVE_SPI_MASTER_SS3_PIN)
#define MAX7219_SPI_SLAVE_PINS         (0u == MAX7219_REMOVE_SPI_SLAVE_PINS)
#define MAX7219_SPI_SLAVE_MOSI_PIN     (0u == MAX7219_REMOVE_SPI_SLAVE_MOSI_PIN)
#define MAX7219_SPI_SLAVE_MISO_PIN     (0u == MAX7219_REMOVE_SPI_SLAVE_MISO_PIN)
#define MAX7219_UART_TX_PIN            (0u == MAX7219_REMOVE_UART_TX_PIN)
#define MAX7219_UART_RX_TX_PIN         (0u == MAX7219_REMOVE_UART_RX_TX_PIN)
#define MAX7219_UART_RX_PIN            (0u == MAX7219_REMOVE_UART_RX_PIN)
#define MAX7219_UART_RX_WAKE_PIN       (0u == MAX7219_REMOVE_UART_RX_WAKE_PIN)
#define MAX7219_UART_RTS_PIN           (0u == MAX7219_REMOVE_UART_RTS_PIN)
#define MAX7219_UART_CTS_PIN           (0u == MAX7219_REMOVE_UART_CTS_PIN)


/***************************************
*             Includes
****************************************/

#if (MAX7219_RX_WAKE_SDA_MOSI_PIN)
    #include "MAX7219_uart_rx_wake_i2c_sda_spi_mosi.h"
#endif /* (MAX7219_RX_SDA_MOSI) */

#if (MAX7219_RX_SDA_MOSI_PIN)
    #include "MAX7219_uart_rx_i2c_sda_spi_mosi.h"
#endif /* (MAX7219_RX_SDA_MOSI) */

#if (MAX7219_TX_SCL_MISO_PIN)
    #include "MAX7219_uart_tx_i2c_scl_spi_miso.h"
#endif /* (MAX7219_TX_SCL_MISO) */

#if (MAX7219_CTS_SCLK_PIN)
    #include "MAX7219_uart_cts_spi_sclk.h"
#endif /* (MAX7219_CTS_SCLK) */

#if (MAX7219_RTS_SS0_PIN)
    #include "MAX7219_uart_rts_spi_ss0.h"
#endif /* (MAX7219_RTS_SS0_PIN) */

#if (MAX7219_SS1_PIN)
    #include "MAX7219_spi_ss1.h"
#endif /* (MAX7219_SS1_PIN) */

#if (MAX7219_SS2_PIN)
    #include "MAX7219_spi_ss2.h"
#endif /* (MAX7219_SS2_PIN) */

#if (MAX7219_SS3_PIN)
    #include "MAX7219_spi_ss3.h"
#endif /* (MAX7219_SS3_PIN) */

#if (MAX7219_I2C_PINS)
    #include "MAX7219_scl.h"
    #include "MAX7219_sda.h"
#endif /* (MAX7219_I2C_PINS) */

#if (MAX7219_SPI_MASTER_PINS)
#if (MAX7219_SPI_MASTER_SCLK_PIN)
    #include "MAX7219_sclk_m.h"
#endif /* (MAX7219_SPI_MASTER_SCLK_PIN) */

#if (MAX7219_SPI_MASTER_MOSI_PIN)
    #include "MAX7219_mosi_m.h"
#endif /* (MAX7219_SPI_MASTER_MOSI_PIN) */

#if (MAX7219_SPI_MASTER_MISO_PIN)
    #include "MAX7219_miso_m.h"
#endif /*(MAX7219_SPI_MASTER_MISO_PIN) */
#endif /* (MAX7219_SPI_MASTER_PINS) */

#if (MAX7219_SPI_SLAVE_PINS)
    #include "MAX7219_sclk_s.h"
    #include "MAX7219_ss_s.h"

#if (MAX7219_SPI_SLAVE_MOSI_PIN)
    #include "MAX7219_mosi_s.h"
#endif /* (MAX7219_SPI_SLAVE_MOSI_PIN) */

#if (MAX7219_SPI_SLAVE_MISO_PIN)
    #include "MAX7219_miso_s.h"
#endif /*(MAX7219_SPI_SLAVE_MISO_PIN) */
#endif /* (MAX7219_SPI_SLAVE_PINS) */

#if (MAX7219_SPI_MASTER_SS0_PIN)
    #include "MAX7219_ss0_m.h"
#endif /* (MAX7219_SPI_MASTER_SS0_PIN) */

#if (MAX7219_SPI_MASTER_SS1_PIN)
    #include "MAX7219_ss1_m.h"
#endif /* (MAX7219_SPI_MASTER_SS1_PIN) */

#if (MAX7219_SPI_MASTER_SS2_PIN)
    #include "MAX7219_ss2_m.h"
#endif /* (MAX7219_SPI_MASTER_SS2_PIN) */

#if (MAX7219_SPI_MASTER_SS3_PIN)
    #include "MAX7219_ss3_m.h"
#endif /* (MAX7219_SPI_MASTER_SS3_PIN) */

#if (MAX7219_UART_TX_PIN)
    #include "MAX7219_tx.h"
#endif /* (MAX7219_UART_TX_PIN) */

#if (MAX7219_UART_RX_TX_PIN)
    #include "MAX7219_rx_tx.h"
#endif /* (MAX7219_UART_RX_TX_PIN) */

#if (MAX7219_UART_RX_PIN)
    #include "MAX7219_rx.h"
#endif /* (MAX7219_UART_RX_PIN) */

#if (MAX7219_UART_RX_WAKE_PIN)
    #include "MAX7219_rx_wake.h"
#endif /* (MAX7219_UART_RX_WAKE_PIN) */

#if (MAX7219_UART_RTS_PIN)
    #include "MAX7219_rts.h"
#endif /* (MAX7219_UART_RTS_PIN) */

#if (MAX7219_UART_CTS_PIN)
    #include "MAX7219_cts.h"
#endif /* (MAX7219_UART_CTS_PIN) */


/***************************************
*              Registers
***************************************/

#if (MAX7219_RX_SDA_MOSI_PIN)
    #define MAX7219_RX_SDA_MOSI_HSIOM_REG   (*(reg32 *) MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM)
    #define MAX7219_RX_SDA_MOSI_HSIOM_PTR   ( (reg32 *) MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM)
    
    #define MAX7219_RX_SDA_MOSI_HSIOM_MASK      (MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM_MASK)
    #define MAX7219_RX_SDA_MOSI_HSIOM_POS       (MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM_SHIFT)
    #define MAX7219_RX_SDA_MOSI_HSIOM_SEL_GPIO  (MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM_GPIO)
    #define MAX7219_RX_SDA_MOSI_HSIOM_SEL_I2C   (MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM_I2C)
    #define MAX7219_RX_SDA_MOSI_HSIOM_SEL_SPI   (MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM_SPI)
    #define MAX7219_RX_SDA_MOSI_HSIOM_SEL_UART  (MAX7219_uart_rx_i2c_sda_spi_mosi__0__HSIOM_UART)
    
#elif (MAX7219_RX_WAKE_SDA_MOSI_PIN)
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG   (*(reg32 *) MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM)
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_PTR   ( (reg32 *) MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM)
    
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_MASK      (MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_MASK)
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_POS       (MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_SHIFT)
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_SEL_GPIO  (MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_GPIO)
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_SEL_I2C   (MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_I2C)
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_SEL_SPI   (MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_SPI)
    #define MAX7219_RX_WAKE_SDA_MOSI_HSIOM_SEL_UART  (MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__HSIOM_UART)    
   
    #define MAX7219_RX_WAKE_SDA_MOSI_INTCFG_REG (*(reg32 *) MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__INTCFG)
    #define MAX7219_RX_WAKE_SDA_MOSI_INTCFG_PTR ( (reg32 *) MAX7219_uart_rx_wake_i2c_sda_spi_mosi__0__INTCFG)
    #define MAX7219_RX_WAKE_SDA_MOSI_INTCFG_TYPE_POS  (MAX7219_uart_rx_wake_i2c_sda_spi_mosi__SHIFT)
    #define MAX7219_RX_WAKE_SDA_MOSI_INTCFG_TYPE_MASK ((uint32) MAX7219_INTCFG_TYPE_MASK << \
                                                                           MAX7219_RX_WAKE_SDA_MOSI_INTCFG_TYPE_POS)
#else
    /* None of pins MAX7219_RX_SDA_MOSI_PIN or MAX7219_RX_WAKE_SDA_MOSI_PIN present.*/
#endif /* (MAX7219_RX_SDA_MOSI_PIN) */

#if (MAX7219_TX_SCL_MISO_PIN)
    #define MAX7219_TX_SCL_MISO_HSIOM_REG   (*(reg32 *) MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM)
    #define MAX7219_TX_SCL_MISO_HSIOM_PTR   ( (reg32 *) MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM)
    
    #define MAX7219_TX_SCL_MISO_HSIOM_MASK      (MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM_MASK)
    #define MAX7219_TX_SCL_MISO_HSIOM_POS       (MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM_SHIFT)
    #define MAX7219_TX_SCL_MISO_HSIOM_SEL_GPIO  (MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM_GPIO)
    #define MAX7219_TX_SCL_MISO_HSIOM_SEL_I2C   (MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM_I2C)
    #define MAX7219_TX_SCL_MISO_HSIOM_SEL_SPI   (MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM_SPI)
    #define MAX7219_TX_SCL_MISO_HSIOM_SEL_UART  (MAX7219_uart_tx_i2c_scl_spi_miso__0__HSIOM_UART)
#endif /* (MAX7219_TX_SCL_MISO_PIN) */

#if (MAX7219_CTS_SCLK_PIN)
    #define MAX7219_CTS_SCLK_HSIOM_REG   (*(reg32 *) MAX7219_uart_cts_spi_sclk__0__HSIOM)
    #define MAX7219_CTS_SCLK_HSIOM_PTR   ( (reg32 *) MAX7219_uart_cts_spi_sclk__0__HSIOM)
    
    #define MAX7219_CTS_SCLK_HSIOM_MASK      (MAX7219_uart_cts_spi_sclk__0__HSIOM_MASK)
    #define MAX7219_CTS_SCLK_HSIOM_POS       (MAX7219_uart_cts_spi_sclk__0__HSIOM_SHIFT)
    #define MAX7219_CTS_SCLK_HSIOM_SEL_GPIO  (MAX7219_uart_cts_spi_sclk__0__HSIOM_GPIO)
    #define MAX7219_CTS_SCLK_HSIOM_SEL_I2C   (MAX7219_uart_cts_spi_sclk__0__HSIOM_I2C)
    #define MAX7219_CTS_SCLK_HSIOM_SEL_SPI   (MAX7219_uart_cts_spi_sclk__0__HSIOM_SPI)
    #define MAX7219_CTS_SCLK_HSIOM_SEL_UART  (MAX7219_uart_cts_spi_sclk__0__HSIOM_UART)
#endif /* (MAX7219_CTS_SCLK_PIN) */

#if (MAX7219_RTS_SS0_PIN)
    #define MAX7219_RTS_SS0_HSIOM_REG   (*(reg32 *) MAX7219_uart_rts_spi_ss0__0__HSIOM)
    #define MAX7219_RTS_SS0_HSIOM_PTR   ( (reg32 *) MAX7219_uart_rts_spi_ss0__0__HSIOM)
    
    #define MAX7219_RTS_SS0_HSIOM_MASK      (MAX7219_uart_rts_spi_ss0__0__HSIOM_MASK)
    #define MAX7219_RTS_SS0_HSIOM_POS       (MAX7219_uart_rts_spi_ss0__0__HSIOM_SHIFT)
    #define MAX7219_RTS_SS0_HSIOM_SEL_GPIO  (MAX7219_uart_rts_spi_ss0__0__HSIOM_GPIO)
    #define MAX7219_RTS_SS0_HSIOM_SEL_I2C   (MAX7219_uart_rts_spi_ss0__0__HSIOM_I2C)
    #define MAX7219_RTS_SS0_HSIOM_SEL_SPI   (MAX7219_uart_rts_spi_ss0__0__HSIOM_SPI)
#if !(MAX7219_CY_SCBIP_V0 || MAX7219_CY_SCBIP_V1)
    #define MAX7219_RTS_SS0_HSIOM_SEL_UART  (MAX7219_uart_rts_spi_ss0__0__HSIOM_UART)
#endif /* !(MAX7219_CY_SCBIP_V0 || MAX7219_CY_SCBIP_V1) */
#endif /* (MAX7219_RTS_SS0_PIN) */

#if (MAX7219_SS1_PIN)
    #define MAX7219_SS1_HSIOM_REG  (*(reg32 *) MAX7219_spi_ss1__0__HSIOM)
    #define MAX7219_SS1_HSIOM_PTR  ( (reg32 *) MAX7219_spi_ss1__0__HSIOM)
    
    #define MAX7219_SS1_HSIOM_MASK     (MAX7219_spi_ss1__0__HSIOM_MASK)
    #define MAX7219_SS1_HSIOM_POS      (MAX7219_spi_ss1__0__HSIOM_SHIFT)
    #define MAX7219_SS1_HSIOM_SEL_GPIO (MAX7219_spi_ss1__0__HSIOM_GPIO)
    #define MAX7219_SS1_HSIOM_SEL_I2C  (MAX7219_spi_ss1__0__HSIOM_I2C)
    #define MAX7219_SS1_HSIOM_SEL_SPI  (MAX7219_spi_ss1__0__HSIOM_SPI)
#endif /* (MAX7219_SS1_PIN) */

#if (MAX7219_SS2_PIN)
    #define MAX7219_SS2_HSIOM_REG     (*(reg32 *) MAX7219_spi_ss2__0__HSIOM)
    #define MAX7219_SS2_HSIOM_PTR     ( (reg32 *) MAX7219_spi_ss2__0__HSIOM)
    
    #define MAX7219_SS2_HSIOM_MASK     (MAX7219_spi_ss2__0__HSIOM_MASK)
    #define MAX7219_SS2_HSIOM_POS      (MAX7219_spi_ss2__0__HSIOM_SHIFT)
    #define MAX7219_SS2_HSIOM_SEL_GPIO (MAX7219_spi_ss2__0__HSIOM_GPIO)
    #define MAX7219_SS2_HSIOM_SEL_I2C  (MAX7219_spi_ss2__0__HSIOM_I2C)
    #define MAX7219_SS2_HSIOM_SEL_SPI  (MAX7219_spi_ss2__0__HSIOM_SPI)
#endif /* (MAX7219_SS2_PIN) */

#if (MAX7219_SS3_PIN)
    #define MAX7219_SS3_HSIOM_REG     (*(reg32 *) MAX7219_spi_ss3__0__HSIOM)
    #define MAX7219_SS3_HSIOM_PTR     ( (reg32 *) MAX7219_spi_ss3__0__HSIOM)
    
    #define MAX7219_SS3_HSIOM_MASK     (MAX7219_spi_ss3__0__HSIOM_MASK)
    #define MAX7219_SS3_HSIOM_POS      (MAX7219_spi_ss3__0__HSIOM_SHIFT)
    #define MAX7219_SS3_HSIOM_SEL_GPIO (MAX7219_spi_ss3__0__HSIOM_GPIO)
    #define MAX7219_SS3_HSIOM_SEL_I2C  (MAX7219_spi_ss3__0__HSIOM_I2C)
    #define MAX7219_SS3_HSIOM_SEL_SPI  (MAX7219_spi_ss3__0__HSIOM_SPI)
#endif /* (MAX7219_SS3_PIN) */

#if (MAX7219_I2C_PINS)
    #define MAX7219_SCL_HSIOM_REG  (*(reg32 *) MAX7219_scl__0__HSIOM)
    #define MAX7219_SCL_HSIOM_PTR  ( (reg32 *) MAX7219_scl__0__HSIOM)
    
    #define MAX7219_SCL_HSIOM_MASK     (MAX7219_scl__0__HSIOM_MASK)
    #define MAX7219_SCL_HSIOM_POS      (MAX7219_scl__0__HSIOM_SHIFT)
    #define MAX7219_SCL_HSIOM_SEL_GPIO (MAX7219_sda__0__HSIOM_GPIO)
    #define MAX7219_SCL_HSIOM_SEL_I2C  (MAX7219_sda__0__HSIOM_I2C)
    
    #define MAX7219_SDA_HSIOM_REG  (*(reg32 *) MAX7219_sda__0__HSIOM)
    #define MAX7219_SDA_HSIOM_PTR  ( (reg32 *) MAX7219_sda__0__HSIOM)
    
    #define MAX7219_SDA_HSIOM_MASK     (MAX7219_sda__0__HSIOM_MASK)
    #define MAX7219_SDA_HSIOM_POS      (MAX7219_sda__0__HSIOM_SHIFT)
    #define MAX7219_SDA_HSIOM_SEL_GPIO (MAX7219_sda__0__HSIOM_GPIO)
    #define MAX7219_SDA_HSIOM_SEL_I2C  (MAX7219_sda__0__HSIOM_I2C)
#endif /* (MAX7219_I2C_PINS) */

#if (MAX7219_SPI_SLAVE_PINS)
    #define MAX7219_SCLK_S_HSIOM_REG   (*(reg32 *) MAX7219_sclk_s__0__HSIOM)
    #define MAX7219_SCLK_S_HSIOM_PTR   ( (reg32 *) MAX7219_sclk_s__0__HSIOM)
    
    #define MAX7219_SCLK_S_HSIOM_MASK      (MAX7219_sclk_s__0__HSIOM_MASK)
    #define MAX7219_SCLK_S_HSIOM_POS       (MAX7219_sclk_s__0__HSIOM_SHIFT)
    #define MAX7219_SCLK_S_HSIOM_SEL_GPIO  (MAX7219_sclk_s__0__HSIOM_GPIO)
    #define MAX7219_SCLK_S_HSIOM_SEL_SPI   (MAX7219_sclk_s__0__HSIOM_SPI)
    
    #define MAX7219_SS0_S_HSIOM_REG    (*(reg32 *) MAX7219_ss0_s__0__HSIOM)
    #define MAX7219_SS0_S_HSIOM_PTR    ( (reg32 *) MAX7219_ss0_s__0__HSIOM)
    
    #define MAX7219_SS0_S_HSIOM_MASK       (MAX7219_ss0_s__0__HSIOM_MASK)
    #define MAX7219_SS0_S_HSIOM_POS        (MAX7219_ss0_s__0__HSIOM_SHIFT)
    #define MAX7219_SS0_S_HSIOM_SEL_GPIO   (MAX7219_ss0_s__0__HSIOM_GPIO)  
    #define MAX7219_SS0_S_HSIOM_SEL_SPI    (MAX7219_ss0_s__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_SLAVE_PINS) */

#if (MAX7219_SPI_SLAVE_MOSI_PIN)
    #define MAX7219_MOSI_S_HSIOM_REG   (*(reg32 *) MAX7219_mosi_s__0__HSIOM)
    #define MAX7219_MOSI_S_HSIOM_PTR   ( (reg32 *) MAX7219_mosi_s__0__HSIOM)
    
    #define MAX7219_MOSI_S_HSIOM_MASK      (MAX7219_mosi_s__0__HSIOM_MASK)
    #define MAX7219_MOSI_S_HSIOM_POS       (MAX7219_mosi_s__0__HSIOM_SHIFT)
    #define MAX7219_MOSI_S_HSIOM_SEL_GPIO  (MAX7219_mosi_s__0__HSIOM_GPIO)
    #define MAX7219_MOSI_S_HSIOM_SEL_SPI   (MAX7219_mosi_s__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_SLAVE_MOSI_PIN) */

#if (MAX7219_SPI_SLAVE_MISO_PIN)
    #define MAX7219_MISO_S_HSIOM_REG   (*(reg32 *) MAX7219_miso_s__0__HSIOM)
    #define MAX7219_MISO_S_HSIOM_PTR   ( (reg32 *) MAX7219_miso_s__0__HSIOM)
    
    #define MAX7219_MISO_S_HSIOM_MASK      (MAX7219_miso_s__0__HSIOM_MASK)
    #define MAX7219_MISO_S_HSIOM_POS       (MAX7219_miso_s__0__HSIOM_SHIFT)
    #define MAX7219_MISO_S_HSIOM_SEL_GPIO  (MAX7219_miso_s__0__HSIOM_GPIO)
    #define MAX7219_MISO_S_HSIOM_SEL_SPI   (MAX7219_miso_s__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_SLAVE_MISO_PIN) */

#if (MAX7219_SPI_MASTER_MISO_PIN)
    #define MAX7219_MISO_M_HSIOM_REG   (*(reg32 *) MAX7219_miso_m__0__HSIOM)
    #define MAX7219_MISO_M_HSIOM_PTR   ( (reg32 *) MAX7219_miso_m__0__HSIOM)
    
    #define MAX7219_MISO_M_HSIOM_MASK      (MAX7219_miso_m__0__HSIOM_MASK)
    #define MAX7219_MISO_M_HSIOM_POS       (MAX7219_miso_m__0__HSIOM_SHIFT)
    #define MAX7219_MISO_M_HSIOM_SEL_GPIO  (MAX7219_miso_m__0__HSIOM_GPIO)
    #define MAX7219_MISO_M_HSIOM_SEL_SPI   (MAX7219_miso_m__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_MASTER_MISO_PIN) */

#if (MAX7219_SPI_MASTER_MOSI_PIN)
    #define MAX7219_MOSI_M_HSIOM_REG   (*(reg32 *) MAX7219_mosi_m__0__HSIOM)
    #define MAX7219_MOSI_M_HSIOM_PTR   ( (reg32 *) MAX7219_mosi_m__0__HSIOM)
    
    #define MAX7219_MOSI_M_HSIOM_MASK      (MAX7219_mosi_m__0__HSIOM_MASK)
    #define MAX7219_MOSI_M_HSIOM_POS       (MAX7219_mosi_m__0__HSIOM_SHIFT)
    #define MAX7219_MOSI_M_HSIOM_SEL_GPIO  (MAX7219_mosi_m__0__HSIOM_GPIO)
    #define MAX7219_MOSI_M_HSIOM_SEL_SPI   (MAX7219_mosi_m__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_MASTER_MOSI_PIN) */

#if (MAX7219_SPI_MASTER_SCLK_PIN)
    #define MAX7219_SCLK_M_HSIOM_REG   (*(reg32 *) MAX7219_sclk_m__0__HSIOM)
    #define MAX7219_SCLK_M_HSIOM_PTR   ( (reg32 *) MAX7219_sclk_m__0__HSIOM)
    
    #define MAX7219_SCLK_M_HSIOM_MASK      (MAX7219_sclk_m__0__HSIOM_MASK)
    #define MAX7219_SCLK_M_HSIOM_POS       (MAX7219_sclk_m__0__HSIOM_SHIFT)
    #define MAX7219_SCLK_M_HSIOM_SEL_GPIO  (MAX7219_sclk_m__0__HSIOM_GPIO)
    #define MAX7219_SCLK_M_HSIOM_SEL_SPI   (MAX7219_sclk_m__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_MASTER_SCLK_PIN) */

#if (MAX7219_SPI_MASTER_SS0_PIN)
    #define MAX7219_SS0_M_HSIOM_REG    (*(reg32 *) MAX7219_ss0_m__0__HSIOM)
    #define MAX7219_SS0_M_HSIOM_PTR    ( (reg32 *) MAX7219_ss0_m__0__HSIOM)
    
    #define MAX7219_SS0_M_HSIOM_MASK       (MAX7219_ss0_m__0__HSIOM_MASK)
    #define MAX7219_SS0_M_HSIOM_POS        (MAX7219_ss0_m__0__HSIOM_SHIFT)
    #define MAX7219_SS0_M_HSIOM_SEL_GPIO   (MAX7219_ss0_m__0__HSIOM_GPIO)
    #define MAX7219_SS0_M_HSIOM_SEL_SPI    (MAX7219_ss0_m__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_MASTER_SS0_PIN) */

#if (MAX7219_SPI_MASTER_SS1_PIN)
    #define MAX7219_SS1_M_HSIOM_REG    (*(reg32 *) MAX7219_ss1_m__0__HSIOM)
    #define MAX7219_SS1_M_HSIOM_PTR    ( (reg32 *) MAX7219_ss1_m__0__HSIOM)
    
    #define MAX7219_SS1_M_HSIOM_MASK       (MAX7219_ss1_m__0__HSIOM_MASK)
    #define MAX7219_SS1_M_HSIOM_POS        (MAX7219_ss1_m__0__HSIOM_SHIFT)
    #define MAX7219_SS1_M_HSIOM_SEL_GPIO   (MAX7219_ss1_m__0__HSIOM_GPIO)
    #define MAX7219_SS1_M_HSIOM_SEL_SPI    (MAX7219_ss1_m__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_MASTER_SS1_PIN) */

#if (MAX7219_SPI_MASTER_SS2_PIN)
    #define MAX7219_SS2_M_HSIOM_REG    (*(reg32 *) MAX7219_ss2_m__0__HSIOM)
    #define MAX7219_SS2_M_HSIOM_PTR    ( (reg32 *) MAX7219_ss2_m__0__HSIOM)
    
    #define MAX7219_SS2_M_HSIOM_MASK       (MAX7219_ss2_m__0__HSIOM_MASK)
    #define MAX7219_SS2_M_HSIOM_POS        (MAX7219_ss2_m__0__HSIOM_SHIFT)
    #define MAX7219_SS2_M_HSIOM_SEL_GPIO   (MAX7219_ss2_m__0__HSIOM_GPIO)
    #define MAX7219_SS2_M_HSIOM_SEL_SPI    (MAX7219_ss2_m__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_MASTER_SS2_PIN) */

#if (MAX7219_SPI_MASTER_SS3_PIN)
    #define MAX7219_SS3_M_HSIOM_REG    (*(reg32 *) MAX7219_ss3_m__0__HSIOM)
    #define MAX7219_SS3_M_HSIOM_PTR    ( (reg32 *) MAX7219_ss3_m__0__HSIOM)
    
    #define MAX7219_SS3_M_HSIOM_MASK      (MAX7219_ss3_m__0__HSIOM_MASK)
    #define MAX7219_SS3_M_HSIOM_POS       (MAX7219_ss3_m__0__HSIOM_SHIFT)
    #define MAX7219_SS3_M_HSIOM_SEL_GPIO  (MAX7219_ss3_m__0__HSIOM_GPIO)
    #define MAX7219_SS3_M_HSIOM_SEL_SPI   (MAX7219_ss3_m__0__HSIOM_SPI)
#endif /* (MAX7219_SPI_MASTER_SS3_PIN) */

#if (MAX7219_UART_RX_PIN)
    #define MAX7219_RX_HSIOM_REG   (*(reg32 *) MAX7219_rx__0__HSIOM)
    #define MAX7219_RX_HSIOM_PTR   ( (reg32 *) MAX7219_rx__0__HSIOM)
    
    #define MAX7219_RX_HSIOM_MASK      (MAX7219_rx__0__HSIOM_MASK)
    #define MAX7219_RX_HSIOM_POS       (MAX7219_rx__0__HSIOM_SHIFT)
    #define MAX7219_RX_HSIOM_SEL_GPIO  (MAX7219_rx__0__HSIOM_GPIO)
    #define MAX7219_RX_HSIOM_SEL_UART  (MAX7219_rx__0__HSIOM_UART)
#endif /* (MAX7219_UART_RX_PIN) */

#if (MAX7219_UART_RX_WAKE_PIN)
    #define MAX7219_RX_WAKE_HSIOM_REG   (*(reg32 *) MAX7219_rx_wake__0__HSIOM)
    #define MAX7219_RX_WAKE_HSIOM_PTR   ( (reg32 *) MAX7219_rx_wake__0__HSIOM)
    
    #define MAX7219_RX_WAKE_HSIOM_MASK      (MAX7219_rx_wake__0__HSIOM_MASK)
    #define MAX7219_RX_WAKE_HSIOM_POS       (MAX7219_rx_wake__0__HSIOM_SHIFT)
    #define MAX7219_RX_WAKE_HSIOM_SEL_GPIO  (MAX7219_rx_wake__0__HSIOM_GPIO)
    #define MAX7219_RX_WAKE_HSIOM_SEL_UART  (MAX7219_rx_wake__0__HSIOM_UART)
#endif /* (MAX7219_UART_WAKE_RX_PIN) */

#if (MAX7219_UART_CTS_PIN)
    #define MAX7219_CTS_HSIOM_REG   (*(reg32 *) MAX7219_cts__0__HSIOM)
    #define MAX7219_CTS_HSIOM_PTR   ( (reg32 *) MAX7219_cts__0__HSIOM)
    
    #define MAX7219_CTS_HSIOM_MASK      (MAX7219_cts__0__HSIOM_MASK)
    #define MAX7219_CTS_HSIOM_POS       (MAX7219_cts__0__HSIOM_SHIFT)
    #define MAX7219_CTS_HSIOM_SEL_GPIO  (MAX7219_cts__0__HSIOM_GPIO)
    #define MAX7219_CTS_HSIOM_SEL_UART  (MAX7219_cts__0__HSIOM_UART)
#endif /* (MAX7219_UART_CTS_PIN) */

#if (MAX7219_UART_TX_PIN)
    #define MAX7219_TX_HSIOM_REG   (*(reg32 *) MAX7219_tx__0__HSIOM)
    #define MAX7219_TX_HSIOM_PTR   ( (reg32 *) MAX7219_tx__0__HSIOM)
    
    #define MAX7219_TX_HSIOM_MASK      (MAX7219_tx__0__HSIOM_MASK)
    #define MAX7219_TX_HSIOM_POS       (MAX7219_tx__0__HSIOM_SHIFT)
    #define MAX7219_TX_HSIOM_SEL_GPIO  (MAX7219_tx__0__HSIOM_GPIO)
    #define MAX7219_TX_HSIOM_SEL_UART  (MAX7219_tx__0__HSIOM_UART)
#endif /* (MAX7219_UART_TX_PIN) */

#if (MAX7219_UART_RX_TX_PIN)
    #define MAX7219_RX_TX_HSIOM_REG   (*(reg32 *) MAX7219_rx_tx__0__HSIOM)
    #define MAX7219_RX_TX_HSIOM_PTR   ( (reg32 *) MAX7219_rx_tx__0__HSIOM)
    
    #define MAX7219_RX_TX_HSIOM_MASK      (MAX7219_rx_tx__0__HSIOM_MASK)
    #define MAX7219_RX_TX_HSIOM_POS       (MAX7219_rx_tx__0__HSIOM_SHIFT)
    #define MAX7219_RX_TX_HSIOM_SEL_GPIO  (MAX7219_rx_tx__0__HSIOM_GPIO)
    #define MAX7219_RX_TX_HSIOM_SEL_UART  (MAX7219_rx_tx__0__HSIOM_UART)
#endif /* (MAX7219_UART_RX_TX_PIN) */

#if (MAX7219_UART_RTS_PIN)
    #define MAX7219_RTS_HSIOM_REG      (*(reg32 *) MAX7219_rts__0__HSIOM)
    #define MAX7219_RTS_HSIOM_PTR      ( (reg32 *) MAX7219_rts__0__HSIOM)
    
    #define MAX7219_RTS_HSIOM_MASK     (MAX7219_rts__0__HSIOM_MASK)
    #define MAX7219_RTS_HSIOM_POS      (MAX7219_rts__0__HSIOM_SHIFT)    
    #define MAX7219_RTS_HSIOM_SEL_GPIO (MAX7219_rts__0__HSIOM_GPIO)
    #define MAX7219_RTS_HSIOM_SEL_UART (MAX7219_rts__0__HSIOM_UART)    
#endif /* (MAX7219_UART_RTS_PIN) */


/***************************************
*        Registers Constants
***************************************/

/* HSIOM switch values. */ 
#define MAX7219_HSIOM_DEF_SEL      (0x00u)
#define MAX7219_HSIOM_GPIO_SEL     (0x00u)
/* The HSIOM values provided below are valid only for MAX7219_CY_SCBIP_V0 
* and MAX7219_CY_SCBIP_V1. It is not recommended to use them for 
* MAX7219_CY_SCBIP_V2. Use pin name specific HSIOM constants provided 
* above instead for any SCB IP block version.
*/
#define MAX7219_HSIOM_UART_SEL     (0x09u)
#define MAX7219_HSIOM_I2C_SEL      (0x0Eu)
#define MAX7219_HSIOM_SPI_SEL      (0x0Fu)

/* Pins settings index. */
#define MAX7219_RX_WAKE_SDA_MOSI_PIN_INDEX   (0u)
#define MAX7219_RX_SDA_MOSI_PIN_INDEX       (0u)
#define MAX7219_TX_SCL_MISO_PIN_INDEX       (1u)
#define MAX7219_CTS_SCLK_PIN_INDEX       (2u)
#define MAX7219_RTS_SS0_PIN_INDEX       (3u)
#define MAX7219_SS1_PIN_INDEX                  (4u)
#define MAX7219_SS2_PIN_INDEX                  (5u)
#define MAX7219_SS3_PIN_INDEX                  (6u)

/* Pins settings mask. */
#define MAX7219_RX_WAKE_SDA_MOSI_PIN_MASK ((uint32) 0x01u << MAX7219_RX_WAKE_SDA_MOSI_PIN_INDEX)
#define MAX7219_RX_SDA_MOSI_PIN_MASK     ((uint32) 0x01u << MAX7219_RX_SDA_MOSI_PIN_INDEX)
#define MAX7219_TX_SCL_MISO_PIN_MASK     ((uint32) 0x01u << MAX7219_TX_SCL_MISO_PIN_INDEX)
#define MAX7219_CTS_SCLK_PIN_MASK     ((uint32) 0x01u << MAX7219_CTS_SCLK_PIN_INDEX)
#define MAX7219_RTS_SS0_PIN_MASK     ((uint32) 0x01u << MAX7219_RTS_SS0_PIN_INDEX)
#define MAX7219_SS1_PIN_MASK                ((uint32) 0x01u << MAX7219_SS1_PIN_INDEX)
#define MAX7219_SS2_PIN_MASK                ((uint32) 0x01u << MAX7219_SS2_PIN_INDEX)
#define MAX7219_SS3_PIN_MASK                ((uint32) 0x01u << MAX7219_SS3_PIN_INDEX)

/* Pin interrupt constants. */
#define MAX7219_INTCFG_TYPE_MASK           (0x03u)
#define MAX7219_INTCFG_TYPE_FALLING_EDGE   (0x02u)

/* Pin Drive Mode constants. */
#define MAX7219_PIN_DM_ALG_HIZ  (0u)
#define MAX7219_PIN_DM_DIG_HIZ  (1u)
#define MAX7219_PIN_DM_OD_LO    (4u)
#define MAX7219_PIN_DM_STRONG   (6u)


/***************************************
*          Macro Definitions
***************************************/

/* Return drive mode of the pin */
#define MAX7219_DM_MASK    (0x7u)
#define MAX7219_DM_SIZE    (3u)
#define MAX7219_GET_P4_PIN_DM(reg, pos) \
    ( ((reg) & (uint32) ((uint32) MAX7219_DM_MASK << (MAX7219_DM_SIZE * (pos)))) >> \
                                                              (MAX7219_DM_SIZE * (pos)) )

#if (MAX7219_TX_SCL_MISO_PIN)
    #define MAX7219_CHECK_TX_SCL_MISO_PIN_USED \
                (MAX7219_PIN_DM_ALG_HIZ != \
                    MAX7219_GET_P4_PIN_DM(MAX7219_uart_tx_i2c_scl_spi_miso_PC, \
                                                   MAX7219_uart_tx_i2c_scl_spi_miso_SHIFT))
#endif /* (MAX7219_TX_SCL_MISO_PIN) */

#if (MAX7219_RTS_SS0_PIN)
    #define MAX7219_CHECK_RTS_SS0_PIN_USED \
                (MAX7219_PIN_DM_ALG_HIZ != \
                    MAX7219_GET_P4_PIN_DM(MAX7219_uart_rts_spi_ss0_PC, \
                                                   MAX7219_uart_rts_spi_ss0_SHIFT))
#endif /* (MAX7219_RTS_SS0_PIN) */

/* Set bits-mask in register */
#define MAX7219_SET_REGISTER_BITS(reg, mask, pos, mode) \
                    do                                           \
                    {                                            \
                        (reg) = (((reg) & ((uint32) ~(uint32) (mask))) | ((uint32) ((uint32) (mode) << (pos)))); \
                    }while(0)

/* Set bit in the register */
#define MAX7219_SET_REGISTER_BIT(reg, mask, val) \
                    ((val) ? ((reg) |= (mask)) : ((reg) &= ((uint32) ~((uint32) (mask)))))

#define MAX7219_SET_HSIOM_SEL(reg, mask, pos, sel) MAX7219_SET_REGISTER_BITS(reg, mask, pos, sel)
#define MAX7219_SET_INCFG_TYPE(reg, mask, pos, intType) \
                                                        MAX7219_SET_REGISTER_BITS(reg, mask, pos, intType)
#define MAX7219_SET_INP_DIS(reg, mask, val) MAX7219_SET_REGISTER_BIT(reg, mask, val)

/* MAX7219_SET_I2C_SCL_DR(val) - Sets I2C SCL DR register.
*  MAX7219_SET_I2C_SCL_HSIOM_SEL(sel) - Sets I2C SCL HSIOM settings.
*/
/* SCB I2C: scl signal */
#if (MAX7219_CY_SCBIP_V0)
#if (MAX7219_I2C_PINS)
    #define MAX7219_SET_I2C_SCL_DR(val) MAX7219_scl_Write(val)

    #define MAX7219_SET_I2C_SCL_HSIOM_SEL(sel) \
                          MAX7219_SET_HSIOM_SEL(MAX7219_SCL_HSIOM_REG,  \
                                                         MAX7219_SCL_HSIOM_MASK, \
                                                         MAX7219_SCL_HSIOM_POS,  \
                                                         (sel))
    #define MAX7219_WAIT_SCL_SET_HIGH  (0u == MAX7219_scl_Read())

/* Unconfigured SCB: scl signal */
#elif (MAX7219_RX_WAKE_SDA_MOSI_PIN)
    #define MAX7219_SET_I2C_SCL_DR(val) \
                            MAX7219_uart_rx_wake_i2c_sda_spi_mosi_Write(val)

    #define MAX7219_SET_I2C_SCL_HSIOM_SEL(sel) \
                    MAX7219_SET_HSIOM_SEL(MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG,  \
                                                   MAX7219_RX_WAKE_SDA_MOSI_HSIOM_MASK, \
                                                   MAX7219_RX_WAKE_SDA_MOSI_HSIOM_POS,  \
                                                   (sel))

    #define MAX7219_WAIT_SCL_SET_HIGH  (0u == MAX7219_uart_rx_wake_i2c_sda_spi_mosi_Read())

#elif (MAX7219_RX_SDA_MOSI_PIN)
    #define MAX7219_SET_I2C_SCL_DR(val) \
                            MAX7219_uart_rx_i2c_sda_spi_mosi_Write(val)


    #define MAX7219_SET_I2C_SCL_HSIOM_SEL(sel) \
                            MAX7219_SET_HSIOM_SEL(MAX7219_RX_SDA_MOSI_HSIOM_REG,  \
                                                           MAX7219_RX_SDA_MOSI_HSIOM_MASK, \
                                                           MAX7219_RX_SDA_MOSI_HSIOM_POS,  \
                                                           (sel))

    #define MAX7219_WAIT_SCL_SET_HIGH  (0u == MAX7219_uart_rx_i2c_sda_spi_mosi_Read())

#else
    #define MAX7219_SET_I2C_SCL_DR(val)        do{ /* Does nothing */ }while(0)
    #define MAX7219_SET_I2C_SCL_HSIOM_SEL(sel) do{ /* Does nothing */ }while(0)

    #define MAX7219_WAIT_SCL_SET_HIGH  (0u)
#endif /* (MAX7219_I2C_PINS) */

/* SCB I2C: sda signal */
#if (MAX7219_I2C_PINS)
    #define MAX7219_WAIT_SDA_SET_HIGH  (0u == MAX7219_sda_Read())
/* Unconfigured SCB: sda signal */
#elif (MAX7219_TX_SCL_MISO_PIN)
    #define MAX7219_WAIT_SDA_SET_HIGH  (0u == MAX7219_uart_tx_i2c_scl_spi_miso_Read())
#else
    #define MAX7219_WAIT_SDA_SET_HIGH  (0u)
#endif /* (MAX7219_MOSI_SCL_RX_PIN) */
#endif /* (MAX7219_CY_SCBIP_V0) */

/* Clear UART wakeup source */
#if (MAX7219_RX_SDA_MOSI_PIN)
    #define MAX7219_CLEAR_UART_RX_WAKE_INTR        do{ /* Does nothing */ }while(0)
    
#elif (MAX7219_RX_WAKE_SDA_MOSI_PIN)
    #define MAX7219_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) MAX7219_uart_rx_wake_i2c_sda_spi_mosi_ClearInterrupt(); \
            }while(0)

#elif(MAX7219_UART_RX_WAKE_PIN)
    #define MAX7219_CLEAR_UART_RX_WAKE_INTR \
            do{                                      \
                (void) MAX7219_rx_wake_ClearInterrupt(); \
            }while(0)
#else
#endif /* (MAX7219_RX_SDA_MOSI_PIN) */


/***************************************
* The following code is DEPRECATED and
* must not be used.
***************************************/

/* Unconfigured pins */
#define MAX7219_REMOVE_MOSI_SCL_RX_WAKE_PIN    MAX7219_REMOVE_RX_WAKE_SDA_MOSI_PIN
#define MAX7219_REMOVE_MOSI_SCL_RX_PIN         MAX7219_REMOVE_RX_SDA_MOSI_PIN
#define MAX7219_REMOVE_MISO_SDA_TX_PIN         MAX7219_REMOVE_TX_SCL_MISO_PIN
#ifndef MAX7219_REMOVE_SCLK_PIN
#define MAX7219_REMOVE_SCLK_PIN                MAX7219_REMOVE_CTS_SCLK_PIN
#endif /* MAX7219_REMOVE_SCLK_PIN */
#ifndef MAX7219_REMOVE_SS0_PIN
#define MAX7219_REMOVE_SS0_PIN                 MAX7219_REMOVE_RTS_SS0_PIN
#endif /* MAX7219_REMOVE_SS0_PIN */

/* Unconfigured pins */
#define MAX7219_MOSI_SCL_RX_WAKE_PIN   MAX7219_RX_WAKE_SDA_MOSI_PIN
#define MAX7219_MOSI_SCL_RX_PIN        MAX7219_RX_SDA_MOSI_PIN
#define MAX7219_MISO_SDA_TX_PIN        MAX7219_TX_SCL_MISO_PIN
#ifndef MAX7219_SCLK_PIN
#define MAX7219_SCLK_PIN               MAX7219_CTS_SCLK_PIN
#endif /* MAX7219_SCLK_PIN */
#ifndef MAX7219_SS0_PIN
#define MAX7219_SS0_PIN                MAX7219_RTS_SS0_PIN
#endif /* MAX7219_SS0_PIN */

#if (MAX7219_MOSI_SCL_RX_WAKE_PIN)
    #define MAX7219_MOSI_SCL_RX_WAKE_HSIOM_REG     MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define MAX7219_MOSI_SCL_RX_WAKE_HSIOM_PTR     MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define MAX7219_MOSI_SCL_RX_WAKE_HSIOM_MASK    MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define MAX7219_MOSI_SCL_RX_WAKE_HSIOM_POS     MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG

    #define MAX7219_MOSI_SCL_RX_WAKE_INTCFG_REG    MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define MAX7219_MOSI_SCL_RX_WAKE_INTCFG_PTR    MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG

    #define MAX7219_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS   MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG
    #define MAX7219_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK  MAX7219_RX_WAKE_SDA_MOSI_HSIOM_REG
#endif /* (MAX7219_RX_WAKE_SDA_MOSI_PIN) */

#if (MAX7219_MOSI_SCL_RX_PIN)
    #define MAX7219_MOSI_SCL_RX_HSIOM_REG      MAX7219_RX_SDA_MOSI_HSIOM_REG
    #define MAX7219_MOSI_SCL_RX_HSIOM_PTR      MAX7219_RX_SDA_MOSI_HSIOM_PTR
    #define MAX7219_MOSI_SCL_RX_HSIOM_MASK     MAX7219_RX_SDA_MOSI_HSIOM_MASK
    #define MAX7219_MOSI_SCL_RX_HSIOM_POS      MAX7219_RX_SDA_MOSI_HSIOM_POS
#endif /* (MAX7219_MOSI_SCL_RX_PIN) */

#if (MAX7219_MISO_SDA_TX_PIN)
    #define MAX7219_MISO_SDA_TX_HSIOM_REG      MAX7219_TX_SCL_MISO_HSIOM_REG
    #define MAX7219_MISO_SDA_TX_HSIOM_PTR      MAX7219_TX_SCL_MISO_HSIOM_REG
    #define MAX7219_MISO_SDA_TX_HSIOM_MASK     MAX7219_TX_SCL_MISO_HSIOM_REG
    #define MAX7219_MISO_SDA_TX_HSIOM_POS      MAX7219_TX_SCL_MISO_HSIOM_REG
#endif /* (MAX7219_MISO_SDA_TX_PIN_PIN) */

#if (MAX7219_SCLK_PIN)
    #ifndef MAX7219_SCLK_HSIOM_REG
    #define MAX7219_SCLK_HSIOM_REG     MAX7219_CTS_SCLK_HSIOM_REG
    #define MAX7219_SCLK_HSIOM_PTR     MAX7219_CTS_SCLK_HSIOM_PTR
    #define MAX7219_SCLK_HSIOM_MASK    MAX7219_CTS_SCLK_HSIOM_MASK
    #define MAX7219_SCLK_HSIOM_POS     MAX7219_CTS_SCLK_HSIOM_POS
    #endif /* MAX7219_SCLK_HSIOM_REG */
#endif /* (MAX7219_SCLK_PIN) */

#if (MAX7219_SS0_PIN)
    #ifndef MAX7219_SS0_HSIOM_REG
    #define MAX7219_SS0_HSIOM_REG      MAX7219_RTS_SS0_HSIOM_REG
    #define MAX7219_SS0_HSIOM_PTR      MAX7219_RTS_SS0_HSIOM_PTR
    #define MAX7219_SS0_HSIOM_MASK     MAX7219_RTS_SS0_HSIOM_MASK
    #define MAX7219_SS0_HSIOM_POS      MAX7219_RTS_SS0_HSIOM_POS
    #endif /* MAX7219_SS0_HSIOM_REG */
#endif /* (MAX7219_SS0_PIN) */

#define MAX7219_MOSI_SCL_RX_WAKE_PIN_INDEX MAX7219_RX_WAKE_SDA_MOSI_PIN_INDEX
#define MAX7219_MOSI_SCL_RX_PIN_INDEX      MAX7219_RX_SDA_MOSI_PIN_INDEX
#define MAX7219_MISO_SDA_TX_PIN_INDEX      MAX7219_TX_SCL_MISO_PIN_INDEX
#ifndef MAX7219_SCLK_PIN_INDEX
#define MAX7219_SCLK_PIN_INDEX             MAX7219_CTS_SCLK_PIN_INDEX
#endif /* MAX7219_SCLK_PIN_INDEX */
#ifndef MAX7219_SS0_PIN_INDEX
#define MAX7219_SS0_PIN_INDEX              MAX7219_RTS_SS0_PIN_INDEX
#endif /* MAX7219_SS0_PIN_INDEX */

#define MAX7219_MOSI_SCL_RX_WAKE_PIN_MASK MAX7219_RX_WAKE_SDA_MOSI_PIN_MASK
#define MAX7219_MOSI_SCL_RX_PIN_MASK      MAX7219_RX_SDA_MOSI_PIN_MASK
#define MAX7219_MISO_SDA_TX_PIN_MASK      MAX7219_TX_SCL_MISO_PIN_MASK
#ifndef MAX7219_SCLK_PIN_MASK
#define MAX7219_SCLK_PIN_MASK             MAX7219_CTS_SCLK_PIN_MASK
#endif /* MAX7219_SCLK_PIN_MASK */
#ifndef MAX7219_SS0_PIN_MASK
#define MAX7219_SS0_PIN_MASK              MAX7219_RTS_SS0_PIN_MASK
#endif /* MAX7219_SS0_PIN_MASK */

#endif /* (CY_SCB_PINS_MAX7219_H) */


/* [] END OF FILE */
