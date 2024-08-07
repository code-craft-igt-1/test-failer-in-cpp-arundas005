#include <assert.h>
#include <string>
#include <iostream>
#include "weatherreport.h"

using std::cout, std::endl, std::string;

namespace WeatherSpace {


        int SensorStub::Humidity() const {
            return 72;
        }

        int SensorStub::Precipitation() const {
            return 70;
        }

        double SensorStub::TemperatureInC() const {
            return 26;
        }

        int SensorStub::WindSpeedKMPH() const {
            return 52;
        }

    // This is a function to predict the weather, based on readings
    // from a sensor

    string Report(const IWeatherSensor& sensor) {
        int precipitation = sensor.Precipitation();
        // precipitation < 20 is a sunny day
        string report = "Sunny day";

        if (sensor.TemperatureInC() > 25) {
            if (precipitation >= 20 && precipitation < 60)
                report = "Partly cloudy";
            else if (sensor.WindSpeedKMPH() > 50)
                report = "Alert, Stormy with heavy rain";
        }
        return report;
    }

}  // namespace WeatherSpace
