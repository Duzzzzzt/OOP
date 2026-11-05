#include <iostream>
#include "temp_tracker.h"

int main() {
    TempTracker a;                                         // default constructor
    TempTracker b(42, 25.5, {1, 2, 3});                    // initialization constructor
    TempTracker d(b);                                      // copy constructor
    TempTracker e;                                         // default constructor
    e = b;                                                 // assignment operator
    TempTracker bad(0, 5000.0, {});                        // initialization + normalize
    e = e;                                                 // assignment operator + self-check
    std::cout << "Name of the class: " << a.class_name << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "temp = " << bad.getTemp() << ", factoryId = " << bad.getFactoryId() << std::endl;
    std::cout << "===================================" << std::endl;
    std::cout << "values = " << bad.getLast10Vals()[0] << std::endl;
    std::cout << "===================================" << std::endl;
    return 0; 
}