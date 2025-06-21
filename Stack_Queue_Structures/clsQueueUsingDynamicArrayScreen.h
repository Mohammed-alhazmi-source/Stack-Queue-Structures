#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "QueueUsingArray.h"
#include <string>
#include "clsDisplayScreen.h"
#include "clsPopScreen.h"
#include "clsPushScreen.h"
#include "clsSearchScreen.h"
#include "clsClearScreen.h"
#include "clsUtil.h"
using namespace std;

QueueUsingArray<string> queueUsingArray;

class clsQueueUsingDynamicArrayScreen : protected clsScreen
{
private:
	enum enQueueOperatorsOptions { eDisplay = 1, ePush = 2, ePop = 3, eShearch = 4, eClear = 5, eToBack = 6 };

	static short _ReadQueueOperatorOption()
	{
		return clsUtil::ReadOption(1, 6);
	}

	static void _GoBackToQueueUsingDynamicArrayMenu()
	{
		system("pause");
		ShowQueueImplementUsingDynamicArrayScreen();
	}

	static void _ShowDisplayScreen()
	{
		clsDisplayScreen<QueueUsingArray<string>>::ShowDisplayScreen(queueUsingArray);
	}
	
	static void _ShowPushScreen()
	{
		clsPushScreen<QueueUsingArray<string>>::ShowPushScreen(queueUsingArray);
	}
	
	static void _ShowPopScreen()
	{
		clsPopScreen<QueueUsingArray<string>>::ShowPopScreen(queueUsingArray);
	}

	static void _ShowSearchScreen()
	{
		clsSearchScreen<QueueUsingArray<string>>::ShowSearchScreen(queueUsingArray);

	}

	static void _ShowClearScreen()
	{
		clsClearScreen<QueueUsingArray<string>>::ShowClearScreen(queueUsingArray);
	}

	static void _ExecuteTheSelectedOption(enQueueOperatorsOptions QueueOperatorsOption)
	{
		switch (QueueOperatorsOption)
		{
		case clsQueueUsingDynamicArrayScreen::eDisplay:
		{
			system("cls");
			_ShowDisplayScreen();
			_GoBackToQueueUsingDynamicArrayMenu();
			break;
		}

		case clsQueueUsingDynamicArrayScreen::ePush:
		{
			system("cls");
			_ShowPushScreen();
			_GoBackToQueueUsingDynamicArrayMenu();
			break;
		}

		case clsQueueUsingDynamicArrayScreen::ePop:
		{
			system("cls");
			_ShowPopScreen();
			_GoBackToQueueUsingDynamicArrayMenu();
			break;
		}

		case clsQueueUsingDynamicArrayScreen::eShearch:
		{
			system("cls");
			_ShowSearchScreen();
			_GoBackToQueueUsingDynamicArrayMenu();
			break;
		}

		case clsQueueUsingDynamicArrayScreen::eClear:
		{
			system("cls");
			_ShowClearScreen();
			_GoBackToQueueUsingDynamicArrayMenu();
			break;
		}

		case clsQueueUsingDynamicArrayScreen::eToBack:
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
	static void ShowQueueImplementUsingDynamicArrayScreen()
	{
		system("cls");
		_DrawHeaderScreen("Queue Using Dynamic Array");
		_PrintQueueOperationMenu();
		_ExecuteTheSelectedOption((enQueueOperatorsOptions)_ReadQueueOperatorOption());
	}
};