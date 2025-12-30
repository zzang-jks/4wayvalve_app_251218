/*
 * defines.h
 *
 *  Created on: 2025. 7. 23.
 *      Author: ?��?��?��?��?��?��
// 2025. 7. 23.
1. temperature conv result modify
 app_sensor.c : minus deg offset 40
2. abnormal retryCnt -> 10
// 2025. 8. 11.
VALVE_DIAGRUN ?��?��?��?��?��?�� enable ?��?��?��?��?��?��?��?��?��?���? Run
get_sys_valve_mode ?��?��곤옙
POINT_TEST_ENABLE
// 2025. 8. 19.
LIN wake up disable
ValveInitTask ?��?��?��?��?��?�� IGN ON ?��?��?�� ?��?��?��?���? ?��?��?��?��
IGN_UNDEF ?��?��?��?��?��?�� ?��?��곤옙
adc_ConvertToVoltage ?��?��?��?��?��?��
valveDiagMcu ?��?��?��?��?��?��
VALVE_CALIBRATION ?��?��?��?��?��?��?��?��?�� ValveFaultReset
?��?��깍옙?��?��?�� ?��?��?��?��?��?��?��?��?��?��?��?�� ?��?��곤옙
valve.diag.stallStatus ?��?��?��?��?��?��?��?��?��?��
// 2025. 9. 04.
sleep mode ?��?��?��?��?��?��?��?��?�� cal ?��?��?��?��?��?��
// 2025. 9. 10.
pwm_Start() -> dir ?��?��곤옙 ?��?��?�� ?��?��?��?��?��?�� ?��?��?��?��?��?��
ValveFaultReset()-> mot fault clear ?��?��?��?��?��?��
log_reset_source()-> ign check ?��?��?��?���? ?��?��?��?��?��?��
pwm_Off() ?��?��곤옙
 */

#ifndef CODE_SRC_DEFINES_H_
#define CODE_SRC_DEFINES_H_
#include <stdint.h>

#define SET	1
#define CLEAR 0
#define PCB_4WAY_VALVE 0
#define PCB_NONE 1
#define MLX81332_PCB PCB_NONE

#define TIME_1S	1000u
#define TIME_2S	2000u
#define TIME_500MS	500u

#define MAX_VALUE_1BYTE	0xffu
#define MAX_VALUE_2BYTE	0xffffu

#define SENSOR_FBS 0
#define SENSOR_GMR 1
#define C_SENSOR_TYPE SENSOR_GMR

#define uPWM_POL_LOW 0
#define uPWM_POL_HIGH 1
#define PWM_POL_METHOD uPWM_POL_LOW
#define C_MOT_POLE_POLAR 1

#define HW_VERSION (uint16_t)0x0001u
#define SW_VERSION (uint16_t)0x0002u

#define UART_FUNC_ENABLE 0
#define LIN_SLEEP_ENABLE 0
#define LIN_TIMEOUT_ENABLE 0
#define LIN_DEBUG_ENABLE 1
#define POINT_TEST_ENABLE 0
#define SOFTSTART_TEST_ENABLE 0
#define DUTY_ADJUST_ENABLE 0
#define LIN_WAKEUP_DISABLE 1
#define VALVE_IGN_PIN 0
#define DEBUG_GPIO_ENABLE 0 /* set to 1 to enable GPIO debug */
#define DEBUG_PIN_6 6
#define DEBUG_PIN_7 7
#define OUTPUT_PIN_5 5
#define NEW_CURCIT_TEST 0
#define DEBUG_INTERRUT_TIMER 0
#define DEBUG_MAIN_TASK_DURATION 1
#define DEBUG_MOT_CTRL_TASK 2
#define DEBUG_LIN_TASK 3
#define DEBUG_CAPTURE_INPUT 4
#define DEBUG_MODE DEBUG_CAPTURE_INPUT

#define PWM_LOW_ACTIVE 0
#define PWM_HIGH_ACTIVE 1
#define PWM_INPUT_POLARITY PWM_LOW_ACTIVE
#define PWM_INPUT_400Hz

#define C_PWMOUT_MAX_DUTY 2048U

#define CHECK_UNDER_VOLTAGE_CNT		600u
#define CHECK_OVER_VOLTAGE_CNT		600u
#define CHECK_HIGH_TEMP_CNT			500u
#define CHECK_LIN_COMM_ERR_CNT		1000u
#define CHECK_OVER_CURRENT_CNT		2u
#define CHECK_POSITION_SENSOR_CNT	5u

#define C_VOLTAGE_RESOLUTION_SCALE 100u
#define C_CURRENT_RESOLUTION_SCALE 1000u
#define C_TEMP_RESOLUTION_SCALE 1u
#define C_TEMP_CONV_OFFSET (40u * C_TEMP_RESOLUTION_SCALE)

#define C_MODE_A 0
#define C_MODE_B 1
#define C_STOPPER_POS_ANGLE (float)(18.5f) /*20250714*/
#define C_GMR_TARGET_OFFSET (180)
#define C_GMR_SENSOR_OFFSET (180)
#define DEFAULT_GMR_OFFSET (111) /* 290 */

#define C_GMR_ANGLE_SCALE_FACTOR 10U /**/
#define C_VALVE_MODE_B_ANGLE (int16_t)((float)((float)C_GMR_TARGET_OFFSET + C_STOPPER_POS_ANGLE) * C_GMR_ANGLE_SCALE_FACTOR)
#define C_VALVE_MODE_A_ANGLE (int16_t)((float)((float)C_GMR_TARGET_OFFSET + C_STOPPER_POS_ANGLE + 90.0f) * C_GMR_ANGLE_SCALE_FACTOR)
#if POINT_TEST_ENABLE == 0
#define C_VALVE_ACCURACY_ANGLE (2.0f * C_GMR_ANGLE_SCALE_FACTOR)
#else
#define C_VALVE_ACCURACY_ANGLE (1.0f * C_GMR_ANGLE_SCALE_FACTOR)
#endif
#define C_VALVE_CAL_HYSTERISYS (1.0f * C_GMR_ANGLE_SCALE_FACTOR)
#define C_STOPPER_0D_ANGLE (C_STOPPER_POS_ANGLE * C_GMR_ANGLE_SCALE_FACTOR)
#define C_STOPPER_360D_ANGLE (C_STOPPER_POS_ANGLE * C_GMR_ANGLE_SCALE_FACTOR)
#define C_GMR_SENSOR_ANGLE_LIMIT (360.0f * C_GMR_ANGLE_SCALE_FACTOR)
#define VDDA_OUTPUT_LEVEL 0 /* 0: 3.3V 1: 5V */


//-------------- Fail-Safe--------------------------------------

/**
 * @brief Position Status Definitions
 */
#define POS_NORMAL	0u	/**< Normal operating state for position. */
#define POS_FAULT	1u	/**< Fault state for position. */

/**
 * @brief MCU Status Definitions
 */
#define MCU_NORMAL 0u	/**< MCU is operating normally. */
#define MCU_FAULT  1u	/**< Fault detected in the MCU. */

/**
 * @brief GMR Sensor Status and Timing Definitions
 */
#define GMR_SENSOR_FAULT_TIME	500u	/**< Time threshold (in ms/ticks) before declaring a GMR sensor fault. */
#define GMR_SENSOR_NORMAL	0		/**< GMR sensor is operating normally. */
#define GMR_SENSOR_FAULT 	1		/**< GMR sensor fault detected. */

/**
 * @brief GMR STATUS Definitions
 */
#define GMR_FAULT_RETRY_CNT	3

/**
 * @brief MOTOR STALL Status Definitions
 */
#define OBSTRUCTION_STALL_RETRY_CNT	3


typedef enum
{
	C_DIR_NONE,
	C_DIR_CW,
	C_DIR_CCW
} tMotDirection;
typedef enum
{
	COMMUNICATION_NORNAL = 0,
	COMMUNICATION_ERROR,
	COMMUNICATION_UNDEF
} tLinComm;
typedef enum
{
	VS_NORMAL = 0,
	VS_UNDERVOLTAGE,
	VS_OVERVOLTAGE,
	VS_UNDEF
} tSupplyCondition;
typedef enum
{
	IGN_NORMAL = 0,
	IGN_OFF,
	IGN_UNDEF
} tIgnitionCondition;
typedef enum
{
	TEMPERATURE_NORMAL = 0,
	TEMPERATURE_LOW,
	TEMPERATURE_HIGH,
	TEMPERATURE_UNDEF
} tTemperCondition;
typedef enum
{
	S_CURR_NORMAL_ = 0,
	S_CURR_HIGH_,
	S_CURR_LOW_
} tCurrentCondition;

typedef enum
{
	C_STATUS_OFF_ = 0, // 0
	C_STATUS_RUN,	   // 1
	C_STATUS_STOP
} tSensorCondition;

typedef enum
{
	NONE_ERROR = 0,
	VS_LOW_ERROR,
	VS_HIGH_ERROR,
	TEMP_HIGH_ERROR,
	MOT_OC_ERROR,
	MOT_ABSTALL_ERROR,
	SENSOR_POS_ERROR,
	SENSOR_OUT_ERROR,
	MCU_ERROR,
	VALVE_CAL_FAULT,
	MOT_STALL_FAULT,
	MOT_SHORT_FAULT,
	MOT_OPEN_FAULT,
	VALVE_LIN_COMM_FAULT,
	UNDEF_ERROR
} tProtectCondition;

extern uint16_t g_u16DebugData[12];
extern uint16_t l_u16LinLostTimeoutDelay;
extern uint16_t l_u16PwmLostTimeoutDelay;

extern uint16_t test_Timer;
extern uint16_t test_relese_Timer;

void system_timer_ISR();
#endif /* CODE_SRC_DEFINES_H_ */

