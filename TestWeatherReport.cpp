#include "TestWeatherReport.h"
#include <assert.h>
#include <string>
#include <iostream>

using std::string , std::cout, std::endl;

namespace WeatherSpace {

    int SensorStub::Humidity() const {
        return 72;
    }

    int SensorStub::Precipitation() const  {
        return 70;
    }

    double SensorStub::TemperatureInC() const  {
        return 26;
    }

    int SensorStub::WindSpeedKMPH() const  {
        return 52;
    }

    int SensorStubHighPrecipitationLowWindSpeed::Humidity() const {
        return 72;
    }

    int SensorStubHighPrecipitationLowWindSpeed::Precipitation() const  {
        return 70;
    }

    double SensorStubHighPrecipitationLowWindSpeed::TemperatureInC() const  {
        return 26;
    }

    int SensorStubHighPrecipitationLowWindSpeed::WindSpeedKMPH() const  {
        return 40;
    }

    // Test a rainy day

void TestRainy() {
    SensorStub sensor;
    string report = Report(sensor);
    cout << report << endl;
    assert(report.find("rain") != string::npos);
}

// Test another rainy day

void TestHighPrecipitationAndLowWindspeed() {
    // This instance of stub needs to be different-
    // to give high precipitation (>60) and low wind-speed (<50)
    SensorStubHighPrecipitationLowWindSpeed sensor;

    // strengthen the assert to expose the bug
    // (function returns Sunny day, it should predict rain)
    string report = Report(sensor);
    assert(report.find("rain") != string::npos);
}
}
