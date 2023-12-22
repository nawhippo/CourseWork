package C322.homework4.partd;

public class TypeAMotorHomeFactory extends AbstractMotorHomeFactory{
    @Override
    public Engine CreateEngine() {
        return new TypeAEngine();
    }

    @Override
    public Style CreateStyle() {
        return new TypeAStyle();
    }

    @Override
    public Kitchen CreateKitchen() {
        return new TypeAKitchen();
    }

    @Override
    public Frame CreateFrame() {
        return new TypeAFrame();
    }
}
