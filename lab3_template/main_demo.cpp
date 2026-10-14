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
    double c;


    std::cout << "first number" << std::endl;
    std::cin >> x;
    std::cout << "sec number" << std::endl;
    std::cin >> y;
    std::cout << "third number" << std::endl;
    std::cin >> c;
    std::cout << "Answer" << def::Add<int, int>(x, y) << std::endl;
    std::cout << "Answer" << def::Add<double, double>(x, c);
    std::cout << "Answer + random" << extended::Add<int, int>(x, y) << std::endl;
    std::cout << "Answer + random" << extended::Add<double, double>(x, c);
}