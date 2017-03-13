#include "Parallelogram.h"

parallelogram::parallelogram(double first_side, double second_side, double diagonal)
{
	if (first_side + second_side < diagonal || first_side + diagonal < second_side || diagonal + second_side < first_side || first_side <= 0 || second_side <= 0 || diagonal <= 0)
		throw 1;
	this->first_side = first_side;
	this->second_side = second_side;
	this->diagonal = diagonal;
}

void parallelogram::size_variation(double n, bool mode)
{
	if (n <= 0)
		throw 1;
	else
	{
		first_side *= pow(n, pow(-1, mode));
		second_side *= pow(n, pow(-1, mode));
		diagonal *= pow(n, pow(-1, mode));
	}
}

double parallelogram::get_diagonal(){ return diagonal; }

double parallelogram::get_first_side() { return first_side; }

double parallelogram::get_second_side() { return second_side; }

double parallelogram::get_height_on_first_side() 
{
	return second_side * sqrt(1 - pow((first_side * first_side + second_side * second_side - diagonal * diagonal) / (2 * first_side * second_side), 2));
}

double parallelogram::get_height_on_second_side() 
{
	return first_side * sqrt(1 - pow((first_side * first_side + second_side * second_side - diagonal * diagonal) / (2 * first_side * second_side), 2));
}

double parallelogram::perimeter_sqrt(){	return sqrt(2 * (first_side + second_side)); }

double parallelogram::area_sqrt() { return sqrt(this->get_height_on_first_side() * first_side); }