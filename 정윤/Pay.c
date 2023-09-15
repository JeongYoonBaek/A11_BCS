#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main() {
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
}