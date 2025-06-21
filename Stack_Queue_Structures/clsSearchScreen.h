#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
using namespace std;

template <typename T>
class clsSearchScreen : protected clsScreen
{
private:
	static string _ReadItem()
	{
		string Item = "";
		cout << "\nPlease Enter Value : ";
		Item = clsInputValidate::ReadString();
		return Item;
	}

	static void _Search(const string& Item, T&Object)
	{
		if (Object.Search(Item) != "")
			cout << "Item Found :-) => " << Item << endl;

		else
			cout << "Item Not Found :-(\n";
	}

	static void _SearchItem(T &Object)
	{
		if (Object.IsEmpty())
			clsUtil::PrintMessage("Empty");
		else
			_Search(_ReadItem(), Object);
	}

public:
	static void ShowSearchScreen(T &Object)
	{
		system("cls");
		_DrawHeaderScreen("\t Search Item");
		_SearchItem(Object);
	}
};

