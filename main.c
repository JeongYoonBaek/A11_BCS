#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //sleep
#include "menu.h"
#include "file.h"
#include "data.h"
#include "ui.h"

void receipt(PARKING car, int hour, int min, int fee);

int main() {
	char file[] = "parkingfee.bin";	//�����̸�
	srand(time(NULL));	//�����Լ�
	set_cursor_type(NOCURSOR);
	font_color(LIGHT_RED);
	title();
	_getch();	//ȭ���� �Ͻ����� ���·� ����� ���� , system("pause") ��밡��

	system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	int hour = 0;	//�ð�
	int min = 0;	//��
	int fee = 0;	//�̿���
	int cost = 0;	//���Աݾ�
	PARKING car = { 0 }; //������ȣ 

	while (1) {
		system("cls");
		switch (main_menu()) {
		case MAIN_CAR_NUM:
			while (1) {
				system("cls");
				printf("==============================================\n");
				printf("\n");
				printf("	  ���� ���� ���α׷� v1.0\n");
				printf("\n");
				printf("==============================================\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("������ȣ 4�ڸ��� �Է��ϼ���. \n");
				printf("\n");
				printf("\n");
				scanf("	%d", &car.car_num);
				printf("\n");
				printf("\n");
				system("cls");
				if (car.car_num>=CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX)	//�̰� �����ĳ��µ� �����Բ��� �ٲ��ּ��� .. ���� ���ذ� �Ȱ��� ���ϰھ��
					break;
			}
			for (int i = 0; i < 1; i++) {
				car.time.ent_hour = (rand() % 14) + 6;
				car.time.ent_min = rand() % 59;
				file_write(car, file);
				printf("==============================================\n");
				printf("\n");
				printf("	  ���� ���� ���α׷� v1.0\n");
				printf("\n");
				printf("==============================================\n");
				printf("\n");
				printf("\n");
				file_read(file);
				printf("\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("==============================================\n");
				printf("\n");
				int num;
				printf(">>> 1 �Է½� ó������ �ǵ��ư��ϴ�. \n");
				scanf("%d", &num);
				if (num == 1) {
					break;
				}
				else if (num != 1) {
				}
		case MAIN_PAYMENT:
			system("cls");
			while (1) {
				printf("==============================================\n");
				printf("\n");
				printf("	  ���� ���� ���α׷� v1.0\n");
				printf("\n");
				printf("==============================================\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("������ȣ 4�ڸ��� �Է��ϼ���. \n");
				printf("\n");
				printf("\n");
				scanf("	%d", &car.car_num);
				printf("\n");
				printf("\n");
				system("cls");
				if (car.car_num < CAR_NUM_MAX) {
					printf("==============================================\n");
					printf("\n");
					printf("	  ���� ���� ���α׷� v1.0\n");
					printf("\n");
					printf("==============================================\n");
					printf("\n");
					printf("\n");
					printf("	���� ��ȣ: %d \n", car.car_num);
					printf("\n");
					printf("	���� �ð�: %d�� %d��\n", car.time.ent_hour, car.time.ent_min);
					printf("\n");
					printf("\n");
					printf("\n");
					printf("\n");
					printf("==============================================\n");
					int num;
					printf(">>> 1 �Է½� �������� �Ѿ�ϴ�. \n");
					scanf("%d", &num);
					system("cls");
					if (num == 1) {
						printf("==============================================\n");
						printf("\n");
						printf("	  ���� ���� ���α׷� v1.0\n");
						printf("\n");
						printf("==============================================\n");
						printf("\n");
						printf("���� �ð��� �Է��ϼ��� =>  ");
						scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
						if (car.time.exit_min > car.time.ent_min) {
							hour = car.time.exit_hour - (car.time.ent_hour);
							min = car.time.exit_min - (car.time.ent_min);
						}
						else {
							hour = (car.time.exit_hour - (car.time.ent_hour)) - 1;
							min = ((car.time.exit_min - car.time.ent_min)) + 60;
						}
						printf("\n");
						printf(">����: %d�� %d��<\n", car.time.ent_hour, car.time.ent_min);
						printf("\n");
						printf(">����: %d�� %d��<\n", car.time.exit_hour, car.time.exit_min);
						printf("\n");
						printf("�̿� �ð� : %d�ð� %d�� \n", hour, min);
						printf("\n");
						printf("\n");
					}
					if (hour < 1) {
						printf("�ѽð� ���ϴ� �����Դϴ�. �ȳ���������.\n");
						break;
					}
					if (min == 0) {
						fee = ((hour * 60) + min) / 30 * 500;
						printf("���: %d��\n", fee);
					}
					else if (min > 0 && min <= 30) {
						fee = ((hour * 60) + 30) / 30 * 500;
						printf("���: %d��\n", fee);
					}
					else {
						fee = (((hour + 1) * 60)) / 30 * 500;
					}
					printf("���: %d��\n", fee);
					printf("��������� �������ּ���.\n");
					printf("\n");
					printf("1.����		2.ī��\n");
					scanf("%d", &num);
					if (num == 1) {
						system("cls");
						while (1) {
							printf("==============================================\n");
							printf("\n");
							printf("	  ���� ���� ���α׷� v1.0\n");
							printf("\n");
							printf("==============================================\n");
							printf("�ݾ��� �����ϼ���: ");   // �̿� �ݾ� ����
							scanf("%d", &cost);              // ������ �ݾ� �Է� 
							printf("�ݾ��� ���� �Ͽ����ϴ�.\n"); // ���������� �ݾ� �����Ͽ����� ���
							printf("\n");
							if (fee == cost) {  // �̿�ݾװ� ���� �ݾ��� ������ ���� �Ϸᰡ �Ǿ��ٴ� ���ǹ��� �ۼ�
								printf("������ �Ϸ� �Ǿ����ϴ�.\n");
								break;
							}
							else if (fee < cost) {  // ���� �ݾ��� �̿� �ݾ׺��� ���� �� �Ž����� �ݾ��� ���
								printf("�Ž����� %d���Դϴ�.\n", cost - fee);
								break;
							}
							else if (fee > cost) { // ���� �ݾ��� ������ �� �ݾ��� �����ϴٴ� ������ ���
								printf("���� �ݾ��� �����մϴ�.\n");
								system("pause");
								system("cls");
							}
						}
						printf("\n");
						printf("\n");
						printf("�������� �޾ư�����.\n");
						receipt(car, hour, min, fee);
					}
					else if (num == 2) {
						system("cls");
						printf("==============================================\n");
						printf("\n");
						printf("	  ���� ���� ���α׷� v1.0\n");
						printf("\n");
						printf("==============================================\n");
						printf("ī�带 �����⿡ �־��ּ���.\n");
						printf("�������Դϴ�.... ī�带 ���� ������.\n");
						Sleep(3000); // sec - ms - us - ns	//������
						printf("\n");
						printf("\n");
						printf("������ �Ϸ�Ǿ����ϴ�.\n");
						printf("�������� �޾ư�����.\n");
						system("pause");
					}
					system("cls");
					receipt(car, hour, min, fee);
				}
				exit(0);
			}
			}
		}
	}
}

	void receipt(PARKING car, int hour, int min, int fee) {
		printf("------------------------------\n");
		printf("   ���� �̿� �ý��� ������\n");
		printf("------------------------------\n");
		printf("���� ��ȣ : %d \n", car.car_num);
		printf("���� �ð� : %d�� %d�� \n", car.time.ent_hour, car.time.ent_min);
		printf("���� �ð� : %d�� %d�� \n", car.time.exit_hour, car.time.exit_min);
		printf("�̿� �ð� : %d�ð� %d��\n", hour, min);
		printf("���� �ݾ� : %d�� \n", fee);
		printf("------------------------------\n");
		printf("�̿� ���ּż� �����մϴ�\n");
		printf("------------------------------\n");
	}



