#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"

int main_menu()
{
	char menu;	
	while (1) {
		system("cls");
		printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("早                                             早\n");
		printf("早	     離榆 薑骯 Щ煎斜極 v1.3          早\n");
		printf("早                                             早\n");
		printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
		printf("\n");
		printf("\n");
		printf("\n"); 
		printf("\n");
		printf("\n");
		printf("           旨收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("           早   1. 離榆廓�� 褻��  早\n");
		printf("           曲收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("\n");
		printf("           旨收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("           早   2. 薑骯           早\n");
		printf("           曲收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("	    摹鷗: ");
		if (scanf(" %c", &menu) == 0 || (menu != '1' && menu != '2')) {	//虜擒 殮溘高縑 僥濠陛 んл腎剪釭 1婁 2陛 嬴棋 棻艇 璋濠蒂 殮溘ц擊 唳辦 營殮溘ж紫煙 籀葬 
			printf("澀跤 殮溘ж樟蝗棲棻.\n");								//scanf煎 殮溘嫡擊 衛縑 霜蕾瞳戲煎 餌辨腎雖 彊朝 僥濠菟(奢寥, 還夥翎 蛔)擎 幗ぷ縑 斜渠煎 陴嬴氈啪 腎朝等,
			printf("1廓 傳朝 2廓 詭景蒂 摹鷗п 輿褊衛螃.\n");				// %c陛 斜匙菟擊 餌辨ж溥堅 п憮 斜溢棻.%c擅縑 奢寥擊 ж釭 厥橫輿賊, 檜楝и 僥濠菟擊 幗葬堅 殮溘 嫡擠
			rewind(stdin);	//殮溘幗ぷ蒂 雖辦晦 嬪п 餌辨
			system("pause");
			continue;
		}
		break;
		printf("\n");
		return menu;
	}
	//-> 離榆廓�� 殮溘(璋濠 啻濠葬 殮溘ж雖 彊戲賊 棻衛 殮溘璽) -> 離榆廓��, 殮離衛除 轎溘 ( / 1.�亞飛�)
			//奩犒僥(離榆廓�� 殮溘 -> 離榆廓�ㄧ� �挫恉媮祤撚�.(1.棻擠)) // -> 
	
			//1. : 轎離衛除擊 殮溘п輿撮蹂 -> 殮離,轎離,檜辨衛除,旎擋 轎溘// ⑷旎檜釭 蘋萄蒂 厥橫輿撮蹂 1.⑷旎 2.蘋萄 )     //2. : 詭檣詭景 轎溘
	
	//1.⑷旎擊 厥橫輿撮蹂(雖わ虜 陛棟) -> 1.> /....艙熱隸擊 轎溘ж衛啊蝗棲梱?(1.蕨/ 2.嬴棲螃) -> 馬餌м棲棻 寰喟�鱁■宒藩�.
	//2.蘋萄蒂 ic蘑 寞щ戲煎 厥橫輿撮蹂 ... 唸薯醞殮棲棻...艙熱隸擊 轎溘ж衛啊蝗棲梱?(1.蕨/ 2.嬴棲螃) ->馬餌м棲棻 寰喟�鱁■宒藩�.
	
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
		printf("      旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("      早 離榆廓�� 啻濠葬蒂 殮溘п輿撮蹂. 早\n");
		printf("      曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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
	printf("旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("早                                             早\n");
	printf("早	     離榆 薑骯 Щ煎斜極 v1.3          早\n");
	printf("早                                             早\n");
	printf("曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭");
	printf("\n");
}

void pay(int fee, int cost) {

	int num;
	int total = 0;
	printf("		  蹂旎: %d 錳\n", fee);
	printf("         早                           早\n");
	printf("         曲收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\n");
	printf("           唸薯寞衝擊 摹鷗п輿撮蹂.\n");
	printf("\n");
	printf("          1.⑷旎	       2.蘋萄\n");
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
			printf("      旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
			printf("      早	       旎擋擊 癱殮ж撮蹂.       早\n");
			printf("      曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");   // 檜辨 旎擋 癱殮
			printf("\n");
			printf("		     ");
			scanf("%d", &cost);              // 癱殮й 旎擋 殮溘 
			total += cost;
			printf("\n");
			printf("\n");
			if (fee == total) {  // 檜辨旎擋婁 癱殮 旎擋檜 偽擊陽 唸薯 諫猿陛 腎歷棻朝 褻勒僥擊 濛撩
				printf("	     唸薯陛 諫猿 腎歷蝗棲棻.\n");
				break;
			}
			else if (fee < total) {  // 癱殮 旎擋檜 檜辨 旎擋爾棻 號擊 陽 剪蝶葷絲 旎擋擊 轎溘
				printf("	     剪蝶葷絲 %d錳殮棲棻.\n", total - fee);
				break;
			}
			else if (fee > total) { // 癱殮 旎擋檜 睡褶й 陽 旎擋檜 睡褶ж棻朝 僥掘蒂 轎溘婁 翕衛 營殮溘戲煎 腎給嬴馬
				printf("	癱殮 旎擋 %d 錳檜 睡褶м棲棻.\n", fee - total);
				printf("\n");
				printf("\n");
				Sleep(2000);
				continue;
			}
		}
	}
	else if (num == 2) {		//轎溘虜 л
		system("cls");
		show_title(); 
		printf("\n");
		printf("      旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
		printf("      早  蘋萄蒂 葬渦晦縑 厥橫輿撮蹂.    早\n");
		printf("      曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
		printf("\n");
		printf("        唸薯醞殮棲棻. 蘋萄蒂 鉻雖 葆撮蹂.\n");
		printf("\n");
		Sleep(3000); // sec - ms - us - ns	//裁溯檜
		printf("		     王\n");
		Sleep(600);
		printf("		     王\n");
		Sleep(600);
		printf("		     王\n");
		Sleep(600);
		printf("	     唸薯陛 諫猿 腎歷蝗棲棻.\n");
	}
}

void receipt(PARKING car, int hour, int min, int fee) {
	printf("        旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("        早                            早\n");
	printf("           輿離 檜辨 衛蝶蠱 艙熱隸\n");
	printf("         式式式式式式式式式式式式式式式式式式式式式式式式式式式式\n");
	printf("          殮離衛除 : %d衛 %d碟 \n", car.time.ent_hour, car.time.ent_min);
	printf("\n");
	printf("          轎離衛除 : %d衛 %d碟 \n", car.time.exit_hour, car.time.exit_min);
	printf("\n");
	printf("          檜辨 衛除 : %d衛除 %d碟\n", hour, min);
	printf("\n");
	printf("          唸薯 旎擋 : %d錳 \n", fee);
	printf("        早                            早\n");
	printf("        曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\n");
	printf("\n");
	printf("	   檜辨 п輿敷憮 馬餌м棲棻\n");
	printf("\n");
}

void show_ent_hour(PARKING car) {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("         旨收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("         早                           早\n");
	printf("             離榆 廓��: %d        \n", car.car_num);
	printf("\n");
	printf("             殮離 衛除: %d 衛 %d 碟 \n", car.time.ent_hour, car.time.ent_min);
	printf("         早                           早\n");
	printf("         曲收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n");
}

void insert_exit_hour() {
	printf("\n");
	printf("\n");
	printf("\n");
	printf("	      <<  蕨衛: 00:00  >>\n");
	printf("\n");
	printf("        旨收收收收收收收收收收收收收收收收收收收收收收收收收收收收旬\n");
	printf("        早    轎離衛除擊 殮溘ж撮蹂.  早\n");
	printf("        曲收收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
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
		printf("	      艙熱隸擊 嫡嬴陛撮蹂. \n");
		printf("\n");
		printf("\n");
		printf("\n");
		system("cls");
		receipt(car, hour, min, fee);
		printf("\n");
		printf("\n");
		printf("%d蟾 菴縑 �亞飛橉虞� 剩橫骨棲棻.", i);
		Sleep(1000);
	}
}

void cal_fee(int fee, int cost, int hour, int min){
	if (hour < 1 || (hour == 1 && min == 0)) {
				printf("		  蹂旎: %d 錳\n", fee);
				printf("         早                           早\n");
				printf("         曲收收收收收收收收收收收收收收收收收收收收收收收收收收收旭\n");
				printf("\n");
				printf("\n");
				printf("	    и衛除 檜ж朝 鼠猿殮棲棻.\n");
			}
			else if (min == 0) {				//30碟渡 500錳噶 睡婁
				fee = (((hour * 60) + min) / 30 * 500) - 1000;		//
				/*printf("蹂旎: %d錳\n", fee);*/
				pay(fee, cost);
			}
			else if (min > 0 && min <= 30) {	//1碟~30碟橾 唳辦 奩螢葡 л	蕨)10碟橾唳辦縑紫 30碟, 25碟橾 唳辦縑紫 30碟戲煎 啗骯
				fee = (((hour * 60) + 30) / 30 * 500) - 1000;
				/*printf("蹂旎: %d錳\n", fee);*/
				pay(fee, cost);
			}
			else {								//31~59碟橾 唳辦 衛除 奩螢葡 蕨) 檜辨衛除檜 2衛除 35碟檜賊 3衛除戲煎 啗骯
				fee = ((((hour + 1) * 60)) / 30 * 500) - 1000;
				pay(fee, cost);
			}
}

