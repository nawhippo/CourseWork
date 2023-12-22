package C322.homework3.parta;

public class CalculatorChoice {

    //choice
    private Calculator calculator;

    public CalculatorChoice(Calculator calculator){
        this.calculator = calculator;
    }

    public int performCalculation(int num1, int num2){
        return this.calculator.operation(num1,num2);
    }
}
