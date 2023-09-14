#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// https://security-nanglam.tistory.com/151

int main() {

	printf("------------------------\n");
	printf("주차 요금 정산기 \n");
	printf("------------------------\n");   // 주차 요금 정산기 틀 작성	
	printf("차량번호 %d\n");
	printf("------------------------\n");

	srand(time(NULL));
	int ent_h[2] = { 0 };
	int ent_m[2] = { 0 };
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			ent_h[i] = (rand() % 15) + 06; // 시간 단위 랜덤 난수 입력 받기 (06시~21시까지 이용가능)
			ent_m[j] = (rand() % 59); // 분 단위 랜덤 난수 입력 받기 
			printf("입차 시간: %d : %d \t", ent_h[i], ent_m[j]);
			printf("\n");
		}
	}

	int exit_h[2] = { 0 };
	int exit_m[2] = { 0 };
	       printf("출차 시간을 입력 하세요 => ");
		   for (int i = 0; i < 1; i++) {
			   for (int j = 0; j < 1; j++) {
		   scanf("%d : %d \n", exit_h[i], exit_m[j]);

			   int use_h = exit_h - ent_h;
			   int use_m = exit_m - ent_m;
			   int min = use_m % 60;
			   int hour = use_m / 60;
		    printf("이용 시간: %d : %d", &use_h, &use_m);
	  }
   }
}