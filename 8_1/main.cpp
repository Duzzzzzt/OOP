#include <iostream>
#include "temp_tracker.h"

int main() {
    TempTracker<double> a;                                         // default constructor
    TempTracker<double> b(42, 25.5, {1, 2, 3});                    // initialization constructor
    TempTracker<double> d(b);                                      // copy constructor
    TempTracker<double> e;                                         // default constructor
    e = b;                                                 // assignment operator
    std::cout << b;
    std::cout << "Name of the class: " << a.class_name << std::endl;
    std::cout << "===================================" << std::endl;
    return 0; 
}