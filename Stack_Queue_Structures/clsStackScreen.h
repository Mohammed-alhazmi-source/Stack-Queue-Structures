#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "clsStackUsingDynamicArrayScreen.h"
#include "clsStackUsingLinkedListScreen.h"
#include "clsStackUsingSmartStackScreen.h"
#include "clsExercisesStackScreen.h"
using namespace std;


class clsStackScreen : protected clsScreen
{
private:
	enum enStackImplementationOptions
	{
		eStackUsingDynamicArray = 1, eStackUsingLinkedList = 2,
		eSmartStack = 3, eExercises = 4, eBackToMainMenu = 5
	};

	static short _ReadStackImplementOption()
	{
		return clsUtil::ReadOption(1, 5);
	}

	static void _GoBackToStackMenu()
	{
		system("pause");
		ShowStackImplementationsScreen();
	}

	static void _ShowStackOperationsUsingDynamicArrayScreen()
	{
		clsStackUsingDynamicArrayScreen::ShowStackImplementUsingDynamicArrayScreen();
	}

	static void _ShowStackOperationsUsingLinkedListScreen()
	{
		clsStackUsingLinkedListScreen::ShowStackImplementUsingLinkedListScreen();
	}

	static void _ShowStackOperationsUsingSmartStackScreen()
	{
		clsStackUsingSmartStackScreen::ShowStackImplementUsingSmartStackScreen();
	}

	static void _ShowExercisesStackScreen()
	{
		clsExercisesStackScreen::ShowExercisesStackScreen();
	}

	static void _ExecuteTheSelectedOption(enStackImplementationOptions StackImplementationOption)
	{
		switch (StackImplementationOption)
		{
		case clsStackScreen::eStackUsingDynamicArray:
		{
			system("cls");
			_ShowStackOperationsUsingDynamicArrayScreen();
			_GoBackToStackMenu();
			break;
		}

		case clsStackScreen::eStackUsingLinkedList:
		{
			system("cls");
			_ShowStackOperationsUsingLinkedListScreen();
			_GoBackToStackMenu();
			break;
		}

		case clsStackScreen::eSmartStack:
		{
			system("cls");
			_ShowStackOperationsUsingSmartStackScreen();
			_GoBackToStackMenu();
			break;
		}

		case clsStackScreen::eExercises:
		{
			system("cls");
			_ShowExercisesStackScreen();
			_GoBackToStackMenu();
			break;
		}

		case clsStackScreen::eBackToMainMenu:
			// Â‰« ·« ‰” œ⁄Ì „—… «Œ—Ï œ«·… «·ﬁ«∆„… «·—∆Ì”Ì… ·«‰Â „‰ Â‰«
			//  —«Õ Ì—ÊÕ «·Ï «·„ﬂ«‰ «·„” œ⁄Ï ÊÌﬂ„· „«»⁄œÂ Ê»Â–« —«Õ Ì—Ã⁄ ··ﬁ«∆„… «·—∆Ì”Ì…
			break;
		}
	}

	static void _PrintStackMenu()
	{
		cout << "\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n"   << setw(42) << left << "" << "[1] Stack Using Dynamic Array.";
		cout << "\n"   << setw(42) << left << "" << "[2] Stack Using Linked List.";
		cout << "\n"   << setw(42) << left << "" << "[3] Smart Stack.";
		cout << "\n"   << setw(42) << left << "" << "[4] Exercises Stack.";
		cout << "\n"   << setw(42) << left << "" << "[5] Main Menue.";
		cout << "\n"   << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowStackImplementationsScreen()
	{
		system("cls");
		_DrawHeaderScreen("   Stack Implementation");
		_PrintStackMenu();
		_ExecuteTheSelectedOption((enStackImplementationOptions)_ReadStackImplementOption());
	}
};