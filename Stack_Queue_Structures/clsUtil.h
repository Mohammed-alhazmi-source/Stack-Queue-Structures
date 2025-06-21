#pragma once
#include <iostream>
#include <iomanip>
#include "ContantPatients.h"
#include "QueueErrors.h"
using namespace std;

class clsUtil
{
public:
	static void PrintMenu()
	{
		cout << "\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n"   << setw(42) << left << "" << "[1] Display Items.";
		cout << "\n"   << setw(42) << left << "" << "[2] Push Item.";
		cout << "\n"   << setw(42) << left << "" << "[3] Pop Item.";
		cout << "\n"   << setw(42) << left << "" << "[4] Search Item.";
		cout << "\n"   << setw(42) << left << "" << "[5] Clear Items.";
		cout << "\n"   << setw(42) << left << "" << "[6] Back.";
		cout << "\n"   << setw(42) << left << "" << "======================================";
	}

	static short ReadOption(short From, short To,string Message = "Please Choose Any Option [1 To 6] ? ")
	{
		short Choose = 0;
		cout << endl << setw(42) << left << "" << "Please Choose Any Option [" << From << " To " << To << "] ? ";
		Choose = clsInputValidate::ReadNumberBetween(From, To);
		return Choose;
	}

	static void PrintMessage(const string &Message = "")
	{
		cout << "\n\n";
		cout << setw(35) << left << "" << "____________________________________________________";
		cout << "\n" << setw(45) << left << "" << Message;
		cout << "\n" << setw(35) << left << "" << "____________________________________________________\n";
	}

	static char DoYouWantToContinue(string AnswerMessage = "")
	{
		char Answer = 'n';
		cout << AnswerMessage;
		cin >> Answer;
		return Answer;
	}

	static void PrintPatientCaseCard(stPatientInformation& PatientInfo)
	{
		cout << "\nPatient Card:";
		cout << "\n-----------------------------\n";
		cout << "Name : " << PatientInfo.PatientName << endl;
		cout << "Case : " << PatientInfo.PatientCase << endl;
		cout << "-----------------------------\n";
	}
};

