#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsExercisePrinterQueueScreen.h"
#include "clsUtil.h"
#include <string>

using namespace std;

class clsExercisesQueueScreen : protected clsScreen
{
private:
	enum enExercisesQueueOptions { ePrinter = 1, eBack = 2 };

	static short _ReadExerciseOption()
	{
		return clsUtil::ReadOption(1, 2);		
	}

	static void _GoBackToQueueMainMenu()
	{
		system("pause");
		ShowExercisesQueueScreen();
	}

	static void _ShowExercisePrinterScreen()
	{
		clsExercisePrinterQueueScreen::ShowExercisePrinterScreen();
	}

	static void _ExecuteTheSelectedOption(enExercisesQueueOptions ExerciseQueueOption)
	{
		switch (ExerciseQueueOption)
		{
		case clsExercisesQueueScreen::ePrinter:
		{
			system("cls");
			_ShowExercisePrinterScreen();
			_GoBackToQueueMainMenu();
			break;
		}

		case clsExercisesQueueScreen::eBack:
			// Â‰« ·« ‰” œ⁄Ì „—… «Œ—Ï œ«·… ﬁ«∆„…  ÿ»Ìﬁ«  «·ÿ«»Ê— ·«‰Â „‰ Â‰«
			//  —«Õ Ì—ÊÕ «·Ï «·„ﬂ«‰ «·„” œ⁄Ï ÊÌﬂ„· „«»⁄œÂ Ê»Â–« —«Õ Ì—Ã⁄ ·ﬁ«∆„…  ÿ»Ìﬁ«  «·ÿ«»Ê—
			break;
		}
	}

	static void _PrintExercisesQueueMenu()
	{
		cout << "\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n"   << setw(42) << left << "" << "[1] Printer Queue.";
		cout << "\n"   << setw(42) << left << "" << "[2] Back.";
		cout << "\n"   << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowExercisesQueueScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t\tExercises Queue");
		_PrintExercisesQueueMenu();
		_ExecuteTheSelectedOption((enExercisesQueueOptions)_ReadExerciseOption());
	}
};

