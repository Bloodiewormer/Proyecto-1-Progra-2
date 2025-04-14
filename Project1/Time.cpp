#include "Time.h"

Time::Time(int startDay): dayOfYear(startDay)
{
	monthLengths[0] = 31;
	monthLengths[1] = 28;
	monthLengths[2] = 31;
	monthLengths[3] = 30;
	monthLengths[4] = 31;
	monthLengths[5] = 30;
	monthLengths[6] = 31;
	monthLengths[7] = 31;
	monthLengths[8] = 30;
	monthLengths[9] = 31;
	monthLengths[10] = 30;
	monthLengths[11] = 31;
	monthNames[0] = "Enero";
	monthNames[1] = "Febrero";
	monthNames[2] = "Marzo";
	monthNames[3] = "Abril";
	monthNames[4] = "Mayo";
	monthNames[5] = "Junio";
	monthNames[6] = "Julio";
	monthNames[7] = "Agosto";
	monthNames[8] = "Septiembre";
	monthNames[9] = "Octubre";
	monthNames[10] = "Noviembre";
	monthNames[11] = "Diciembre";

}

void Time::pasarDia(int days)
{
	//for example, if dayOfYear is 5 and days is 10, it should return 15.
	//if dayOfYear is 360 and days is 10, it should return 5.
	dayOfYear = (dayOfYear + days) % 365;
}

void Time::regresarDia(int days)
{
	//for example, if dayOfYear is 5 and days is 10, it should return 360.
	dayOfYear = (dayOfYear - days + 365) % 365;
}

void Time::irAlDia(int day)
{
	dayOfYear = day % 365;
}

int Time::getDia() const
{
	return dayOfYear;
}

int Time::diasHasta(const Time& other) const
{
	return 0;
}

bool Time::isSameDay(const Time& other) const
{
	return dayOfYear == other.dayOfYear;
}



std::string Time::toString() const
{
	std::ostringstream oss;
	int daycount = dayOfYear;

	for (int i = 0; i < 12; i++) {
		if (daycount < monthLengths[i]) {
			oss << daycount + 1 << " de " << monthNames[i];
			return oss.str();
		}
		daycount -= monthLengths[i];
	}
	return oss.str();
}



