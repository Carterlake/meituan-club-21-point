#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main ()
{  	struct card   {int extence; 
                char num ;
                char color[10];
				}   ca[4][13];
				for(int i=0;i<13;i++){
	strcpy (ca[3][i].color ,"����");//���ɱ�����ɫ 
	strcpy(ca[2][i].color,"����");		
	strcpy(	ca[1][i].color,"÷��");
	strcpy(	ca[0][i].color,"����");}
	 				
	 	for(int t = 0;t<4;t++){
	 ca[t][0].num='A';
				for(int b =1;b<10;b++){
	ca[t][b].num=b+49 ;//���ɱ������� 
									 }
		ca[t][9].num='x';
		 ca[t][10].num='J'  ;
	   ca[t][11].num='Q' ;
	 ca[t][12].num='K'  ;
	    for(int s=0;s<13;s++){//�����Ա����ĸ�ֵ 
		ca[t][s].extence=1;
		}
		for(int k=0;k<13;k++){//������� 
			//printf("ca[t][k].num=%c\n",ca[t][k].num);
			printf("ca[%d][%d]:\n",t+1,k+1);
			printf("%s,%c\n",ca[t][k].color,ca[t][k].num);
		  
		} 
				printf("-----------\n");			 }
							 
							 
		return 0;
	 } 
