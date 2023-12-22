package C322.homework3.partb;

public class Soy extends IngredientDecorator {
    private Beverage beverage;

    Soy(Beverage beverage) {
        this.beverage = beverage;
    }

    public String getDesc() {
        return beverage.getDesc() + ", Soy Milk";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 0.33;
    }
}
