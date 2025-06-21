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
#include "QueueUsingLinkedList.h"
#include "clsUtil.h"
using namespace std;

QueueUsingLinkedList<string> queueLinkedList;

class clsQueueUsingLinkedListScreen : protected clsScreen
{
private:
	enum enQueueOperatorsOptions { eDisplay = 1, ePush = 2, ePop = 3, eShearch = 4, eClear = 5 ,eToBack = 6 };

	static short _ReadQueueOperatorOption()
	{
		return clsUtil::ReadOption(1, 6);
	}

	static void _GoBackToOperationsQueue()
	{
		system("pause");
		ShowQueueImplementUsingLinkedListScreen();
	}

	static void _ShowDisplayScreen()
	{
		clsDisplayScreen<QueueUsingLinkedList<string>>::ShowDisplayScreen(queueLinkedList);
	}

	static void _ShowPushLinkedListScreen()
	{
		clsPushDirectScreen<QueueUsingLinkedList<string>>::ShowPushDirectScreen(queueLinkedList);
	}

	static void _ShowPopScreen()
	{
		clsPopScreen<QueueUsingLinkedList<string>>::ShowPopScreen(queueLinkedList);
	}

	static void _ShowSearchScreen()
	{
		clsSearchScreen<QueueUsingLinkedList<string>>::ShowSearchScreen(queueLinkedList);
	}

	static void _ShowClearScreen()
	{
		clsClearScreen<QueueUsingLinkedList<string>>::ShowClearScreen(queueLinkedList);
	}

	static void _ExecuteTheSelectedOption(enQueueOperatorsOptions QueueOperatorsOption)
	{
		switch (QueueOperatorsOption)
		{
		case clsQueueUsingLinkedListScreen::eDisplay:
		{
			system("cls");
			_ShowDisplayScreen();
			_GoBackToOperationsQueue();
			break;
		}

		case clsQueueUsingLinkedListScreen::ePush:
		{
			system("cls");
			_ShowPushLinkedListScreen();
			_GoBackToOperationsQueue();
			break;
		}

		case clsQueueUsingLinkedListScreen::ePop:
		{
			system("cls");
			_ShowPopScreen();
			_GoBackToOperationsQueue();
			break;
		}

		case clsQueueUsingLinkedListScreen::eShearch:
		{
			system("cls");
			_ShowSearchScreen();
			_GoBackToOperationsQueue();
			break;
		}

		case clsQueueUsingLinkedListScreen::eClear:
		{
			system("cls");
			_ShowClearScreen();
			_GoBackToOperationsQueue();
			break;
		}

		case clsQueueUsingLinkedListScreen::eToBack:
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
	static void ShowQueueImplementUsingLinkedListScreen()
	{
		system("cls");
		_DrawHeaderScreen("Queue Using Linked List");
		_PrintQueueOperationMenu();
		_ExecuteTheSelectedOption((enQueueOperatorsOptions)_ReadQueueOperatorOption());
	}
};

