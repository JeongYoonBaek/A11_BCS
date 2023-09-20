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
void show_title();
void pay(int fee,int cost);
int insert_carnum();
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
				system("cls");
				show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
				car.car_num = insert_carnum();	//������ȣ ���ڸ� �޴� �Լ�
				system("cls");
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX)
					break;							//������ȣ �Է¹��� ���� 
			}
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
				show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
				car.car_num = insert_carnum();	//������ȣ ���ڸ� �Է¹޴� �Լ�
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX) {
					break;
				}
			}
			system("cls");
			show_title();	//�ߺ��Ǵ� �ȳ��� �Լ���
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("         ����������������������������������������������������������\n");
			printf("         ��                           ��\n");
			printf("             ���� ��ȣ: %d        \n", car.car_num);
			printf("\n");
			printf("             ���� �ð�: %d �� %d �� \n", car.time.ent_hour, car.time.ent_min);
			printf("         ��                           ��\n");
			printf("         ����������������������������������������������������������\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
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
				printf("\n");
				printf("\n");
				printf("\n");
				printf("	      <<  ����: 00:00  >>\n");
				printf("\n");
				printf("        ������������������������������������������������������������\n");
				printf("        ��    �����ð��� �Է��ϼ���.  ��\n");
				printf("        ������������������������������������������������������������\n");
				printf("\n");
				printf("\n");
				printf("		    ");
				scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
				if (car.time.exit_hour > car.time.ent_hour  )		//�����ð��� �����ð����� ���� ��� ���Է�
					break;
			}
			system("cls");
			show_title();
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
			file_read2(file, hour, min);
			/*printf(">����: %d�� %d��<\n", car.time.ent_hour, car.time.ent_min);
			printf("\n");
			printf(">����: %d�� %d��<\n", car.time.exit_hour, car.time.exit_min);
			printf("\n");
			printf("�̿� �ð� : %d�ð� %d�� \n", hour, min);*/
			printf("\n");
			printf("\n");

			if (hour < 1 || (hour == 1 && min == 0)) {			
				printf("�ѽð� ���ϴ� �����Դϴ�. �ȳ���������.\n");
			}		
			else if (min == 0) {				//30�д� 500���� �ΰ�
				fee = (((hour * 60) + min) / 30 * 500)-1000;		//
				/*printf("���: %d��\n", fee);*/
				pay(fee, cost);		
			}
			else if (min > 0 && min <= 30) {	//1��~30���� ��� �ݿø� ��	��)10���ϰ�쿡�� 30��, 25���� ��쿡�� 30������ ���
				fee = (((hour * 60) + 30) / 30 * 500)-1000;
				/*printf("���: %d��\n", fee);*/
				pay(fee, cost);
			}
			else {								//31~59���� ��� �ð� �ݿø� ��) �̿�ð��� 2�ð� 35���̸� 3�ð����� ���
				fee = ((((hour + 1) * 60)) / 30 * 500)-1000;
				pay(fee, cost);
			}
			printf("\n");
			printf("\n");
			printf("	 �������� �޾ư�����. \n");
			printf("\n");
			printf("\n");
			system("pause");
			system("cls");
			receipt(car, hour, min, fee);
			printf("\n");
			printf("\n");
			printf("5�ʵڿ� Ȩȭ������ �Ѿ�ϴ�.");
			Sleep(5000);
		}
	}//while �� �ݴ� ��ȣ��
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

int insert_carnum() {
	PARKING car = { 0 };
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("      ����������������������������������������������������������������������\n");
	printf("      �� ������ȣ ���ڸ��� �Է����ּ���. ��\n");
	printf("      ����������������������������������������������������������������������\n");
	printf("\n");
	printf("\n");
	printf("		    ");
	scanf("%d", &car.car_num);
	printf("\n");
	printf("\n");
	printf("\n");
	return car.car_num;
}
void show_title() {
	printf("����������������������������������������������������������������������������������������������\n");
	printf("��                                             ��\n");
	printf("��	       ���� ���� ���α׷�             ��\n");
	printf("��                                             ��\n");
	printf("����������������������������������������������������������������������������������������������");
	printf("\n");
}
void pay(int fee,int cost){
	
	int num;
	printf("		 ���: %d��\n", fee);
	printf("         ��                           ��\n");
	printf("         ����������������������������������������������������������\n");
	printf("\n");
	printf("��������� �������ּ���.\n");
	printf("\n");
	printf("1.����		2.ī��\n");
	scanf("%d", &num);
	if (num == 1) {
		system("cls");
		while (1) {
			show_title();
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
			else if (fee > cost) { // ���� �ݾ��� ������ �� �ݾ��� �����ϴٴ� ������ ��°� ���� ���Է����� �ǵ��ư�
				printf("���� �ݾ��� �����մϴ�.\n");
				system("pause");
				system("cls");
			}
		}
	}
	else if (num == 2) {		//��¸� ��
		system("cls");
		show_title(); printf("\n");
		printf("      ����������������������������������������������������������������������\n");
		printf("      ��  ī�带 �����⿡ �־��ּ���.    ��\n");
		printf("      ����������������������������������������������������������������������\n");
		printf("\n");
		printf("      �������Դϴ�.... ī�带 ���� ������.\n");
		Sleep(3000); // sec - ms - us - ns	//������
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("	 ������ �Ϸ�Ǿ����ϴ�.\n");
	}
}
