#include <iostream>
#include "add.h"
using namespace extended;
using namespace def;


int main() {
    int x = 0, y = 0;
    double c = 0.0;

    std::cout << "first number" << std::endl;
    std::cin >> x;
    std::cout << "sec number" << std::endl;
    std::cin >> y;
    std::cout << "third number" << std::endl;
    std::cin >> c;

    std::cout << "def::Add<int, int>= " << def::Add<int, int>(x, y) << std::endl;
    std::cout << "def::Add<int, double>= " << def::Add<int, double>(x, y) << std::endl;
    std::cout << "def::Add<double, int>= " << def::Add<double, int>(c, c) << std::endl;
    std::cout << "extended::Add<int, int>= " << extended::Add<int, int>(x, y) << std::endl;
    std::cout << "extended::Add<int, double>= " << extended::Add<int, double>(x, y) << std::endl;
    return 0;
}