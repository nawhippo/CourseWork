package C322.homework4.partd;

public class MotorDriver {
    public static void main(String[] args) {
        AbstractMotorHomeFactory mhfac = null;

        String nextmotorhome = "TypeA";
        if (nextmotorhome.equals("TypeA")) {
            System.out.println("c322.homework.homework4.partd.Type A selected");
        }
        AbstractMotorHomeFactory motorHomeFactory = new TypeAMotorHomeFactory();
        Style style = motorHomeFactory.CreateStyle();
        Frame frame = motorHomeFactory.CreateFrame();
        Engine engine = motorHomeFactory.CreateEngine();
        Kitchen kitchen = motorHomeFactory.CreateKitchen();

        //everything else functions in exactly the same way
        //goes for other types
        System.out.println(style.getStyle());
        System.out.println(frame.getFrame());
        System.out.println(engine.getEngine());
        System.out.println(kitchen.getKitchen());
    }
}
