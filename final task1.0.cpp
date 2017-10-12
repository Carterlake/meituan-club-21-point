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
		strcpy(ca[3][i].color,"黑桃");//生成变量花色 
		strcpy(ca[2][i].color,"方块");		
		strcpy(ca[1][i].color,"梅花");
		strcpy(ca[0][i].color,"红桃");
	                     }
	 				
	for(int t = 0;t<4;t++)										         {
		ca[t][0].num='A';
		                          for(int b =1;b<10;b++)    { 
			                         ca[t][b].num=b+49 ;//生成变量数字 
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
	case 'b': printf("拥有最高点数的玩家获胜，其点数必须等于或低于21点；\n超过21点的玩家称为爆牌。2点到10点的牌以牌面的点数计算\n") ;
              printf("J.Q,K每张为10点，A记为11点，\n输入任意键开始游戏");

	          system("pause") ;break;
	case 'a':printf("游戏马上开始\n") ; 
	          break;        
	default :exit(0)   ;  }                        }
	
void choose2(char &q,int &o)	{
	
printf("您还想要下一张牌吗 y or n \n") ;
    getchar();
	scanf("%c", &q);
	if(q=='y')  o = 1; 
	if(q=='n')  o = 0; 
      
                                }
 int main(){
					printf("欢迎来到hustMT21点");
					system("pause");
					printf("请输入你想要进行的操作\n");
					printf("a.进入游戏\nb.游戏帮助\nc.退出游戏");
					char a ;
					scanf("%c",&a);
					choose1(a);
					player player1,player2;
	
	printf("玩家1，请问你的名字是？请输入三个字母来代表你自己");
	scanf("%s",player1.name);

	printf("玩家2，请问你的名字是？请输入三个字母来代表你自己");
	scanf("%s",player2.name);

	       card ca[4][13];
	       creatcard(ca);
	       player1.dom = 0;
	       player2.dom = 0;
	 
			int k1,k2,l1,l2;
			getcard(k1,l1);
			count(ca[k1][l1].num,player1.dom);
			printf("%s得到了%s%c\n",player1.name,ca[k1][l1].color,ca[k1][l1].num);
			printf("目前TA有%d点\n",player1.dom);
			
       k2=rand()%4 ;
	   l2=rand()%13 ; 

	count(ca[k2][l2].num,player2.dom);
	printf("%s得到了%s%c\n",player2.name,ca[k2][l2].color,ca[k2][l2].num);
    printf("目前TA有%d点\n",player2.dom);
    char q1='1',q2='1';
    
    
    for(int h=0;h<22;h++)  {
		       
              	printf("%s请您进行下一步",player1.name);
				choose2(q1,player1.ex) ;
				if (player1.ex == 1)                                                       {
				getcard(k1,l1);
				count(ca[k1][l1].num,player1.dom);
				printf("%s得到了%s%c\n",player1.name,ca[k1][l1].color,ca[k1][l1].num);
				printf("目前TA有%d点\n",player1.dom);
			                                                                               }
				if(player1.dom>21){
				printf("你爆点了！！！\n%s获得胜利",player2.name);
				system("pause") ;
				exit(0);}
				
				
	            if(player1.ex + player2.ex == 0 ){printf("游戏结束\n");
	            	           if(player1.dom>player2.dom){printf("%s获得了胜利",player1.name);};
					           if(player1.dom<player2.dom){printf("%s获得了胜利",player2.name);};
					           if(player1.dom==player2.dom){printf("和局");};
					           system("pause") ;		     exit(0);              };
								                                               
		
				printf("%s请您进行下一步",player2.name);
				choose2(q2,player2.ex) ;
				if (player2.ex == 1){
				 getcard(k2,l2);
				count(ca[k2][l2].num,player2.dom);
				printf("%s得到了%s%c\n",player2.name,ca[k2][l2].color,ca[k2][l2].num);
				printf("目前TA有%d点\n",player2.dom);
				} 
				if(player2.dom>21){printf("你爆点了！！！\n%s获得胜利",player1.name);system("pause") ;
				                                                             exit(0);};
				
				
	            if(player1.ex + player2.ex == 0 ){printf("游戏结束\n");
	            	           if(player1.dom>player2.dom){printf("%s获得了胜利",player1.name);};
					           if(player1.dom<player2.dom){printf("%s获得了胜利",player2.name);};
					           if(player1.dom==player2.dom){printf("和局");};
					system("pause") ;		     exit(0);              };}
								                                               
	
    
	return 0;}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
