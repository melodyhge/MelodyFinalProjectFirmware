#include "main.h"
#include "hardware.h"
#include "system.h"
#include "timer.h"
#include "adc.h"
#include "tempr.h"
#include "display.h"
#include "scheduler.h"

void main()
{
    bool ret;
    delay_ms(100);                  /*power up delay, wait a 100ms*/
    /*Initialize scheduler:*/
    ret = scheduler_init(get_ticks_counter);
    
    
    if (true == ret)
    {
        //output_high(CT_COL);
        /*Initialize system:*/
        ret &= init_hw();           /*initialize HW and create LED heartbeat task*/
        ret &= init_system();       /*initialize system and enable interrupt(s) (events)*/
        ret &= init_adc();  
        ret &= init_temp_sensor();
        
        /*initialize ADC sampling*/
        /*. . . . . . .*/
        if (true == ret)            /*success?*/
        {
            while (true)
            {
                scheduler();        /*run scheduler forever*/
            }
        }
        else
        {
            while (true);           /*stall*/
        }
    }
    else
    {
        while (true);               /*stall*/
    }
}


