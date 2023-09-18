#ifndef __MENU_H__		//->헤더 파일 중복 사용을 방지 , 이름은 사용자가 만듦 == 
#define __MENU_H__

typedef enum {
	MAIN_CAR_NUM = '1',		//차량번호조회 메뉴												//소스관리도구:형상관리도구
	MAIN_PAYMENT 		//정산 메뉴
							//github,Perforce,SVN,NAS

} MAIN_MENU;

extern int main_menu();		//extern 외부에 보여주도록 하는 기능. 생략가능 컴파일러가 자동으로 붙여줌
#endif