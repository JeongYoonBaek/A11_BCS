#include <stdio.h>	//printf사용
#include <windows.h>	//win32 api 사용 (윈도우 환경에서만 사용 가능)
#include "ui.h"

void title()
{
	int x = 10;
	int y = 5;
	gotoxy(x, y + 0); printf("▣▣▣▣▣       ▣▣        ▣▣▣▣      ▣    ▣     ▣▣▣     ▣      ▣      ▣▣▣");
	gotoxy(x, y + 1); printf("▣      ▣      ▣  ▣       ▣      ▣    ▣  ▣         ▣       ▣▣    ▣    ▣     ▣");
	gotoxy(x, y + 2); printf("▣      ▣     ▣    ▣      ▣      ▣    ▣▣           ▣       ▣ ▣   ▣    ▣");
	gotoxy(x, y + 3); printf("▣▣▣▣▣    ▣▣▣▣▣     ▣▣▣▣      ▣▣           ▣       ▣  ▣  ▣    ▣");
	gotoxy(x, y + 4); printf("▣            ▣      ▣     ▣   ▣       ▣ ▣          ▣       ▣   ▣ ▣    ▣  ▣▣▣");
	gotoxy(x, y + 5); printf("▣            ▣      ▣     ▣    ▣      ▣   ▣        ▣       ▣    ▣▣    ▣     ▣");
	gotoxy(x, y + 6); printf("▣            ▣      ▣     ▣     ▣     ▣    ▣       ▣       ▣      ▣     ▣    ▣");
	gotoxy(x, y + 7); printf("▣            ▣      ▣     ▣      ▣    ▣     ▣    ▣▣▣     ▣      ▣      ▣▣▣");
	gotoxy(x, y + 13); printf("▣▣▣▣▣    ▣▣▣▣▣    ▣▣▣▣▣");
	gotoxy(x, y + 14); printf("▣            ▣            ▣");
	gotoxy(x, y + 15); printf("▣            ▣            ▣");
	gotoxy(x, y + 16); printf("▣▣▣▣▣    ▣▣▣▣▣    ▣▣▣▣▣");
	gotoxy(x, y + 17); printf("▣            ▣            ▣");
	gotoxy(x, y + 18); printf("▣            ▣            ▣");
	gotoxy(x, y + 19); printf("▣            ▣            ▣");
	gotoxy(x, y + 20); printf("▣            ▣▣▣▣▣    ▣▣▣▣▣");
	gotoxy(x + 30, y + 12); printf("");
	gotoxy(x + 30, y + 13); printf("");
	gotoxy(x + 30, y + 14); printf("");
	gotoxy(x + 30, y + 15); printf("");
	gotoxy(x + 30, y + 16); printf("");
	gotoxy(x + 30, y + 17); printf("");
	gotoxy(x + 30, y + 18); printf("");
	gotoxy(x + 30, y + 19); printf("");
	gotoxy(x + 30, y + 20); printf("");
	gotoxy(x+78, y + 13); printf("이용시간: 06:00~22:00\n");
	gotoxy(x+80, y + 17); printf("1시간 이하 무료");
	gotoxy(x+80, y + 20); printf("30분당 500원 부과");
	
}

void gotoxy(int x, int y)
{
	COORD pos = { x, y };
	// 윈도우 콘솔에서 커서 위치 이동
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
	// 커서 타입을 설정(win32 API) 윈도우 전용함수
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void font_color(FONT_COLOR color)
{
	// 폰트에 색상 적용
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}