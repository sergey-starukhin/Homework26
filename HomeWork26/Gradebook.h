#include <iostream>
#pragma once

using namespace std;

class Gradebook
{
private:
	int* grades;
	int count;

public:
	explicit Gradebook(int count_) : grades(nullptr), count(count_) {
		if (count_ < 1)
			count_ = 1;
		grades = new int[count_];
		for (int i = 0; i < count; ++i)
			grades[i] = 0;
	}

	Gradebook(const double count) = delete;
	Gradebook(const Gradebook& book) = delete;
	Gradebook operator=(const Gradebook& other) = delete;

	~Gradebook(){
		delete[] grades;
	}

	//getters
	double average() const;
	int getCount() const;
	
	//setters
	bool setGrade(int lesson, int grade);

	//operators
	int& operator[](int lesson)
	{
		return grades[lesson];
	}

	int operator[](int lesson) const
	{
		return grades[lesson];
	}

	explicit operator bool() const {
		return count > 0;
	}

	friend ostream& operator<<(ostream& out, const Gradebook& book) {
		out << "Оцінки: ";
		for (int i = 0; i < book.getCount(); ++i)
		{
			if (book[i] == 0)
				out << "- ";
			else
				out << book[i] << " ";
		}
		out << "| середній бал : " << book.average();
		return out;
	}

	friend istream& operator>>(istream& in, Gradebook& book) {
		for (int i = 0; i < book.getCount(); ++i)
		{
			cout << "Ведите " << i + 1 << " оценку: " << endl;
			int grade;
			in >> grade;
			if (grade < 0 || grade > 12)
				book[i] = 0;
			else
				book[i] = grade; 
		}
		return in;
	}

	bool operator>(const Gradebook& other) const;
};

inline int Gradebook::getCount() const {
	return count;
}

inline bool Gradebook::operator>(const Gradebook& other) const {
	return average() > other.average();
}



