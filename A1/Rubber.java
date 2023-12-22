package c322.homework.homework1;

public class Rubber extends Duck {
    public Rubber() {
        this.species = "c322.homework.homework1.Rubber";
    }
    @Override
    void quack(){
        System.out.println("SQUEAK");
    }
    @Override
    void fly(){
        System.out.println("This duck can't fly, but you can throw it");
    }
    @Override
    void display(){
        System.out.println("This duck may not be real...");
    }
}
