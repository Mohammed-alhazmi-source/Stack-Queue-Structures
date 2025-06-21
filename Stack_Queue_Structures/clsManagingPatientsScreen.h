#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsShowPatientsCasesScreen.h"
#include "clsAddPatientCaseScreen.h"
#include "clsUpdatePatientCaseScreen.h"
#include "clsShowDeletePatientCaseScreen.h"
#include "clsShowProcessPatientsCasesScreen.h"
using namespace std;

class clsManagingPatientsScreen : protected clsScreen
{
private:
	enum enPatientManagementOptionsMenu
	{
		eShowPatientsCases = 1,	eAddPatientCase = 2, eUpdatePatientCase = 3,
		eExitPatientCase = 4, eProcessPatientsCases = 5, eExit = 6
	};

	static short _ReadOption()
	{
		return clsUtil::ReadOption(1, 6);
	}

	static void _GoBackToMenuPatientManagement()
	{
		cout << endl;
		system("pause");
		ShowManagingPatientsScreen();
	}

	static void _ShowPatientsCasesScreen()
	{
		clsShowPatientsCasesScreen::ShowPatientsCasesScreen();
	}

	static void _ShowAddPatientCaseScreen()
	{
		clsAddPatientCaseScreen::ShowAddPatientCaseScreen();
	}

	static void _ShowUpdatePatientCaseScreen()
	{
		clsUpdatePatientCaseScreen::ShowUpdatePatientCaseScreen();
	}

	static void _ShowDeletePatientCaseScreen()
	{
		clsShowDeletePatientCaseScreen::ShowDeletePatientCaseScreen();
	}

	static void _ShowProcessPatientsCasesScreen()
	{
		clsShowProcessPatientsCasesScreen::ShowProcessPatientsCasesScreen();
	}

	static void _ExecuteTheSelectedOption(enPatientManagementOptionsMenu Option)
	{
		switch (Option)
		{
		case clsManagingPatientsScreen::eShowPatientsCases:
		{
			system("cls");
			_ShowPatientsCasesScreen();
			_GoBackToMenuPatientManagement();
			break;
		}

		case clsManagingPatientsScreen::eAddPatientCase:
		{
			system("cls");
			_ShowAddPatientCaseScreen();
			_GoBackToMenuPatientManagement();
			break;
		}

		case clsManagingPatientsScreen::eUpdatePatientCase:
		{
			system("cls");
			_ShowUpdatePatientCaseScreen();
			_GoBackToMenuPatientManagement();
			break;
		}

		case clsManagingPatientsScreen::eExitPatientCase:
		{
			system("cls");
			_ShowDeletePatientCaseScreen();
			_GoBackToMenuPatientManagement();
			break;
		}

		case clsManagingPatientsScreen::eProcessPatientsCases:
		{
			system("cls");
			_ShowProcessPatientsCasesScreen();
			_GoBackToMenuPatientManagement();
			break;
		}

		case clsManagingPatientsScreen::eExit:
		{
			// go back end out this screen
			break;
		}
		}
	}

	static void _PrintPatientsManagementMenu()
	{
		cout << "\n\n" << setw(42)   << left << "" << "======================================";
		cout << "\n"   << setw(42)   << left << "" << "Enter <1> Show Patients Cases.";
		cout << "\n"   << setw(42)   << left << "" << "Enter <2> Add New Patient Case.";
		cout << "\n"   << setw(42)   << left << "" << "Enter <3> Update Patient Case.";
		cout << "\n"   << setw(42)   << left << "" << "Enter <4> Exit Patient Case.";
		cout << "\n"   << setw(42)   << left << "" << "Enter <5> Process Patients Cases.";
		cout << "\n"   << setw(42)   << left << "" << "Enter <6> Back.";
		cout << "\n"   << setw(42)   << left << "" << "======================================";
	}

public:
	static void ShowManagingPatientsScreen()
	{
		system("cls");
		_DrawHeaderScreen("Patient Management System - Hybrid Mode\n\t\t\t\t\t     (Stack and Queue Integrated Architecture)");
		_PrintPatientsManagementMenu();
		_ExecuteTheSelectedOption((enPatientManagementOptionsMenu)_ReadOption());
	}
};