#ifndef __UI_H__
#define __UI_H__

// #define NOCURSOR			0
// #define SOLID_CURSOR		1
// #define NORMAL_CURSOR	2

typedef enum {
	NOCURSOR,		// 커서 없앰		0												//소스관리도구:형상관리도구
	SOLID_CURSOR,	// solid 형태	1												//github,Perforce,SVN,NAS
	NORMAL_CURSOR	// 일반 형태		2
} CURSOR_TYPE;

typedef enum {
	BLACK,	// 0
	BLUE,	// 1
	GREEN,	// 2
	CYAN,
	RED,
	PURPLE,
	YELLOW,
	WHITE,
	GRAY,
	LIGHT_BLUE,
	LIGHT_GREEN,
	LIGHT_CYAN,
	LIGHT_RED,
	LIGHT_PURPLE,
	LIGHT_YELLOW,
	LIGHT_GRAY	// 15
} FONT_COLOR;

extern void title();
extern void gotoxy(int x, int y);
extern void set_cursor_type(CURSOR_TYPE type);
extern void font_color(FONT_COLOR color);

#endif