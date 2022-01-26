//ques 5: On changing priority, output messages also changes.

#include <stdio.h>
#include <conio.h>

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "timers.h"
#include "queue.h"

TaskHandle_t xHandle = NULL;

void task1(void)
{
	while (1)
	{
		printf("this is task with priority 20");
		vTaskDelay(500);
		//vTaskDelete(xHandle);
	}
}

void task2(void)
{
	while (1)
	{
		printf("this is task with priority 0");
		vTaskDelay(500);
		//vTaskDelete(xHandle);
	}
}

int main(void)
{
	BaseType_t xReturned;
	xTaskCreate(task1, "task alpha1", configMINIMAL_STACK_SIZE, NULL, 20, NULL);
	xTaskCreate(task2, "task alpha2", configMINIMAL_STACK_SIZE, NULL, 0, NULL);
	vTaskStartScheduler();

	/*
	if (xReturned == pdPASS)
	{
		printf("task created\n");
	}
	*/
}
