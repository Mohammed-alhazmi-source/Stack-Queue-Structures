#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include <string>
#include "clsDisplayScreen.h"
#include "clsPopScreen.h"
#include "clsPushDirectScreen.h"
#include "clsSearchScreen.h"
#include "clsClearScreen.h"
#include "SmartStack.h"
#include "clsUtil.h"
using namespace std;

SmartStack<string> smartStack;

class clsStackUsingSmartStackScreen : protected clsScreen
{
private:
	enum enStackOperatorsOptions { eDisplay = 1, ePush = 2, ePop = 3, eShearch = 4, eClear = 5, eToBack = 6 };

	static short _ReadStackOperatorOption()
	{
		return clsUtil::ReadOption(1, 6);
	}

	static void _GoBackToOperationsStackUsingSmartStackMenu()
	{
		system("pause");
		ShowStackImplementUsingSmartStackScreen();
	}

	static void _ShowDisplayScreen()
	{
		clsDisplayScreen<SmartStack<string>>::ShowDisplayScreen(smartStack);
	}

	static void _ShowPushScreen()
	{
		clsPushDirectScreen<SmartStack<string>>::ShowPushDirectScreen(smartStack);
	}

	static void _ShowPopScreen()
	{
		clsPopScreen<SmartStack<string>>::ShowPopScreen(smartStack);
	}

	static void _ShowSearchScreen()
	{
		clsSearchScreen<SmartStack<string>>::ShowSearchScreen(smartStack);
	}

	static void _ShowClearScreen()
	{
		clsClearScreen<SmartStack<string>>::ShowClearScreen(smartStack);
	}

	static void _ExecuteTheSelectedOption(enStackOperatorsOptions StackOperatorsOption)
	{
		switch (StackOperatorsOption)
		{
		case clsStackUsingSmartStackScreen::eDisplay:
		{
			system("cls");
			_ShowDisplayScreen();
			_GoBackToOperationsStackUsingSmartStackMenu();
			break;
		}

		case clsStackUsingSmartStackScreen::ePush:
		{
			system("cls");
			_ShowPushScreen();
			_GoBackToOperationsStackUsingSmartStackMenu();
			break;
		}

		case clsStackUsingSmartStackScreen::ePop:
		{
			system("cls");
			_ShowPopScreen();
			_GoBackToOperationsStackUsingSmartStackMenu();
			break;
		}

		case clsStackUsingSmartStackScreen::eShearch:
		{
			system("cls");
			_ShowSearchScreen();
			_GoBackToOperationsStackUsingSmartStackMenu();
			break;
		}

		case clsStackUsingSmartStackScreen::eClear:
		{
			system("cls");
			_ShowClearScreen();
			_GoBackToOperationsStackUsingSmartStackMenu();
			break;
		}

		case clsStackUsingSmartStackScreen::eToBack:
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
	static void ShowStackImplementUsingSmartStackScreen()
	{
		system("cls");
		_DrawHeaderScreen("Stack Using Smart Stack");
		_PrintStackOperationMenu();
		_ExecuteTheSelectedOption((enStackOperatorsOptions)_ReadStackOperatorOption());
	}
};
