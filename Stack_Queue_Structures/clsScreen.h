#pragma once
#include <iostream>
#include <ctime>
#include <iomanip>
#include "clsDate.h"
#include <string>
using namespace std;

class clsScreen
{

private:	
	static string _DateNow()
	{
		auto Date = clsDate::DateNow();
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}

	static void _PrintDate()
	{
		cout << setw(42) << left << "" << "--------------------------------------";
		cout << "\n" << setw(54) << left << "" << "Date : " << left << setw(30) << _DateNow();
		cout << "\n" << setw(42) << left << "" << "--------------------------------------";
	}

protected:
	static void _DrawHeaderScreen(string Title, string SubTitle = "")
	{
		cout << "\t\t\t\t  _________________________________________________________";
		cout << "\n\n\t\t\t\t\t      " << Title;
		
		if (SubTitle != "")
			cout << "\n\t\t\t\t\t  " << SubTitle;

		cout << "\n\t\t\t\t  _________________________________________________________\n\n";
		_PrintDate();
	}
};