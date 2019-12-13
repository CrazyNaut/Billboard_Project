/*******************************************************************************
* File Name: DisplayTimer.c
* Version 2.10
*
* Description:
*  This file provides the source code to the API for the DisplayTimer
*  component
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

uint8 DisplayTimer_initVar = 0u;


/*******************************************************************************
* Function Name: DisplayTimer_Init
********************************************************************************
*
* Summary:
*  Initialize/Restore default DisplayTimer configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_Init(void)
{

    /* Set values from customizer to CTRL */
    #if (DisplayTimer__QUAD == DisplayTimer_CONFIG)
        DisplayTimer_CONTROL_REG = DisplayTimer_CTRL_QUAD_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        DisplayTimer_TRIG_CONTROL1_REG  = DisplayTimer_QUAD_SIGNALS_MODES;

        /* Set values from customizer to INTR */
        DisplayTimer_SetInterruptMode(DisplayTimer_QUAD_INTERRUPT_MASK);
        
         /* Set other values */
        DisplayTimer_SetCounterMode(DisplayTimer_COUNT_DOWN);
        DisplayTimer_WritePeriod(DisplayTimer_QUAD_PERIOD_INIT_VALUE);
        DisplayTimer_WriteCounter(DisplayTimer_QUAD_PERIOD_INIT_VALUE);
    #endif  /* (DisplayTimer__QUAD == DisplayTimer_CONFIG) */

    #if (DisplayTimer__TIMER == DisplayTimer_CONFIG)
        DisplayTimer_CONTROL_REG = DisplayTimer_CTRL_TIMER_BASE_CONFIG;
        
        /* Set values from customizer to CTRL1 */
        DisplayTimer_TRIG_CONTROL1_REG  = DisplayTimer_TIMER_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        DisplayTimer_SetInterruptMode(DisplayTimer_TC_INTERRUPT_MASK);
        
        /* Set other values from customizer */
        DisplayTimer_WritePeriod(DisplayTimer_TC_PERIOD_VALUE );

        #if (DisplayTimer__COMPARE == DisplayTimer_TC_COMP_CAP_MODE)
            DisplayTimer_WriteCompare(DisplayTimer_TC_COMPARE_VALUE);

            #if (1u == DisplayTimer_TC_COMPARE_SWAP)
                DisplayTimer_SetCompareSwap(1u);
                DisplayTimer_WriteCompareBuf(DisplayTimer_TC_COMPARE_BUF_VALUE);
            #endif  /* (1u == DisplayTimer_TC_COMPARE_SWAP) */
        #endif  /* (DisplayTimer__COMPARE == DisplayTimer_TC_COMP_CAP_MODE) */

        /* Initialize counter value */
        #if (DisplayTimer_CY_TCPWM_V2 && DisplayTimer_TIMER_UPDOWN_CNT_USED && !DisplayTimer_CY_TCPWM_4000)
            DisplayTimer_WriteCounter(1u);
        #elif(DisplayTimer__COUNT_DOWN == DisplayTimer_TC_COUNTER_MODE)
            DisplayTimer_WriteCounter(DisplayTimer_TC_PERIOD_VALUE);
        #else
            DisplayTimer_WriteCounter(0u);
        #endif /* (DisplayTimer_CY_TCPWM_V2 && DisplayTimer_TIMER_UPDOWN_CNT_USED && !DisplayTimer_CY_TCPWM_4000) */
    #endif  /* (DisplayTimer__TIMER == DisplayTimer_CONFIG) */

    #if (DisplayTimer__PWM_SEL == DisplayTimer_CONFIG)
        DisplayTimer_CONTROL_REG = DisplayTimer_CTRL_PWM_BASE_CONFIG;

        #if (DisplayTimer__PWM_PR == DisplayTimer_PWM_MODE)
            DisplayTimer_CONTROL_REG |= DisplayTimer_CTRL_PWM_RUN_MODE;
            DisplayTimer_WriteCounter(DisplayTimer_PWM_PR_INIT_VALUE);
        #else
            DisplayTimer_CONTROL_REG |= DisplayTimer_CTRL_PWM_ALIGN | DisplayTimer_CTRL_PWM_KILL_EVENT;
            
            /* Initialize counter value */
            #if (DisplayTimer_CY_TCPWM_V2 && DisplayTimer_PWM_UPDOWN_CNT_USED && !DisplayTimer_CY_TCPWM_4000)
                DisplayTimer_WriteCounter(1u);
            #elif (DisplayTimer__RIGHT == DisplayTimer_PWM_ALIGN)
                DisplayTimer_WriteCounter(DisplayTimer_PWM_PERIOD_VALUE);
            #else 
                DisplayTimer_WriteCounter(0u);
            #endif  /* (DisplayTimer_CY_TCPWM_V2 && DisplayTimer_PWM_UPDOWN_CNT_USED && !DisplayTimer_CY_TCPWM_4000) */
        #endif  /* (DisplayTimer__PWM_PR == DisplayTimer_PWM_MODE) */

        #if (DisplayTimer__PWM_DT == DisplayTimer_PWM_MODE)
            DisplayTimer_CONTROL_REG |= DisplayTimer_CTRL_PWM_DEAD_TIME_CYCLE;
        #endif  /* (DisplayTimer__PWM_DT == DisplayTimer_PWM_MODE) */

        #if (DisplayTimer__PWM == DisplayTimer_PWM_MODE)
            DisplayTimer_CONTROL_REG |= DisplayTimer_CTRL_PWM_PRESCALER;
        #endif  /* (DisplayTimer__PWM == DisplayTimer_PWM_MODE) */

        /* Set values from customizer to CTRL1 */
        DisplayTimer_TRIG_CONTROL1_REG  = DisplayTimer_PWM_SIGNALS_MODES;
    
        /* Set values from customizer to INTR */
        DisplayTimer_SetInterruptMode(DisplayTimer_PWM_INTERRUPT_MASK);

        /* Set values from customizer to CTRL2 */
        #if (DisplayTimer__PWM_PR == DisplayTimer_PWM_MODE)
            DisplayTimer_TRIG_CONTROL2_REG =
                    (DisplayTimer_CC_MATCH_NO_CHANGE    |
                    DisplayTimer_OVERLOW_NO_CHANGE      |
                    DisplayTimer_UNDERFLOW_NO_CHANGE);
        #else
            #if (DisplayTimer__LEFT == DisplayTimer_PWM_ALIGN)
                DisplayTimer_TRIG_CONTROL2_REG = DisplayTimer_PWM_MODE_LEFT;
            #endif  /* ( DisplayTimer_PWM_LEFT == DisplayTimer_PWM_ALIGN) */

            #if (DisplayTimer__RIGHT == DisplayTimer_PWM_ALIGN)
                DisplayTimer_TRIG_CONTROL2_REG = DisplayTimer_PWM_MODE_RIGHT;
            #endif  /* ( DisplayTimer_PWM_RIGHT == DisplayTimer_PWM_ALIGN) */

            #if (DisplayTimer__CENTER == DisplayTimer_PWM_ALIGN)
                DisplayTimer_TRIG_CONTROL2_REG = DisplayTimer_PWM_MODE_CENTER;
            #endif  /* ( DisplayTimer_PWM_CENTER == DisplayTimer_PWM_ALIGN) */

            #if (DisplayTimer__ASYMMETRIC == DisplayTimer_PWM_ALIGN)
                DisplayTimer_TRIG_CONTROL2_REG = DisplayTimer_PWM_MODE_ASYM;
            #endif  /* (DisplayTimer__ASYMMETRIC == DisplayTimer_PWM_ALIGN) */
        #endif  /* (DisplayTimer__PWM_PR == DisplayTimer_PWM_MODE) */

        /* Set other values from customizer */
        DisplayTimer_WritePeriod(DisplayTimer_PWM_PERIOD_VALUE );
        DisplayTimer_WriteCompare(DisplayTimer_PWM_COMPARE_VALUE);

        #if (1u == DisplayTimer_PWM_COMPARE_SWAP)
            DisplayTimer_SetCompareSwap(1u);
            DisplayTimer_WriteCompareBuf(DisplayTimer_PWM_COMPARE_BUF_VALUE);
        #endif  /* (1u == DisplayTimer_PWM_COMPARE_SWAP) */

        #if (1u == DisplayTimer_PWM_PERIOD_SWAP)
            DisplayTimer_SetPeriodSwap(1u);
            DisplayTimer_WritePeriodBuf(DisplayTimer_PWM_PERIOD_BUF_VALUE);
        #endif  /* (1u == DisplayTimer_PWM_PERIOD_SWAP) */
    #endif  /* (DisplayTimer__PWM_SEL == DisplayTimer_CONFIG) */
    
}


/*******************************************************************************
* Function Name: DisplayTimer_Enable
********************************************************************************
*
* Summary:
*  Enables the DisplayTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_Enable(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();
    DisplayTimer_BLOCK_CONTROL_REG |= DisplayTimer_MASK;
    CyExitCriticalSection(enableInterrupts);

    /* Start Timer or PWM if start input is absent */
    #if (DisplayTimer__PWM_SEL == DisplayTimer_CONFIG)
        #if (0u == DisplayTimer_PWM_START_SIGNAL_PRESENT)
            DisplayTimer_TriggerCommand(DisplayTimer_MASK, DisplayTimer_CMD_START);
        #endif /* (0u == DisplayTimer_PWM_START_SIGNAL_PRESENT) */
    #endif /* (DisplayTimer__PWM_SEL == DisplayTimer_CONFIG) */

    #if (DisplayTimer__TIMER == DisplayTimer_CONFIG)
        #if (0u == DisplayTimer_TC_START_SIGNAL_PRESENT)
            DisplayTimer_TriggerCommand(DisplayTimer_MASK, DisplayTimer_CMD_START);
        #endif /* (0u == DisplayTimer_TC_START_SIGNAL_PRESENT) */
    #endif /* (DisplayTimer__TIMER == DisplayTimer_CONFIG) */
    
    #if (DisplayTimer__QUAD == DisplayTimer_CONFIG)
        #if (0u != DisplayTimer_QUAD_AUTO_START)
            DisplayTimer_TriggerCommand(DisplayTimer_MASK, DisplayTimer_CMD_RELOAD);
        #endif /* (0u != DisplayTimer_QUAD_AUTO_START) */
    #endif  /* (DisplayTimer__QUAD == DisplayTimer_CONFIG) */
}


/*******************************************************************************
* Function Name: DisplayTimer_Start
********************************************************************************
*
* Summary:
*  Initializes the DisplayTimer with default customizer
*  values when called the first time and enables the DisplayTimer.
*  For subsequent calls the configuration is left unchanged and the component is
*  just enabled.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  DisplayTimer_initVar: global variable is used to indicate initial
*  configuration of this component.  The variable is initialized to zero and set
*  to 1 the first time DisplayTimer_Start() is called. This allows
*  enabling/disabling a component without re-initialization in all subsequent
*  calls to the DisplayTimer_Start() routine.
*
*******************************************************************************/
void DisplayTimer_Start(void)
{
    if (0u == DisplayTimer_initVar)
    {
        DisplayTimer_Init();
        DisplayTimer_initVar = 1u;
    }

    DisplayTimer_Enable();
}


/*******************************************************************************
* Function Name: DisplayTimer_Stop
********************************************************************************
*
* Summary:
*  Disables the DisplayTimer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_Stop(void)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_BLOCK_CONTROL_REG &= (uint32)~DisplayTimer_MASK;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetMode
********************************************************************************
*
* Summary:
*  Sets the operation mode of the DisplayTimer. This function is used when
*  configured as a generic DisplayTimer and the actual mode of operation is
*  set at runtime. The mode must be set while the component is disabled.
*
* Parameters:
*  mode: Mode for the DisplayTimer to operate in
*   Values:
*   - DisplayTimer_MODE_TIMER_COMPARE - Timer / Counter with
*                                                 compare capability
*         - DisplayTimer_MODE_TIMER_CAPTURE - Timer / Counter with
*                                                 capture capability
*         - DisplayTimer_MODE_QUAD - Quadrature decoder
*         - DisplayTimer_MODE_PWM - PWM
*         - DisplayTimer_MODE_PWM_DT - PWM with dead time
*         - DisplayTimer_MODE_PWM_PR - PWM with pseudo random capability
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetMode(uint32 mode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_MODE_MASK;
    DisplayTimer_CONTROL_REG |= mode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetQDMode
********************************************************************************
*
* Summary:
*  Sets the the Quadrature Decoder to one of the 3 supported modes.
*  Its functionality is only applicable to Quadrature Decoder operation.
*
* Parameters:
*  qdMode: Quadrature Decoder mode
*   Values:
*         - DisplayTimer_MODE_X1 - Counts on phi 1 rising
*         - DisplayTimer_MODE_X2 - Counts on both edges of phi1 (2x faster)
*         - DisplayTimer_MODE_X4 - Counts on both edges of phi1 and phi2
*                                        (4x faster)
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetQDMode(uint32 qdMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_QUAD_MODE_MASK;
    DisplayTimer_CONTROL_REG |= qdMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetPrescaler
********************************************************************************
*
* Summary:
*  Sets the prescaler value that is applied to the clock input.  Not applicable
*  to a PWM with the dead time mode or Quadrature Decoder mode.
*
* Parameters:
*  prescaler: Prescaler divider value
*   Values:
*         - DisplayTimer_PRESCALE_DIVBY1    - Divide by 1 (no prescaling)
*         - DisplayTimer_PRESCALE_DIVBY2    - Divide by 2
*         - DisplayTimer_PRESCALE_DIVBY4    - Divide by 4
*         - DisplayTimer_PRESCALE_DIVBY8    - Divide by 8
*         - DisplayTimer_PRESCALE_DIVBY16   - Divide by 16
*         - DisplayTimer_PRESCALE_DIVBY32   - Divide by 32
*         - DisplayTimer_PRESCALE_DIVBY64   - Divide by 64
*         - DisplayTimer_PRESCALE_DIVBY128  - Divide by 128
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetPrescaler(uint32 prescaler)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_PRESCALER_MASK;
    DisplayTimer_CONTROL_REG |= prescaler;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetOneShot
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the DisplayTimer runs
*  continuously or stops when terminal count is reached.  By default the
*  DisplayTimer operates in the continuous mode.
*
* Parameters:
*  oneShotEnable
*   Values:
*     - 0 - Continuous
*     - 1 - Enable One Shot
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetOneShot(uint32 oneShotEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_ONESHOT_MASK;
    DisplayTimer_CONTROL_REG |= ((uint32)((oneShotEnable & DisplayTimer_1BIT_MASK) <<
                                                               DisplayTimer_ONESHOT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetPWMMode
********************************************************************************
*
* Summary:
*  Writes the control register that determines what mode of operation the PWM
*  output lines are driven in.  There is a setting for what to do on a
*  comparison match (CC_MATCH), on an overflow (OVERFLOW) and on an underflow
*  (UNDERFLOW).  The value for each of the three must be ORed together to form
*  the mode.
*
* Parameters:
*  modeMask: A combination of three mode settings.  Mask must include a value
*  for each of the three or use one of the preconfigured PWM settings.
*   Values:
*     - CC_MATCH_SET        - Set on comparison match
*     - CC_MATCH_CLEAR      - Clear on comparison match
*     - CC_MATCH_INVERT     - Invert on comparison match
*     - CC_MATCH_NO_CHANGE  - No change on comparison match
*     - OVERLOW_SET         - Set on overflow
*     - OVERLOW_CLEAR       - Clear on  overflow
*     - OVERLOW_INVERT      - Invert on overflow
*     - OVERLOW_NO_CHANGE   - No change on overflow
*     - UNDERFLOW_SET       - Set on underflow
*     - UNDERFLOW_CLEAR     - Clear on underflow
*     - UNDERFLOW_INVERT    - Invert on underflow
*     - UNDERFLOW_NO_CHANGE - No change on underflow
*     - PWM_MODE_LEFT       - Setting for left aligned PWM.  Should be combined
*                             with up counting mode
*     - PWM_MODE_RIGHT      - Setting for right aligned PWM.  Should be combined
*                             with down counting mode
*     - PWM_MODE_CENTER     - Setting for center aligned PWM.  Should be
*                             combined with up/down 0 mode
*     - PWM_MODE_ASYM       - Setting for asymmetric PWM.  Should be combined
*                             with up/down 1 mode
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetPWMMode(uint32 modeMask)
{
    DisplayTimer_TRIG_CONTROL2_REG = (modeMask & DisplayTimer_6BIT_MASK);
}



/*******************************************************************************
* Function Name: DisplayTimer_SetPWMSyncKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes asynchronous or synchronous kill operation.  By default the kill
*  operation is asynchronous.  This functionality is only applicable to the PWM
*  and PWM with dead time modes.
*
*  For Synchronous mode the kill signal disables both the line and line_n
*  signals until the next terminal count.
*
*  For Asynchronous mode the kill signal disables both the line and line_n
*  signals when the kill signal is present.  This mode should only be used
*  when the kill signal (stop input) is configured in the pass through mode
*  (Level sensitive signal).

*
* Parameters:
*  syncKillEnable
*   Values:
*     - 0 - Asynchronous
*     - 1 - Synchronous
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetPWMSyncKill(uint32 syncKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_PWM_SYNC_KILL_MASK;
    DisplayTimer_CONTROL_REG |= ((uint32)((syncKillEnable & DisplayTimer_1BIT_MASK)  <<
                                               DisplayTimer_PWM_SYNC_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetPWMStopOnKill
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the PWM kill signal (stop input)
*  causes the PWM counter to stop.  By default the kill operation does not stop
*  the counter.  This functionality is only applicable to the three PWM modes.
*
*
* Parameters:
*  stopOnKillEnable
*   Values:
*     - 0 - Don't stop
*     - 1 - Stop
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetPWMStopOnKill(uint32 stopOnKillEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_PWM_STOP_KILL_MASK;
    DisplayTimer_CONTROL_REG |= ((uint32)((stopOnKillEnable & DisplayTimer_1BIT_MASK)  <<
                                                         DisplayTimer_PWM_STOP_KILL_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetPWMDeadTime
********************************************************************************
*
* Summary:
*  Writes the dead time control value.  This value delays the rising edge of
*  both the line and line_n signals the designated number of cycles resulting
*  in both signals being inactive for that many cycles.  This functionality is
*  only applicable to the PWM in the dead time mode.

*
* Parameters:
*  Dead time to insert
*   Values: 0 to 255
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetPWMDeadTime(uint32 deadTime)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_PRESCALER_MASK;
    DisplayTimer_CONTROL_REG |= ((uint32)((deadTime & DisplayTimer_8BIT_MASK) <<
                                                          DisplayTimer_PRESCALER_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetPWMInvert
********************************************************************************
*
* Summary:
*  Writes the bits that control whether the line and line_n outputs are
*  inverted from their normal output values.  This functionality is only
*  applicable to the three PWM modes.
*
* Parameters:
*  mask: Mask of outputs to invert.
*   Values:
*         - DisplayTimer_INVERT_LINE   - Inverts the line output
*         - DisplayTimer_INVERT_LINE_N - Inverts the line_n output
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetPWMInvert(uint32 mask)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_INV_OUT_MASK;
    DisplayTimer_CONTROL_REG |= mask;

    CyExitCriticalSection(enableInterrupts);
}



/*******************************************************************************
* Function Name: DisplayTimer_WriteCounter
********************************************************************************
*
* Summary:
*  Writes a new 16bit counter value directly into the counter register, thus
*  setting the counter (not the period) to the value written. It is not
*  advised to write to this field when the counter is running.
*
* Parameters:
*  count: value to write
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_WriteCounter(uint32 count)
{
    DisplayTimer_COUNTER_REG = (count & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadCounter
********************************************************************************
*
* Summary:
*  Reads the current counter value.
*
* Parameters:
*  None
*
* Return:
*  Current counter value
*
*******************************************************************************/
uint32 DisplayTimer_ReadCounter(void)
{
    return (DisplayTimer_COUNTER_REG & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetCounterMode
********************************************************************************
*
* Summary:
*  Sets the counter mode.  Applicable to all modes except Quadrature Decoder
*  and the PWM with a pseudo random output.
*
* Parameters:
*  counterMode: Enumerated counter type values
*   Values:
*     - DisplayTimer_COUNT_UP       - Counts up
*     - DisplayTimer_COUNT_DOWN     - Counts down
*     - DisplayTimer_COUNT_UPDOWN0  - Counts up and down. Terminal count
*                                         generated when counter reaches 0
*     - DisplayTimer_COUNT_UPDOWN1  - Counts up and down. Terminal count
*                                         generated both when counter reaches 0
*                                         and period
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetCounterMode(uint32 counterMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_UPDOWN_MASK;
    DisplayTimer_CONTROL_REG |= counterMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_WritePeriod
********************************************************************************
*
* Summary:
*  Writes the 16 bit period register with the new period value.
*  To cause the counter to count for N cycles this register should be written
*  with N-1 (counts from 0 to period inclusive).
*
* Parameters:
*  period: Period value
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_WritePeriod(uint32 period)
{
    DisplayTimer_PERIOD_REG = (period & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadPeriod
********************************************************************************
*
* Summary:
*  Reads the 16 bit period register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 DisplayTimer_ReadPeriod(void)
{
    return (DisplayTimer_PERIOD_REG & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetCompareSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the compare registers are
*  swapped. When enabled in the Timer/Counter mode(without capture) the swap
*  occurs at a TC event. In the PWM mode the swap occurs at the next TC event
*  following a hardware switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetCompareSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_RELOAD_CC_MASK;
    DisplayTimer_CONTROL_REG |= (swapEnable & DisplayTimer_1BIT_MASK);

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_WritePeriodBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit period buf register with the new period value.
*
* Parameters:
*  periodBuf: Period value
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_WritePeriodBuf(uint32 periodBuf)
{
    DisplayTimer_PERIOD_BUF_REG = (periodBuf & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadPeriodBuf
********************************************************************************
*
* Summary:
*  Reads the 16 bit period buf register.
*
* Parameters:
*  None
*
* Return:
*  Period value
*
*******************************************************************************/
uint32 DisplayTimer_ReadPeriodBuf(void)
{
    return (DisplayTimer_PERIOD_BUF_REG & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetPeriodSwap
********************************************************************************
*
* Summary:
*  Writes the register that controls whether the period registers are
*  swapped. When enabled in Timer/Counter mode the swap occurs at a TC event.
*  In the PWM mode the swap occurs at the next TC event following a hardware
*  switch event.
*
* Parameters:
*  swapEnable
*   Values:
*     - 0 - Disable swap
*     - 1 - Enable swap
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetPeriodSwap(uint32 swapEnable)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_CONTROL_REG &= (uint32)~DisplayTimer_RELOAD_PERIOD_MASK;
    DisplayTimer_CONTROL_REG |= ((uint32)((swapEnable & DisplayTimer_1BIT_MASK) <<
                                                            DisplayTimer_RELOAD_PERIOD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_WriteCompare
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compare: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void DisplayTimer_WriteCompare(uint32 compare)
{
    #if (DisplayTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (DisplayTimer_CY_TCPWM_4000) */

    #if (DisplayTimer_CY_TCPWM_4000)
        currentMode = ((DisplayTimer_CONTROL_REG & DisplayTimer_UPDOWN_MASK) >> DisplayTimer_UPDOWN_SHIFT);

        if (((uint32)DisplayTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compare))
        {
            compare++;
        }
        else if (((uint32)DisplayTimer__COUNT_UP == currentMode) && (0u != compare))
        {
            compare--;
        }
        else
        {
        }
        
    
    #endif /* (DisplayTimer_CY_TCPWM_4000) */
    
    DisplayTimer_COMP_CAP_REG = (compare & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadCompare
********************************************************************************
*
* Summary:
*  Reads the compare register. Not applicable for Timer/Counter with Capture
*  or in Quadrature Decoder modes.
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
* Parameters:
*  None
*
* Return:
*  Compare value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 DisplayTimer_ReadCompare(void)
{
    #if (DisplayTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (DisplayTimer_CY_TCPWM_4000) */

    #if (DisplayTimer_CY_TCPWM_4000)
        currentMode = ((DisplayTimer_CONTROL_REG & DisplayTimer_UPDOWN_MASK) >> DisplayTimer_UPDOWN_SHIFT);
        
        regVal = DisplayTimer_COMP_CAP_REG;
        
        if (((uint32)DisplayTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)DisplayTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & DisplayTimer_16BIT_MASK);
    #else
        return (DisplayTimer_COMP_CAP_REG & DisplayTimer_16BIT_MASK);
    #endif /* (DisplayTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: DisplayTimer_WriteCompareBuf
********************************************************************************
*
* Summary:
*  Writes the 16 bit compare buffer register with the new compare value. Not
*  applicable for Timer/Counter with Capture or in Quadrature Decoder modes.
*
* Parameters:
*  compareBuf: Compare value
*
* Return:
*  None
*
* Note:
*  It is not recommended to use the value equal to "0" or equal to 
*  "period value" in Center or Asymmetric align PWM modes on the 
*  PSoC 4100/PSoC 4200 devices.
*  PSoC 4000 devices write the 16 bit compare register with the decremented 
*  compare value in the Up counting mode (except 0x0u), and the incremented 
*  compare value in the Down counting mode (except 0xFFFFu).
*
*******************************************************************************/
void DisplayTimer_WriteCompareBuf(uint32 compareBuf)
{
    #if (DisplayTimer_CY_TCPWM_4000)
        uint32 currentMode;
    #endif /* (DisplayTimer_CY_TCPWM_4000) */

    #if (DisplayTimer_CY_TCPWM_4000)
        currentMode = ((DisplayTimer_CONTROL_REG & DisplayTimer_UPDOWN_MASK) >> DisplayTimer_UPDOWN_SHIFT);

        if (((uint32)DisplayTimer__COUNT_DOWN == currentMode) && (0xFFFFu != compareBuf))
        {
            compareBuf++;
        }
        else if (((uint32)DisplayTimer__COUNT_UP == currentMode) && (0u != compareBuf))
        {
            compareBuf --;
        }
        else
        {
        }
    #endif /* (DisplayTimer_CY_TCPWM_4000) */
    
    DisplayTimer_COMP_CAP_BUF_REG = (compareBuf & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadCompareBuf
********************************************************************************
*
* Summary:
*  Reads the compare buffer register. Not applicable for Timer/Counter with
*  Capture or in Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Compare buffer value
*
* Note:
*  PSoC 4000 devices read the incremented compare register value in the 
*  Up counting mode (except 0xFFFFu), and the decremented value in the 
*  Down counting mode (except 0x0u).
*
*******************************************************************************/
uint32 DisplayTimer_ReadCompareBuf(void)
{
    #if (DisplayTimer_CY_TCPWM_4000)
        uint32 currentMode;
        uint32 regVal;
    #endif /* (DisplayTimer_CY_TCPWM_4000) */

    #if (DisplayTimer_CY_TCPWM_4000)
        currentMode = ((DisplayTimer_CONTROL_REG & DisplayTimer_UPDOWN_MASK) >> DisplayTimer_UPDOWN_SHIFT);

        regVal = DisplayTimer_COMP_CAP_BUF_REG;
        
        if (((uint32)DisplayTimer__COUNT_DOWN == currentMode) && (0u != regVal))
        {
            regVal--;
        }
        else if (((uint32)DisplayTimer__COUNT_UP == currentMode) && (0xFFFFu != regVal))
        {
            regVal++;
        }
        else
        {
        }

        return (regVal & DisplayTimer_16BIT_MASK);
    #else
        return (DisplayTimer_COMP_CAP_BUF_REG & DisplayTimer_16BIT_MASK);
    #endif /* (DisplayTimer_CY_TCPWM_4000) */
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadCapture
********************************************************************************
*
* Summary:
*  Reads the captured counter value. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture value
*
*******************************************************************************/
uint32 DisplayTimer_ReadCapture(void)
{
    return (DisplayTimer_COMP_CAP_REG & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadCaptureBuf
********************************************************************************
*
* Summary:
*  Reads the capture buffer register. This API is applicable only for
*  Timer/Counter with the capture mode and Quadrature Decoder modes.
*
* Parameters:
*  None
*
* Return:
*  Capture buffer value
*
*******************************************************************************/
uint32 DisplayTimer_ReadCaptureBuf(void)
{
    return (DisplayTimer_COMP_CAP_BUF_REG & DisplayTimer_16BIT_MASK);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetCaptureMode
********************************************************************************
*
* Summary:
*  Sets the capture trigger mode. For PWM mode this is the switch input.
*  This input is not applicable to the Timer/Counter without Capture and
*  Quadrature Decoder modes.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - DisplayTimer_TRIG_LEVEL     - Level
*     - DisplayTimer_TRIG_RISING    - Rising edge
*     - DisplayTimer_TRIG_FALLING   - Falling edge
*     - DisplayTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetCaptureMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_TRIG_CONTROL1_REG &= (uint32)~DisplayTimer_CAPTURE_MASK;
    DisplayTimer_TRIG_CONTROL1_REG |= triggerMode;

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetReloadMode
********************************************************************************
*
* Summary:
*  Sets the reload trigger mode. For Quadrature Decoder mode this is the index
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - DisplayTimer_TRIG_LEVEL     - Level
*     - DisplayTimer_TRIG_RISING    - Rising edge
*     - DisplayTimer_TRIG_FALLING   - Falling edge
*     - DisplayTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetReloadMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_TRIG_CONTROL1_REG &= (uint32)~DisplayTimer_RELOAD_MASK;
    DisplayTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << DisplayTimer_RELOAD_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetStartMode
********************************************************************************
*
* Summary:
*  Sets the start trigger mode. For Quadrature Decoder mode this is the
*  phiB input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - DisplayTimer_TRIG_LEVEL     - Level
*     - DisplayTimer_TRIG_RISING    - Rising edge
*     - DisplayTimer_TRIG_FALLING   - Falling edge
*     - DisplayTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetStartMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_TRIG_CONTROL1_REG &= (uint32)~DisplayTimer_START_MASK;
    DisplayTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << DisplayTimer_START_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetStopMode
********************************************************************************
*
* Summary:
*  Sets the stop trigger mode. For PWM mode this is the kill input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - DisplayTimer_TRIG_LEVEL     - Level
*     - DisplayTimer_TRIG_RISING    - Rising edge
*     - DisplayTimer_TRIG_FALLING   - Falling edge
*     - DisplayTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetStopMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_TRIG_CONTROL1_REG &= (uint32)~DisplayTimer_STOP_MASK;
    DisplayTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << DisplayTimer_STOP_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_SetCountMode
********************************************************************************
*
* Summary:
*  Sets the count trigger mode. For Quadrature Decoder mode this is the phiA
*  input.
*
* Parameters:
*  triggerMode: Enumerated trigger mode value
*   Values:
*     - DisplayTimer_TRIG_LEVEL     - Level
*     - DisplayTimer_TRIG_RISING    - Rising edge
*     - DisplayTimer_TRIG_FALLING   - Falling edge
*     - DisplayTimer_TRIG_BOTH      - Both rising and falling edge
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetCountMode(uint32 triggerMode)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_TRIG_CONTROL1_REG &= (uint32)~DisplayTimer_COUNT_MASK;
    DisplayTimer_TRIG_CONTROL1_REG |= ((uint32)(triggerMode << DisplayTimer_COUNT_SHIFT));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_TriggerCommand
********************************************************************************
*
* Summary:
*  Triggers the designated command to occur on the designated TCPWM instances.
*  The mask can be used to apply this command simultaneously to more than one
*  instance.  This allows multiple TCPWM instances to be synchronized.
*
* Parameters:
*  mask: A combination of mask bits for each instance of the TCPWM that the
*        command should apply to.  This function from one instance can be used
*        to apply the command to any of the instances in the design.
*        The mask value for a specific instance is available with the MASK
*        define.
*  command: Enumerated command values. Capture command only applicable for
*           Timer/Counter with Capture and PWM modes.
*   Values:
*     - DisplayTimer_CMD_CAPTURE    - Trigger Capture/Switch command
*     - DisplayTimer_CMD_RELOAD     - Trigger Reload/Index command
*     - DisplayTimer_CMD_STOP       - Trigger Stop/Kill command
*     - DisplayTimer_CMD_START      - Trigger Start/phiB command
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_TriggerCommand(uint32 mask, uint32 command)
{
    uint8 enableInterrupts;

    enableInterrupts = CyEnterCriticalSection();

    DisplayTimer_COMMAND_REG = ((uint32)(mask << command));

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: DisplayTimer_ReadStatus
********************************************************************************
*
* Summary:
*  Reads the status of the DisplayTimer.
*
* Parameters:
*  None
*
* Return:
*  Status
*   Values:
*     - DisplayTimer_STATUS_DOWN    - Set if counting down
*     - DisplayTimer_STATUS_RUNNING - Set if counter is running
*
*******************************************************************************/
uint32 DisplayTimer_ReadStatus(void)
{
    return ((DisplayTimer_STATUS_REG >> DisplayTimer_RUNNING_STATUS_SHIFT) |
            (DisplayTimer_STATUS_REG & DisplayTimer_STATUS_DOWN));
}


/*******************************************************************************
* Function Name: DisplayTimer_SetInterruptMode
********************************************************************************
*
* Summary:
*  Sets the interrupt mask to control which interrupt
*  requests generate the interrupt signal.
*
* Parameters:
*   interruptMask: Mask of bits to be enabled
*   Values:
*     - DisplayTimer_INTR_MASK_TC       - Terminal count mask
*     - DisplayTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetInterruptMode(uint32 interruptMask)
{
    DisplayTimer_INTERRUPT_MASK_REG =  interruptMask;
}


/*******************************************************************************
* Function Name: DisplayTimer_GetInterruptSourceMasked
********************************************************************************
*
* Summary:
*  Gets the interrupt requests masked by the interrupt mask.
*
* Parameters:
*   None
*
* Return:
*  Masked interrupt source
*   Values:
*     - DisplayTimer_INTR_MASK_TC       - Terminal count mask
*     - DisplayTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 DisplayTimer_GetInterruptSourceMasked(void)
{
    return (DisplayTimer_INTERRUPT_MASKED_REG);
}


/*******************************************************************************
* Function Name: DisplayTimer_GetInterruptSource
********************************************************************************
*
* Summary:
*  Gets the interrupt requests (without masking).
*
* Parameters:
*  None
*
* Return:
*  Interrupt request value
*   Values:
*     - DisplayTimer_INTR_MASK_TC       - Terminal count mask
*     - DisplayTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
*******************************************************************************/
uint32 DisplayTimer_GetInterruptSource(void)
{
    return (DisplayTimer_INTERRUPT_REQ_REG);
}


/*******************************************************************************
* Function Name: DisplayTimer_ClearInterrupt
********************************************************************************
*
* Summary:
*  Clears the interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to clear
*   Values:
*     - DisplayTimer_INTR_MASK_TC       - Terminal count mask
*     - DisplayTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_ClearInterrupt(uint32 interruptMask)
{
    DisplayTimer_INTERRUPT_REQ_REG = interruptMask;
}


/*******************************************************************************
* Function Name: DisplayTimer_SetInterrupt
********************************************************************************
*
* Summary:
*  Sets a software interrupt request.
*
* Parameters:
*   interruptMask: Mask of interrupts to set
*   Values:
*     - DisplayTimer_INTR_MASK_TC       - Terminal count mask
*     - DisplayTimer_INTR_MASK_CC_MATCH - Compare count / capture mask
*
* Return:
*  None
*
*******************************************************************************/
void DisplayTimer_SetInterrupt(uint32 interruptMask)
{
    DisplayTimer_INTERRUPT_SET_REG = interruptMask;
}


/* [] END OF FILE */
