package C322.homework4.partc;

public class MowerDriver {
    public static void main(String[] args) {

// output header

        System.out.println("\n\nMOWER SELECTION HELPER");

// create first mower

        LawnMowerFactory mowerFactory = new ConcreteLawnMowerFactory();

        LawnMower rideIt = mowerFactory.getLawnMowerType("Riding");

        rideIt.mowlawn();

// create second mower

        LawnMower pushIt = mowerFactory.getLawnMowerType("Push");

        pushIt.mowlawn();

    }

}
