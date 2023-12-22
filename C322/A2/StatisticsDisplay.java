package C322.homework.homework2;

public class StatisticsDisplay implements Display {
    double avg;
    double min;
    double max;

    double size;
    double total;

    public StatisticsDisplay(WeatherData weatherData) {
        //register it automatically with the weatherdata
        weatherData.addDisplay(this);
        this.avg = 0;
        this.min = 500;
        this.max = 0;
        this.size = 0;
        this.total = 0;
    }


    @Override
    public void weatherupdate(double pressure, double humidity, double temperature) {
        //total for average calculations.
        total+=temperature;
        size++;
        //use the public round function created in the weatherstation class
        avg = WeatherStation.round(total/size);
        if (temperature > max){
            this.max = temperature;
        }

        if (temperature < min){
            this.min = temperature;
        }
        //stats should be updated before displaying
        //now call all inherent values
        System.out.println("Avg/Max/Min temperature = " + this.avg + "/" + this.max + "/" + this.min);

    }
}
