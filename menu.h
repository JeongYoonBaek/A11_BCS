#ifndef __MENU_H__		//->��� ���� �ߺ� ����� ���� , �̸��� ����ڰ� ���� == 
#define __MENU_H__

typedef enum {
	MAIN_CAR_NUM = '1',		//������ȣ��ȸ �޴�												//�ҽ���������:�����������
	MAIN_PAYMENT 		//���� �޴�
							//github,Perforce,SVN,NAS

} MAIN_MENU;

extern int main_menu();		//extern �ܺο� �����ֵ��� �ϴ� ���. �������� �����Ϸ��� �ڵ����� �ٿ���
#endif