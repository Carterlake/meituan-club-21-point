#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<conio.h>
using namespace std;
struct card{ 
	    int extence; 
	    char num ;
	    char color[4];
};
struct player{int ex;
			  int dom;
			  char name[3]; 
	         };


void creatcard(card  ca[4][13]){	
	for(int i=0;i<13;i++){
		strcpy(ca[3][i].color,"����");//���ɱ�����ɫ 
		strcpy(ca[2][i].color,"����");		
		strcpy(ca[1][i].color,"÷��");
		strcpy(ca[0][i].color,"����");
	                     }
	 				
	for(int t = 0;t<4;t++)										         {
		ca[t][0].num='A';
		                          for(int b =1;b<10;b++)    { 
			                         ca[t][b].num=b+49 ;//���ɱ������� 
							                                }
        ca[t][9 ].num='x';
	    ca[t][10].num='J';
	    ca[t][11].num='Q';
	    ca[t][12].num='K';
		                                       }
				
                                }
                                
                                

void getcard(int &u,int &j){
	    srand(time(NULL));
	    u=rand()%4 ;
	    j=rand()%13 ; 
}


void count(char &a,int &b)           {
	if(a=='A') {b=b+11;
	}
	else{
	if(a>57){b = b+10;}  		
	else{b =(int)a - 48 + b; } } 
    
                                     }


void choose1(char g)                               {
	switch(g){
	
	case 'c':  exit(0);
	case 'b': printf("ӵ����ߵ�������һ�ʤ�������������ڻ����21�㣻\n����21�����ҳ�Ϊ���ơ�2�㵽10�����������ĵ�������\n") ;
              printf("J.Q,Kÿ��Ϊ10�㣬A��Ϊ11�㣬\n�����������ʼ��Ϸ");

	          system("pause") ;break;
	case 'a':printf("��Ϸ���Ͽ�ʼ\n") ; 
	          break;        
	default :exit(0)   ;  }                        }
	
void choose2(char &q,int &o)	{
	
printf("������Ҫ��һ������ y or n \n") ;
    getchar();
	scanf("%c", &q);
	if(q=='y')  o = 1; 
	if(q=='n')  o = 0; 
      
                                }
 int main(){
					printf("��ӭ����hustMT21��");
					system("pause");
					printf("����������Ҫ���еĲ���\n");
					printf("a.������Ϸ\nb.��Ϸ����\nc.�˳���Ϸ");
					char a ;
					scanf("%c",&a);
					choose1(a);
					player player1,player2;
	
	printf("���1��������������ǣ�������������ĸ���������Լ�");
	scanf("%s",player1.name);

	printf("���2��������������ǣ�������������ĸ���������Լ�");
	scanf("%s",player2.name);

	       card ca[4][13];
	       creatcard(ca);
	       player1.dom = 0;
	       player2.dom = 0;
	 
			int k1,k2,l1,l2;
			getcard(k1,l1);
			count(ca[k1][l1].num,player1.dom);
			printf("%s�õ���%s%c\n",player1.name,ca[k1][l1].color,ca[k1][l1].num);
			printf("ĿǰTA��%d��\n",player1.dom);
			
       k2=rand()%4 ;
	   l2=rand()%13 ; 

	count(ca[k2][l2].num,player2.dom);
	printf("%s�õ���%s%c\n",player2.name,ca[k2][l2].color,ca[k2][l2].num);
    printf("ĿǰTA��%d��\n",player2.dom);
    char q1='1',q2='1';
    
    
    for(int h=0;h<22;h++)  {
		       
              	printf("%s����������һ��",player1.name);
				choose2(q1,player1.ex) ;
				if (player1.ex == 1)                                                       {
				getcard(k1,l1);
				count(ca[k1][l1].num,player1.dom);
				printf("%s�õ���%s%c\n",player1.name,ca[k1][l1].color,ca[k1][l1].num);
				printf("ĿǰTA��%d��\n",player1.dom);
			                                                                               }
				if(player1.dom>21){
				printf("�㱬���ˣ�����\n%s���ʤ��",player2.name);
				system("pause") ;
				exit(0);}
				
				
	            if(player1.ex + player2.ex == 0 ){printf("��Ϸ����\n");
	            	           if(player1.dom>player2.dom){printf("%s�����ʤ��",player1.name);};
					           if(player1.dom<player2.dom){printf("%s�����ʤ��",player2.name);};
					           if(player1.dom==player2.dom){printf("�;�");};
					           system("pause") ;		     exit(0);              };
								                                               
		
				printf("%s����������һ��",player2.name);
				choose2(q2,player2.ex) ;
				if (player2.ex == 1){
				 getcard(k2,l2);
				count(ca[k2][l2].num,player2.dom);
				printf("%s�õ���%s%c\n",player2.name,ca[k2][l2].color,ca[k2][l2].num);
				printf("ĿǰTA��%d��\n",player2.dom);
				} 
				if(player2.dom>21){printf("�㱬���ˣ�����\n%s���ʤ��",player1.name);system("pause") ;
				                                                             exit(0);};
				
				
	            if(player1.ex + player2.ex == 0 ){printf("��Ϸ����\n");
	            	           if(player1.dom>player2.dom){printf("%s�����ʤ��",player1.name);};
					           if(player1.dom<player2.dom){printf("%s�����ʤ��",player2.name);};
					           if(player1.dom==player2.dom){printf("�;�");};
					system("pause") ;		     exit(0);              };}
								                                               
	
    
	return 0;}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
