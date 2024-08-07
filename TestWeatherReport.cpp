#include "TestWeatherReport.h"
#include <gtest\gtest.h>


using namespace WeatherSpace;
using namespace testing;

TEST(TestWeatherReport, TestRainy)
{
    SensorStub sensor;
    std::string weatherReport = Report(sensor);
    bool actual = weatherReport.find("rain") != std::string::npos;
    bool expected = true;
    EXPECT_EQ(actual, expected);
}


TEST(TestWeatherReport, TestHighPrecipitationAndLowWindspeed)
{
    MockSensor mockSensor;
    ON_CALL(mockSensor, Humidity()).WillByDefault(Return(72));
    ON_CALL(mockSensor, Precipitation()).WillByDefault(Return(65));
    ON_CALL(mockSensor, WindSpeedKMPH()).WillByDefault(Return(20));
    ON_CALL(mockSensor, TemperatureInC()).WillByDefault(Return(30));
    std::string weatherReport = Report(mockSensor);
    bool actual = weatherReport.find("rain") != std::string::npos;
    bool expected = true;
    EXPECT_EQ(actual, expected);
}

