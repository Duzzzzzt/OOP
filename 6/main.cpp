#include <iostream>
#include <vector>


class TempTracker {
	int id, factoryId;
	double temp;
	std::vector<double> last_10_vals;
	void normalize() {
		if (temp < -273.0) {
			temp = -273.0;
		}
		if (temp > 1000.0) {
			temp = 1000.0;
		}
		if (factoryId <= 0) {
			factoryId = 1;
		}
	}
public:

	TempTracker() : id(0), factoryId(0), temp(0.0), last_10_vals(10, 0.0) {
    	std::cout << "default constructor" << std::endl;
		normalize();
	}
	TempTracker(int id, int factoryId, double temp, std::vector<double> last_10_vals) :
		id(id), factoryId(factoryId), temp(temp), last_10_vals(last_10_vals) {
		std::cout << "initialization constructor" << std::endl;
		normalize();
	}
	TempTracker(const TempTracker& T) {
		std::cout << "copy constructor" << std::endl;
		this->id = T.id;
		this->factoryId = T.factoryId;
		this->temp = T.temp;
		this->last_10_vals = T.last_10_vals;
		normalize();
	}
	TempTracker& operator= (const TempTracker& T) {
		if (this == &T){
			return *this;
		}
		std::cout << "assignment operator" << std::endl;
		this->id = T.id;
		this->factoryId = T.factoryId;
		this->temp = T.temp;
		this->last_10_vals = T.last_10_vals;
		normalize();
		return *this;
	}
	int getFactoryId() const {return factoryId;}
	int getId() const {return id;}
	double getTemp() const {return temp;}
	std::vector<double> getLast10Vals() const {return last_10_vals;}

	int setFactoryId(int factoryId) {this->factoryId = factoryId; normalize();}
	int setId(int id) {this->id = id; normalize();}
	double setTemp(double temp) {this->temp = temp; normalize();}
	std::vector<double> setLast10Vals(std::vector<double> last10) {this->last_10_vals = last10; normalize();}

};

int main() {
    TempTracker a;                                         // default constructor
    TempTracker b(7, 42, 25.5, {1, 2, 3});                 // initialization constructor
    TempTracker d(b);                                      // copy constructor
    TempTracker e;                                         // default constructor
    e = b;                                                 // assignment op
    TempTracker f = b;   
	TempTracker bad(1, 0, 5000.0, {});
	std::cout << "temp = " << bad.getTemp() << ", factoryId = " << bad.getFactoryId() << std::endl;
    return 0;
}