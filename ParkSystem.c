#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// https://security-nanglam.tistory.com/151

int main() {

	printf("------------------------\n");
	printf("���� ��� ����� \n");
	printf("------------------------\n");   // ���� ��� ����� Ʋ �ۼ�	
	printf("������ȣ %d\n");
	printf("------------------------\n");

	srand(time(NULL));
	int ent_h[2] = { 0 };
	int ent_m[2] = { 0 };
	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < 1; j++) {
			ent_h[i] = (rand() % 15) + 06; // �ð� ���� ���� ���� �Է� �ޱ� (06��~21�ñ��� �̿밡��)
			ent_m[j] = (rand() % 59); // �� ���� ���� ���� �Է� �ޱ� 
			printf("���� �ð�: %d : %d \t", ent_h[i], ent_m[j]);
			printf("\n");
		}
	}

	int exit_h[2] = { 0 };
	int exit_m[2] = { 0 };
	       printf("���� �ð��� �Է� �ϼ��� => ");
		   for (int i = 0; i < 1; i++) {
			   for (int j = 0; j < 1; j++) {
		   scanf("%d : %d \n", exit_h[i], exit_m[j]);

			   int use_h = exit_h - ent_h;
			   int use_m = exit_m - ent_m;
			   int min = use_m % 60;
			   int hour = use_m / 60;
		    printf("�̿� �ð�: %d : %d", &use_h, &use_m);
	  }
   }
}