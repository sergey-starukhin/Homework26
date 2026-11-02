#include <iostream>
#include "Gradebook.h"

double Gradebook::average() const {
	if (!*this)
		return 0;

	int counter = 0;
	double summary = 0;
	for (int i = 0; i < getCount(); ++i)
	{
		if ((*this)[i] != 0) 
		{
			summary += (*this)[i];
			++counter;
		}
	}

	return summary / counter;
}

bool Gradebook::setGrade(int lesson, int grade) {
	if (lesson < 0 || lesson > getCount() || grade < 1 || grade > 12)
		return false;
	(*this)[lesson] = grade;
	return true;
}



