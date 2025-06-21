#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "Global.h"
#include "clsPrintPatientsCases.h"
using namespace std;

class clsShowGeneralPatientsCasesScreen : protected clsScreen
{
public:
	static void ShowGeneralPatientCasesScreen()
	{
		system("cls");
		_DrawHeaderScreen("General Patient Cases Screen");
		clsPrintPatientsCases::Display(Queue_General, "Queue General Cases");
	}
};