package C322.homework3.partb;

import java.util.Scanner;

public class MyCoffee {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to myCoffee");
        System.out.println("Please enter an order");
        System.out.println("1. Houseblend");
        System.out.println("2. Decaf");
        System.out.println("3. DarkRoast");
        System.out.println("4. Espresso");


        int choice = scanner.nextInt();
        Beverage drink = null;
        if(choice == 1){
            drink = new HouseBlend();
        }else if (choice == 2){
            drink = new Decaf();
        }else if (choice == 3){
            drink = new DarkRoast();
        }else if (choice == 4){
            drink = new Espresso();
        }else{
            System.out.println("Invalid choice");
        }

        System.out.println("Now please enter choice of condiments");
        System.out.println("Enter 0 to Finish Order");
        int choice2 = 1;
        while (choice2 != 0){
            System.out.println("1. Chocolate");
            System.out.println("2. Soy");
            System.out.println("3. Whipped Milk");
            System.out.println("4. Steamed Milk");
            choice2 = scanner.nextInt();
            if(choice2 == 1){
                Beverage newdrink;
                newdrink = new Chocolate(drink);
                drink = newdrink;
            }
            if(choice2 == 2){
                Beverage newdrink;
                newdrink = new Soy(drink);
                drink = newdrink;
            }
            if(choice2 == 3){
                Beverage newdrink;
                newdrink = new WhippedMilk(drink);
                drink = newdrink;
            }
            if(choice2 == 3){
                Beverage newdrink;
                newdrink = new SteamedMilk(drink);
                drink = newdrink;
            }
        }
        System.out.println("You ordered: " + drink.getDesc());
        System.out.println("Total Cost: " + drink.getCost());
    }
}
