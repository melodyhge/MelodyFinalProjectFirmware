#include "rtc.h"
#include "i2c.h"  // Include your I2C communication interface header
#define DS1307_ADDRESS 0x68  // I2C address of the DS1307 RTC
// Function to initialize the DS1307 RTC
bool init_rtc(void) {
    uint8_t seconds = 0x00;  // Clear the CH (Clock Halt) bit to start the oscillator
    if (!I2C_Write(DS1307_ADDRESS, 0x00, &seconds, 1)) {
        return false;
    }

    uint8_t control = 0x00; // Enable the oscillator without enabling the square wave output
    return I2C_Write(DS1307_ADDRESS, 0x07, &control, 1);
}


// Function to get the current time and date from the RTC
bool get_time_date(uint8_t *hours, uint8_t *minutes, uint8_t *seconds,
                   uint8_t *day, uint8_t *date, uint8_t *month, uint8_t *year) {
    uint8_t data[7];
    if (!I2C_Read(DS1307_ADDRESS, 0x00, data, 7)) {
        return false;
    }

    if (seconds) *seconds = (data[0] & 0x0F) + ((data[0] >> 4) * 10);
    if (minutes) *minutes = (data[1] & 0x0F) + ((data[1] >> 4) * 10);
    if (hours) *hours = (data[2] & 0x0F) + ((data[2] >> 4) * 10);
    if (day) *day = data[3];
    if (date) *date = (data[4] & 0x0F) + ((data[4] >> 4) * 10);
    if (month) *month = (data[5] & 0x0F) + ((data[5] >> 4) * 10);
    if (year) *year = (data[6] & 0x0F) + ((data[6] >> 4) * 10);

    return true;
}

