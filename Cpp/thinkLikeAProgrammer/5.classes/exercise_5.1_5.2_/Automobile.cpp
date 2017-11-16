#include "Automobile.h"
#include <ctime>
#include <iostream>

// constructor
Automobile::Automobile(std::string manufacturer, std::string modelName,
                       int modelYear) {
    _manufacturer = manufacturer;
    _modelName = modelName;
    _modelYear = modelYear;
}

// set/get manufacturer
std::string Automobile::getManufacturer() { return _manufacturer; }

void Automobile::setManufacturer(std::string newManufacturer) {
    _manufacturer = newManufacturer;
}

// set/get model name
std::string Automobile::getModelName() { return _modelName; }

void Automobile::setModelName(std::string newModelName) {
    _modelName = newModelName;
}

// set/get model year
int Automobile::getModelYear() { return _modelYear; }

void Automobile::setModelYear(int newModelYear) { _modelYear = newModelYear; }

// display automobile description
void Automobile::displayDescription() {
    std::cout << _modelYear << " " << _manufacturer << " " << _modelName
              << std::endl;
}

// calculate automobile age in years
int Automobile::getAge() {
    time_t t = time(0);
    struct tm *now = localtime(&t);
    int age = (now->tm_year + 1900) - _modelYear;
    return age;
}