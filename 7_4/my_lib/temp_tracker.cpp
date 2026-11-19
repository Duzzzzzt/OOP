#include "temp_tracker.h"


unsigned TempTracker::count = 0;
const std::string TempTracker::class_name = "Temperature tracker";

void TempTracker::normalize() {
    if (temp < -273.0 || temp > 1000.0)
        throw std::string("temp out of range [-273, 1000]");
    if (factoryId <= 0)
        throw std::string("factoryId must be > 0");
    for (int i = 0; i < 10; i++)
        if (last_10_vals[i] < -273.0 || last_10_vals[i] > 1000.0)
            throw std::string("value in last10 out of range [-273, 1000]");
}

std::ostream& operator << (std::ostream& out, const TempTracker& b){
    out << b.getFactoryId() << std::endl;
    out << b.getId() << std::endl;
    out << b.getTemp() << std::endl;
	out << b.getCount() << std::endl;
    return out;
}

std::istream& operator >> (std::istream& in, TempTracker& b){
    
    int factoryId, id;
	double temp;
    in >> factoryId;
    in >> id;
    in >> temp;
    b = TempTracker{factoryId, temp, {1, 2, 3}};
    return in;
}


TempTracker::TempTracker() : id(count), factoryId(1), temp(0.0), last_10_vals(new double[10]()) {
	normalize();
	count++;
	std::cout << "default constructor, count = " << count << std::endl;
	
}

TempTracker::TempTracker(int factoryId, double temp, std::vector<double> last10) :
	factoryId(factoryId), temp(temp), last_10_vals(new double[10]()) {
	normalize();
	id = count;
	count++;
	std::size_t n = last10.size() < 10 ? last10.size() : 10;
	for (std::size_t i = 0; i < n; i++) {
		last_10_vals[i] = last10[i];
	}
	std::cout << "initialization constructor, count = " << count << std::endl;
	
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


bool TempTracker::operator<(const TempTracker& T) const {
	if (factoryId != T.factoryId) {
		return factoryId < T.factoryId;
	}
	return temp < T.temp;
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
unsigned TempTracker::getCount() { return TempTracker::count; }

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

void TempTracker::print_count() {
	std::cout << "Total objects: " << count << std::endl;
}
