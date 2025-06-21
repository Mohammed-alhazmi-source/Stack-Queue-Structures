#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "QueueErrors.h"
#include "clsInputValidate.h"
using namespace std;
template <typename T>
class clsPushDirectScreen : protected clsScreen
{
private:
	static void _ReadValue(T& Object)
	{
		short ItemsCount = 0;
		string Item = "";
	
		cout << "\n\nExit [0].\n";
		while(true)
		{
			cout << "\nEnter Item " << ++ItemsCount << " : ";
			Item = clsInputValidate::ReadString();

			if (Item == "0")
				break;

			Object.Push(Item);
		}
	}

	static void _PushItem(T& Object)
	{
		_ReadValue(Object);
	}

	static void _PushItems(T& Object)
	{
		_PushItem(Object);
	}

public:
	static void ShowPushDirectScreen(T& Object)
	{
		system("cls");
		_DrawHeaderScreen("\t Push Screen");
		_PushItems(Object);
	}
};


