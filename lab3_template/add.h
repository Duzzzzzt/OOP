#pragma once
#include <random>


namespace def {
    template <typename T, typename P>
    P Add(const T& x, const T& y) {

        return (x + y);
    }
}


namespace extended {
    template <typename T, typename P>
    P Add(const T& x, const T& y) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 10);


        if (std::rand() % 2 == 0) {
            return (x + y + dist(gen));
        }
        else {
            return (x + y);
        }


    }
}
