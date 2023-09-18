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
	char file[] = "parkingfee.bin";	//파일이름
	srand(time(NULL));	//랜덤함수
	set_cursor_type(NOCURSOR);
	font_color(LIGHT_RED);
	title();
	_getch();	//화면을 일시정지 상태로 만들기 위해 , system("pause") 사용가능

	system("cls");
	font_color(LIGHT_GRAY);
	set_cursor_type(NORMAL_CURSOR);
	int hour = 0;	//시간
	int min = 0;	//분
	int fee = 0;	//이용요금
	int cost = 0;	//투입금액
	PARKING car = { 0 }; //차량번호 

	while (1) {
		system("cls");
		switch (main_menu()) {
		case MAIN_CAR_NUM:
			while (1) {
				system("cls");
				printf("==============================================\n");
				printf("\n");
				printf("	  차량 정산 프로그램 v1.0\n");
				printf("\n");
				printf("==============================================\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("차량번호 4자리를 입력하세요. \n");
				printf("\n");
				printf("\n");
				scanf("	%d", &car.car_num);
				printf("\n");
				printf("\n");
				system("cls");
				if (car.car_num>=CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX)	//이거 대충쳐놨는데 예원님껄로 바꿔주세요 .. 저는 이해가 안가서 못하겠어요
					break;
			}
			for (int i = 0; i < 1; i++) {
				car.time.ent_hour = (rand() % 14) + 6;
				car.time.ent_min = rand() % 59;
				file_write(car, file);
				printf("==============================================\n");
				printf("\n");
				printf("	  차량 정산 프로그램 v1.0\n");
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
				printf(">>> 1 입력시 처음으로 되돌아갑니다. \n");
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
				printf("	  차량 정산 프로그램 v1.0\n");
				printf("\n");
				printf("==============================================\n");
				printf("\n");
				printf("\n");
				printf("\n");
				printf("차량번호 4자리를 입력하세요. \n");
				printf("\n");
				printf("\n");
				scanf("	%d", &car.car_num);
				printf("\n");
				printf("\n");
				system("cls");
				if (car.car_num < CAR_NUM_MAX) {
					printf("==============================================\n");
					printf("\n");
					printf("	  차량 정산 프로그램 v1.0\n");
					printf("\n");
					printf("==============================================\n");
					printf("\n");
					printf("\n");
					printf("	차량 번호: %d \n", car.car_num);
					printf("\n");
					printf("	입차 시간: %d시 %d분\n", car.time.ent_hour, car.time.ent_min);
					printf("\n");
					printf("\n");
					printf("\n");
					printf("\n");
					printf("==============================================\n");
					int num;
					printf(">>> 1 입력시 다음으로 넘어갑니다. \n");
					scanf("%d", &num);
					system("cls");
					if (num == 1) {
						printf("==============================================\n");
						printf("\n");
						printf("	  차량 정산 프로그램 v1.0\n");
						printf("\n");
						printf("==============================================\n");
						printf("\n");
						printf("출차 시간을 입력하세요 =>  ");
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
						printf(">입차: %d시 %d분<\n", car.time.ent_hour, car.time.ent_min);
						printf("\n");
						printf(">출차: %d시 %d분<\n", car.time.exit_hour, car.time.exit_min);
						printf("\n");
						printf("이용 시간 : %d시간 %d분 \n", hour, min);
						printf("\n");
						printf("\n");
					}
					if (hour < 1) {
						printf("한시간 이하는 무료입니다. 안녕히가세요.\n");
						break;
					}
					if (min == 0) {
						fee = ((hour * 60) + min) / 30 * 500;
						printf("요금: %d원\n", fee);
					}
					else if (min > 0 && min <= 30) {
						fee = ((hour * 60) + 30) / 30 * 500;
						printf("요금: %d원\n", fee);
					}
					else {
						fee = (((hour + 1) * 60)) / 30 * 500;
					}
					printf("요금: %d원\n", fee);
					printf("결제방식을 선택해주세요.\n");
					printf("\n");
					printf("1.현금		2.카드\n");
					scanf("%d", &num);
					if (num == 1) {
						system("cls");
						while (1) {
							printf("==============================================\n");
							printf("\n");
							printf("	  차량 정산 프로그램 v1.0\n");
							printf("\n");
							printf("==============================================\n");
							printf("금액을 투입하세요: ");   // 이용 금액 투입
							scanf("%d", &cost);              // 투입할 금액 입력 
							printf("금액을 투입 하였습니다.\n"); // 성공적으로 금액 투입하였음을 출력
							printf("\n");
							if (fee == cost) {  // 이용금액과 투입 금액이 같을때 결제 완료가 되었다는 조건문을 작성
								printf("결제가 완료 되었습니다.\n");
								break;
							}
							else if (fee < cost) {  // 투입 금액이 이용 금액보다 많을 때 거스름돈 금액을 출력
								printf("거스름돈 %d원입니다.\n", cost - fee);
								break;
							}
							else if (fee > cost) { // 투입 금액이 부족할 때 금액이 부족하다는 문구를 출력
								printf("투입 금액이 부족합니다.\n");
								system("pause");
								system("cls");
							}
						}
						printf("\n");
						printf("\n");
						printf("영수증을 받아가세요.\n");
						receipt(car, hour, min, fee);
					}
					else if (num == 2) {
						system("cls");
						printf("==============================================\n");
						printf("\n");
						printf("	  차량 정산 프로그램 v1.0\n");
						printf("\n");
						printf("==============================================\n");
						printf("카드를 리더기에 넣어주세요.\n");
						printf("결제중입니다.... 카드를 뽑지 마세요.\n");
						Sleep(3000); // sec - ms - us - ns	//딜레이
						printf("\n");
						printf("\n");
						printf("결제가 완료되었습니다.\n");
						printf("영수증을 받아가세요.\n");
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
		printf("   주차 이용 시스템 영수증\n");
		printf("------------------------------\n");
		printf("차량 번호 : %d \n", car.car_num);
		printf("입차 시간 : %d시 %d분 \n", car.time.ent_hour, car.time.ent_min);
		printf("출차 시간 : %d시 %d분 \n", car.time.exit_hour, car.time.exit_min);
		printf("이용 시간 : %d시간 %d분\n", hour, min);
		printf("결제 금액 : %d원 \n", fee);
		printf("------------------------------\n");
		printf("이용 해주셔서 감사합니다\n");
		printf("------------------------------\n");
	}



