package C322.homework.homework2;

public class ForecastDisplay implements Display {
    boolean rainy = false;
    boolean hot = false;
    boolean cold = false;
    boolean same = false;

    boolean firstforecast = true;

    double prevpressure = 0;
    double prevhumidity = 0;
    double prevtemp = 0;
    public ForecastDisplay(WeatherData weatherData) {
        //register it automatically with the weatherdata
        weatherData.addDisplay(this);
    }



    @Override
    public void weatherupdate(double pressure, double humidity, double temperature) {
        //in case of similar weather, check previous measurements;
        if((pressure > (prevpressure - 8) && (pressure < (prevpressure + 8))) &&
                (humidity > (prevhumidity - 8) && (humidity < (prevhumidity + 8))) &&
            (pressure > (prevtemp - 8) && (pressure < (prevtemp + 8)))
        ){
            same = true;
        }

        if((humidity > 90) && (pressure < 28)){
            rainy = true;
        }
        if(temperature > 75){
            hot = true;
        }
        if(temperature < 50){
            cold = true;
        }
        //skip the first forecast so it is formatted like the assignment's example
        if (firstforecast){}
            else if(same){
                System.out.println("More of the same coming up");
            }
            else if (hot && rainy) {
                System.out.println("Muggy weather ahead");
            } else if (rainy && cold) {
                System.out.println("Freezing rain on the way!");
            } else if (hot) {
                System.out.println("Hot weather incoming!");
            } else if (cold) {
                System.out.println("Cold weather ahead!");
            } else if (rainy) {
                System.out.println("Watch out for cooler rainy weather!\n");
            } else {
                System.out.println("Mild weather on the way!");
            }
            //switch these off again.
            prevtemp = temperature;
            prevhumidity = humidity;
            prevpressure = pressure;
            rainy = false;
            hot = false;
            cold = false;
            firstforecast = false;
        }
    }

