/*******************************************************************************
* File Name: DisplayTimer.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the DisplayTimer
*  component.
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

#if !defined(CY_TCPWM_DisplayTimer_H)
#define CY_TCPWM_DisplayTimer_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} DisplayTimer_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  DisplayTimer_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define DisplayTimer_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define DisplayTimer_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define DisplayTimer_CONFIG                         (1lu)

/* Quad Mode */
/* Parameters */
#define DisplayTimer_QUAD_ENCODING_MODES            (0lu)
#define DisplayTimer_QUAD_AUTO_START                (0lu)

/* Signal modes */
#define DisplayTimer_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define DisplayTimer_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define DisplayTimer_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define DisplayTimer_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define DisplayTimer_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define DisplayTimer_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define DisplayTimer_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define DisplayTimer_TC_RUN_MODE                    (0lu)
#define DisplayTimer_TC_COUNTER_MODE                (0lu)
#define DisplayTimer_TC_COMP_CAP_MODE               (2lu)
#define DisplayTimer_TC_PRESCALER                   (0lu)

/* Signal modes */
#define DisplayTimer_TC_RELOAD_SIGNAL_MODE          (0lu)
#define DisplayTimer_TC_COUNT_SIGNAL_MODE           (3lu)
#define DisplayTimer_TC_START_SIGNAL_MODE           (0lu)
#define DisplayTimer_TC_STOP_SIGNAL_MODE            (0lu)
#define DisplayTimer_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define DisplayTimer_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define DisplayTimer_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define DisplayTimer_TC_START_SIGNAL_PRESENT        (0lu)
#define DisplayTimer_TC_STOP_SIGNAL_PRESENT         (0lu)
#define DisplayTimer_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define DisplayTimer_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define DisplayTimer_PWM_KILL_EVENT                 (0lu)
#define DisplayTimer_PWM_STOP_EVENT                 (0lu)
#define DisplayTimer_PWM_MODE                       (4lu)
#define DisplayTimer_PWM_OUT_N_INVERT               (0lu)
#define DisplayTimer_PWM_OUT_INVERT                 (0lu)
#define DisplayTimer_PWM_ALIGN                      (0lu)
#define DisplayTimer_PWM_RUN_MODE                   (0lu)
#define DisplayTimer_PWM_DEAD_TIME_CYCLE            (0lu)
#define DisplayTimer_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define DisplayTimer_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define DisplayTimer_PWM_COUNT_SIGNAL_MODE          (3lu)
#define DisplayTimer_PWM_START_SIGNAL_MODE          (0lu)
#define DisplayTimer_PWM_STOP_SIGNAL_MODE           (0lu)
#define DisplayTimer_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define DisplayTimer_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define DisplayTimer_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define DisplayTimer_PWM_START_SIGNAL_PRESENT       (0lu)
#define DisplayTimer_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define DisplayTimer_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define DisplayTimer_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define DisplayTimer_TC_PERIOD_VALUE                (63999lu)
#define DisplayTimer_TC_COMPARE_VALUE               (65535lu)
#define DisplayTimer_TC_COMPARE_BUF_VALUE           (65535lu)
#define DisplayTimer_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define DisplayTimer_PWM_PERIOD_VALUE               (65535lu)
#define DisplayTimer_PWM_PERIOD_BUF_VALUE           (65535lu)
#define DisplayTimer_PWM_PERIOD_SWAP                (0lu)
#define DisplayTimer_PWM_COMPARE_VALUE              (65535lu)
#define DisplayTimer_PWM_COMPARE_BUF_VALUE          (65535lu)
#define DisplayTimer_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define DisplayTimer__LEFT 0
#define DisplayTimer__RIGHT 1
#define DisplayTimer__CENTER 2
#define DisplayTimer__ASYMMETRIC 3

#define DisplayTimer__X1 0
#define DisplayTimer__X2 1
#define DisplayTimer__X4 2

#define DisplayTimer__PWM 4
#define DisplayTimer__PWM_DT 5
#define DisplayTimer__PWM_PR 6

#define DisplayTimer__INVERSE 1
#define DisplayTimer__DIRECT 0

#define DisplayTimer__CAPTURE 2
#define DisplayTimer__COMPARE 0

#define DisplayTimer__TRIG_LEVEL 3
#define DisplayTimer__TRIG_RISING 0
#define DisplayTimer__TRIG_FALLING 1
#define DisplayTimer__TRIG_BOTH 2

#define DisplayTimer__INTR_MASK_TC 1
#define DisplayTimer__INTR_MASK_CC_MATCH 2
#define DisplayTimer__INTR_MASK_NONE 0
#define DisplayTimer__INTR_MASK_TC_CC 3

#define DisplayTimer__UNCONFIG 8
#define DisplayTimer__TIMER 1
#define DisplayTimer__QUAD 3
#define DisplayTimer__PWM_SEL 7

#define DisplayTimer__COUNT_UP 0
#define DisplayTimer__COUNT_DOWN 1
#define DisplayTimer__COUNT_UPDOWN0 2
#define DisplayTimer__COUNT_UPDOWN1 3


/* Prescaler */
#define DisplayTimer_PRESCALE_DIVBY1                ((uint32)(0u << DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_PRESCALE_DIVBY2                ((uint32)(1u << DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_PRESCALE_DIVBY4                ((uint32)(2u << DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_PRESCALE_DIVBY8                ((uint32)(3u << DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_PRESCALE_DIVBY16               ((uint32)(4u << DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_PRESCALE_DIVBY32               ((uint32)(5u << DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_PRESCALE_DIVBY64               ((uint32)(6u << DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_PRESCALE_DIVBY128              ((uint32)(7u << DisplayTimer_PRESCALER_SHIFT))

/* TCPWM set modes */
#define DisplayTimer_MODE_TIMER_COMPARE             ((uint32)(DisplayTimer__COMPARE         <<  \
                                                                  DisplayTimer_MODE_SHIFT))
#define DisplayTimer_MODE_TIMER_CAPTURE             ((uint32)(DisplayTimer__CAPTURE         <<  \
                                                                  DisplayTimer_MODE_SHIFT))
#define DisplayTimer_MODE_QUAD                      ((uint32)(DisplayTimer__QUAD            <<  \
                                                                  DisplayTimer_MODE_SHIFT))
#define DisplayTimer_MODE_PWM                       ((uint32)(DisplayTimer__PWM             <<  \
                                                                  DisplayTimer_MODE_SHIFT))
#define DisplayTimer_MODE_PWM_DT                    ((uint32)(DisplayTimer__PWM_DT          <<  \
                                                                  DisplayTimer_MODE_SHIFT))
#define DisplayTimer_MODE_PWM_PR                    ((uint32)(DisplayTimer__PWM_PR          <<  \
                                                                  DisplayTimer_MODE_SHIFT))

/* Quad Modes */
#define DisplayTimer_MODE_X1                        ((uint32)(DisplayTimer__X1              <<  \
                                                                  DisplayTimer_QUAD_MODE_SHIFT))
#define DisplayTimer_MODE_X2                        ((uint32)(DisplayTimer__X2              <<  \
                                                                  DisplayTimer_QUAD_MODE_SHIFT))
#define DisplayTimer_MODE_X4                        ((uint32)(DisplayTimer__X4              <<  \
                                                                  DisplayTimer_QUAD_MODE_SHIFT))

/* Counter modes */
#define DisplayTimer_COUNT_UP                       ((uint32)(DisplayTimer__COUNT_UP        <<  \
                                                                  DisplayTimer_UPDOWN_SHIFT))
#define DisplayTimer_COUNT_DOWN                     ((uint32)(DisplayTimer__COUNT_DOWN      <<  \
                                                                  DisplayTimer_UPDOWN_SHIFT))
#define DisplayTimer_COUNT_UPDOWN0                  ((uint32)(DisplayTimer__COUNT_UPDOWN0   <<  \
                                                                  DisplayTimer_UPDOWN_SHIFT))
#define DisplayTimer_COUNT_UPDOWN1                  ((uint32)(DisplayTimer__COUNT_UPDOWN1   <<  \
                                                                  DisplayTimer_UPDOWN_SHIFT))

/* PWM output invert */
#define DisplayTimer_INVERT_LINE                    ((uint32)(DisplayTimer__INVERSE         <<  \
                                                                  DisplayTimer_INV_OUT_SHIFT))
#define DisplayTimer_INVERT_LINE_N                  ((uint32)(DisplayTimer__INVERSE         <<  \
                                                                  DisplayTimer_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define DisplayTimer_TRIG_RISING                    ((uint32)DisplayTimer__TRIG_RISING)
#define DisplayTimer_TRIG_FALLING                   ((uint32)DisplayTimer__TRIG_FALLING)
#define DisplayTimer_TRIG_BOTH                      ((uint32)DisplayTimer__TRIG_BOTH)
#define DisplayTimer_TRIG_LEVEL                     ((uint32)DisplayTimer__TRIG_LEVEL)

/* Interrupt mask */
#define DisplayTimer_INTR_MASK_TC                   ((uint32)DisplayTimer__INTR_MASK_TC)
#define DisplayTimer_INTR_MASK_CC_MATCH             ((uint32)DisplayTimer__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define DisplayTimer_CC_MATCH_SET                   (0x00u)
#define DisplayTimer_CC_MATCH_CLEAR                 (0x01u)
#define DisplayTimer_CC_MATCH_INVERT                (0x02u)
#define DisplayTimer_CC_MATCH_NO_CHANGE             (0x03u)
#define DisplayTimer_OVERLOW_SET                    (0x00u)
#define DisplayTimer_OVERLOW_CLEAR                  (0x04u)
#define DisplayTimer_OVERLOW_INVERT                 (0x08u)
#define DisplayTimer_OVERLOW_NO_CHANGE              (0x0Cu)
#define DisplayTimer_UNDERFLOW_SET                  (0x00u)
#define DisplayTimer_UNDERFLOW_CLEAR                (0x10u)
#define DisplayTimer_UNDERFLOW_INVERT               (0x20u)
#define DisplayTimer_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define DisplayTimer_PWM_MODE_LEFT                  (DisplayTimer_CC_MATCH_CLEAR        |   \
                                                         DisplayTimer_OVERLOW_SET           |   \
                                                         DisplayTimer_UNDERFLOW_NO_CHANGE)
#define DisplayTimer_PWM_MODE_RIGHT                 (DisplayTimer_CC_MATCH_SET          |   \
                                                         DisplayTimer_OVERLOW_NO_CHANGE     |   \
                                                         DisplayTimer_UNDERFLOW_CLEAR)
#define DisplayTimer_PWM_MODE_ASYM                  (DisplayTimer_CC_MATCH_INVERT       |   \
                                                         DisplayTimer_OVERLOW_SET           |   \
                                                         DisplayTimer_UNDERFLOW_CLEAR)

#if (DisplayTimer_CY_TCPWM_V2)
    #if(DisplayTimer_CY_TCPWM_4000)
        #define DisplayTimer_PWM_MODE_CENTER                (DisplayTimer_CC_MATCH_INVERT       |   \
                                                                 DisplayTimer_OVERLOW_NO_CHANGE     |   \
                                                                 DisplayTimer_UNDERFLOW_CLEAR)
    #else
        #define DisplayTimer_PWM_MODE_CENTER                (DisplayTimer_CC_MATCH_INVERT       |   \
                                                                 DisplayTimer_OVERLOW_SET           |   \
                                                                 DisplayTimer_UNDERFLOW_CLEAR)
    #endif /* (DisplayTimer_CY_TCPWM_4000) */
#else
    #define DisplayTimer_PWM_MODE_CENTER                (DisplayTimer_CC_MATCH_INVERT       |   \
                                                             DisplayTimer_OVERLOW_NO_CHANGE     |   \
                                                             DisplayTimer_UNDERFLOW_CLEAR)
#endif /* (DisplayTimer_CY_TCPWM_NEW) */

/* Command operations without condition */
#define DisplayTimer_CMD_CAPTURE                    (0u)
#define DisplayTimer_CMD_RELOAD                     (8u)
#define DisplayTimer_CMD_STOP                       (16u)
#define DisplayTimer_CMD_START                      (24u)

/* Status */
#define DisplayTimer_STATUS_DOWN                    (1u)
#define DisplayTimer_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   DisplayTimer_Init(void);
void   DisplayTimer_Enable(void);
void   DisplayTimer_Start(void);
void   DisplayTimer_Stop(void);

void   DisplayTimer_SetMode(uint32 mode);
void   DisplayTimer_SetCounterMode(uint32 counterMode);
void   DisplayTimer_SetPWMMode(uint32 modeMask);
void   DisplayTimer_SetQDMode(uint32 qdMode);

void   DisplayTimer_SetPrescaler(uint32 prescaler);
void   DisplayTimer_TriggerCommand(uint32 mask, uint32 command);
void   DisplayTimer_SetOneShot(uint32 oneShotEnable);
uint32 DisplayTimer_ReadStatus(void);

void   DisplayTimer_SetPWMSyncKill(uint32 syncKillEnable);
void   DisplayTimer_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   DisplayTimer_SetPWMDeadTime(uint32 deadTime);
void   DisplayTimer_SetPWMInvert(uint32 mask);

void   DisplayTimer_SetInterruptMode(uint32 interruptMask);
uint32 DisplayTimer_GetInterruptSourceMasked(void);
uint32 DisplayTimer_GetInterruptSource(void);
void   DisplayTimer_ClearInterrupt(uint32 interruptMask);
void   DisplayTimer_SetInterrupt(uint32 interruptMask);

void   DisplayTimer_WriteCounter(uint32 count);
uint32 DisplayTimer_ReadCounter(void);

uint32 DisplayTimer_ReadCapture(void);
uint32 DisplayTimer_ReadCaptureBuf(void);

void   DisplayTimer_WritePeriod(uint32 period);
uint32 DisplayTimer_ReadPeriod(void);
void   DisplayTimer_WritePeriodBuf(uint32 periodBuf);
uint32 DisplayTimer_ReadPeriodBuf(void);

void   DisplayTimer_WriteCompare(uint32 compare);
uint32 DisplayTimer_ReadCompare(void);
void   DisplayTimer_WriteCompareBuf(uint32 compareBuf);
uint32 DisplayTimer_ReadCompareBuf(void);

void   DisplayTimer_SetPeriodSwap(uint32 swapEnable);
void   DisplayTimer_SetCompareSwap(uint32 swapEnable);

void   DisplayTimer_SetCaptureMode(uint32 triggerMode);
void   DisplayTimer_SetReloadMode(uint32 triggerMode);
void   DisplayTimer_SetStartMode(uint32 triggerMode);
void   DisplayTimer_SetStopMode(uint32 triggerMode);
void   DisplayTimer_SetCountMode(uint32 triggerMode);

void   DisplayTimer_SaveConfig(void);
void   DisplayTimer_RestoreConfig(void);
void   DisplayTimer_Sleep(void);
void   DisplayTimer_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define DisplayTimer_BLOCK_CONTROL_REG              (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define DisplayTimer_BLOCK_CONTROL_PTR              ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define DisplayTimer_COMMAND_REG                    (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define DisplayTimer_COMMAND_PTR                    ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define DisplayTimer_INTRRUPT_CAUSE_REG             (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define DisplayTimer_INTRRUPT_CAUSE_PTR             ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define DisplayTimer_CONTROL_REG                    (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__CTRL )
#define DisplayTimer_CONTROL_PTR                    ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__CTRL )
#define DisplayTimer_STATUS_REG                     (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__STATUS )
#define DisplayTimer_STATUS_PTR                     ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__STATUS )
#define DisplayTimer_COUNTER_REG                    (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__COUNTER )
#define DisplayTimer_COUNTER_PTR                    ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__COUNTER )
#define DisplayTimer_COMP_CAP_REG                   (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__CC )
#define DisplayTimer_COMP_CAP_PTR                   ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__CC )
#define DisplayTimer_COMP_CAP_BUF_REG               (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define DisplayTimer_COMP_CAP_BUF_PTR               ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__CC_BUFF )
#define DisplayTimer_PERIOD_REG                     (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__PERIOD )
#define DisplayTimer_PERIOD_PTR                     ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__PERIOD )
#define DisplayTimer_PERIOD_BUF_REG                 (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define DisplayTimer_PERIOD_BUF_PTR                 ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define DisplayTimer_TRIG_CONTROL0_REG              (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define DisplayTimer_TRIG_CONTROL0_PTR              ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define DisplayTimer_TRIG_CONTROL1_REG              (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define DisplayTimer_TRIG_CONTROL1_PTR              ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define DisplayTimer_TRIG_CONTROL2_REG              (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define DisplayTimer_TRIG_CONTROL2_PTR              ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define DisplayTimer_INTERRUPT_REQ_REG              (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR )
#define DisplayTimer_INTERRUPT_REQ_PTR              ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR )
#define DisplayTimer_INTERRUPT_SET_REG              (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define DisplayTimer_INTERRUPT_SET_PTR              ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR_SET )
#define DisplayTimer_INTERRUPT_MASK_REG             (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define DisplayTimer_INTERRUPT_MASK_PTR             ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR_MASK )
#define DisplayTimer_INTERRUPT_MASKED_REG           (*(reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR_MASKED )
#define DisplayTimer_INTERRUPT_MASKED_PTR           ( (reg32 *) DisplayTimer_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define DisplayTimer_MASK                           ((uint32)DisplayTimer_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define DisplayTimer_RELOAD_CC_SHIFT                (0u)
#define DisplayTimer_RELOAD_PERIOD_SHIFT            (1u)
#define DisplayTimer_PWM_SYNC_KILL_SHIFT            (2u)
#define DisplayTimer_PWM_STOP_KILL_SHIFT            (3u)
#define DisplayTimer_PRESCALER_SHIFT                (8u)
#define DisplayTimer_UPDOWN_SHIFT                   (16u)
#define DisplayTimer_ONESHOT_SHIFT                  (18u)
#define DisplayTimer_QUAD_MODE_SHIFT                (20u)
#define DisplayTimer_INV_OUT_SHIFT                  (20u)
#define DisplayTimer_INV_COMPL_OUT_SHIFT            (21u)
#define DisplayTimer_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define DisplayTimer_RELOAD_CC_MASK                 ((uint32)(DisplayTimer_1BIT_MASK        <<  \
                                                                            DisplayTimer_RELOAD_CC_SHIFT))
#define DisplayTimer_RELOAD_PERIOD_MASK             ((uint32)(DisplayTimer_1BIT_MASK        <<  \
                                                                            DisplayTimer_RELOAD_PERIOD_SHIFT))
#define DisplayTimer_PWM_SYNC_KILL_MASK             ((uint32)(DisplayTimer_1BIT_MASK        <<  \
                                                                            DisplayTimer_PWM_SYNC_KILL_SHIFT))
#define DisplayTimer_PWM_STOP_KILL_MASK             ((uint32)(DisplayTimer_1BIT_MASK        <<  \
                                                                            DisplayTimer_PWM_STOP_KILL_SHIFT))
#define DisplayTimer_PRESCALER_MASK                 ((uint32)(DisplayTimer_8BIT_MASK        <<  \
                                                                            DisplayTimer_PRESCALER_SHIFT))
#define DisplayTimer_UPDOWN_MASK                    ((uint32)(DisplayTimer_2BIT_MASK        <<  \
                                                                            DisplayTimer_UPDOWN_SHIFT))
#define DisplayTimer_ONESHOT_MASK                   ((uint32)(DisplayTimer_1BIT_MASK        <<  \
                                                                            DisplayTimer_ONESHOT_SHIFT))
#define DisplayTimer_QUAD_MODE_MASK                 ((uint32)(DisplayTimer_3BIT_MASK        <<  \
                                                                            DisplayTimer_QUAD_MODE_SHIFT))
#define DisplayTimer_INV_OUT_MASK                   ((uint32)(DisplayTimer_2BIT_MASK        <<  \
                                                                            DisplayTimer_INV_OUT_SHIFT))
#define DisplayTimer_MODE_MASK                      ((uint32)(DisplayTimer_3BIT_MASK        <<  \
                                                                            DisplayTimer_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define DisplayTimer_CAPTURE_SHIFT                  (0u)
#define DisplayTimer_COUNT_SHIFT                    (2u)
#define DisplayTimer_RELOAD_SHIFT                   (4u)
#define DisplayTimer_STOP_SHIFT                     (6u)
#define DisplayTimer_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define DisplayTimer_CAPTURE_MASK                   ((uint32)(DisplayTimer_2BIT_MASK        <<  \
                                                                  DisplayTimer_CAPTURE_SHIFT))
#define DisplayTimer_COUNT_MASK                     ((uint32)(DisplayTimer_2BIT_MASK        <<  \
                                                                  DisplayTimer_COUNT_SHIFT))
#define DisplayTimer_RELOAD_MASK                    ((uint32)(DisplayTimer_2BIT_MASK        <<  \
                                                                  DisplayTimer_RELOAD_SHIFT))
#define DisplayTimer_STOP_MASK                      ((uint32)(DisplayTimer_2BIT_MASK        <<  \
                                                                  DisplayTimer_STOP_SHIFT))
#define DisplayTimer_START_MASK                     ((uint32)(DisplayTimer_2BIT_MASK        <<  \
                                                                  DisplayTimer_START_SHIFT))

/* MASK */
#define DisplayTimer_1BIT_MASK                      ((uint32)0x01u)
#define DisplayTimer_2BIT_MASK                      ((uint32)0x03u)
#define DisplayTimer_3BIT_MASK                      ((uint32)0x07u)
#define DisplayTimer_6BIT_MASK                      ((uint32)0x3Fu)
#define DisplayTimer_8BIT_MASK                      ((uint32)0xFFu)
#define DisplayTimer_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define DisplayTimer_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define DisplayTimer_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(DisplayTimer_QUAD_ENCODING_MODES     << DisplayTimer_QUAD_MODE_SHIFT))       |\
         ((uint32)(DisplayTimer_CONFIG                  << DisplayTimer_MODE_SHIFT)))

#define DisplayTimer_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(DisplayTimer_PWM_STOP_EVENT          << DisplayTimer_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(DisplayTimer_PWM_OUT_INVERT          << DisplayTimer_INV_OUT_SHIFT))         |\
         ((uint32)(DisplayTimer_PWM_OUT_N_INVERT        << DisplayTimer_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(DisplayTimer_PWM_MODE                << DisplayTimer_MODE_SHIFT)))

#define DisplayTimer_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(DisplayTimer_PWM_RUN_MODE         << DisplayTimer_ONESHOT_SHIFT))
            
#define DisplayTimer_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(DisplayTimer_PWM_ALIGN            << DisplayTimer_UPDOWN_SHIFT))

#define DisplayTimer_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(DisplayTimer_PWM_KILL_EVENT      << DisplayTimer_PWM_SYNC_KILL_SHIFT))

#define DisplayTimer_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(DisplayTimer_PWM_DEAD_TIME_CYCLE  << DisplayTimer_PRESCALER_SHIFT))

#define DisplayTimer_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(DisplayTimer_PWM_PRESCALER        << DisplayTimer_PRESCALER_SHIFT))

#define DisplayTimer_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(DisplayTimer_TC_PRESCALER            << DisplayTimer_PRESCALER_SHIFT))       |\
         ((uint32)(DisplayTimer_TC_COUNTER_MODE         << DisplayTimer_UPDOWN_SHIFT))          |\
         ((uint32)(DisplayTimer_TC_RUN_MODE             << DisplayTimer_ONESHOT_SHIFT))         |\
         ((uint32)(DisplayTimer_TC_COMP_CAP_MODE        << DisplayTimer_MODE_SHIFT)))
        
#define DisplayTimer_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(DisplayTimer_QUAD_PHIA_SIGNAL_MODE   << DisplayTimer_COUNT_SHIFT))           |\
         ((uint32)(DisplayTimer_QUAD_INDEX_SIGNAL_MODE  << DisplayTimer_RELOAD_SHIFT))          |\
         ((uint32)(DisplayTimer_QUAD_STOP_SIGNAL_MODE   << DisplayTimer_STOP_SHIFT))            |\
         ((uint32)(DisplayTimer_QUAD_PHIB_SIGNAL_MODE   << DisplayTimer_START_SHIFT)))

#define DisplayTimer_PWM_SIGNALS_MODES                                                              \
        (((uint32)(DisplayTimer_PWM_SWITCH_SIGNAL_MODE  << DisplayTimer_CAPTURE_SHIFT))         |\
         ((uint32)(DisplayTimer_PWM_COUNT_SIGNAL_MODE   << DisplayTimer_COUNT_SHIFT))           |\
         ((uint32)(DisplayTimer_PWM_RELOAD_SIGNAL_MODE  << DisplayTimer_RELOAD_SHIFT))          |\
         ((uint32)(DisplayTimer_PWM_STOP_SIGNAL_MODE    << DisplayTimer_STOP_SHIFT))            |\
         ((uint32)(DisplayTimer_PWM_START_SIGNAL_MODE   << DisplayTimer_START_SHIFT)))

#define DisplayTimer_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(DisplayTimer_TC_CAPTURE_SIGNAL_MODE  << DisplayTimer_CAPTURE_SHIFT))         |\
         ((uint32)(DisplayTimer_TC_COUNT_SIGNAL_MODE    << DisplayTimer_COUNT_SHIFT))           |\
         ((uint32)(DisplayTimer_TC_RELOAD_SIGNAL_MODE   << DisplayTimer_RELOAD_SHIFT))          |\
         ((uint32)(DisplayTimer_TC_STOP_SIGNAL_MODE     << DisplayTimer_STOP_SHIFT))            |\
         ((uint32)(DisplayTimer_TC_START_SIGNAL_MODE    << DisplayTimer_START_SHIFT)))
        
#define DisplayTimer_TIMER_UPDOWN_CNT_USED                                                          \
                ((DisplayTimer__COUNT_UPDOWN0 == DisplayTimer_TC_COUNTER_MODE)                  ||\
                 (DisplayTimer__COUNT_UPDOWN1 == DisplayTimer_TC_COUNTER_MODE))

#define DisplayTimer_PWM_UPDOWN_CNT_USED                                                            \
                ((DisplayTimer__CENTER == DisplayTimer_PWM_ALIGN)                               ||\
                 (DisplayTimer__ASYMMETRIC == DisplayTimer_PWM_ALIGN))               
        
#define DisplayTimer_PWM_PR_INIT_VALUE              (1u)
#define DisplayTimer_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_DisplayTimer_H */

/* [] END OF FILE */
