#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h> //sleep
#include "menu.h"
#include "file.h"
#include "data.h"
#include "ui.h"



int main() {
	char file[] = "parkingfee.bin";	//�����̸�
	srand(time(NULL));	//�����Լ�
	
	set_cursor_type(NOCURSOR);	
	font_color(YELLOW);
	title();
	_getch();	//ȭ���� �Ͻ����� ���·� ����� ���� , system("pause") ��밡��

	system("cls");	
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	int hour = 0;	//�ð�
	int min = 0;	//��
	int fee = 0;	//�̿���
	int cost = 0;	//���Աݾ�
	 //������ȣ 
	PARKING car = { 0 };
	while (1) {
		system("cls");
		char menu = main_menu();	
		rewind(stdin);

		if (MAIN_CAR_NUM == menu) {
			while (1) {
				car.car_num = insert_carnum(car);	//������ȣ ���ڸ� �޴� �Լ�
				system("cls");
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX)	//������ȣ �Է¹��� ���� 
					break;														//���� ���ڸ��� �Էµ����� ���� �Է� �� ���ѷ��� 
			}
			strcpy(car.area.eng, eng[rand() % 8]);
			car.area.num = num[rand() % 11];
			car.time.ent_hour = (rand() % 14) + 6;	//���� �� 06~20 ���� ������ ����	 
			car.time.ent_min = rand() % 59;			//���� �� 00~59 ���� ������ ���� 
			file_write(car, file);					//���Ͽ� ������ȣ�� �����ð� ����
			show_title();							//�ߺ��Ǵ� �ȳ��� �Լ���
			file_read(file);						//�� ���� �о����
			printf("\n");
			int num;
			printf("	1 �Է½� ó������ �ǵ��ư��ϴ�. \n");
			printf("\n");
			printf("	  >>>  ");
			scanf("%d", &num);
			printf("\n");
			system("pause");						//while���� ����� �ʵ��� �Ͻ����� ���¸� �������
		}
		else if (MAIN_PAYMENT == menu) {
			system("cls");
			while (1) {
				car.car_num = insert_carnum(car);	//������ȣ ���ڸ� �Է¹޴� �Լ�
				system("cls");
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX) {
					break;
				}
			}
			system("cls");
			show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
			show_ent_hour(car);	//������ȣ,�����ð� �ȳ�
			int num;
			printf("	1 �Է½� �������� �Ѿ�ϴ�. \n");
			printf("\n");
			printf("	  >>>  ");
			scanf("%d", &num);
			printf("\n");
			system("pause");
			system("cls");
			while (1) {
				system("cls");
				show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
				insert_exit_hour();	//�����ð� �Է�
				scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
				//������ ���ϰ�� �극��ũ ���������� ����
				if ((car.time.exit_hour > car.time.ent_hour												//1. �����ð��� �����ð����� ũ��(�ʰ�),
					&& car.time.exit_hour >= 6 && car.time.exit_hour < 22 && car.time.exit_min <= 59)	//2. �����ð��� 6�ÿ��� 21:59�� �����̰ų� 	
					|| (car.time.exit_hour == 22  && car.time.exit_min == 00))							//3. �����ð��� 22: 00���� �� while�� Ż��. 
					break;
			}
			system("cls");
			show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
			file_write(car, file);
			if (car.time.exit_min >= car.time.ent_min) {	
				hour = car.time.exit_hour - (car.time.ent_hour);
				min = car.time.exit_min - (car.time.ent_min);
			}
			else {				//���� (���� �� - ���� ��) ���� �� �������� ���´ٸ� 
				hour = (car.time.exit_hour - (car.time.ent_hour)) - 1;		//�ð� -1
				min = ((car.time.exit_min - car.time.ent_min)) + 60;		//�� +60
			}
			printf("\n");
			file_read2(file, hour, min);		//������ȣ, ����, ����, �̿�ð� �ȳ�
			printf("\n");
			printf("\n");
			if (hour < 1 || (hour == 1 && min == 0)) {
				printf("		  ���: %d ��\n", fee);
				printf("         ��                           ��\n");
				printf("         ����������������������������������������������������������\n");
				printf("\n");
				printf("\n");
				printf("	    �ѽð� ���ϴ� �����Դϴ�.\n");
			}
			else if (min == 0) {				//30�д� 500���� �ΰ�
				fee = (((hour * 60) + min) / 30 * 500) - 1000;		//
				/*printf("���: %d��\n", fee);*/
				pay(fee, cost);
			}
			else if (min > 0 && min <= 30) {	//1��~30���� ��� �ݿø� ��	��)10���ϰ�쿡�� 30��, 25���� ��쿡�� 30������ ���
				fee = (((hour * 60) + 30) / 30 * 500) - 1000;
				/*printf("���: %d��\n", fee);*/
				pay(fee, cost);
			}
			else {								//31~59���� ��� �ð� �ݿø� ��) �̿�ð��� 2�ð� 35���̸� 3�ð����� ���
				fee = ((((hour + 1) * 60)) / 30 * 500) - 1000;
				pay(fee, cost);
			} 
			receipt_msg(car, hour, min, fee);
		}
	}//while �� �ݴ� ��ȣ��
}


