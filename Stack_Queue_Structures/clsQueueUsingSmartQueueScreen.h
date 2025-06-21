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
#include "SmartQueue.h"
#include "clsUtil.h"
using namespace std;

SmartQueue<string> smartQueue;

class clsQueueUsingSmartQueueScreen : protected clsScreen
{
private:
	enum enQueueOperatorsOptions { eDisplay = 1, ePush = 2, ePop = 3, eShearch = 4, eClear = 5, eToBack = 6 };

	static short _ReadQueueOperatorOption()
	{
		return clsUtil::ReadOption(1, 6);
	}

	static void _GoBackToOperationsQueueUsingSmartQueueMenu()
	{
		system("pause");
		ShowQueueImplementUsingSmartQueueScreen();
	}

	static void _ShowDisplayScreen()
	{
		clsDisplayScreen<SmartQueue<string>>::ShowDisplayScreen(smartQueue);
	}

	static void _ShowPushScreen()
	{
		clsPushDirectScreen<SmartQueue<string>>::ShowPushDirectScreen(smartQueue);
	}

	static void _ShowPopScreen()
	{
		clsPopScreen<SmartQueue<string>>::ShowPopScreen(smartQueue);
	}

	static void _ShowSearchScreen()
	{
		clsSearchScreen<SmartQueue<string>>::ShowSearchScreen(smartQueue);
	}

	static void _ShowClearScreen()
	{
		clsClearScreen<SmartQueue<string>>::ShowClearScreen(smartQueue);
	}

	static void _ExecuteTheSelectedOption(enQueueOperatorsOptions QueueOperatorsOption)
	{
		switch (QueueOperatorsOption)
		{
		case clsQueueUsingSmartQueueScreen::eDisplay:
		{
			system("cls");
			_ShowDisplayScreen();
			_GoBackToOperationsQueueUsingSmartQueueMenu();
			break;
		}

		case clsQueueUsingSmartQueueScreen::ePush:
		{
			system("cls");
			_ShowPushScreen();
			_GoBackToOperationsQueueUsingSmartQueueMenu();
			break;
		}

		case clsQueueUsingSmartQueueScreen::ePop:
		{
			system("cls");
			_ShowPopScreen();
			_GoBackToOperationsQueueUsingSmartQueueMenu();
			break;
		}

		case clsQueueUsingSmartQueueScreen::eShearch:
		{
			system("cls");
			_ShowSearchScreen();
			_GoBackToOperationsQueueUsingSmartQueueMenu();
			break;
		}

		case clsQueueUsingSmartQueueScreen::eClear:
		{
			system("cls");
			_ShowClearScreen();
			_GoBackToOperationsQueueUsingSmartQueueMenu();
			break;
		}

		case clsQueueUsingSmartQueueScreen::eToBack:
			// Â‰« ·« ‰” œ⁄Ì „—… «Œ—Ï œ«·… ﬁ«∆„…  ÿ»Ìﬁ«  «·ÿ«»Ê— ·«‰Â „‰ Â‰«
			//  —«Õ Ì—ÊÕ «·Ï «·„ﬂ«‰ «·„” œ⁄Ï ÊÌﬂ„· „«»⁄œÂ Ê»Â–« —«Õ Ì—Ã⁄ ·ﬁ«∆„…  ÿ»Ìﬁ«  «·ÿ«»Ê—
			break;
		}
	}

	static void _PrintQueueOperationMenu()
	{
		clsUtil::PrintMenu();
	}

public:
	static void ShowQueueImplementUsingSmartQueueScreen()
	{
		system("cls");
		_DrawHeaderScreen("Queue Using Smart Queue");
		_PrintQueueOperationMenu();
		_ExecuteTheSelectedOption((enQueueOperatorsOptions)_ReadQueueOperatorOption());
	}
};
