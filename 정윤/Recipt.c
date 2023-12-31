#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct time { // 구조체를 이용하여 시간 변수 저장한다. 
	int hour, min;
};

int main() {
	struct time ent; // 입차 시간 구조체
	struct time exit; // 출차 시간 구조체
	int hour, min; // 시간, 분 변수 

	srand(time(NULL));
	int ent_hour[2] = { 0 };
	int ent_min[2] = { 0 };
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			ent_hour[i] = (rand() % 14) + 06; // 시간 단위 랜덤 난수 입력 받기 (06시~21시까지 이용가능)
			ent_min[j] = (rand() % 59); // 분 단위 랜덤 난수 입력 받기 
			printf("입차 시간: %d시 %d분 \t", ent_hour[i], ent_min[j]);
			printf("\n");

			printf("출차 시간을 입력하세요 =>  ");
			scanf("%d : %d", &exit.hour, &exit.min);
			hour = exit.hour - (ent_hour[0]);
			min = exit.min - (ent_min[0]);
			if (exit.min < ent_min[0]) {
				hour = (exit.hour - (ent_hour[0])) - 1;
				min = ((exit.min - ent_min[0])) + 60;
			}
			printf("이용 시간 : %d시간 %d분 \n", hour, min);


			int car_num = 1234;
			int fee = 5000; // 이용 금액 변수
			int cost = 0;   // 투입 금액 변수
			char str = "";

			printf("이용 금액 : %d원\n", fee); // 이용금액 출력
			printf("금액을 투입하세요 => ");   // 이용 금액 투입
			scanf("%d", &cost);              // 투입할 금액 입력 
			printf("금액을 투입 하였습니다.\n"); // 성공적으로 금액 투입하였음을 출력

			if (fee == cost) {  // 이용금액과 투입 금액이 같을때 결제 완료가 되었다는 조건문을 작성
				printf("결제가 완료 되었습니다! 이용 해주셔서 감사합니다 ^^\n");
			}
			else if (fee < cost) {  // 투입 금액이 이용 금액보다 많을 때 거스름돈 금액을 출력
				printf("거스름돈 %d원을 받으세요 이용 해주셔서 감사합니다 ^^\n", cost - fee);
			}
			else if (fee > cost) { // 투입 금액이 부족할 때 금액이 부족하다는 문구를 출력
				printf("투입 금액이 부족 합니다!");
			}
			else if (str) {
				printf("잘못 입력하셨습니다. 다시 입력 해주세요\n");
			}
			else {
				
			}
			printf("------------------------------\n");
			printf("   주차 이용 시스템 영수증\n");
			printf("------------------------------\n");
			printf("차량 번호 : %d \n", car_num);
			printf("입차 시간 : %d시 %d분 \n", ent_hour[i], ent_min[j]);
			printf("출차 시간 : %d시 %d분 \n", exit.hour, exit.min);
			printf("이용 시간 : %d시간 %d분\n", hour, min);
			printf("결제 금액 : %d원 \n", fee);
			printf("------------------------------\n");
			printf("이용 해주셔서 감사합니다\n");
			printf("------------------------------\n");
		}
	}
}