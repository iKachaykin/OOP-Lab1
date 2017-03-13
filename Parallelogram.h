#pragma once
#include <iostream>
#include <algorithm>
using namespace std;
class parallelogram {
private:
	double first_side, second_side, diagonal;
public:

	parallelogram(double, double, double);
	void size_variation(double, bool);
	double get_diagonal();
	double get_first_side();
	double get_second_side();
	double get_height_on_first_side();
	double get_height_on_second_side();
	double perimeter_sqrt();
	double area_sqrt();
};