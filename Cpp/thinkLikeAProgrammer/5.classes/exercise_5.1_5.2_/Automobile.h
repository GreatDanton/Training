#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H

#include <string>

class Automobile {
  public:
    Automobile(std::string manufacturer, std::string modelName, int modelYear);
    std::string getManufacturer();
    void setManufacturer(std::string newManufacturer);
    std::string getModelName();
    void setModelName(std::string newModelName);
    int getModelYear();
    void setModelYear(int newModelYear);

    void displayDescription();
    int getAge();

  private:
    std::string _manufacturer;
    std::string _modelName;
    int _modelYear;
};

#endif