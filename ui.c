#include <stdio.h>	//printf���
#include <windows.h>	//win32 api ��� (������ ȯ�濡���� ��� ����)
#include "ui.h"

void title()
{
	int x = 10;
	int y = 5;
	gotoxy(x, y + 0); printf("�ââââ�       �â�        �âââ�      ��    ��     �ââ�     ��      ��      �ââ�");
	gotoxy(x, y + 1); printf("��      ��      ��  ��       ��      ��    ��  ��         ��       �â�    ��    ��     ��");
	gotoxy(x, y + 2); printf("��      ��     ��    ��      ��      ��    �â�           ��       �� ��   ��    ��");
	gotoxy(x, y + 3); printf("�ââââ�    �ââââ�     �âââ�      �â�           ��       ��  ��  ��    ��");
	gotoxy(x, y + 4); printf("��            ��      ��     ��   ��       �� ��          ��       ��   �� ��    ��  �ââ�");
	gotoxy(x, y + 5); printf("��            ��      ��     ��    ��      ��   ��        ��       ��    �â�    ��     ��");
	gotoxy(x, y + 6); printf("��            ��      ��     ��     ��     ��    ��       ��       ��      ��     ��    ��");
	gotoxy(x, y + 7); printf("��            ��      ��     ��      ��    ��     ��    �ââ�     ��      ��      �ââ�");
	gotoxy(x, y + 10); printf("�ââââ�    �ââââ�    �ââââ�");
	gotoxy(x, y + 11); printf("��            ��            ��");
	gotoxy(x, y + 12); printf("��            ��            ��");
	gotoxy(x, y + 13); printf("�ââââ�    �ââââ�    �ââââ�");
	gotoxy(x, y + 14); printf("��            ��            ��");
	gotoxy(x, y + 15); printf("��            ��            ��");
	gotoxy(x, y + 16); printf("��            ��            ��");
	gotoxy(x, y + 17); printf("��            �ââââ�    �ââââ�");
	gotoxy(x+60, y + 11); printf("�̿�ð�: 06:00~22:00\n");
	gotoxy(x+60, y + 15); printf("1�ð� ���� ����");
	gotoxy(x+60, y + 17); printf("30�д� 500�� �ΰ�");
	
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// ������ �ֿܼ��� Ŀ�� ��ġ �̵�
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void set_cursor_type(CURSOR_TYPE type)
{
	CONSOLE_CURSOR_INFO info = { 0 };
	switch (type) {
	case NOCURSOR:
		info.dwSize = 1;
		info.bVisible = FALSE;
		break;
	case SOLID_CURSOR:
		info.dwSize = 100;
		info.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		info.dwSize = 20;
		info.bVisible = TRUE;
		break;
	}
	// Ŀ�� Ÿ���� ����(win32 API) ������ �����Լ�
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void font_color(FONT_COLOR color)
{
	// ��Ʈ�� ���� ����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}