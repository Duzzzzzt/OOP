#pragma once
#include <iostream>
#include <vector>

template <typename T>
class TempTracker {
	int id;
	int factoryId;
	T temp;
	T* last_10_vals;

	static unsigned count;

	void normalize();

public:

	static const std::string class_name;
	TempTracker();
	TempTracker(int, T, std::vector<T>);

	TempTracker(const TempTracker&);

	TempTracker& operator= (const TempTracker&);

	bool operator<(const TempTracker&) const;

	~TempTracker();

	int getFactoryId() const;
	int getId() const;
	T getTemp() const;
	std::vector<T> getLast10Vals() const;
	static unsigned getCount();
	void print_tracker();


	void setTemp(T);
	void setLast10Vals(const std::vector<T>&);

	static void print_count();
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const TempTracker<T>& t);
template <typename T>
std::istream& operator>>(std::istream& is, TempTracker<T>& t);

// определение статических полей (как было в .cpp, только с template)

template <typename T>
unsigned TempTracker<T>::count = 0;
template <typename T>
const std::string TempTracker<T>::class_name = "Temperature tracker";

template <typename T>
void TempTracker<T>::normalize() {
    if (temp < -273.0 || temp > 1000.0)
        throw std::string("temp out of range [-273, 1000]");
    if (factoryId <= 0)
        throw std::string("factoryId must be > 0");
    for (int i = 0; i < 10; i++)
        if (last_10_vals[i] < -273.0 || last_10_vals[i] > 1000.0)
            throw std::string("value in last10 out of range [-273, 1000]");
}

template <typename T>
std::ostream& operator << (std::ostream& out, const TempTracker<T>& b){
    out << TempTracker<T>::class_name << std::endl;
    out << b.getFactoryId() << std::endl;
    out << b.getId() << std::endl;
    out << b.getTemp() << std::endl;
	out << b.getCount() << std::endl;
    return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, TempTracker<T>& b){

    int factoryId, id;
	T temp;
    in >> factoryId;
    in >> id;
    in >> temp;
    b = TempTracker<T>{factoryId, temp, {1, 2, 3}};
    return in;
}


template <typename T>
TempTracker<T>::TempTracker() : id(count), factoryId(1), temp(0.0), last_10_vals(new T[10]()) {
	normalize();
	count++;
	std::cout << "default constructor, count = " << count << std::endl;

}

template <typename T>
TempTracker<T>::TempTracker(int factoryId, T temp, std::vector<T> last10) :
	factoryId(factoryId), temp(temp), last_10_vals(new T[10]()) {
	std::size_t n = last10.size() < 10 ? last10.size() : 10;
	for (std::size_t i = 0; i < n; i++) {
		last_10_vals[i] = last10[i];
	}
	normalize();
	id = count;
	count++;
	std::cout << "initialization constructor, count = " << count << std::endl;

}

template <typename T>
TempTracker<T>::TempTracker(const TempTracker& other) {

	this->id = count;
	count++;
	this->factoryId = other.factoryId;
	this->temp = other.temp;
	last_10_vals = new T[10]();
	for (std::size_t i = 0; i < 10; i++) {
		last_10_vals[i] = other.last_10_vals[i];
	}
	std::cout << "copy constructor, count = " << count << std::endl;
	normalize();
}

template <typename T>
TempTracker<T>& TempTracker<T>::operator= (const TempTracker& other) {
	if (this == &other) {
		return *this;
	}

	this->id = other.id;
	this->factoryId = other.factoryId;
	this->temp = other.temp;
	delete[] last_10_vals;
	last_10_vals = new T[10]();
	for (std::size_t i = 0; i < 10; i++) {
		last_10_vals[i] = other.last_10_vals[i];
	}
	std::cout << "assignment operator, count = " << count << std::endl;
	normalize();
	return *this;
}


template <typename T>
bool TempTracker<T>::operator<(const TempTracker& other) const {
	if (factoryId != other.factoryId) {
		return factoryId < other.factoryId;
	}
	return temp < other.temp;
}

template <typename T>
TempTracker<T>::~TempTracker() {
	count--;
	delete[] last_10_vals;
	last_10_vals = nullptr;
	std::cout << "destructor, count = " << count << std::endl;
}

template <typename T>
int TempTracker<T>::getFactoryId() const { return factoryId; }
template <typename T>
int TempTracker<T>::getId() const { return id; }
template <typename T>
T TempTracker<T>::getTemp() const { return temp; }
template <typename T>
std::vector<T> TempTracker<T>::getLast10Vals() const {
	return std::vector<T>(last_10_vals, last_10_vals + 10);
}
template <typename T>
unsigned TempTracker<T>::getCount() { return TempTracker<T>::count; }

template <typename T>
void TempTracker<T>::print_tracker() {
	std::cout << "Factry id: " << factoryId << std::endl;
	std::cout << "Current temperature: " << temp << std::endl;
	std::cout << "Last 10 values: ";
	for (int i = 0; i < 10; i++) {
		std::cout << last_10_vals[i] << " ";
	}
	std::cout << std::endl;

}


template <typename T>
void TempTracker<T>::setTemp(T v) { temp = v; normalize(); }
template <typename T>
void TempTracker<T>::setLast10Vals(const std::vector<T>& v) {
	delete[] last_10_vals;
	last_10_vals = new T[10]();
	std::size_t n = v.size() < 10 ? v.size() : 10;
	for (std::size_t i = 0; i < n; i++) {
		last_10_vals[i] = v[i];
	}
	normalize();
}

template <typename T>
void TempTracker<T>::print_count() {
	std::cout << "Total objects: " << count << std::endl;
}
