package c322.homework.homework1;

public class Domestic extends Duck {
    public Domestic() {
        this.species = "Dosmetic";
    }
    @Override
    void display(){
        System.out.println("This duck is white, with an orange bill.");
    }
}
