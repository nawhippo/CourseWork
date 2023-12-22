package C322.homework3.parta;

public class Main {
    public static void main(String[] args) {
        CalculatorChoice calculator = new CalculatorChoice(new OperationAdd());
        int result = (calculator.performCalculation(3,5));
        System.out.println(result);
    }
}
