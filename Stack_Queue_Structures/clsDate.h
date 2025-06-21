#pragma once
#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std; 

class clsDate
{
private:
	struct stDate
	{
		int Year;
		int Month;
		int Day;
	};

public:
	static stDate DateNow()
	{
		stDate Date;

		time_t now = time(0);
		tm* t = localtime(&now);
		Date.Year = t->tm_year + 1900;
		Date.Month = t->tm_mon + 1;
		Date.Day = t->tm_mday;

		return Date;
	}
};