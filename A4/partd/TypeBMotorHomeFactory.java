package C322.homework4.partd;

public class TypeBMotorHomeFactory extends AbstractMotorHomeFactory{
    @Override
    public Engine CreateEngine() {
        return new TypeBEngine();
    }

    @Override
    public Style CreateStyle() {
        return new TypeBStyle();
    }

    @Override
    public Kitchen CreateKitchen() {
        return new TypeBKitchen();
    }

    @Override
    public Frame CreateFrame() {
        return new TypeBFrame();
    }
}
