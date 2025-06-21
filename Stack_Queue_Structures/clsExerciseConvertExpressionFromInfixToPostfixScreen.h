#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsConvertFromInfixToPostfix.h"
#include "clsEvaluatePostfixExpression.h"
#include "clsBalancedParentheses.h"

class clsExerciseConvertExpressionFromInfixToPostfixScreen : protected clsScreen
{
private:
	static string _ReadExpression()
	{
		string Expression = "";
		cout << "\n\n\nPlease Enter Expression : ";
		Expression = clsInputValidate::ReadString();
		return Expression;
	}

	static void _PrintExpressionAfterConverted(const string&& Expression)
	{
		cout << "\nPostfix : " << Expression << endl;
	}

	static void _ExecuteConvertExpressionAndEvaluateExpression()
	{
		string Expression = _ReadExpression();
		//Expression = _PaperExpression(Expression);

		if (clsBalancedParentheses::IsBalanced(Expression))
		{
			_PrintExpressionAfterConverted(clsConvertFromInfixToPostfix::GetExpressionPostfix(Expression));
		}

		else
			cout << "\nError, Correct Expression...\n\n";
	}

public:
	static void ShowExerciseConvertExpressionFromInfixToPostfixScreen()
	{
		system("cls");
		_DrawHeaderScreen("Convert Infix To Postfix Screen");
		_ExecuteConvertExpressionAndEvaluateExpression();
	}
};

