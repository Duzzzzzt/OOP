#include <iostream>
#include <vector>

class TempTracker {
	int id, factoryId;
	double temp;

	std::vector < double > last_10_vals(10);
public:
	TempTracker(int, double, std::vector<double>);
	TempTracker() = default;
	TempTracker(int id, int factoryId, double temp, std::vector<double> last_10_vals) :
		id(id), temp(temp), last_10_vals(last_10_vals) {
		std::cout << "initialization constructor" << std::endl;
	}
	TempTracker(const TempTracker& T) {
		std::cout << "copy operator";
		this->id = T.id;
		this->factoryId = T.factoryId;
		this->temp = T.temp;
		this->last_10_vals->T.last_10_vals;
	}
	TempTracker& operator= (const TempTracker& T) {
		std::cout << "assignment op";
		this->id = T.id;
		this->factoryId = T.factoryId;
		this->temp = T.temp;
		this->last_10_vals = T.last_10_vals;
		return *this;
	}
};
TempTracker(int id, int factoryId, double temp, std::vector<double> last_10_vals) :
	id(id), factoryId(factoryId), temp(temp), last_10_vals(last_10_vals) {
	std::cout << "default constructor" << std::endl;
}

int main() {

}