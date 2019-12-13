/*******************************************************************************
* File Name: Timer_CLK.h
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

#if !defined(CY_CLOCK_Timer_CLK_H)
#define CY_CLOCK_Timer_CLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Timer_CLK_StartEx(uint32 alignClkDiv);
#define Timer_CLK_Start() \
    Timer_CLK_StartEx(Timer_CLK__PA_DIV_ID)

#else

void Timer_CLK_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Timer_CLK_Stop(void);

void Timer_CLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Timer_CLK_GetDividerRegister(void);
uint8  Timer_CLK_GetFractionalDividerRegister(void);

#define Timer_CLK_Enable()                         Timer_CLK_Start()
#define Timer_CLK_Disable()                        Timer_CLK_Stop()
#define Timer_CLK_SetDividerRegister(clkDivider, reset)  \
    Timer_CLK_SetFractionalDividerRegister((clkDivider), 0u)
#define Timer_CLK_SetDivider(clkDivider)           Timer_CLK_SetDividerRegister((clkDivider), 1u)
#define Timer_CLK_SetDividerValue(clkDivider)      Timer_CLK_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Timer_CLK_DIV_ID     Timer_CLK__DIV_ID

#define Timer_CLK_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Timer_CLK_CTRL_REG   (*(reg32 *)Timer_CLK__CTRL_REGISTER)
#define Timer_CLK_DIV_REG    (*(reg32 *)Timer_CLK__DIV_REGISTER)

#define Timer_CLK_CMD_DIV_SHIFT          (0u)
#define Timer_CLK_CMD_PA_DIV_SHIFT       (8u)
#define Timer_CLK_CMD_DISABLE_SHIFT      (30u)
#define Timer_CLK_CMD_ENABLE_SHIFT       (31u)

#define Timer_CLK_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Timer_CLK_CMD_DISABLE_SHIFT))
#define Timer_CLK_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Timer_CLK_CMD_ENABLE_SHIFT))

#define Timer_CLK_DIV_FRAC_MASK  (0x000000F8u)
#define Timer_CLK_DIV_FRAC_SHIFT (3u)
#define Timer_CLK_DIV_INT_MASK   (0xFFFFFF00u)
#define Timer_CLK_DIV_INT_SHIFT  (8u)

#else 

#define Timer_CLK_DIV_REG        (*(reg32 *)Timer_CLK__REGISTER)
#define Timer_CLK_ENABLE_REG     Timer_CLK_DIV_REG
#define Timer_CLK_DIV_FRAC_MASK  Timer_CLK__FRAC_MASK
#define Timer_CLK_DIV_FRAC_SHIFT (16u)
#define Timer_CLK_DIV_INT_MASK   Timer_CLK__DIVIDER_MASK
#define Timer_CLK_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Timer_CLK_H) */

/* [] END OF FILE */
