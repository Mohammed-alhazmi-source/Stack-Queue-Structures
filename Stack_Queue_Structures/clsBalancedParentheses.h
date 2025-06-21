#pragma once
#include <iostream>
#include "clsConvertFromInfixToPostfix.h"
#include "SmartStack.h"
#include "clsValidateData.h"

using namespace std;


class clsBalancedParentheses
{
private:
	static bool IsCloseBracketBalancedOpenBracket(char OpenBracket, char CloseBracket)
	{
		return ((OpenBracket == CloseBracket - 1) || (OpenBracket == CloseBracket - 2));
	}

	static bool IsMatchingPair(char OpenBracket, char CloseBracket)
	{
		return IsCloseBracketBalancedOpenBracket(OpenBracket, CloseBracket);
	}

public:

	static bool IsBalanced(string Expression)
	{
		SmartStack<char> stack;

		if (clsValidateData::_IsOperator(Expression[Expression.length() - 1]))
			return false;

		for (short i = 0; i < Expression.length(); i++)
		{
			if (clsValidateData::_IsEmptySpace(Expression[i]))
				continue;

			else if (clsValidateData::_IsOpenBracket(Expression[i]))
				stack.Push(Expression[i]);

			else if (clsValidateData::_IsCloseBracket(Expression[i]))
			{
				if (stack.IsEmpty())
					return false;

				else if (IsMatchingPair(stack.Peek(), Expression[i]))
					stack.Pop();

				else
					return false;
			}
		}

		if (stack.IsEmpty())
			return true;

		return false;
	}
};