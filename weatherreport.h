#pragma once
#include <string>

namespace WeatherSpace {
    class IWeatherSensor {
    public:
            virtual double TemperatureInC() const = 0;
            virtual int Precipitation() const = 0;
            virtual int Humidity() const = 0;
            virtual int WindSpeedKMPH() const = 0;
    };

    std::string Report(const IWeatherSensor& sensor);
}
