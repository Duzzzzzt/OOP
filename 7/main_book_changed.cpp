#include "temp_tracker.h"



int main() {
    std::cout << "static values: " << std::endl;
    TempTracker::print_count();
    std::cout << TempTracker::class_name << std::endl;
    std::cout << std::endl << "=================" << std::endl;


    std::cout << "Tracker creation: " << std::endl;
    TempTracker first_tracker(123, 36.6, {12.3, 45.5, 38.9});
    first_tracker.print_tracker();
    first_tracker.print_count();     
//    std::cout << my_first_book << std::endl;

    std::cout << std::endl << "=================" << std::endl << std::endl;

    std::cout << "Second tracker: " << std::endl;
    TempTracker second_tracker{ first_tracker };
//    std::cout << my_second_book << std::endl;
    second_tracker.setTemp(34.5);
    first_tracker.setTemp(36.4);
    second_tracker.print_tracker();

    std::cout << std::endl << "=================" << std::endl << std::endl;

    {
        TempTracker second_tracker{ first_tracker };
        //    std::cout << my_second_book << std::endl;
        second_tracker.setTemp(54.5);
        first_tracker.setTemp(66.4);
        second_tracker.print_tracker();
    }

    std::cout << std::endl << "=================" << std::endl << std::endl;

    std::cout << " outside {} " << std::endl;
    second_tracker.print_tracker();


    return 0;
}
