#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

int main_menu()
{
	char menu;	
	while (1) {
		system("cls");
		printf("����������������������������������������������������������������������������������������������\n");
		printf("��                                             ��\n");
		printf("��	     ���� ���� ���α׷� v1.3          ��\n");
		printf("��                                             ��\n");
		printf("����������������������������������������������������������������������������������������������");
		printf("\n");
		printf("\n");
		printf("\n"); 
		printf("\n");
		printf("\n");
		printf("           ����������������������������������������������\n");
		printf("           ��   1. ������ȣ ��ȸ  ��\n");
		printf("           ����������������������������������������������\n");
		printf("\n");
		printf("           ����������������������������������������������\n");
		printf("           ��   2. ����           ��\n");
		printf("           ����������������������������������������������\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("	    ����: ");
		if (scanf(" %c", &menu) == 0 || (menu != '1' && menu != '2')) {	//���� �Է°��� ���ڰ� ���Եǰų� 1�� 2�� �ƴ� �ٸ� ���ڸ� �Է����� ��� ���Է��ϵ��� ó�� 
			printf("�߸� �Է��ϼ̽��ϴ�.\n");								//scanf�� �Է¹��� �ÿ� ���������� ������ �ʴ� ���ڵ�(����, �ٹٲ� ��)�� ���ۿ� �״�� �����ְ� �Ǵµ�,
			printf("1�� �Ǵ� 2�� �޴��� ������ �ֽʽÿ�.\n");				// %c�� �װ͵��� ����Ϸ��� �ؼ� �׷���.%c�տ� ������ �ϳ� �־��ָ�, �̷��� ���ڵ��� ������ �Է� ����
			rewind(stdin);	//�Է¹��۸� ����� ���� ���
			system("pause");
			continue;
		}
		break;
		printf("\n");
		return menu;
	}
	//-> ������ȣ �Է�(���� ���ڸ� �Է����� ������ �ٽ� �Է�â) -> ������ȣ, �����ð� ��� ( / 1.Ȩȭ��)
			//�ݺ���(������ȣ �Է� -> ������ȣ�� Ȯ�����ּ���.(1.����)) // -> 
	
			//1. : �����ð��� �Է����ּ��� -> ����,����,�̿�ð�,�ݾ� ���// �����̳� ī�带 �־��ּ��� 1.���� 2.ī�� )     //2. : ���θ޴� ���
	
	//1.������ �־��ּ���(���� ����) -> 1.> /....�������� ����Ͻðڽ��ϱ�?(1.��/ 2.�ƴϿ�) -> �����մϴ� �ȳ������ʽÿ�.
	//2.ī�带 icĨ �������� �־��ּ��� ... �������Դϴ�...�������� ����Ͻðڽ��ϱ�?(1.��/ 2.�ƴϿ�) ->�����մϴ� �ȳ������ʽÿ�.
	
}

int insert_carnum(PARKING car) {

	while (1) {
		system("cls");
		show_title();
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("      ����������������������������������������������������������������������\n");
		printf("      �� ������ȣ ���ڸ��� �Է����ּ���. ��\n");
		printf("      ����������������������������������������������������������������������\n");
		printf("\n");
		printf("\n");
		printf("		   ");
		if (scanf("%d", &car.car_num) == 0) {
			rewind(stdin);
		}
		else {
			break;
		}
		printf("\n");
		printf("\n");
		printf("\n");
	}
	return car.car_num;
}
void show_title() {
	printf("����������������������������������������������������������������������������������������������\n");
	printf("��                                             ��\n");
	printf("��	     ���� ���� ���α׷� v1.3          ��\n");
	printf("��                                             ��\n");
	printf("����������������������������������������������������������������������������������������������");
	printf("\n");
}

void pay(int fee, int cost) {

	int num;
	int total = 0;
	printf("		  ���: %d ��\n", fee);
	printf("         ��                           ��\n");
	printf("         ����������������������������������������������������������\n");
	printf("\n");
	printf("           ��������� �������ּ���.\n");
	printf("\n");
	printf("          1.����	       2.ī��\n");
	printf("\n");
	printf("           ");
	scanf("%d", &num);
	if (num == 1) {
		system("cls");
		while (1) {
			system("cls");
			show_title();
			printf("\n");
			printf("\n");
			printf("\n");
			printf("      ����������������������������������������������������������������������\n");
			printf("      ��	       �ݾ��� �����ϼ���.       ��\n");
			printf("      ����������������������������������������������������������������������\n");   // �̿� �ݾ� ����
			printf("\n");
			printf("		     ");
			scanf("%d", &cost);              // ������ �ݾ� �Է� 
			total += cost;
			printf("\n");
			printf("\n");
			if (fee == total) {  // �̿�ݾװ� ���� �ݾ��� ������ ���� �Ϸᰡ �Ǿ��ٴ� ���ǹ��� �ۼ�
				printf("	     ������ �Ϸ� �Ǿ����ϴ�.\n");
				break;
			}
			else if (fee < total) {  // ���� �ݾ��� �̿� �ݾ׺��� ���� �� �Ž����� �ݾ��� ���
				printf("	     �Ž����� %d���Դϴ�.\n", total - fee);
				break;
			}
			else if (fee > total) { // ���� �ݾ��� ������ �� �ݾ��� �����ϴٴ� ������ ��°� ���� ���Է����� �ǵ��ư�
				printf("	���� �ݾ� %d ���� �����մϴ�.\n", fee - total);
				printf("\n");
				printf("\n");
				Sleep(2000);
				continue;
			}
		}
	}
	else if (num == 2) {		//��¸� ��
		system("cls");
		show_title(); 
		printf("\n");
		printf("      ����������������������������������������������������������������������\n");
		printf("      ��  ī�带 �����⿡ �־��ּ���.    ��\n");
		printf("      ����������������������������������������������������������������������\n");
		printf("\n");
		printf("        �������Դϴ�. ī�带 ���� ������.\n");
		printf("\n");
		Sleep(3000); // sec - ms - us - ns	//������
		printf("		     ��\n");
		Sleep(600);
		printf("		     ��\n");
		Sleep(600);
		printf("		     ��\n");
		Sleep(600);
		printf("	     ������ �Ϸ� �Ǿ����ϴ�.\n");
	}
}

void receipt(PARKING car, int hour, int min, int fee) {
	printf("        ������������������������������������������������������������\n");
	printf("        ��                            ��\n");
	printf("           ���� �̿� �ý��� ������\n");
	printf("         ��������������������������������������������������������\n");
	printf("          �����ð� : %d�� %d�� \n", car.time.ent_hour, car.time.ent_min);
	printf("\n");
	printf("          �����ð� : %d�� %d�� \n", car.time.exit_hour, car.time.exit_min);
	printf("\n");
	printf("          �̿� �ð� : %d�ð� %d��\n", hour, min);
	printf("\n");
	printf("          ���� �ݾ� : %d�� \n", fee);
	printf("        ��                            ��\n");
	printf("        ������������������������������������������������������������\n");
	printf("\n");
	printf("\n");
	printf("	   �̿� ���ּż� �����մϴ�\n");
	printf("\n");
}

void show_ent_hour(PARKING car) {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("         ����������������������������������������������������������\n");
	printf("         ��                           ��\n");
	printf("             ���� ��ȣ: %d        \n", car.car_num);
	printf("\n");
	printf("             ���� �ð�: %d �� %d �� \n", car.time.ent_hour, car.time.ent_min);
	printf("         ��                           ��\n");
	printf("         ����������������������������������������������������������\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}

void insert_exit_hour() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("	      <<  ����: 00:00  >>\n");
	printf("\n");
	printf("        ������������������������������������������������������������\n");
	printf("        ��    �����ð��� �Է��ϼ���.  ��\n");
	printf("        ������������������������������������������������������������\n");
	printf("\n");
	printf("\n");
	printf("		    ");
}

void receipt_msg(PARKING car, int hour, int min, int fee) {
	for (int i = 5; i > 0; i--) {
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("	      �������� �޾ư�����. \n");
		printf("\n");
		printf("\n");
		printf("\n");
		system("cls");
		receipt(car, hour, min, fee);
		printf("\n");
		printf("\n");
		printf("%d�� �ڿ� Ȩȭ������ �Ѿ�ϴ�.", i);
		Sleep(1000);
	}
}

void cal_fee(int fee, int cost, int hour, int min){
	if (hour < 1 || (hour == 1 && min == 0)) {
				printf("		  ���: %d ��\n", fee);
				printf("         ��                           ��\n");
				printf("         ����������������������������������������������������������\n");
				printf("\n");
				printf("\n");
				printf("	    �ѽð� ���ϴ� �����Դϴ�.\n");
			}
			else if (min == 0) {				//30�д� 500���� �ΰ�
				fee = (((hour * 60) + min) / 30 * 500) - 1000;		//
				/*printf("���: %d��\n", fee);*/
				pay(fee, cost);
			}
			else if (min > 0 && min <= 30) {	//1��~30���� ��� �ݿø� ��	��)10���ϰ�쿡�� 30��, 25���� ��쿡�� 30������ ���
				fee = (((hour * 60) + 30) / 30 * 500) - 1000;
				/*printf("���: %d��\n", fee);*/
				pay(fee, cost);
			}
			else {								//31~59���� ��� �ð� �ݿø� ��) �̿�ð��� 2�ð� 35���̸� 3�ð����� ���
				fee = ((((hour + 1) * 60)) / 30 * 500) - 1000;
				pay(fee, cost);
			}
}

