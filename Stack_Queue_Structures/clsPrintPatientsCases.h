#pragma once
#include <iostream>
#include "ContantPatients.h"
#include "clsReturnPatientCaseType.h"
#include <iomanip>
#include "clsUtil.h"
#include "Global.h"
using namespace std;

class clsPrintPatientsCases
{
private:
	static void _PrintHeader(const string& Structure)
	{
		cout << "\n\n\n";
		cout << setw(50) << left << "" << Structure << endl;
		cout << setw(40) << left << "" << "-----------------------------------------\n";
		cout << setw(40) << left << "" << "| " << left << setw(25) << "Name";
		cout << "| " << left << setw(10) << "Case" << " |\n";
		cout << setw(40) << left << "" << "-----------------------------------------\n";
	}

public:
	template <typename T> static void Display(T& Source, const string& TableHeader)
	{
		if (!Source.IsEmpty())
		{
			_PrintHeader(TableHeader);
			Node<stPatientInformation>* Temp = Source.FirstNode();
			while (Temp != nullptr)
			{

				cout << setw(40) << left << "" << "| " << left << setw(25) << Temp->Data.PatientName;
				cout << "| " << left << setw(10) << clsReturnPatientCaseType::TextPatientCaseType(Temp->Data.PatientCase) << " |\n";
				Temp = Temp->Next;
			}
		}
		else
			clsUtil::PrintMessage("\t\t  Empty");
	}
};