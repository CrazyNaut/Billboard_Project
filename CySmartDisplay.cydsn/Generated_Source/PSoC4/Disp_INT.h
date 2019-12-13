/*******************************************************************************
* File Name: Disp_INT.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_Disp_INT_H)
#define CY_ISR_Disp_INT_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void Disp_INT_Start(void);
void Disp_INT_StartEx(cyisraddress address);
void Disp_INT_Stop(void);

CY_ISR_PROTO(Disp_INT_Interrupt);

void Disp_INT_SetVector(cyisraddress address);
cyisraddress Disp_INT_GetVector(void);

void Disp_INT_SetPriority(uint8 priority);
uint8 Disp_INT_GetPriority(void);

void Disp_INT_Enable(void);
uint8 Disp_INT_GetState(void);
void Disp_INT_Disable(void);

void Disp_INT_SetPending(void);
void Disp_INT_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the Disp_INT ISR. */
#define Disp_INT_INTC_VECTOR            ((reg32 *) Disp_INT__INTC_VECT)

/* Address of the Disp_INT ISR priority. */
#define Disp_INT_INTC_PRIOR             ((reg32 *) Disp_INT__INTC_PRIOR_REG)

/* Priority of the Disp_INT interrupt. */
#define Disp_INT_INTC_PRIOR_NUMBER      Disp_INT__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable Disp_INT interrupt. */
#define Disp_INT_INTC_SET_EN            ((reg32 *) Disp_INT__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the Disp_INT interrupt. */
#define Disp_INT_INTC_CLR_EN            ((reg32 *) Disp_INT__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the Disp_INT interrupt state to pending. */
#define Disp_INT_INTC_SET_PD            ((reg32 *) Disp_INT__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the Disp_INT interrupt. */
#define Disp_INT_INTC_CLR_PD            ((reg32 *) Disp_INT__INTC_CLR_PD_REG)



#endif /* CY_ISR_Disp_INT_H */


/* [] END OF FILE */
