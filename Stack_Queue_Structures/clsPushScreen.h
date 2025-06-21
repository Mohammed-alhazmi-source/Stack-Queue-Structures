#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;
template <typename T>
class clsPushScreen : protected clsScreen
{
private:	
	static int _ReadSize()
	{
		cout << "\n\nExit[0].\n";

		cout << "\nPlease Enter Size Array : ";
		int Size = clsInputValidate::ReadNumber<int>();

		/*while (Size == 0)
		{
			cout << "\nError Don't Size Zero, Enter Again : ";
			Size = clsInputValidate::ReadNumber<int>();
		}*/
		return Size;
	}

	static void _ReadValue(T &Object)
	{
		short ItemsCount = 0;
		string Item = "";
		int Size = Object.Size();

		if (Size == 0)
			return;

		do
		{
			cout << "\nEnter Item " << ++ItemsCount << " : ";
			Item = clsInputValidate::ReadString();
			Object.Push(Item);
			--Size;
		} while (Size > 0);
	}

	static void _PushItem(T &Object)
	{				
		Object.SetSize(_ReadSize());	
		_ReadValue(Object);
	}

	static void _PushItems(T &Object)
	{
		if (Object.IsEmpty())
			_PushItem(Object);

		else if (Object.IsFull())
			clsUtil::PrintMessage("Full");
	}

public:
	static void ShowPushScreen(T &Object)
	{
		system("cls");
		_DrawHeaderScreen("\t Push Screen");
		_PushItems(Object);
	}
};

