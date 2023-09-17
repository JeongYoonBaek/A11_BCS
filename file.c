#define _CRT_SECURE_NO_WARNINGS	//fopen, fclose
#include <stdio.h>	//printf()
#include <stdlib.h>	//exit(0)
#include <string.h>	// strcpy()
#include "file.h"

void file_write(PARKING car , char filename[])	//���ǿ� �ִ� �Ű������� �󲮵���. ���ο��� ȣ���� �� ä����
{
	FILE* fp = fopen(filename, "wb");
	if (fp == NULL) {
		printf("���� ���� ����!\n");
		return;
	}
	fwrite(&car, sizeof(PARKING), 1, fp);
	fclose(fp);
}


void file_read(char filename[])
{
	FILE* fp = fopen(filename, "rb");
	if (fp == NULL) {
		printf("���� �б� ����!\n");
	}
	PARKING car = { 0 };	//����ִ� �ӽ� ���� ����
	int count = 1;
	int check = 0;	//while�����ϸ� 1�ιٲ��, ������ϸ� 0	check �÷��׺���
	while (fread(&car, sizeof(car), 1, fp) == 1) {
		printf("	���� ��ȣ: %d \n", car.car_num);
		printf("\n");
		printf("	���� �ð�: %d�� %d��\n", car.time.ent_hour, car.time.ent_min);
		check = 1;
	}
	fclose(fp);
	if (check == 0) {
		printf("�����Ͱ� �������� �ʽ��ϴ�.\n");
	}
}


