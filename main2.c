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
		printf("   ���� ���� ���α׷� v1.0\n");
		printf("=================================\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("������ȣ 4�ڸ��� �Է��ϼ���. \n");
		printf("\n");
		printf("\n");
		scanf("	%d", &car.car_num);
		printf("\n");
		printf("\n");
		if (car.car_num < 9999)	//���ڿ� ���� ���ǵ� �ɾ���� ..
			break;
	}

	system("cls");
	for (int i = 0; i < 1; i++) {
		car.time.ent_hour = (rand() % 14) + 6;
		car.time.ent_min = rand() % 59;
		while (1) {
			system("cls");
			printf("====================================\n");
			printf("   ���� ���� ���α׷� v1.0\n");
			printf("====================================\n");
			printf("\n");
			printf("\n");
			printf("	���� ��ȣ: %d \n", car.car_num);
			printf("\n");
			printf("	���� �ð�: %d�� %d��\n", car.time.ent_hour, car.time.ent_min);
			file_write(car, file);
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("====================================\n");
			printf("\n");
			int num;
			printf(">>> 1 �Է½� �������� �Ѿ�ϴ�. \n");
			printf(">>> 2 �Է½� ó��ȭ������ �ǵ��ư��ϴ�. \n");
			scanf("%d", &num);
			system("cls");
			if (num == 1) {
				printf("====================================\n");
				printf("   ���� ���� ���α׷� v1.0\n");
				printf("====================================\n");
				printf("���� �ð��� �Է��ϼ��� =>  ");
				scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
				hour = car.time.exit_hour - (car.time.ent_hour);
				min = car.time.exit_min - (car.time.ent_min);
				if (car.time.exit_min < car.time.ent_min) {
					hour = (car.time.exit_hour - (car.time.ent_hour)) - 1;
					min = ((car.time.exit_min - car.time.ent_min)) + 60;

					printf("�̿� �ð� : %d�ð� %d�� \n", hour, min);
				}
			}
			else if (num == 2) {
			}
			break;
		}
	}
}
