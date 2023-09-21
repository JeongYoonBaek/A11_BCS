#ifndef __MENU_H__		
#define __MENU_H__
#include <stdio.h>
#include "file.h"
typedef enum {
	MAIN_CAR_NUM = '1',		//차량번호조회 메뉴												
	MAIN_PAYMENT 			//정산 메뉴


} MAIN_MENU;

extern int main_menu();				//extern 외부에 보여주도록 하는 기능, 안붙여도됨
void show_title();
int insert_carnum(PARKING car);
void insert_exit_time();
void pay(PARKING CAR);
void receipt(PARKING car);
void show_ent_time(PARKING car);
void cal_fee(PARKING car);
#endif