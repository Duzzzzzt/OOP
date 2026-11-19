#include "temp_tracker.h"
#include <vector>
#include <list>
#include <set>
#include <iostream>

int main() {
	
	std::cout << "vector of objects: " << std::endl;
	std::cout << std::endl;

	{
		std::vector<TempTracker<double>> v;
		for (int i = 0; i < 5; i++) {
			v.push_back(TempTracker<double>(12 * (i + 1), 23.6 * i, std::vector<double>{12.4, 43.5, 45.3}));
		}
		TempTracker<double>::print_count();
	}

	std::cout << std::endl;
	std::cout << "list of objects: " << std::endl;
	std::cout << std::endl;

	{
		std::list<TempTracker<double>> l;
		for (int i = 0; i < 5; i++) {
			l.push_back(TempTracker<double>(21 * (i + 1), 34.1 * i, std::vector<double>{34.2, 12.2, 67.5}));

		}
		TempTracker<double>::print_count();
	}

	std::cout << std::endl;
	std::cout << "set of objects: " << std::endl;
	std::cout << std::endl;

	{
		std::set<TempTracker<double>> s;
		for (int i = 0; i < 5; i++) {
			s.insert(TempTracker<double>(34 * (i + 1), 56.3 * i, std::vector<double>{234.34, 43.4, 76.3}));
		}
		TempTracker<double>::print_count();
	}
	return 0;
}