package c322.homework.homework1;

public class Decoy extends Duck {
    public Decoy() {
        this.species = "c322.homework.homework1.Decoy";
    }
    @Override
    void fly(){
        System.out.println("It can't fly!");
    }
    @Override
    void quack(){
        System.out.println("Silence");
    }
    @Override
    void display(){
        System.out.println("This looks like a mallard, but for some reason it isn't moving");
    }
}
