#include <iostream>
#include "temp_tracker.h"

int main() {
    TempTracker a;                                       
    TempTracker b(7, 42, 25.5, {1, 2, 3});                
    TempTracker d(b);
    std::cout << "b temp = " << b.getTemp() << ", b id = " << b.getId() << std::endl;
    TempTracker e;                                        
    e = b;                                                 
    TempTracker f = b;                                    
    TempTracker bad(1, 0, 5000.0, {});                   
    e = e;                                                 
    std::cout << "temp = " << bad.getTemp() << ", factoryId = " << bad.getFactoryId() << std::endl;
    std::cout << "values = " << bad.getLast10Vals()[0] << std::endl;
    return 0; 
}