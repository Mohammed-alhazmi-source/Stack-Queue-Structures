#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBalancedParentheses.h"
#include "clsConvertFromInfixToPostfix.h"
using namespace std;

class clsExerciseEvaluatePostfixExpressionScreen : protected clsScreen
{
private:
	static string _ReadExpression()
	{
		string Expression = "";
		cout << "\n\n\nPlease Enter Expression : ";
		Expression = clsInputValidate::ReadString();
		return Expression;
	}

	static void _PrintEvaluateExpression(const float&& EvaluateExpression)
	{
		cout << "\nEvaluate Postfix = " << EvaluateExpression << endl;
	}

	static void _ExecuteEvaluateExpression()
	{
		string Expression = _ReadExpression();

		if (clsBalancedParentheses::IsBalanced(Expression))
		{
			Expression = clsConvertFromInfixToPostfix::GetExpressionPostfix(Expression);
			_PrintEvaluateExpression(clsEvaluatePostfixExpression::GetEvaluatePostfixExpression(Expression));
		}

		else
			cout << "\nError, Correct Expression...\n\n";
	}

public:
	static void ShowExerciseEvaluatePostfixExpressionScreen()
	{
		system("cls");
		_DrawHeaderScreen("Evaluate Postfix Expression Screen");
		_ExecuteEvaluateExpression();
	}
};