#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsUtil.h"
using namespace std;

template <typename T>
class clsPopScreen : protected clsScreen
{
private:
	static void _PopItem(T &Object)
	{
		cout << "\nItems : ";
		Object.Display();

		char Answer = clsUtil::DoYouWantToContinue("\nDo You Want To Pop Item Of Queue ? y/n ? ");

		while (Answer == 'Y' || Answer == 'y')
		{			
			Object.Pop();
			cout << "Remaining Items : ";
			Object.Display();

			if (Object.IsEmpty())
				break;

			Answer = clsUtil::DoYouWantToContinue("\nDo You Want To More Pop ? y/n ? ");
		}
		cout << endl;
	}

	static void _PopItems(T &Object)
	{
		if (Object.IsEmpty())
			clsUtil::PrintMessage("Empty");

		else
			_PopItem(Object);
	}

public:
	static void ShowPopScreen(T &Object)
	{
		system("cls");
		_DrawHeaderScreen("\tPop Items");
		_PopItems(Object);
	}
};

