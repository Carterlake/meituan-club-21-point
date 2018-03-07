#include<stdio.h>
#include<cstdlib>
#include<ctime>

#define numberLength 4  // 数字长度, 本例子猜4位数


void generateActNumber(char actNumber[]){  // 生成数字 
	srand(time(NULL));  // 设置随机种子
	
	for(int i = 0; i < numberLength; i++){  // 随机得到一个4位数字
		actNumber[i] = rand() % 10 + 48;
	}
}


void inputGuessNumber(char guessNumber[]){  // 输入数字 
		for(int j = 0; j < numberLength; j++){  // 输入猜测的数字
			scanf("%c",&guessNumber[j]);
		}
		getchar();
}

void judge(char guessNumber[], char actNumber[], int &aTip, int &bTip){  // 判断正确性 
	for(int x = 0; x < numberLength; x++){
		for(int y = 0; y < numberLength; y++){
			if (x == y && guessNumber[x] == actNumber[y]){  // 数字正确且位置正确
				aTip++;
			}else if(guessNumber[x] == actNumber[y]){ // 数字正确
				bTip++;
			}
			
		}
	}
}


int main(){

	int guessTimes = 10;  // 猜测的次数, 不能大于这个次数
	char actNumber[numberLength];  // 生成的数字
	char guessNumber[numberLength];  // 用户猜的数字
	int bTip = 0;  // B类提醒 
	int aTip = 0;  // A类提醒
	printf("系统随机生成一个4位数，你有十次机会来猜测这个数字，\n每次你猜完之后我会给你一个提示--\nA数字正确且位置正确的数字的个数，B数字正确但位置不正确的个数，\n看看你几次能猜中吧\n");
	
	generateActNumber(actNumber);


	for(int i = 0; i < guessTimes; i++){
		
		aTip = 0;
		bTip = 0;
		inputGuessNumber(guessNumber);
		//printf("%s", guessNumber);
		judge(guessNumber, actNumber, aTip, bTip);
		
		if(aTip == numberLength){  // 全部猜中
			printf("恭喜你用%d次才对了!!\n", i+1);
			return 0;
		}else{ // 只猜中部分 
			printf("A%dB%d\n", aTip, bTip);
		}
	} // 限制次数内都没猜中 
	printf("次数用完啦，智商该充值了!\n");
    printf("正确答案是 %c",actNumber);
	return 0; 
}

