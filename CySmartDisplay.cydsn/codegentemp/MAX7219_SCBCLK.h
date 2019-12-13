/*******************************************************************************
* File Name: MAX7219_SCBCLK.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_MAX7219_SCBCLK_H)
#define CY_CLOCK_MAX7219_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void MAX7219_SCBCLK_StartEx(uint32 alignClkDiv);
#define MAX7219_SCBCLK_Start() \
    MAX7219_SCBCLK_StartEx(MAX7219_SCBCLK__PA_DIV_ID)

#else

void MAX7219_SCBCLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void MAX7219_SCBCLK_Stop(void);

void MAX7219_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 MAX7219_SCBCLK_GetDividerRegister(void);
uint8  MAX7219_SCBCLK_GetFractionalDividerRegister(void);

#define MAX7219_SCBCLK_Enable()                         MAX7219_SCBCLK_Start()
#define MAX7219_SCBCLK_Disable()                        MAX7219_SCBCLK_Stop()
#define MAX7219_SCBCLK_SetDividerRegister(clkDivider, reset)  \
    MAX7219_SCBCLK_SetFractionalDividerRegister((clkDivider), 0u)
#define MAX7219_SCBCLK_SetDivider(clkDivider)           MAX7219_SCBCLK_SetDividerRegister((clkDivider), 1u)
#define MAX7219_SCBCLK_SetDividerValue(clkDivider)      MAX7219_SCBCLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define MAX7219_SCBCLK_DIV_ID     MAX7219_SCBCLK__DIV_ID

#define MAX7219_SCBCLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define MAX7219_SCBCLK_CTRL_REG   (*(reg32 *)MAX7219_SCBCLK__CTRL_REGISTER)
#define MAX7219_SCBCLK_DIV_REG    (*(reg32 *)MAX7219_SCBCLK__DIV_REGISTER)

#define MAX7219_SCBCLK_CMD_DIV_SHIFT          (0u)
#define MAX7219_SCBCLK_CMD_PA_DIV_SHIFT       (8u)
#define MAX7219_SCBCLK_CMD_DISABLE_SHIFT      (30u)
#define MAX7219_SCBCLK_CMD_ENABLE_SHIFT       (31u)

#define MAX7219_SCBCLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << MAX7219_SCBCLK_CMD_DISABLE_SHIFT))
#define MAX7219_SCBCLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << MAX7219_SCBCLK_CMD_ENABLE_SHIFT))

#define MAX7219_SCBCLK_DIV_FRAC_MASK  (0x000000F8u)
#define MAX7219_SCBCLK_DIV_FRAC_SHIFT (3u)
#define MAX7219_SCBCLK_DIV_INT_MASK   (0xFFFFFF00u)
#define MAX7219_SCBCLK_DIV_INT_SHIFT  (8u)

#else 

#define MAX7219_SCBCLK_DIV_REG        (*(reg32 *)MAX7219_SCBCLK__REGISTER)
#define MAX7219_SCBCLK_ENABLE_REG     MAX7219_SCBCLK_DIV_REG
#define MAX7219_SCBCLK_DIV_FRAC_MASK  MAX7219_SCBCLK__FRAC_MASK
#define MAX7219_SCBCLK_DIV_FRAC_SHIFT (16u)
#define MAX7219_SCBCLK_DIV_INT_MASK   MAX7219_SCBCLK__DIVIDER_MASK
#define MAX7219_SCBCLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_MAX7219_SCBCLK_H) */

/* [] END OF FILE */
