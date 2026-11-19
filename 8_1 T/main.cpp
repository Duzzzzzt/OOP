#include <iostream>
#include "temp_tracker.h"

int main() {
    TempTracker a;                                         // default constructor
    TempTracker b(42, 25.5, {1, 2, 3});                   // initialization constructor
    TempTracker d(b);                                      // copy constructor
    while (true) {
        int factoryId;
        double temp;
        std::cout << "Enter factoryId and temp: ";
        std::cin >> factoryId >> temp;
        try {
            TempTracker t(factoryId, temp, {});   // конструктор вызывает normalize
            std::cout << "Object created ok." << std::endl;
            break;                                  // данные прин€ты, выходим из цикла
        }
        catch (const std::string& e) {
            std::cout << "Error: " << e << " Ч enter data again" << std::endl;
        }
    }
    TempTracker e;                                         // default constructor
    e = b;                                                 // assignment operator
    std::cout << b;
    std::cout << "Name of the class: " << a.class_name << std::endl;
    std::cout << "===================================" << std::endl;
    return 0; 
}