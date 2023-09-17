#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //sleep
#include "menu.h"
#include "file.h"


int main() {

	char file[] = "parkingfee.bin";
	PARKING car = { 0 };
	srand(time(NULL));
	int hour = 0;
	int min = 0;

	while (1) {
		system("cls");
		printf("=================================\n");
		printf("   차량 정산 프로그램 v1.0\n");
		printf("=================================\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("차량번호 4자리를 입력하세요. \n");
		printf("\n");
		printf("\n");
		scanf("	%d", &car.car_num);
		printf("\n");
		printf("\n");
		if (car.car_num < 9999)	//문자열 제외 조건도 걸어야함 ..
			break;
	}

	system("cls");
	for (int i = 0; i < 1; i++) {
		car.time.ent_hour = (rand() % 14) + 6;
		car.time.ent_min = rand() % 59;
		while (1) {
			system("cls");
			printf("====================================\n");
			printf("   차량 정산 프로그램 v1.0\n");
			printf("====================================\n");
			printf("\n");
			printf("\n");
			printf("	차량 번호: %d \n", car.car_num);
			printf("\n");
			printf("	입차 시간: %d시 %d분\n", car.time.ent_hour, car.time.ent_min);
			file_write(car, file);
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("====================================\n");
			printf("\n");
			int num;
			printf(">>> 1 입력시 다음으로 넘어갑니다. \n");
			printf(">>> 2 입력시 처음화면으로 되돌아갑니다. \n");
			scanf("%d", &num);
			system("cls");
			if (num == 1) {
				printf("====================================\n");
				printf("   차량 정산 프로그램 v1.0\n");
				printf("====================================\n");
				printf("출차 시간을 입력하세요 =>  ");
				scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
				hour = car.time.exit_hour - (car.time.ent_hour);
				min = car.time.exit_min - (car.time.ent_min);
				if (car.time.exit_min < car.time.ent_min) {
					hour = (car.time.exit_hour - (car.time.ent_hour)) - 1;
					min = ((car.time.exit_min - car.time.ent_min)) + 60;

					printf("이용 시간 : %d시간 %d분 \n", hour, min);
				}
			}
			else if (num == 2) {
			}
			break;
		}
	}
}
