#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "Global.h"
#include "clsPrintPatientsCases.h"
using namespace std; 

class clsShowSimplePatientsCasesScreen : protected clsScreen
{
public:
	static void ShowSimplePatientCasesScreen()
	{
		system("cls");
		_DrawHeaderScreen("Simple Patients Cases Screen");
		clsPrintPatientsCases::Display(Stack_Low, "Patients Cases Simple");
	}
};