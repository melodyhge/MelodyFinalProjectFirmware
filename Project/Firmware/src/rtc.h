#ifndef RTC_H
#define RTC_H
#include <stdint.h>  // for using standard integer types
#include <stdbool.h> // for using boolean type
// Function to initialize the DS1307 RTC
bool init_rtc(void);
// Function to get the current time and date from the RTC
bool get_time_date(uint8_t *hours, uint8_t *minutes, uint8_t *seconds,
                   uint8_t *day, uint8_t *date, uint8_t *month, uint8_t *year);

#endif // RTC_H
