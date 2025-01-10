/**
* @file tempr.c
* @author Majdi Richa (majdi.richa@gmail.com)
* @brief 
* @version 0.1
* @date 2024-11-18
* 
* @copyright Copyright (c) 2024
* 
*/
#include "main.h"
#include "tempr.h"
#include "adc.h"
#include "scheduler.h"
#include "hardware.h"
void display_temp(s_task_handle_t me, s_task_msg_t **msg, void* arg);
 
 
bool init_temp_sensor(void)
{
    bool ret = false;
    ret &= s_task_create(true,S_TASK_NORMAL_PRIORITY,1000,display_temp,NULL,NULL);
    return ret;
}
float read_temperature(void)
{
    uint16_t adc_value = get_adc_live(0); // Get the latest ADC value for channel 0
    float voltage = (adc_value * ADC_VREF) / ADC_MAX_LVL; // Convert ADC value to voltage
    float temperature = voltage * 100.0; // Convert voltage to temperature (LM35 outputs 10mV/°C)
    return temperature;
}
void display_temp(s_task_handle_t me, s_task_msg_t **msg, void* arg){
    float temp = read_temperature();     /*get it*/
}
