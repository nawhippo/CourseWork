package C322.homework3.partb;

public class Chocolate extends IngredientDecorator {
    private Beverage beverage;

    Chocolate(Beverage beverage) {
        this.beverage = beverage;
    }

    public String getDesc() {
        return beverage.getDesc() + ", Chocolate";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 0.75;
    }
}
