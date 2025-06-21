#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ContantPatients.h"
#include "Node.h"
#include "clsReturnPatientCaseType.h"
#include <iomanip>
#include "Global.h"
#include "clsUtil.h"
#include "clsShowGeneralPatientsCasesScreen.h"
#include "clsShowSimplePatientsCasesScreen.h"
#include "clsShowMediumPatientCasesScreen.h"
#include "clsShowHightPatientCasesScreen.h"

class clsShowPatientsCasesScreen : protected clsScreen
{
private:
	enum enPatientCaseOptions { eGeneral = 1, eSimple = 2, eMiduim = 3, eHight = 4, Back = 5 };

	static short _ReadOption()
	{
		return clsUtil::ReadOption(1, 5);
	}

	static void _GoBackToShowPatientsCasesScreen()
	{
		cout << endl;
		system("pause");
		ShowPatientsCasesScreen();
	}

	static void _ShowGeneralPatientCasesScreen()
	{
		clsShowGeneralPatientsCasesScreen::ShowGeneralPatientCasesScreen();
	}

	static void _ShowSimplePatientCasesScreen()
	{
		clsShowSimplePatientsCasesScreen::ShowSimplePatientCasesScreen();
	}

	static void _ShowMediumPatientCasesScreen()
	{
		clsShowMediumPatientCasesScreen::ShowMediumPatientCasesScreen();
	}

	static void _ShowHightPatientCasesScreen()
	{
		clsShowHightPatientCasesScreen::ShowHightPatientCasesScreen();
	}

	static void _ExecuteTheSelectedOption(enPatientCaseOptions Option)
	{
		switch (Option)
		{
		 case clsShowPatientsCasesScreen::eGeneral:
		 {
		 	system("cls");
		 	_ShowGeneralPatientCasesScreen();
		 	_GoBackToShowPatientsCasesScreen();
		 	break;
		 }
		 case clsShowPatientsCasesScreen::eSimple:
		 {
		 	system("cls");
		 	_ShowSimplePatientCasesScreen();
		 	_GoBackToShowPatientsCasesScreen();
		 	break;
		 }
		 case clsShowPatientsCasesScreen::eMiduim:
		 {
		 	system("cls");
		 	_ShowMediumPatientCasesScreen();
		 	_GoBackToShowPatientsCasesScreen();
		 	break;
		 }
		 case clsShowPatientsCasesScreen::eHight:
		 {
		 	system("cls");
		 	_ShowHightPatientCasesScreen();
		 	_GoBackToShowPatientsCasesScreen();
		 	break;
		 }
		 case clsShowPatientsCasesScreen::Back:
		 {
		 	// go back end out this screen
		 	break;
		 }
		}
	}

	static void _PrintPatientsCasesMenu()
	{
		cout << "\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n" << setw(42) << left << "" << "Enter <1> General Patients Cases.";
		cout << "\n" << setw(42) << left << "" << "Enter <2> Simple  Patients Cases.";
		cout << "\n" << setw(42) << left << "" << "Enter <3> Medium  Patients Cases.";
		cout << "\n" << setw(42) << left << "" << "Enter <4> Hight   Patients Cases.";
		cout << "\n" << setw(42) << left << "" << "Enter <5> Back.";
		cout << "\n" << setw(42) << left << "" << "======================================";
	}	

public:
	static void ShowPatientsCasesScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t  Patients Cases List Screen");
		_PrintPatientsCasesMenu();
		_ExecuteTheSelectedOption((enPatientCaseOptions)_ReadOption());
	}
};

