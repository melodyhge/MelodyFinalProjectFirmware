#ifndef ELEVATOR_CONTROL_H
#define ELEVATOR_CONTROL_H
 
#include <stdint.h>
#include <stdbool.h>
 
// Motor Control Pins
#define MOTOR_SPEED_HIGH   PIN_X1
#define MOTOR_SPEED_LOW    PIN_X2
#define MOTOR_DIR1         PIN_X3
#define MOTOR_DIR2         PIN_X4
 
// Floor LEDs
#define LED_UP             PIN_Y1
#define LED_MIDDLE         PIN_Y2
#define LED_DOWN           PIN_Y3
 
// Floor Buttons (Outside the Elevator)
#define BTN_GF             PIN_A1
#define BTN_F1             PIN_A2
#define BTN_F2             PIN_A3
#define BTN_F3             PIN_A4
 
// Buttons Inside the Elevator
#define CAB_BTN_F1         PIN_B1
#define CAB_BTN_F2         PIN_B2
#define CAB_BTN_F3         PIN_B3
 
// 7-Segment Display Pins
#define DISP_CT_D1_BCD0    PIN_C1
#define DISP_CT_D2_BCD0    PIN_C2
#define DISP_CT_D3_BCD0    PIN_C3
#define DISP_CT_D4_BCD0    PIN_C4
 
// Elevator States
typedef enum {
    FLOOR_GF,
    FLOOR_F1,
    FLOOR_F2,
    FLOOR_F3
} floor_t;
 
// Functions
void init_elevator(void);
void move_to_floor(floor_t target_floor);
void update_leds(floor_t current_floor, floor_t target_floor);
void display_floor(floor_t floor);
void handle_buttons(void);
 
#endif
