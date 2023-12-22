package c322.homework.homework1;

public class Duck {
    public static void main(String[] args) {
        Alabio alabio = new Alabio();
        alabio.fly();
        alabio.quack();
        alabio.swim();
        alabio.display();
    }

    public String species;
    void swim(){
        System.out.println(this.species + " is swimming!");
    }

    void fly(){
        System.out.println(this.species + " is flying!");
    }
    void quack(){
        System.out.println("QUACK");
    }

    void display(){
        System.out.println("It's a duck");
    }
}

