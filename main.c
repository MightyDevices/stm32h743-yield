/**
 * @file main.c
 *
 * @date 23.06.2019
 * @author twatorowski (tw@mightydevices.com)
 *
 * @brief main application file
 */

#include "compiler.h"
#include "vectors.h"
#include "dev/led.h"
#include "dev/systime.h"
#include "dev/usart3.h"
#include "sys/yield.h"

/* program init function, called before main with interrupts disabled */
void Init(void)
{
    /* start the context switcher */
    Yield_Init();
}

/* program main function, must return int so that gcc does not complain in 
 * pedantic mode (-Wmain) */
int Main(void)
{
    /* initialize usart 3 */
    USART3_Init();
    /* initialize system timer */
    SysTime_Init();
    /* initialize led driver */
    Led_Init();
    /* set led state */
    Led_SetState(1, LED_GRN | LED_RED | LED_YEL);

    /* execution loop */
    while (1) {
    }

    /* never reached */
    return 0;
}
