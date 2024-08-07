#pragma once
#include <gmock\gmock.h>
#include "weatherreport.h"

namespace WeatherSpace
{
    class MockSensor : public IWeatherSensor
    {
        public:
            MOCK_METHOD(int, Humidity, (), (const override));
            MOCK_METHOD(int, Precipitation, (), (const override));
            MOCK_METHOD(int, WindSpeedKMPH, (), (const override));
            MOCK_METHOD(double, TemperatureInC, (), (const override));
    };
}

