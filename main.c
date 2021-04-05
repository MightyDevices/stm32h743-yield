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
#include "sys/heap.h"
#include "sys/yield.h"

#define DEBUG
#include "debug.h"

/* tests */
#include "test/yield_task_usart3.h"
#include "test/heap.h"
#include "test/lock.h"

/* program init function, called before main with interrupts disabled */
void Init(void)
{
    /* initialize dynamic memory */
    Heap_Init();
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

    /* show some debug activity */
    dprintf("Welcome!\n", 0);

    /* tests */
    /* test usart 3 communication */
    // TestYieldTaskUSART3_Init();
    // TestHeap_Init();
    TestLock_Init();

    /* execution loop */
    while (1) {
        Yield();
    }

    /* never reached */
    return 0;
}
