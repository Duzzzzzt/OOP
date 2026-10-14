#include "add.h"
#include <random>

namespace def {
    int Add(int x, int y) {
        return x + y;
    }
}

namespace extended {
    int Add(int x, int y) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dist(1, 10);
        if (dist(gen) % 2 == 0) {
            return x + y + dist(gen);
        }
        return x + y;
    }
}