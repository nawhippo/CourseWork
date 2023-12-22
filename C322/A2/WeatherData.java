package C322.homework.homework2;

import java.util.ArrayList;

public class WeatherData {
    double temperature;
    double humidity;
    double pressure;

    public double getTemperature() {
        return temperature;
    }

    public double getHumidity() {
        return humidity;
    }

    public double getPressure() {
        return pressure;
    }

    private ArrayList<Display> displays = new ArrayList<>();

    public void addDisplay(Display dis){
        this.displays.add(dis);
    }

    public void removeDisplay(Display dis){
        this.displays.remove(dis);
    }

    public void measurementsChanged() {
        for (Display display : this.displays) {
            display.weatherupdate(this.getPressure(),this.getHumidity(),this.getTemperature());
        }
    }
}
