/*
 *   Exercise 5-1
 *
 *   Let's try implementing a class using the basic framework. Consider a class
 * to store the data for an automobile. We'll have three pieces of data: a
 * manufacturer name and model name, both strings, and a model year, an
 * integer. Create a class with get/set methods for each data member. Make
 * sure you make good decisions concerning details like member names. It's not
 * important that you follow my particular naming conventions. What's
 * important is that you think about the choices you make and are consistent
 * in your decisions
 *
 *   Exercise 5-2
 *
 *   For our automobile class from the previous exercise, add a support method
 * that returns a complete description of the automobile object as a formatted
 * string, such as, "1957 Chevrolet Impala". Add a second support method that
 * returns the age of the automobile in years.
 */
#include "Automobile.h"
#include <iostream>

void AutomobileTester() {
    Automobile a("Audi", "A5", 2015);
    std::cout << a.getManufacturer() << std::endl;
    std::cout << a.getModelName() << std::endl;
    std::cout << a.getModelYear() << std::endl;

    std::cout << "Setting model name to A8" << std::endl;
    a.setModelName("A8");
    std::cout << a.getModelName() << std::endl;
    a.setModelYear(2016);
    std::cout << "Model year: " << a.getModelYear() << std::endl;
    a.setManufacturer("Mercedes Benz");
    std::cout << "Manufacturer " << a.getManufacturer() << std::endl;

    std::cout << "Age: " << a.getAge() << std::endl;
    a.displayDescription();
    // std::cout << "Description: " << a.displayDescription() << std::endl;
}

int main() {
    AutomobileTester();
    return 0;
}