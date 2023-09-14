#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>

typedef struct _CAR {
	char num[20];
} CAR;

int sub_menu();

int main()
{
	while (1) {
		system("cls");
		printf("차량번호 4자리를 입력해 주십시오.\n");		// 차량번호 입력 안내문 출력
		int car_num[4] = { 0 };							// 차량번호 저장 배열 변수

		for (int i = 0; i < 4; i++) {						// 배열 인덱스에 차량번호 1개씩 담기 위해 4번(4자리) 반복
			if (scanf("%1d", &car_num[i]) == 0) {			// 만약 입력한 값이 숫자가 아니라면(scanf도 반환값이 있나방!)
				printf("잘못 입력하셨습니다.\n");				// 다시 입력하라고 안내문 출력
				printf("다시 입력하여 주십시오.\n");
				rewind(stdin);								// 문자 입력시 버퍼에 남아 있는 '공백'과 '\n' 삭제
				i = (i - i) - 1;							// 문자 입력시 i는 -1로 재설정 됨
			}
			// if문 탈출시 i++되어 결국 i는 0이 된다(= car_num[0]부터 다시 입력이 가능)
		}
		printf("\n");


		// [디버깅] 차량번호(한 자리씩 x 4번 반복)
		for (int i = 0; i < 4; i++) {
			printf("car_num[%d] = %d\n", i, car_num[i]);
		}
		printf("\n");


		// 입력한 차량번호가 맞는지 재확인 안내문 출력
		printf("입력하신 차량번호를 확인하여 주십시오.\n");
		for (int i = 0; i < 4; i++) {	// 차량번호 한 자리씩x네 번 출력
			printf("%d", car_num[i]);
		}
		printf("\n");
				
		while (1) {
			printf("1.다음 단계  2.다시 입력\n");
			int answer = sub_menu();
			if (answer == 2) {		// 2번 다시입력 선택시 while문을 탈출, 메인 while문으로 되돌아간다
				break;
			}
		}


	}
}

int sub_menu()
{
	int menu;
	scanf("%d", &menu);
	return menu;
}