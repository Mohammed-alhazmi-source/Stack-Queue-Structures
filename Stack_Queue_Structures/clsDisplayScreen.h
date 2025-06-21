#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"

template <typename T>
class clsDisplayScreen : protected clsScreen
{
private:
	static void _DisplayItems(T &Object)
	{
		if (Object.IsEmpty())
			clsUtil::PrintMessage("Empty");

		else
		{
			cout << "\n\nItems : ";
			Object.Display();
		}
		cout << endl;
	}
public:
	static void ShowDisplayScreen(T &Object)
	{
		system("cls");
		_DrawHeaderScreen("Display Screen");
		_DisplayItems(Object);
	}
};