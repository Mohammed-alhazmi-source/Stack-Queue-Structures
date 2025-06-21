#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsQueueUsingDynamicArrayScreen.h"
#include "clsQueueUsingSmartQueueScreen.h"
#include "clsQueueUsingLinkedListScreen.h"
#include "clsExercisesQueueScreen.h"
#include "clsUtil.h"
using namespace std;


class clsQueueScreen : protected clsScreen
{
private:
	enum enQueueImplementationOptions
	{
		eQueueUsingDynamicArray = 1, eQueueUsingLinkedList = 2, 
		eSmartQueue = 3, eExercises = 4, eBackToMainMenu = 5
	};

	static short _ReadQueueImplementOption()
	{
		return clsUtil::ReadOption(1, 5);
	}

	static void _GoBackToQueueMenu()
	{
		system("pause");
		ShowQueueImplementationsScreen();
	}

	static void _ShowQueueOperationsUsingDynamicArrayScreen()
	{
		clsQueueUsingDynamicArrayScreen::ShowQueueImplementUsingDynamicArrayScreen();
	}

	static void _ShowQueueOperationsUsingLinkedListScreen()
	{
		clsQueueUsingLinkedListScreen::ShowQueueImplementUsingLinkedListScreen();
	}

	static void _ShowQueueOperationsUsingSmartQueueScreen()
	{
		clsQueueUsingSmartQueueScreen::ShowQueueImplementUsingSmartQueueScreen();
	}

	static void _ShowExercisesQueueScreen()
	{
		clsExercisesQueueScreen::ShowExercisesQueueScreen();
	}

	static void _ExecuteTheSelectedOption(enQueueImplementationOptions QueueImplementationOption)
	{
		switch (QueueImplementationOption)
		{
		case clsQueueScreen::eQueueUsingDynamicArray:
		{
			system("cls");
			_ShowQueueOperationsUsingDynamicArrayScreen();
			_GoBackToQueueMenu();
			break;
		}

		case clsQueueScreen::eQueueUsingLinkedList:
		{
			system("cls");
			_ShowQueueOperationsUsingLinkedListScreen();
			_GoBackToQueueMenu();
			break;
		}

		case clsQueueScreen::eSmartQueue:
		{
			system("cls");
			_ShowQueueOperationsUsingSmartQueueScreen();
			_GoBackToQueueMenu();
			break;
		}

		case clsQueueScreen::eExercises:
		{
			system("cls");
			_ShowExercisesQueueScreen();
			_GoBackToQueueMenu();
			break;
		}

		case clsQueueScreen::eBackToMainMenu:
			// Â‰« ·« ‰” œ⁄Ì „—… «Œ—Ï œ«·… «·ﬁ«∆„… «·—∆Ì”Ì… ·«‰Â „‰ Â‰«
			//  —«Õ Ì—ÊÕ «·Ï «·„ﬂ«‰ «·„” œ⁄Ï ÊÌﬂ„· „«»⁄œÂ Ê»Â–« —«Õ Ì—Ã⁄ ··ﬁ«∆„… «·—∆Ì”Ì…
			break;
		}
	}

	static void _PrintQueueMenu()
	{
		cout << "\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n"   << setw(42) << left << "" << "[1] Queue Using Dynamic Array.";
		cout << "\n"   << setw(42) << left << "" << "[2] Queue Using Linked List.";
		cout << "\n"   << setw(42) << left << "" << "[3] Smart Queue.";
		cout << "\n"   << setw(42) << left << "" << "[4] Exercises Queue.";
		cout << "\n"   << setw(42) << left << "" << "[5] Main Menue.";
		cout << "\n"   << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowQueueImplementationsScreen()
	{
		system("cls");
		_DrawHeaderScreen("   Queue Implementation");
		_PrintQueueMenu();
		_ExecuteTheSelectedOption((enQueueImplementationOptions)_ReadQueueImplementOption());
	}
};