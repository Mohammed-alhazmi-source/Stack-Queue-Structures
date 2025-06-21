#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsQueueScreen.h"
#include "clsStackScreen.h"
#include "clsManagingPatientsScreen.h"
#include "clsUtil.h"
#include <iomanip>
using namespace std;

class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOptions { eStack = 1, eQueue = 2, StackAndQueueIntegrated = 3, Exit = 4 };

	static short _ReadMainMenuOption()
	{
		return clsUtil::ReadOption(1, 4);
	}

	static void _Exit()
	{
		cout << endl << "--------------------------------------";
		cout << "\nEnd Program :-)";
		cout << endl << "--------------------------------------\n";
	}

	static void _GoBackToMainMenu()
	{
		system("pause");
		ShowMainMenu();
	}

	static void _ShowStackImplementationsScreen()
	{
		clsStackScreen::ShowStackImplementationsScreen();
	}

	static void _ShowQueueImplementationsScreen()
	{
		clsQueueScreen::ShowQueueImplementationsScreen();
	}

	static void _ShowStackAndQueueMergeScreen()
	{
		clsManagingPatientsScreen::ShowManagingPatientsScreen();
	}

	static void _ExecuteTheSelectedOption(enMainMenuOptions DataStructureOption)
	{
		switch (DataStructureOption)
		{
		case clsMainScreen::eStack:
		{
			system("cls");
			_ShowStackImplementationsScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::eQueue:
		{
			system("cls");
			_ShowQueueImplementationsScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::StackAndQueueIntegrated:
		{
			system("cls");
			_ShowStackAndQueueMergeScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::Exit:
		{
			system("cls");
			_Exit();
			break;
		}
		}
	}

	static void _PrintMainMenu()
	{
		cout << "\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n" <<   setw(42) << left << "" << "Enter <1> Data Structure Stack.";
		cout << "\n" <<   setw(42) << left << "" << "Enter <2> Data Structure Queue.";
		cout << "\n" <<   setw(42) << left << "" << "Enter <3> Data Structure Stack And Queue.";
		cout << "\n" <<   setw(42) << left << "" << "Enter <4> Exit.";
		cout << "\n" <<   setw(42) << left << "" << "======================================";
	}

public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawHeaderScreen("\t\tMain Menu");
		_PrintMainMenu();
		_ExecuteTheSelectedOption((enMainMenuOptions)_ReadMainMenuOption());
	}
};

