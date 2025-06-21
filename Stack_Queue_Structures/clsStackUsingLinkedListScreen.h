#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <string>
#include "clsPopScreen.h"
#include "clsDisplayScreen.h"
#include "clsSearchScreen.h"
#include "clsClearScreen.h"
#include "clsPushDirectScreen.h"
#include "StackUsingLinkedList.h"
#include "clsUtil.h"
using namespace std;

StackUsingLinkedList<string> stackLinkedList;

class clsStackUsingLinkedListScreen : protected clsScreen
{
private:
	enum enStackOperatorsOptions { eDisplay = 1, ePush = 2, ePop = 3, eShearch = 4, eClear = 5, eToBack = 6 };

	static short _ReadStackOperatorOption()
	{
		return clsUtil::ReadOption(1, 6);
	}

	static void _GoBackToOperationsStack()
	{
		system("pause");
		ShowStackImplementUsingLinkedListScreen();
	}

	static void _ShowDisplayScreen()
	{
		clsDisplayScreen<StackUsingLinkedList<string>>::ShowDisplayScreen(stackLinkedList);
	}

	static void _ShowPushLinkedListScreen()
	{
		clsPushDirectScreen<StackUsingLinkedList<string>>::ShowPushDirectScreen(stackLinkedList);
	}

	static void _ShowPopScreen()
	{
		clsPopScreen<StackUsingLinkedList<string>>::ShowPopScreen(stackLinkedList);
	}

	static void _ShowSearchScreen()
	{
		clsSearchScreen<StackUsingLinkedList<string>>::ShowSearchScreen(stackLinkedList);
	}

	static void _ShowClearScreen()
	{
		clsClearScreen<StackUsingLinkedList<string>>::ShowClearScreen(stackLinkedList);
	}

	static void _ExecuteTheSelectedOption(enStackOperatorsOptions StackOperatorsOption)
	{
		switch (StackOperatorsOption)
		{
		case clsStackUsingLinkedListScreen::eDisplay:
		{
			system("cls");
			_ShowDisplayScreen();
			_GoBackToOperationsStack();
			break;
		}

		case clsStackUsingLinkedListScreen::ePush:
		{
			system("cls");
			_ShowPushLinkedListScreen();
			_GoBackToOperationsStack();
			break;
		}

		case clsStackUsingLinkedListScreen::ePop:
		{
			system("cls");
			_ShowPopScreen();
			_GoBackToOperationsStack();
			break;
		}

		case clsStackUsingLinkedListScreen::eShearch:
		{
			system("cls");
			_ShowSearchScreen();
			_GoBackToOperationsStack();
			break;
		}

		case clsStackUsingLinkedListScreen::eClear:
		{
			system("cls");
			_ShowClearScreen();
			_GoBackToOperationsStack();
			break;
		}

		case clsStackUsingLinkedListScreen::eToBack:
			// Â‰« ·« ‰” œ⁄Ì „—… «Œ—Ï œ«·… ﬁ«∆„…  ÿ»Ìﬁ«  «·ÿ«»Ê— ·«‰Â „‰ Â‰«
			//  —«Õ Ì—ÊÕ «·Ï «·„ﬂ«‰ «·„” œ⁄Ï ÊÌﬂ„· „«»⁄œÂ Ê»Â–« —«Õ Ì—Ã⁄ ·ﬁ«∆„…  ÿ»Ìﬁ«  «·ÿ«»Ê—
			break;
		}
	}

	static void _PrintStackOperationMenu()
	{
		clsUtil::PrintMenu();
	}

public:
	static void ShowStackImplementUsingLinkedListScreen()
	{
		system("cls");
		_DrawHeaderScreen("Stack Using Linked List");
		_PrintStackOperationMenu();
		_ExecuteTheSelectedOption((enStackOperatorsOptions)_ReadStackOperatorOption());
	}
};

