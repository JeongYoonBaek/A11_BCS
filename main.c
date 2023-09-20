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
				system("cls");
				show_title();	//중복되는 안내문 함수로
				car.car_num = insert_carnum();	//차량번호 네자리 받는 함수
				system("cls");
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX)
					break;							//차량번호 입력받을 범위 
			}
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
				show_title();	//중복되는 안내문 함수로
				car.car_num = insert_carnum();	//차량번호 네자리 입력받는 함수
				if (car.car_num >= CAR_NUM_MIN && car.car_num <= CAR_NUM_MAX) {
					break;
				}
			}
			system("cls");
			show_title();	//중복되는 안내문 함수로
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("         ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
			printf("         ┃                           ┃\n");
			printf("             차량 번호: %d        \n", car.car_num);
			printf("\n");
			printf("             입차 시간: %d 시 %d 분 \n", car.time.ent_hour, car.time.ent_min);
			printf("         ┃                           ┃\n");
			printf("         ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
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
				printf("\n");
				printf("\n");
				printf("\n");
				printf("	      <<  예시: 00:00  >>\n");
				printf("\n");
				printf("        ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
				printf("        ┃    출차시간을 입력하세요.  ┃\n");
				printf("        ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
				printf("\n");
				printf("\n");
				printf("		    ");
				scanf("%d : %d", &car.time.exit_hour, &car.time.exit_min);
				if (car.time.exit_hour > car.time.ent_hour  )		//출차시간이 입차시간보다 작을 경우 재입력
					break;
			}
			system("cls");
			show_title();
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
			file_read2(file, hour, min);
			/*printf(">입차: %d시 %d분<\n", car.time.ent_hour, car.time.ent_min);
			printf("\n");
			printf(">출차: %d시 %d분<\n", car.time.exit_hour, car.time.exit_min);
			printf("\n");
			printf("이용 시간 : %d시간 %d분 \n", hour, min);*/
			printf("\n");
			printf("\n");

			if (hour < 1 || (hour == 1 && min == 0)) {			
				printf("한시간 이하는 무료입니다. 안녕히가세요.\n");
			}		
			else if (min == 0) {				//30분당 500원씩 부과
				fee = (((hour * 60) + min) / 30 * 500)-1000;		//
				/*printf("요금: %d원\n", fee);*/
				pay(fee, cost);		
			}
			else if (min > 0 && min <= 30) {	//1분~30분일 경우 반올림 함	예)10분일경우에도 30분, 25분일 경우에도 30분으로 계산
				fee = (((hour * 60) + 30) / 30 * 500)-1000;
				/*printf("요금: %d원\n", fee);*/
				pay(fee, cost);
			}
			else {								//31~59분일 경우 시간 반올림 예) 이용시간이 2시간 35분이면 3시간으로 계산
				fee = ((((hour + 1) * 60)) / 30 * 500)-1000;
				pay(fee, cost);
			}
			printf("\n");
			printf("\n");
			printf("	 영수증을 받아가세요. \n");
			printf("\n");
			printf("\n");
			system("pause");
			system("cls");
			receipt(car, hour, min, fee);
			printf("\n");
			printf("\n");
			printf("5초뒤에 홈화면으로 넘어갑니다.");
			Sleep(5000);
		}
	}//while 문 닫는 괄호임
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

int insert_carnum() {
	PARKING car = { 0 };
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("      ┃ 차량번호 네자리를 입력해주세요. ┃\n");
	printf("      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
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
	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃                                             ┃\n");
	printf("┃	       차량 정산 프로그램             ┃\n");
	printf("┃                                             ┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	printf("\n");
}
void pay(int fee,int cost){
	
	int num;
	printf("		 요금: %d원\n", fee);
	printf("         ┃                           ┃\n");
	printf("         ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	printf("\n");
	printf("결제방식을 선택해주세요.\n");
	printf("\n");
	printf("1.현금		2.카드\n");
	scanf("%d", &num);
	if (num == 1) {
		system("cls");
		while (1) {
			show_title();
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
			else if (fee > cost) { // 투입 금액이 부족할 때 금액이 부족하다는 문구를 출력과 동시 재입력으로 되돌아감
				printf("투입 금액이 부족합니다.\n");
				system("pause");
				system("cls");
			}
		}
	}
	else if (num == 2) {		//출력만 함
		system("cls");
		show_title(); printf("\n");
		printf("      ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
		printf("      ┃  카드를 리더기에 넣어주세요.    ┃\n");
		printf("      ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		printf("\n");
		printf("      결제중입니다.... 카드를 뽑지 마세요.\n");
		Sleep(3000); // sec - ms - us - ns	//딜레이
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("	 결제가 완료되었습니다.\n");
	}
}
