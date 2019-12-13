/*******************************************************************************
* File Name: DisplayTimer_PM.c
* Version 2.10
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "DisplayTimer.h"

static DisplayTimer_BACKUP_STRUCT DisplayTimer_backup;


/*******************************************************************************
* Function Name: DisplayTimer_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: DisplayTimer_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_Sleep(void)
{
    if(0u != (DisplayTimer_BLOCK_CONTROL_REG & DisplayTimer_MASK))
    {
        DisplayTimer_backup.enableState = 1u;
    }
    else
    {
        DisplayTimer_backup.enableState = 0u;
    }

    DisplayTimer_Stop();
    DisplayTimer_SaveConfig();
}


/*******************************************************************************
* Function Name: DisplayTimer_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: DisplayTimer_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_Wakeup(void)
{
    DisplayTimer_RestoreConfig();

    if(0u != DisplayTimer_backup.enableState)
    {
        DisplayTimer_Enable();
    }
}


/* [] END OF FILE */
