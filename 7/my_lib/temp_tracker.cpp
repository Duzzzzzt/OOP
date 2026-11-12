#include "temp_tracker.h"


unsigned TempTracker::count = 0;
const std::string TempTracker::class_name = "Temperature tracker";

void TempTracker::normalize() {
	if (temp < -273.0) {
		temp = -273.0;
	}
	if (temp > 1000.0) {
		temp = 1000.0;
	}
	if (factoryId <= 0) {
		factoryId = 1;
	}
	for (std::size_t i = 0; i < 10; i++) {
		if (last_10_vals[i] < -273.0) last_10_vals[i] = -273.0;
		if (last_10_vals[i] > 1000.0) last_10_vals[i] = 1000.0;
	}
}

static const std::string class_name;
TempTracker::TempTracker() : id(count), factoryId(0), temp(0.0), last_10_vals(new double[10]()) {
	count++;
	std::cout << "default constructor, count = " << count << std::endl;
	normalize();
}

TempTracker::TempTracker(int factoryId, double temp, std::vector<double> last10) :
	factoryId(factoryId), temp(temp), last_10_vals(new double[10]()) {
	id = count;
	count++;
	std::size_t n = last10.size() < 10 ? last10.size() : 10;
	for (std::size_t i = 0; i < n; i++) {
		last_10_vals[i] = last10[i];
	}
	std::cout << "initialization constructor, count = " << count << std::endl;
	normalize();
}

TempTracker::TempTracker(const TempTracker& T) {

	this->id = count;
	count++;
	this->factoryId = T.factoryId;
	this->temp = T.temp;
	last_10_vals = new double[10]();
	for (std::size_t i = 0; i < 10; i++) {
		last_10_vals[i] = T.last_10_vals[i];
	}
	std::cout << "copy constructor, count = " << count << std::endl;
	normalize();
}

TempTracker& TempTracker::operator= (const TempTracker& T) {
	if (this == &T) {
		return *this;
	}

	this->id = T.id;
	this->factoryId = T.factoryId;
	this->temp = T.temp;
	delete[] last_10_vals;
	last_10_vals = new double[10]();
	for (std::size_t i = 0; i < 10; i++) {
		last_10_vals[i] = T.last_10_vals[i];
	}
	std::cout << "assignment operator, count = " << count << std::endl;
	normalize();
	return *this;
}


TempTracker::~TempTracker() {
	count--;
	delete[] last_10_vals;
	last_10_vals = nullptr;
	std::cout << "destructor, count = " << count << std::endl;
}

int TempTracker::getFactoryId() const { return factoryId; }
int TempTracker::getId() const { return id; }
double TempTracker::getTemp() const { return temp; }
std::vector<double> TempTracker::getLast10Vals() const {
	return std::vector<double>(last_10_vals, last_10_vals + 10);
}


void TempTracker::print_tracker() {
	std::cout << "Factry id: " << factoryId << std::endl;
	std::cout << "Current temperature: " << temp << std::endl;
	std::cout << "Last 10 values: ";
	for (int i = 0; i < 10; i++) {
		std::cout << last_10_vals[i] << " ";
	}
	std::cout << std::endl;

}


void TempTracker::setTemp(double v) { temp = v; normalize(); }
void TempTracker::setLast10Vals(const std::vector<double>& v) {
	delete[] last_10_vals;
	last_10_vals = new double[10]();
	std::size_t n = v.size() < 10 ? v.size() : 10;
	for (std::size_t i = 0; i < n; i++) {
		last_10_vals[i] = v[i];
	}
	normalize();
}
