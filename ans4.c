//ques 4: Create two task with priority 10 and 20

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
		printf("this is task with priority 10");
		vTaskDelay(500);
		//vTaskDelete(xHandle);
	}
}

void task2(void)
{
	while (1)
	{
		printf("this is task with priority 20");
		vTaskDelay(500);
		//vTaskDelete(xHandle);
	}
}

int main(void)
{
	BaseType_t xReturned;
	
	xReturned = xTaskCreate(task1, "task alpha", configMINIMAL_STACK_SIZE, NULL, 10, NULL);
	xTaskCreate(task2, "task alpha", configMINIMAL_STACK_SIZE, NULL, 20, NULL);
	if (xReturned == pdPASS)
	{
		printf("task created\n");
	}
	vTaskStartScheduler();
}




































