#pragma once
#include <iostream>
#include <vector>


class TempTracker {
	int id, factoryId;
	double temp;
	double* last_10_vals;

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
		for (std::size_t i = 0; i < 10; i++) {
			if (last_10_vals[i] < -273.0) last_10_vals[i] = -273.0;
			if (last_10_vals[i] > 1000.0) last_10_vals[i] = 1000.0;
		}
	}
public:

	TempTracker() : id(0), factoryId(0), temp(0.0), last_10_vals(new double[10]()) {
		std::cout << "default constructor" << std::endl;
		normalize();
	}
	TempTracker(int idg, int factoryId, double tempg, std::vector<double> last10) :
		factoryId(factoryId), last_10_vals(new double[10]()) {
		id = idg;
		temp = tempg;
		std::size_t n = last10.size() < 10 ? last10.size() : 10;
		for (std::size_t i = 0; i < n; i++) {
			last_10_vals[i] = last10[i];
		}
		std::cout << "initialization constructor" << std::endl;
		normalize();
	}

	TempTracker(const TempTracker& T) {
		std::cout << "copy constructor" << std::endl;
		this->id = T.id;
		this->factoryId = T.factoryId;
		this->temp = T.temp;
		last_10_vals = new double[10]();
		for (std::size_t i = 0; i < 10; i++) {
			last_10_vals[i] = T.last_10_vals[i];
		}
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
		delete[] last_10_vals;
		last_10_vals = new double[10]();
		for (std::size_t i = 0; i < 10; i++) {
			last_10_vals[i] = T.last_10_vals[i];
		}
		normalize();
		return *this;
	}

	~TempTracker(){
		delete[] last_10_vals;
		last_10_vals = nullptr;
		std::cout << "destructor" << std::endl;
	}

	int getFactoryId() const {return factoryId;}
	int getId() const {return id;}
	double getTemp() const {return temp;}
	std::vector<double> getLast10Vals() const {
		return std::vector<double>(last_10_vals, last_10_vals + 10);
	}

	void setId(int v) {id = v; normalize();}
	void setTemp(double v) {temp = v; normalize();}
	void setLast10Vals(const std::vector<double>& v) {
		delete[] last_10_vals;
		last_10_vals = new double[10]();
		std::size_t n = v.size() < 10 ? v.size() : 10;
		for (std::size_t i = 0; i < n; i++) {
			last_10_vals[i] = v[i];
		}
		normalize();
	}
};
