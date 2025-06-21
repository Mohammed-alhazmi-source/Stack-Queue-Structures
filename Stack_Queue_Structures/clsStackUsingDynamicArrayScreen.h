#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "StackUsingArray.h"
#include <string>
#include "clsDisplayScreen.h"
#include "clsPopScreen.h"
#include "clsPushScreen.h"
#include "clsSearchScreen.h"
#include "clsClearScreen.h"
#include "clsUtil.h"
using namespace std;

StackUsingArray<string> stackUsingArray;

class clsStackUsingDynamicArrayScreen : protected clsScreen
{
protected:
	enum enStackOperatorsOptions { eDisplay = 1, ePush = 2, ePop = 3, eShearch = 4, eClear = 5, eToBack = 6 };

	static short _ReadStackOperatorOption()
	{
		return clsUtil::ReadOption(1, 6);
	}

	static void _GoBackToStackUsingDynamicArrayMenu()
	{
		system("pause");
		ShowStackImplementUsingDynamicArrayScreen();
	}

	static void _ShowDisplayScreen()
	{
		clsDisplayScreen<StackUsingArray<string>>::ShowDisplayScreen(stackUsingArray);
	}

	static void _ShowPushScreen()
	{
		clsPushScreen<StackUsingArray<string>>::ShowPushScreen(stackUsingArray);
	}

	static void _ShowPopScreen()
	{
		clsPopScreen<StackUsingArray<string>>::ShowPopScreen(stackUsingArray);
	}

	static void _ShowSearchScreen()
	{
		clsSearchScreen<StackUsingArray<string>>::ShowSearchScreen(stackUsingArray);

	}

	static void _ShowClearScreen()
	{
		clsClearScreen<StackUsingArray<string>>::ShowClearScreen(stackUsingArray);
	}

	static void _ExecuteTheSelectedOption(enStackOperatorsOptions StackOperatorsOption)
	{
		switch (StackOperatorsOption)
		{
		case clsStackUsingDynamicArrayScreen::eDisplay:
		{
			system("cls");
			_ShowDisplayScreen();
			_GoBackToStackUsingDynamicArrayMenu();
			break;
		}

		case clsStackUsingDynamicArrayScreen::ePush:
		{
			system("cls");
			_ShowPushScreen();
			_GoBackToStackUsingDynamicArrayMenu();
			break;
		}

		case clsStackUsingDynamicArrayScreen::ePop:
		{
			system("cls");
			_ShowPopScreen();
			_GoBackToStackUsingDynamicArrayMenu();
			break;
		}

		case clsStackUsingDynamicArrayScreen::eShearch:
		{
			system("cls");
			_ShowSearchScreen();
			_GoBackToStackUsingDynamicArrayMenu();
			break;
		}

		case clsStackUsingDynamicArrayScreen::eClear:
		{
			system("cls");
			_ShowClearScreen();
			_GoBackToStackUsingDynamicArrayMenu();
			break;
		}

		case clsStackUsingDynamicArrayScreen::eToBack:
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
	static void ShowStackImplementUsingDynamicArrayScreen()
	{
		system("cls");
		_DrawHeaderScreen("Stack Using Dynamic Array");
		_PrintStackOperationMenu();
		_ExecuteTheSelectedOption((enStackOperatorsOptions)_ReadStackOperatorOption());
	}
};