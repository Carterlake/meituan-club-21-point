
import java.util.Scanner;

public class MainProject {

    private static void StartScreen(){
        System.out.print("Welcome to this small game!\n");
        System.out.print("You now have three choices:\n");
        System.out.printf("1: Start game at once\n");
        System.out.printf("2:look up the rule of this game\n");
        System.out.println("3:exit right now\n");
        System.out.println("Now please input your choice\n");
    }

    private static void creatPokers(pokers[] aPoker){
        int i = 0, j = 0;
        String[] color = new String[4];
        String[] number = new String[13];
        number[0] = "A";
        color[0] = "Heart";
        color[1] = "Spade";
        color[2] = "Diamond";
        color[3] = "Club";
        for(int k = 0; k < 52;k++){
            aPoker[k] = new pokers();
        }
        for( ; i < 4; i++){
            aPoker[i*13].number = "A";
            aPoker[i*13+1].number = "2";
            aPoker[i*13+2].number = "3";
            aPoker[i*13+3].number = "4";
            aPoker[i*13+4].number = "5";
            aPoker[i*13+5].number = "6";
            aPoker[i*13+6].number = "7";
            aPoker[i*13+7].number = "8";
            aPoker[i*13+8].number = "9";
            aPoker[i*13+9].number = "10";
            aPoker[i*13+10].number = "J";
            aPoker[i*13+11].number = "Q";
            aPoker[i*13+12].number = "K";
            for(j = 0; j < 13; j++){
                aPoker[i*13+j].color = color[i];
                aPoker[i*13+j].exist = true;
            }
        }

    }

    private static void  rules(){
        System.out.print("");
    }

    private static pokers getPoker(pokers[] aPoker ){
        int n = (int)(Math.random()*53);
        while (!aPoker[n].exist)
            n = (int)(Math.random()*53);
        aPoker[n].exist = false;
        return aPoker[n];
    }
    private   static int addDot(pokers aPoker){
        int i = 0;
        switch (aPoker.number){
            case "A": i = 1;break;
            case "2": i = 2;break;
            case "3": i = 3;break;
            case "4": i = 4;break;
            case "5": i = 5;break;
            case "6": i = 6;break;
            case "7": i = 7;break;
            case "8": i = 8;break;
            case "9": i = 9;break;
            case "10": i = 10;break;
            case "J": i = 11;break;
            case "Q": i = 12;break;
            case "k": i =13;break;
            default:i = 0;
        }
        return i;
    }
    public static void BoutStart(Banker banker){
        System.out.printf("Now,sum of Bet is %d\n",banker.Bet);
    }


    public static void BoutPlayerStart(Player player){
        System.out.printf("%s, you now have  ",player.name);
        for (int i = 0;i < player.pokerNum;i++){
            System.out.printf("%s %s  ",player.Pokers[i].color,player.Pokers[i].number);
    }
        System.out.printf("\nand you now have %d dot\n",player.dots);
        System.out.print("Would want to put more money?\nA.No, give up this game\nB.50\n C.100  \n");
    }


    public static void BoutBetChoice(Player player[],int i,Banker banker ){
        Scanner in = new Scanner(System.in);
        String command = in.next();
        switch(command){
            case "A":player[i].exist = false;
            case "B": player[i].deduceMoney(50);banker.raiseBet(50);break;
            case "C":player[i].deduceMoney(100);banker.raiseBet(100);break;
            default:System.out.print("Wrong Command!!\n Please input command again!!\n");
                    BoutBetChoice(player,i,banker);
                    break;
        }

    }

    protected static void BoutPokerChoice(Player player[],int i ,pokers[] aPoker){
        Scanner in = new Scanner(System.in);
        System.out.print("would you like to take next poker?please input Y or N");
        String command = in.next();
        switch (command){
            case "Y":
            case "y": player[i].Pokers[player[i].pokerNum] = getPoker(aPoker);
            player[i].raiseDot(addDot(player[i].Pokers[player[i].pokerNum] ));
            player[i].pokerNum++;
            break;
            case "N":
            case "n":break;
                default:System.out.print("Wrong Command!!\n Please input command again!!\n");
                    BoutPokerChoice(player,i,aPoker);
                    break;
        }

    }



    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int command ;
        StartScreen();
        command = in.nextInt();
        while(command>3||command<1)
            System.out.print("Wrong Command!!\n Please input command again!!\n");
        if (command == 3){
            return ;
        }
        if (command == 2){
            rules();
        }
        if (command==1){
            pokers[]  aPokers = new pokers[52];
            System.out.print("OK\n ");
            creatPokers(aPokers);
            System.out.print("Please input the number of players:");
            int playerNum = in.nextInt();
            Player player[] = new Player[playerNum];
            System.out.print("Please input players' name");
            for (int i = 0; i < playerNum;i++){
                player[i] = new Player();
                player[i].name = in.next();
            }

            Banker banker = new Banker();//生成庄家
            banker.Bet = 0;//庄家掌握总赌注，初始值为零

            for(int i = 0; i < playerNum;i++){//生成玩家，初始资本为1000，总点数为零，0张牌，存在为真
                player[i].money = 1000;
                player[i].dots = 0;
                player[i].pokerNum = 0;
                player[i].exist = true;
            }

            int existPlayerNum = playerNum;
            for (int i = 0; i < playerNum;i++) {//第一轮游戏
                player[i].Pokers[0] = getPoker(aPokers);
                player[i].raiseDot(addDot(player[i].Pokers[0]));
                player[i].pokerNum++;
            }
            while(existPlayerNum > 1){
                existPlayerNum = playerNum;
                BoutStart(banker);
                for (int i = 0;i < playerNum;i++){
                    if (player[i].dots>21){
                        System.out.print("You lose!");
                        player[i].exist = false;
                    }
                    if (player[i].exist == false){
                        existPlayerNum--;
                        continue;
                    }
                    BoutPlayerStart(player[i]);
                    BoutBetChoice(player,i,banker);
                    BoutPokerChoice(player,i,aPokers);
                    System.out.print("\n\n");
                }
            }

        }
    }
}
