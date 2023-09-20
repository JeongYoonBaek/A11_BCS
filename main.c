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
	char file[] = "parkingfee.bin";	//파일이름
	srand(time(NULL));	//랜덤함수
	
	set_cursor_type(NOCURSOR);	
	font_color(YELLOW);
	title();
	_getch();	//화면을 일시정지 상태로 만들기 위해 , system("pause") 사용가능

	system("cls");	
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	int hour = 0;	//시간
	int min = 0;	//분
	int fee = 0;	//이용요금
	int cost = 0;	//투입금액
	 //차량번호 
	PARKING car = { 0 };
	while (1) {
		system("cls");
		char menu = main_menu();	
		rewind(stdin);

		if (MAIN_CAR_NUM == menu) {
			while (1) {
				car.car_num = insert_carnum(car);	//차량번호 네자리 받는 함수
				system("cls");
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX)	//차량번호 입력받을 범위 
					break;														//숫자 네자리는 입력되지만 문자 입력 시 무한루프 
			}
			strcpy(car.area.eng, eng[rand() % 8]);
			car.area.num = num[rand() % 11];
			car.time.ent_hour = (rand() % 14) + 6;	//입차 시 06~20 사이 랜덤값 저장	 
			car.time.ent_min = rand() % 59;			//입차 분 00~59 사이 랜덤값 저장 
			file_write(car, file);					//파일에 차량번호와 입차시간 쓰기
			show_title();							//중복되는 안내문 함수로
			file_read(file);						//쓴 파일 읽어오기
			printf("\n");
			int num;
			printf("	1 입력시 처음으로 되돌아갑니다. \n");
			printf("\n");
			printf("	  >>>  ");
			scanf("%d", &num);
			printf("\n");
			system("pause");						//while문을 벗어나지 않도록 일시정지 상태를 만들어줌
		}
		else if (MAIN_PAYMENT == menu) {
			system("cls");
			while (1) {
				car.car_num = insert_carnum(car);	//차량번호 네자리 입력받는 함수
				system("cls");
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX) {
					break;
				}
			}
			system("cls");
			show_title();	//중복되는 안내문 함수로
			show_ent_hour(car);	//차량번호,입차시간 안내
			int num;
			printf("	1 입력시 다음으로 넘어갑니다. \n");
			printf("\n");
			printf("	  >>>  ");
			scanf("%d", &num);
			printf("\n");
			system("pause");
			system("cls");
			while (1) {
				system("cls");
				show_title();	//중복되는 안내문 함수로
				insert_exit_hour();	//출차시간 입력
				scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
				//조건이 참일경우 브레이크 빠져나가서 실행
				if ((car.time.exit_hour > car.time.ent_hour												//1. 출차시간이 입차시간보다 크고(늦고),
					&& car.time.exit_hour >= 6 && car.time.exit_hour < 22 && car.time.exit_min <= 59)	//2. 출차시간이 6시에서 21:59분 사이이거나 	
					|| (car.time.exit_hour == 22  && car.time.exit_min == 00))							//3. 출차시간이 22: 00분일 때 while문 탈출. 
					break;
			}
			system("cls");
			show_title();	//중복되는 안내문 함수로
			file_write(car, file);
			if (car.time.exit_min >= car.time.ent_min) {	
				hour = car.time.exit_hour - (car.time.ent_hour);
				min = car.time.exit_min - (car.time.ent_min);
			}
			else {				//만약 (출차 분 - 입차 분) 했을 때 음수값이 나온다면 
				hour = (car.time.exit_hour - (car.time.ent_hour)) - 1;		//시간 -1
				min = ((car.time.exit_min - car.time.ent_min)) + 60;		//분 +60
			}
			printf("\n");
			file_read2(file, hour, min);		//차량번호, 입차, 출차, 이용시간 안내
			printf("\n");
			printf("\n");
			if (hour < 1 || (hour == 1 && min == 0)) {
				printf("		  요금: %d 원\n", fee);
				printf("         ┃                           ┃\n");
				printf("         ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				printf("\n");
				printf("\n");
				printf("	    한시간 이하는 무료입니다.\n");
			}
			else if (min == 0) {				//30분당 500원씩 부과
				fee = (((hour * 60) + min) / 30 * 500) - 1000;		//
				/*printf("요금: %d원\n", fee);*/
				pay(fee, cost);
			}
			else if (min > 0 && min <= 30) {	//1분~30분일 경우 반올림 함	예)10분일경우에도 30분, 25분일 경우에도 30분으로 계산
				fee = (((hour * 60) + 30) / 30 * 500) - 1000;
				/*printf("요금: %d원\n", fee);*/
				pay(fee, cost);
			}
			else {								//31~59분일 경우 시간 반올림 예) 이용시간이 2시간 35분이면 3시간으로 계산
				fee = ((((hour + 1) * 60)) / 30 * 500) - 1000;
				pay(fee, cost);
			} 
			receipt_msg(car, hour, min, fee);
		}
	}//while 문 닫는 괄호임
}


