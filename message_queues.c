//ques 1

#include <stdio.h>
#include <conio.h>

#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "timers.h"
#include "queue.h"

//TaskHandle_t xHandle = NULL;
xTaskHandle TaskHandle_1;
xTaskHandle TaskHandle_2;
xTaskHandle TaskHandle_3;
xTaskHandle TaskHandle_4;
xTaskHandle TaskHandle_5;

QueueHandle_t xQueue1;
unsigned long ulVar = 10UL;

void task1(void)
{

		printf("this is task 1\n");
		vTaskDelay(1000);
		vTaskDelete(TaskHandle_1);
}

void task2(void)
{

		printf("this is task 2\n");
		vTaskDelay(2000);
		vTaskDelete(TaskHandle_2);
}

void task3(void)
{

		printf("this is task 3\n");
		vTaskDelay(5000);
		vTaskDelete(TaskHandle_3);
}

void send_msg(void)
{

	xQueue1 = xQueueCreate(10, sizeof(unsigned long));
	xQueueSend(xQueue1, (void*)&ulVar, (TickType_t)10);
	printf("this is task 4\n");
	//vTaskDelay(5000);
}

void receive_msg(void)
{
	unsigned long receive_val = 0;
	printf("this is task 5\n");
	xQueueReceive(xQueue1, &(receive_val), (TickType_t)10);
	printf("\nMesseage received in message queue: %ul\n", receive_val);
	//vTaskDelay(5000);
}

int main(void)
{
	xTaskCreate(task1, "task1", configMINIMAL_STACK_SIZE, NULL, 5, &TaskHandle_1);
	xTaskCreate(task2, "task2", configMINIMAL_STACK_SIZE, NULL, 6, &TaskHandle_2);
	xTaskCreate(task3, "task3", configMINIMAL_STACK_SIZE, NULL, 7, &TaskHandle_3);
	xTaskCreate(send_msg, "task4", configMINIMAL_STACK_SIZE, NULL, 8, &TaskHandle_4);
	xTaskCreate(receive_msg, "task5", configMINIMAL_STACK_SIZE, NULL, 9, &TaskHandle_5);

	vTaskStartScheduler();

	vQueueDelete(xQueue1);

}
