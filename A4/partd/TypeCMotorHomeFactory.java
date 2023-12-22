package C322.homework4.partd;

public class TypeCMotorHomeFactory extends AbstractMotorHomeFactory{
    @Override
    public Engine CreateEngine() {
        return new TypeCEngine();
    }

    @Override
    public Style CreateStyle() {
        return new TypeCStyle();
    }

    @Override
    public Kitchen CreateKitchen() {
        return new TypeCKitchen();
    }

    @Override
    public Frame CreateFrame() {
        return new TypeCFrame();
    }
}
