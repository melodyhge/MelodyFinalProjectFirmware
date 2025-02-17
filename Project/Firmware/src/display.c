#include "main.h"
#include "display.h"
#include "rtc.h"
#include "tempr.h"
#include "scheduler.h"



#define DISPLAY_INTERVAL_MS 10000 // Switch display every 10 seconds

typedef enum {
    DISPLAY_TIME,
    DISPLAY_DATE,
    DISPLAY_TEMPERATURE
} display_mode_t;

static display_mode_t current_mode = DISPLAY_TIME; // Start with time display

/**
 * Task to manage the display of time, date, and temperature
 * @param me Task handle
 * @param msg Message pointer (not used here)
 * @param arg Additional arguments (not used here)
 */
void display_task(s_task_handle_t me, s_task_msg_t **msg, void *arg) {
    static uint32_t last_switch_ticks = 0; // Last time the display was switched
    uint32_t current_ticks = get_system_ticks();

    // Only update the display every DISPLAY_INTERVAL_MS
    if ((current_ticks - last_switch_ticks) >= DISPLAY_INTERVAL_MS) {
        last_switch_ticks = current_ticks; // Update the last switch time

        // Switch the display mode
        switch (current_mode) {
            case DISPLAY_TIME: {
                uint8_t hours, minutes, seconds;
                if (get_time_date(&hours, &minutes, &seconds, NULL, NULL, NULL, NULL)) {
                    display_time(hours, minutes);
                }
                current_mode = DISPLAY_DATE;
                break;
            }
            case DISPLAY_DATE: {
                uint8_t date, month, year;
                if (get_time_date(NULL, NULL, NULL, NULL, &date, &month, &year)) {
                    display_date(date, month, year);
                }
                current_mode = DISPLAY_TEMPERATURE;
                break;
            }
            case DISPLAY_TEMPERATURE: {
                float temperature = read_temperature();
                display_temperature(temperature);
                current_mode = DISPLAY_TIME;
                break;
            }
        }
    }

    s_task_flush_msgs(msg);
}

/**
 * Initialize the display hardware and create the display task
 * @return true if initialized successfully, false otherwise
 */
 
bool init_display(void) {
    // Initialize hardware-related display components here, if necessary
    bool ret = true; // Initialize the ret variable

    // Create the display task
    ret &= s_task_create(
        true,                    // Task is enabled
        S_TASK_NORMAL_PRIORITY,  // Normal priority for the task
        1000,                    // Periodicity in ms
        display_task,            // Task function
        NULL,                    // No specific argument
        NULL                     // No message queue for this task
    );

    if (ret) {
        printf("Display initialized successfully.\n");
    } else {
        printf("Failed to initialize display.\n");
    }

    return ret; // Return the result of task creation
}
