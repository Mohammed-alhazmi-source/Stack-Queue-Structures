#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
using namespace std;

template <typename T>
class clsClearScreen : protected clsScreen
{
private:
	static void _Clear(T &Object)
	{
		Object.Clear();
	}

	static void _ClearItems(T &Object)
	{
		if (Object.IsEmpty())
		{
			clsUtil::PrintMessage("Empty");
			return;
		}

		cout << "\n\nItems : ";
		Object.Display();

		char Answer = clsUtil::DoYouWantToContinue("\nAre You Sure Clear Items, y/n ? ");

		if (Answer == 'Y' || Answer == 'y')
		{
			Object.Clear();
			cout << "\nDone...\n";
		}
	}

public:
	static void ShowClearScreen(T &Object)
	{
		system("cls");
		_DrawHeaderScreen("\tClear Screen");
		_ClearItems(Object);
	}
};

