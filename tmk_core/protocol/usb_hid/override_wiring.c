/*
 * To keep Timer0 for common/timer.c override arduino/wiring.c.
 */
#define __DELAY_BACKWARD_COMPATIBLE__
<<<<<<< HEAD
#include <util/delay.h>
=======
#include "wait.h"
>>>>>>> upstream/master
#include "platforms/timer.h"


unsigned long millis(void)
{
    return timer_read32();
}
unsigned long micros(void)
{
    return timer_read32() * 1000UL;
}
void delay(unsigned long ms)
{
    wait_ms(ms);
}
void delayMicroseconds(unsigned int us)
{
    wait_us(us);
}
void init(void)
{
    timer_init();
}
