//ques 2

#include <stdio.h>
#include <conio.h>

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "timers.h"
#include "queue.h"

xTaskHandle TaskHandle_1;
xTaskHandle TaskHandle_2;
xTaskHandle TaskHandle_3;

TimerHandle_t xTimers;

void task1(void)
{
    while (1) {
        printf("this is task 1\n");
        vTaskDelay(1000);
    }
}

void task2(void)
{
    while (1) {
        printf("this is task 2\n");
        vTaskDelay(2000);
    }
}

void task3(void)
{
    while (1) {
        printf("this is task 3\n");
        vTaskDelay(5000);
    }
}


void vcallback(TimerHandle_t xTimer)
{

    const uint32_t ulMaxExpiryCountBeforeStopping = 10;
    uint32_t ulCount;

    configASSERT(xTimer);

    ulCount = (uint32_t)pvTimerGetTimerID(xTimer);
    ulCount++;

    if (ulCount >= ulMaxExpiryCountBeforeStopping)
    {
        xTimerStop(xTimer, 0);
    }
    else
    {
        vTimerSetTimerID(xTimer, (void*)ulCount);
    }
}

int main(void)
{
	xTaskCreate(task1, "task1", configMINIMAL_STACK_SIZE, NULL, 5, &TaskHandle_1);
	xTaskCreate(task2, "task2", configMINIMAL_STACK_SIZE, NULL, 6, &TaskHandle_2);
	xTaskCreate(task3, "task3", configMINIMAL_STACK_SIZE, NULL, 7, &TaskHandle_3);

	xTimerCreate("Timer",10000, pdTRUE, (void*)0, vcallback);
	xTimerStart(xTimers,0);

	vTaskStartScheduler();

}
