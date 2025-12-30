/*
 * AppValve.h
 *
 *  Created on: 2025. 5. 27.
 *      Author: mctp
 */

#ifndef CODE_SRC_APPVALVE_H_
#define CODE_SRC_APPVALVE_H_
#include <stdint.h>
#include "defines.h"

#define CALSTEP_RESET 0
#define CALSTEP_START 1
#define CALSTEP_0d_POS 2
#define CALSTEP_360d_POS 3
#define CALSTEP_CALC 5
#define CALSTEP_INIT_POS 7
#define CALSTEP_FAULT 8
#define CALSTEP_COMPLETED 9

/*scale: 0.01V */
#define VS_UNDER_STOP (uint16_t)(8.0f * C_VOLTAGE_RESOLUTION_SCALE)	  //
#define VS_UNDER_RETURN (uint16_t)(9.0f * C_VOLTAGE_RESOLUTION_SCALE) //
#define VS_OVER_STOP (uint16_t)(17.0f * C_VOLTAGE_RESOLUTION_SCALE)	  //
#define VS_OVER_RETURN (uint16_t)(16.0f * C_VOLTAGE_RESOLUTION_SCALE) //
#define VS_ENTER_COUNT 200u

#define IGN_UNDER_STOP (uint16_t)(7.0f * C_VOLTAGE_RESOLUTION_SCALE)   //
#define IGN_UNDER_RETURN (uint16_t)(8.0f * C_VOLTAGE_RESOLUTION_SCALE) //
#define IGN_OVER_STOP (uint16_t)(18.0f * C_VOLTAGE_RESOLUTION_SCALE)   //
#define IGN_OVER_RETURN (uint16_t)(17.0f * C_VOLTAGE_RESOLUTION_SCALE) //
#define IGN_ENTER_COUNT 500u

#define TEMP_UNDER_STOP ((0u * C_TEMP_RESOLUTION_SCALE) + C_TEMP_CONV_OFFSET)	 //
#define TEMP_UNDER_RETURN ((10u * C_TEMP_RESOLUTION_SCALE) + C_TEMP_CONV_OFFSET) //
#define TEMP_OVER_STOP ((135u * C_TEMP_RESOLUTION_SCALE) + C_TEMP_CONV_OFFSET)	 //
#define TEMP_OVER_RETURN ((125u * C_TEMP_RESOLUTION_SCALE) + C_TEMP_CONV_OFFSET) //
#define TEMP_ENTER_COUNT 100u

#define MCU_FAULT_COUNT 		200u
#define MCU_FAULT_VS 			300u
#define MCU_FAULT_RETURN_VS 	320u
#define MCU_FAULT_RERTY_TIME 	500u


#define LIN_TIMEOUT_COUNT 4000u

typedef enum
{
	VALVE_INIT,
	VALVE_STANDBY,
	VALVE_READY,
	VALVE_OPERATION, // 3
	VALVE_DIAGRUN,
	VALVE_CALIBRATION,
	VALVE_FAULT,	  /* recoverable by power on only - motor fault */
	VALVE_PROTECTION, /* recoverable by condition change - i.e. vs, temp */
	VALVE_POWERLATCH,
	VALVE_LOWPOWER,
	VALVE_UNDEF
} tValveState;

typedef struct 
{
	uint8_t status;
	tValveState next_state;
}Protectoin_Check_Result;


extern tProtectCondition u16EventState;
extern uint16_t u16EventValue;

void clear_fail_safe_retry_cnt(tProtectCondition event_state);
void ValveTargetAngleUpdate(int16_t angle);
tValveState get_sys_valve_mode(void);
tValveState get_valve_mode(void);
uint16_t get_valve_voltage(void);
int16_t get_valve_temperature(void);
uint16_t get_valve_motCurrent(void);
void ValveLinGetCommand(void);
void ValveLinUpdateSignals(void);
void AppValveInit(void);
void check_retry_cnt_protection_uv(void);
void check_retry_cnt_protection_ov(void);
Protectoin_Check_Result check_protection_uv_ov(Protectoin_Check_Result result_data);
Protectoin_Check_Result check_protection_temp(Protectoin_Check_Result result_data);
void check_retry_cnt_protection_comm(void);
Protectoin_Check_Result check_protection_comm(Protectoin_Check_Result result_data);
void check_retry_cnt_protection_oc(void);
Protectoin_Check_Result check_protection_oc(Protectoin_Check_Result result_data);
void check_retry_cnt_protection_pos_fault(void);
Protectoin_Check_Result check_protection_pos_fault(Protectoin_Check_Result result_data);
void check_retry_cnt_protection_mcu_fault(void);
Protectoin_Check_Result check_protection_mcu_fault(Protectoin_Check_Result result_data);
void check_retry_cnt_protection_obstruction_stall(void);
Protectoin_Check_Result check_protection_obstruction_stall(Protectoin_Check_Result result_data);
void check_retry_cnt_protection_gmr_fault(void);
Protectoin_Check_Result check_protection_gmr_fault(Protectoin_Check_Result result_data);
void event_memry_save(tProtectCondition event_state, uint16_t event_value);
void AppValveTask(void);

#endif /* CODE_SRC_APPVALVE_H_ */
