#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBalancedParentheses.h"
#include "clsInputValidate.h"
using namespace std;

class clsExerciseBalancedParenthesesScreen : protected clsScreen
{
private:
	static string _ReadExpression()
	{
		string Expression = "";
		cout << "\n\n\nPlease Enter Expression : ";
		Expression = clsInputValidate::ReadString();
		return Expression;
	}

	static void _ExecuteCheckOfTruthExpression(const string &Expression)
	{
		if (clsBalancedParentheses::IsBalanced(Expression))
			cout << "\nExpression Is Truth :-)\n";
		else
			cout << "\nExpression Is Not Truth :-(\n";
	}


public:
	static void ShowExerciseBalancedParenthesesScreen()
	{
		system("cls");
		_DrawHeaderScreen("Exercise Balanced Parentheses Screen");
		_ExecuteCheckOfTruthExpression(_ReadExpression());
	}
};

