#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "Global.h"
#include "clsPrintPatientsCases.h"
using namespace std;

class clsShowMediumPatientCasesScreen : protected clsScreen
{
public:
	static void ShowMediumPatientCasesScreen()
	{
		system("cls");
		_DrawHeaderScreen("Medium Patients Cases Screen");
		clsPrintPatientsCases::Display(Stack_Mid, "Patients Cases Medium");
	}
};