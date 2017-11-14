#include <iostream>

int licenseCost(double grossSales) {
    const int NUM_CATEGORIES = 4;
    const double categoryTresholds[NUM_CATEGORIES] = {25.0, 50000.0, 150000.0,
                                                      500000.0};
    const double licenseCost[NUM_CATEGORIES] = {50.0, 200.0, 1000.0, 5000.0};
    int category = 0;
    while (category < NUM_CATEGORIES &&
           categoryTresholds[category] <= grossSales) {
        category++;
    }
    double cost = licenseCost[category - 1];
    std::cout << "Category: " << category << std::endl;
    std::cout << "License Cost: " << cost << std::endl;
}

int main() {
    licenseCost(5000.0);
    std::cout << "\n";
    licenseCost(65000);
    std::cout << "\n";
    licenseCost(250000);
    return 0;
}