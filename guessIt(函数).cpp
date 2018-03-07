#include<stdio.h>
#include<cstdlib>
#include<ctime>

#define numberLength 4  // ���ֳ���, �����Ӳ�4λ��


void generateActNumber(char actNumber[]){  // �������� 
	srand(time(NULL));  // �����������
	
	for(int i = 0; i < numberLength; i++){  // ����õ�һ��4λ����
		actNumber[i] = rand() % 10 + 48;
	}
}


void inputGuessNumber(char guessNumber[]){  // �������� 
		for(int j = 0; j < numberLength; j++){  // ����²������
			scanf("%c",&guessNumber[j]);
		}
		getchar();
}

void judge(char guessNumber[], char actNumber[], int &aTip, int &bTip){  // �ж���ȷ�� 
	for(int x = 0; x < numberLength; x++){
		for(int y = 0; y < numberLength; y++){
			if (x == y && guessNumber[x] == actNumber[y]){  // ������ȷ��λ����ȷ
				aTip++;
			}else if(guessNumber[x] == actNumber[y]){ // ������ȷ
				bTip++;
			}
			
		}
	}
}


int main(){

	int guessTimes = 10;  // �²�Ĵ���, ���ܴ����������
	char actNumber[numberLength];  // ���ɵ�����
	char guessNumber[numberLength];  // �û��µ�����
	int bTip = 0;  // B������ 
	int aTip = 0;  // A������
	printf("ϵͳ�������һ��4λ��������ʮ�λ������²�������֣�\nÿ�������֮���һ����һ����ʾ--\nA������ȷ��λ����ȷ�����ֵĸ�����B������ȷ��λ�ò���ȷ�ĸ�����\n�����㼸���ܲ��а�\n");
	
	generateActNumber(actNumber);


	for(int i = 0; i < guessTimes; i++){
		
		aTip = 0;
		bTip = 0;
		inputGuessNumber(guessNumber);
		//printf("%s", guessNumber);
		judge(guessNumber, actNumber, aTip, bTip);
		
		if(aTip == numberLength){  // ȫ������
			printf("��ϲ����%d�βŶ���!!\n", i+1);
			return 0;
		}else{ // ֻ���в��� 
			printf("A%dB%d\n", aTip, bTip);
		}
	} // ���ƴ����ڶ�û���� 
	printf("���������������̸ó�ֵ��!\n");
    printf("��ȷ���� %c",actNumber);
	return 0; 
}

