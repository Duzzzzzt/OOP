#include <iostream>
#include "temp_tracker.h"

int main() {
    TempTracker a;                                         // default constructor
    TempTracker b(42, 25.5, {1, 2, 3});                    // initialization constructor
    TempTracker d(b);                                      // copy constructor
    TempTracker e;                                         // default constructor
    e = b;                                                 // assignment operator
    std::cout << b;
    std::cout << "Name of the class: " << a.class_name << std::endl;
    std::cout << "===================================" << std::endl;
    return 0; 
}