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

	printf("------------------------\n");
	printf("주차 요금 정산기 \n");
	printf("------------------------\n");   // 주차 요금 정산기 틀 작성	
	printf("차량번호 %d\n");
	printf("------------------------\n");

	srand(time(NULL));
	int ent_hour[2] = { 0 };
	int ent_min[2] = { 0 };
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			ent_hour[i] = (rand() % 15) + 06; // 시간 단위 랜덤 난수 입력 받기 (06시~21시까지 이용가능)
			ent_min[j] = (rand() % 59); // 분 단위 랜덤 난수 입력 받기 
			printf("입차 시간: %d : %d \t", ent_hour[i], ent_min[j]);
			printf("\n");
		}
	}         
			printf("출차 시간을 입력하세요 =>  ");
			scanf("%d : %d", &exit.hour, &exit.min);
			hour = exit.hour - (ent_hour[0]);
			min = exit.min - (ent_min[0]);
			printf("이용 시간 : %d : %d", hour, min);
}
	
	