/**
* @file tempr.h
* @author Majdi Richa (majdi.richa@gmail.com)
* @brief 
* @version 0.1
* @date 2024-11-18
* 
* @copyright Copyright (c) 2024
* 
*/
#ifndef TEMPR_H
#define TEMPR_H
#define MAX_TEMPERATURE     (100.0)   // Maximum range for LM35
bool init_temp_sensor(void);
float read_temperature(void);
#endif
