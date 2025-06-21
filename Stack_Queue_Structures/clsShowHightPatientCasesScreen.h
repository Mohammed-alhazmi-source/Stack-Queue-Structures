#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "Global.h"
#include "clsPrintPatientsCases.h"
using namespace std;

class clsShowHightPatientCasesScreen : protected clsScreen
{
public:
	static void ShowHightPatientCasesScreen()
	{
		system("cls");
		_DrawHeaderScreen("Hight Patients Cases Screen");
		clsPrintPatientsCases::Display(Stack_Hight, "Patients Cases Hight");
	}
};