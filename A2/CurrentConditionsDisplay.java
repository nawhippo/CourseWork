package C322.homework.homework2;

public class CurrentConditionsDisplay implements Display {
    public CurrentConditionsDisplay(WeatherData weatherData) {
        //register it automatically with the weatherdata
        weatherData.addDisplay(this);
    }

    @Override
    public void weatherupdate(double pressure, double humidity, double temperature) {
        System.out.println("Current Conditions: " + temperature + "F degrees and " + humidity + "% humidity");
    }
}
