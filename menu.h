#ifndef __MENU_H__		//->��� ���� �ߺ� ����� ���� , �̸��� ����ڰ� ���� == 
#define __MENU_H__
#include <stdio.h>
#include "file.h"
typedef enum {
	MAIN_CAR_NUM = '1',		//������ȣ��ȸ �޴�												//�ҽ���������:�����������
	MAIN_PAYMENT 		//���� �޴�
							//github,Perforce,SVN,NAS

} MAIN_MENU;

extern int main_menu();		//extern �ܺο� �����ֵ��� �ϴ� ���. �������� �����Ϸ��� �ڵ����� �ٿ���
int insert_carnum(PARKING car);
void show_title();
void pay(int fee, int cost);
void receipt(PARKING car, int hour, int min, int fee);
void show_ent_hour(PARKING car);
void insert_exit_hour();
void receipt_msg(PARKING car, int hour, int min, int fee);
void cal_fee(int fee, int cost, int hour, int min);

#endif