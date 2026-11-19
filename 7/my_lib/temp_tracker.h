#pragma once
#include <iostream>
#include <vector>


class TempTracker {
	int id;
	int factoryId;
	double temp;
	double* last_10_vals;

	static unsigned count;
	

	void normalize();

public:

	static const std::string class_name;
	TempTracker();
	TempTracker(int, double, std::vector<double>);

	TempTracker(const TempTracker&);

	TempTracker& operator= (const TempTracker&);

	bool operator<(const TempTracker&) const;

	~TempTracker();

	int getFactoryId() const;
	int getId() const;
	double getTemp() const;
	std::vector<double> getLast10Vals() const;

	void print_tracker();


	void setTemp(double);
	void setLast10Vals(const std::vector<double>&);

	static void print_count();
};

