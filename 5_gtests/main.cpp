#include <iostream>
#include "add.h"
#include <ctime>
#include <random>
using namespace def;
using namespace extended;

int main() {
    std::srand(std::time(nullptr));
    int x;
    int y;
    int c = 0;


    std::cout << "first number" << std::endl;
    std::cin >> x;
    std::cout << "sec number" << std::endl;
    std::cin >> y;
    std::cout << "third number" << std::endl;
    std::cin >> c;
    std::cout << "Answer 1 " << def::Add(x, y) << std::endl;
    std::cout << "Answer 2 " << def::Add(x, c) << std::endl;
    std::cout << "Answer 1 + random " << extended::Add(x, y) << std::endl;
    std::cout << "Answer 2 + random " << extended::Add(x, c) << std::endl;
}