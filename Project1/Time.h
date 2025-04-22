#pragma once
#include <iostream>
#include <sstream>
#include "Utility.h"

class Time
{
private:
	int dayOfYear;
	int monthLengths[12];
	std::string monthNames[12];
public:
	Time(int startDay = 0);
	void pasarDia(int days);
	void regresarDia(int days);
	void irAlDia(int day);
	int getDia() const;
	int diasHasta(const Time& other) const;
	bool isSameDay(const Time& other) const;
	std::string toString() const;

	//operator + returns a string



};

