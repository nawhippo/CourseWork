package C322.homework3.partb;

public class SteamedMilk extends IngredientDecorator {
    private Beverage beverage;

    SteamedMilk(Beverage beverage) {
        this.beverage = beverage;
    }

    public String getDesc() {
        return beverage.getDesc() + ", Steamed Milk";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 0.33;
    }
}
