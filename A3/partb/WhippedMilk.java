package C322.homework3.partb;

public class WhippedMilk extends IngredientDecorator {
    private Beverage beverage;

    WhippedMilk(Beverage beverage) {
        this.beverage = beverage;
    }

    public String getDesc() {
        return beverage.getDesc() + ", Whipped Milk";
    }

    @Override
    public double getCost() {
        return beverage.getCost() + 0.33;
    }
}
