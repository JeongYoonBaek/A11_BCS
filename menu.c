#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

int main_menu()
{
	char menu;	
	while (1) {
		system("cls");
		printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("¦­                                             ¦­\n");
		printf("¦­	     Â÷·® Á¤»ê ÇÁ·Î±×·¥ v1.3          ¦­\n");
		printf("¦­                                             ¦­\n");
		printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
		printf("\n");
		printf("\n");
		printf("\n"); 
		printf("\n");
		printf("\n");
		printf("           ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("           ¦­   1. Â÷·®¹øÈ£ Á¶È¸  ¦­\n");
		printf("           ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
		printf("\n");
		printf("           ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("           ¦­   2. Á¤»ê           ¦­\n");
		printf("           ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("	    ¼±ÅÃ: ");
		if (scanf(" %c", &menu) == 0 || (menu != '1' && menu != '2')) {	//¸¸¾à ÀÔ·Â°ª¿¡ ¹®ÀÚ°¡ Æ÷ÇÔµÇ°Å³ª 1°ú 2°¡ ¾Æ´Ñ ´Ù¸¥ ¼ýÀÚ¸¦ ÀÔ·ÂÇßÀ» °æ¿ì ÀçÀÔ·ÂÇÏµµ·Ï Ã³¸® 
			printf("Àß¸ø ÀÔ·ÂÇÏ¼Ì½À´Ï´Ù.\n");								//scanf·Î ÀÔ·Â¹ÞÀ» ½Ã¿¡ Á÷Á¢ÀûÀ¸·Î »ç¿ëµÇÁö ¾Ê´Â ¹®ÀÚµé(°ø¹é, ÁÙ¹Ù²Þ µî)Àº ¹öÆÛ¿¡ ±×´ë·Î ³²¾ÆÀÖ°Ô µÇ´Âµ¥,
			printf("1¹ø ¶Ç´Â 2¹ø ¸Þ´º¸¦ ¼±ÅÃÇØ ÁÖ½Ê½Ã¿À.\n");				// %c°¡ ±×°ÍµéÀ» »ç¿ëÇÏ·Á°í ÇØ¼­ ±×·¸´Ù.%c¾Õ¿¡ °ø¹éÀ» ÇÏ³ª ³Ö¾îÁÖ¸é, ÀÌ·¯ÇÑ ¹®ÀÚµéÀ» ¹ö¸®°í ÀÔ·Â ¹ÞÀ½
			rewind(stdin);	//ÀÔ·Â¹öÆÛ¸¦ Áö¿ì±â À§ÇØ »ç¿ë
			system("pause");
			continue;
		}
		break;
		printf("\n");
		return menu;
	}
	//-> Â÷·®¹øÈ£ ÀÔ·Â(¼ýÀÚ ³×ÀÚ¸® ÀÔ·ÂÇÏÁö ¾ÊÀ¸¸é ´Ù½Ã ÀÔ·ÂÃ¢) -> Â÷·®¹øÈ£, ÀÔÂ÷½Ã°£ Ãâ·Â ( / 1.È¨È­¸é)
			//¹Ýº¹¹®(Â÷·®¹øÈ£ ÀÔ·Â -> Â÷·®¹øÈ£¸¦ È®ÀÎÇØÁÖ¼¼¿ä.(1.´ÙÀ½)) // -> 
	
			//1. : ÃâÂ÷½Ã°£À» ÀÔ·ÂÇØÁÖ¼¼¿ä -> ÀÔÂ÷,ÃâÂ÷,ÀÌ¿ë½Ã°£,±Ý¾× Ãâ·Â// Çö±ÝÀÌ³ª Ä«µå¸¦ ³Ö¾îÁÖ¼¼¿ä 1.Çö±Ý 2.Ä«µå )     //2. : ¸ÞÀÎ¸Þ´º Ãâ·Â
	
	//1.Çö±ÝÀ» ³Ö¾îÁÖ¼¼¿ä(ÁöÆó¸¸ °¡´É) -> 1.> /....¿µ¼öÁõÀ» Ãâ·ÂÇÏ½Ã°Ú½À´Ï±î?(1.¿¹/ 2.¾Æ´Ï¿À) -> °¨»çÇÕ´Ï´Ù ¾È³çÈ÷°¡½Ê½Ã¿À.
	//2.Ä«µå¸¦ icÄ¨ ¹æÇâÀ¸·Î ³Ö¾îÁÖ¼¼¿ä ... °áÁ¦ÁßÀÔ´Ï´Ù...¿µ¼öÁõÀ» Ãâ·ÂÇÏ½Ã°Ú½À´Ï±î?(1.¿¹/ 2.¾Æ´Ï¿À) ->°¨»çÇÕ´Ï´Ù ¾È³çÈ÷°¡½Ê½Ã¿À.
	
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
		printf("      ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("      ¦­ Â÷·®¹øÈ£ ³×ÀÚ¸®¸¦ ÀÔ·ÂÇØÁÖ¼¼¿ä. ¦­\n");
		printf("      ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
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
	printf("¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("¦­                                             ¦­\n");
	printf("¦­	     Â÷·® Á¤»ê ÇÁ·Î±×·¥ v1.3          ¦­\n");
	printf("¦­                                             ¦­\n");
	printf("¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°");
	printf("\n");
}

void pay(int fee, int cost) {

	int num;
	int total = 0;
	printf("		  ¿ä±Ý: %d ¿ø\n", fee);
	printf("         ¦­                           ¦­\n");
	printf("         ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
	printf("\n");
	printf("           °áÁ¦¹æ½ÄÀ» ¼±ÅÃÇØÁÖ¼¼¿ä.\n");
	printf("\n");
	printf("          1.Çö±Ý	       2.Ä«µå\n");
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
			printf("      ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
			printf("      ¦­	       ±Ý¾×À» ÅõÀÔÇÏ¼¼¿ä.       ¦­\n");
			printf("      ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");   // ÀÌ¿ë ±Ý¾× ÅõÀÔ
			printf("\n");
			printf("		     ");
			scanf("%d", &cost);              // ÅõÀÔÇÒ ±Ý¾× ÀÔ·Â 
			total += cost;
			printf("\n");
			printf("\n");
			if (fee == total) {  // ÀÌ¿ë±Ý¾×°ú ÅõÀÔ ±Ý¾×ÀÌ °°À»¶§ °áÁ¦ ¿Ï·á°¡ µÇ¾ú´Ù´Â Á¶°Ç¹®À» ÀÛ¼º
				printf("	     °áÁ¦°¡ ¿Ï·á µÇ¾ú½À´Ï´Ù.\n");
				break;
			}
			else if (fee < total) {  // ÅõÀÔ ±Ý¾×ÀÌ ÀÌ¿ë ±Ý¾×º¸´Ù ¸¹À» ¶§ °Å½º¸§µ· ±Ý¾×À» Ãâ·Â
				printf("	     °Å½º¸§µ· %d¿øÀÔ´Ï´Ù.\n", total - fee);
				break;
			}
			else if (fee > total) { // ÅõÀÔ ±Ý¾×ÀÌ ºÎÁ·ÇÒ ¶§ ±Ý¾×ÀÌ ºÎÁ·ÇÏ´Ù´Â ¹®±¸¸¦ Ãâ·Â°ú µ¿½Ã ÀçÀÔ·ÂÀ¸·Î µÇµ¹¾Æ°¨
				printf("	ÅõÀÔ ±Ý¾× %d ¿øÀÌ ºÎÁ·ÇÕ´Ï´Ù.\n", fee - total);
				printf("\n");
				printf("\n");
				Sleep(2000);
				continue;
			}
		}
	}
	else if (num == 2) {		//Ãâ·Â¸¸ ÇÔ
		system("cls");
		show_title(); 
		printf("\n");
		printf("      ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
		printf("      ¦­  Ä«µå¸¦ ¸®´õ±â¿¡ ³Ö¾îÁÖ¼¼¿ä.    ¦­\n");
		printf("      ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
		printf("\n");
		printf("        °áÁ¦ÁßÀÔ´Ï´Ù. Ä«µå¸¦ »ÌÁö ¸¶¼¼¿ä.\n");
		printf("\n");
		Sleep(3000); // sec - ms - us - ns	//µô·¹ÀÌ
		printf("		     ¤ý\n");
		Sleep(600);
		printf("		     ¤ý\n");
		Sleep(600);
		printf("		     ¤ý\n");
		Sleep(600);
		printf("	     °áÁ¦°¡ ¿Ï·á µÇ¾ú½À´Ï´Ù.\n");
	}
}

void receipt(PARKING car, int hour, int min, int fee) {
	printf("        ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("        ¦­                            ¦­\n");
	printf("           ÁÖÂ÷ ÀÌ¿ë ½Ã½ºÅÛ ¿µ¼öÁõ\n");
	printf("         ¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡\n");
	printf("          ÀÔÂ÷½Ã°£ : %d½Ã %dºÐ \n", car.time.ent_hour, car.time.ent_min);
	printf("\n");
	printf("          ÃâÂ÷½Ã°£ : %d½Ã %dºÐ \n", car.time.exit_hour, car.time.exit_min);
	printf("\n");
	printf("          ÀÌ¿ë ½Ã°£ : %d½Ã°£ %dºÐ\n", hour, min);
	printf("\n");
	printf("          °áÁ¦ ±Ý¾× : %d¿ø \n", fee);
	printf("        ¦­                            ¦­\n");
	printf("        ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
	printf("\n");
	printf("\n");
	printf("	   ÀÌ¿ë ÇØÁÖ¼Å¼­ °¨»çÇÕ´Ï´Ù\n");
	printf("\n");
}

void show_ent_hour(PARKING car) {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("         ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("         ¦­                           ¦­\n");
	printf("             Â÷·® ¹øÈ£: %d        \n", car.car_num);
	printf("\n");
	printf("             ÀÔÂ÷ ½Ã°£: %d ½Ã %d ºÐ \n", car.time.ent_hour, car.time.ent_min);
	printf("         ¦­                           ¦­\n");
	printf("         ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}

void insert_exit_hour() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("	      <<  ¿¹½Ã: 00:00  >>\n");
	printf("\n");
	printf("        ¦®¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¯\n");
	printf("        ¦­    ÃâÂ÷½Ã°£À» ÀÔ·ÂÇÏ¼¼¿ä.  ¦­\n");
	printf("        ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
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
		printf("	      ¿µ¼öÁõÀ» ¹Þ¾Æ°¡¼¼¿ä. \n");
		printf("\n");
		printf("\n");
		printf("\n");
		system("cls");
		receipt(car, hour, min, fee);
		printf("\n");
		printf("\n");
		printf("%dÃÊ µÚ¿¡ È¨È­¸éÀ¸·Î ³Ñ¾î°©´Ï´Ù.", i);
		Sleep(1000);
	}
}

void cal_fee(int fee, int cost, int hour, int min){
	if (hour < 1 || (hour == 1 && min == 0)) {
				printf("		  ¿ä±Ý: %d ¿ø\n", fee);
				printf("         ¦­                           ¦­\n");
				printf("         ¦±¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦¬¦°\n");
				printf("\n");
				printf("\n");
				printf("	    ÇÑ½Ã°£ ÀÌÇÏ´Â ¹«·áÀÔ´Ï´Ù.\n");
			}
			else if (min == 0) {				//30ºÐ´ç 500¿ø¾¿ ºÎ°ú
				fee = (((hour * 60) + min) / 30 * 500) - 1000;		//
				/*printf("¿ä±Ý: %d¿ø\n", fee);*/
				pay(fee, cost);
			}
			else if (min > 0 && min <= 30) {	//1ºÐ~30ºÐÀÏ °æ¿ì ¹Ý¿Ã¸² ÇÔ	¿¹)10ºÐÀÏ°æ¿ì¿¡µµ 30ºÐ, 25ºÐÀÏ °æ¿ì¿¡µµ 30ºÐÀ¸·Î °è»ê
				fee = (((hour * 60) + 30) / 30 * 500) - 1000;
				/*printf("¿ä±Ý: %d¿ø\n", fee);*/
				pay(fee, cost);
			}
			else {								//31~59ºÐÀÏ °æ¿ì ½Ã°£ ¹Ý¿Ã¸² ¿¹) ÀÌ¿ë½Ã°£ÀÌ 2½Ã°£ 35ºÐÀÌ¸é 3½Ã°£À¸·Î °è»ê
				fee = ((((hour + 1) * 60)) / 30 * 500) - 1000;
				pay(fee, cost);
			}
}

