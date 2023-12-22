package C322.homework.homework2;
    public class HeatIndexDisplay implements Display {
        public HeatIndexDisplay(WeatherData weatherData) {
            weatherData.addDisplay(this);
        }

        private float computeHeatIndex(float temperature, float humidity) {
            float index = (float)((16.923 + (0.185212 * temperature) + (5.37941 * humidity) - (0.100254 * temperature * humidity) +
                    (0.00941695 * (temperature * temperature)) + (0.00728898 * (humidity * humidity)) +
                    (0.000345372 * (temperature * temperature * humidity)) - (0.000814971 * (temperature * humidity * humidity)) +
                    (0.0000102102 * (temperature * temperature * humidity * humidity)) - (0.000038646 * (temperature * temperature * temperature)) + (0.0000291583 *
                    (humidity * humidity * humidity)) + (0.00000142721 * (temperature * temperature * temperature * humidity)) +
                    (0.000000197483 * (temperature * humidity * humidity * humidity)) - (0.0000000218429 * (temperature * temperature * temperature * humidity * humidity)) +
                    0.000000000843296 * (temperature * temperature * humidity * humidity * humidity)) -
                    (0.0000000000481975 * (temperature * temperature * temperature * humidity * humidity * humidity)));
            return index;
        }

        @Override
        public void weatherupdate(double pressure, double humidity, double temperature) {
            System.out.println("Head index is "+computeHeatIndex((float)temperature,(float)humidity));
        }
    }
