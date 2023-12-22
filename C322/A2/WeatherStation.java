package C322.homework.homework2;

import java.util.Random;

public class WeatherStation {

    WeatherData weatherData;

    WeatherStation(){
        this.weatherData = new WeatherData();
    }

    //weather data should change in each subclass
    //this gets new weather readings and should update every single one.
    public void updateweather() {
        Random rand1 = new Random();
        Random rand2 = new Random();
        Random rand3 = new Random();

        //updates temperatures in the weatherData Object.
        //do it once before
        this.weatherData.temperature = round(rand1.nextDouble(0,100));
        //barometric pressure in inches
        this.weatherData.pressure = round(rand2.nextDouble(27,30));
        this.weatherData.humidity = round(rand3.nextDouble(0,99));
        this.weatherData.measurementsChanged();
    }

    public static void main(String[] args) {
        WeatherStation myweatherstation = new WeatherStation();
        myweatherstation.updateweather();
        ForecastDisplay forecastDisplay = new ForecastDisplay(myweatherstation.weatherData);
        CurrentConditionsDisplay currentConditionsDisplay = new CurrentConditionsDisplay(myweatherstation.weatherData);
        StatisticsDisplay statisticsDisplay = new StatisticsDisplay(myweatherstation.weatherData);
        HeatIndexDisplay heatIndexDisplay = new HeatIndexDisplay(myweatherstation.weatherData);
        for (int i = 0; i < 5; i++) {
            myweatherstation.updateweather();
        }
    }

    //rounds to two decimals
    public static double round(double x){
        x = Math.round(x * 100.0) / 100.0;
        return x;
    }
}