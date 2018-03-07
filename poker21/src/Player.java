public class Player {
    public String name;
    public int dots;
    public int money;
    public pokers[] Pokers = new pokers[10];
    public int pokerNum;
    public boolean exist;

    public String showName() {return name; }
    public int showDots(){return  dots;}
    public int showMoney(){return money;}

    public void raiseMoney(int addition){
        money += addition;
    }

    public void deduceMoney(int deduce){
        money += deduce;
    }

    public void raiseDot(int addition){
        dots += addition;
    }

}
