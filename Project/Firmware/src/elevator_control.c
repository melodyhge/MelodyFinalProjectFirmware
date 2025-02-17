#include "elevator_control.h"
#include "hardware.h"
 
// Current state
static floor_t current_floor = FLOOR_GF;
 
// Initialize the elevator system
void init_elevator(void) {
    // Set motor pins to low
    output_low(MOTOR_SPEED_HIGH);
    output_low(MOTOR_SPEED_LOW);
    output_low(MOTOR_DIR1);
    output_low(MOTOR_DIR2);
 
    // Initialize LEDs
    output_low(LED_UP);
    output_low(LED_MIDDLE);
    output_low(LED_DOWN);
 
    // Initialize 7-segment display
    display_floor(FLOOR_GF);
}
 
// Move the elevator to a target floor
void move_to_floor(floor_t target_floor) {
    if (current_floor == target_floor) {
        // Elevator already at the target floor
        update_leds(current_floor, target_floor);
        return;
    }
 
    // Determine direction
    if (current_floor < target_floor) {
        // Move up
        output_high(MOTOR_DIR1);
        output_low(MOTOR_DIR2);
    } else {
        // Move down
        output_low(MOTOR_DIR1);
        output_high(MOTOR_DIR2);
    }
 
    // Set motor speed
    output_high(MOTOR_SPEED_HIGH);
    delay_ms(2000); // Simulate movement time (adjust as needed)
 
    // Stop motor
    output_low(MOTOR_SPEED_HIGH);
    output_low(MOTOR_DIR1);
    output_low(MOTOR_DIR2);
 
    // Update current floor
    current_floor = target_floor;
 
    // Update LEDs and display
    update_leds(current_floor, target_floor);
    display_floor(current_floor);
}
 
// Update LEDs to show the elevator's movement
void update_leds(floor_t current_floor, floor_t target_floor) {
    // Turn off all LEDs
    output_low(LED_UP);
    output_low(LED_MIDDLE);
    output_low(LED_DOWN);
 
    if (current_floor == target_floor) {
        // Elevator at target floor
        output_high(LED_MIDDLE);
    } else if (current_floor < target_floor) {
        // Moving up
        output_high(LED_MIDDLE);
        output_high(LED_UP);
    } else {
        // Moving down
        output_high(LED_MIDDLE);
        output_high(LED_DOWN);
    }
}
 
// Display the current floor on the 7-segment display
void display_floor(floor_t floor) {
    switch (floor) {
        case FLOOR_GF:
            set_segments(DISP_CT_D1_BCD0, 0x00); // Display '0' for GF
            break;
        case FLOOR_F1:
            set_segments(DISP_CT_D1_BCD0, 0x01); // Display '1'
            break;
        case FLOOR_F2:
            set_segments(DISP_CT_D1_BCD0, 0x02); // Display '2'
            break;
        case FLOOR_F3:
            set_segments(DISP_CT_D1_BCD0, 0x03); // Display '3'
            break;
    }
}
 
// Handle button presses (outside and inside the elevator)
void handle_buttons(void) {
    // Check floor buttons
    if (input(BTN_GF)) {
        move_to_floor(FLOOR_GF);
    } else if (input(BTN_F1)) {
        move_to_floor(FLOOR_F1);
    } else if (input(BTN_F2)) {
        move_to_floor(FLOOR_F2);
    } else if (input(BTN_F3)) {
        move_to_floor(FLOOR_F3);
    }
 
    // Check cabin buttons
    if (input(CAB_BTN_F1)) {
        move_to_floor(FLOOR_F1);
    } else if (input(CAB_BTN_F2)) {
        move_to_floor(FLOOR_F2);
    } else if (input(CAB_BTN_F3)) {
        move_to_floor(FLOOR_F3);
    }
}
