#pragma once
#include <iostream>
#include "SmartStack.h"
#include "StackUsingLinkedList.h"
#include "clsValidateData.h"
using namespace std;


class clsConvertFromInfixToPostfix
{
private:
	static bool _IsTopMulOrDiv(const char& CurrentOp, const char& TopOfStackOp)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		if (TopOfStackOp == clsValidateData::enOperators::Multiply || TopOfStackOp == clsValidateData::enOperators::Divide)
		{
			if (CurrentOp == clsValidateData::enOperators::Additional || CurrentOp == clsValidateData::enOperators::Subtract)
				return true;

			return true;
		}
		return false;
	}

	static bool _IsTopAddOrSub(const char& CurrentOp, const char& TopOfStackOp)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		if (TopOfStackOp == clsValidateData::enOperators::Additional || TopOfStackOp == clsValidateData::enOperators::Subtract)
		{
			if (CurrentOp == clsValidateData::enOperators::Multiply || CurrentOp == clsValidateData::enOperators::Divide)
				return false;

			return true;
		}
		return false;
	}

	static bool _HasHigherPrecedence(char CurrentOp, char TopOfStackOp)
	{
		if (CurrentOp == ' ')
			return false;

		return (_IsTopMulOrDiv(CurrentOp, TopOfStackOp) || _IsTopAddOrSub(CurrentOp, TopOfStackOp));
	}	

	static void _PopUntilOpenBracket(string& Postfix, StackUsingLinkedList<char>& stack)
	{
		// Space Complexity O(1) & Time Complexity O(n)
		while (stack.Count())
		{
			if (clsValidateData::_IsOpenBracket(stack.Peek()))
			{
				stack.Pop();
				break;
			}

			if (!clsValidateData::_IsEmptySpace(Postfix[Postfix.length() - 1]))
				Postfix += ' ';

			Postfix += stack.Peek();
			stack.Pop();
		}
	}

	static void _PopWhileHigherOrEqualPrecedence(string& Postfix, StackUsingLinkedList<char>& stack, char CurrentOp)
	{
		// Space Complexity O(1) & Time Complexity O(n)

		int size = stack.Count();
		while (size--)
		{
			if (clsValidateData::_IsOpenBracket(stack.Peek()))
			{
				if (clsValidateData::_IsOperator(CurrentOp))
					stack.Push(CurrentOp);
				break;
			}
			else if (_HasHigherPrecedence(CurrentOp, stack.Peek()))
			{
				if (!clsValidateData::_IsEmptySpace(Postfix[Postfix.length() - 1]))
					Postfix += ' ';

				Postfix += stack.Peek();
				stack.Pop();
			}
		}
		if (stack.IsEmpty())
			stack.Push(CurrentOp);

		else
			stack.Push(CurrentOp);
	}	

public:
	static string GetExpressionPostfix(string& Expression)
	{
		StackUsingLinkedList<char> stack;

		string Postfix = "";
		int Size = 0;

		for (short Counter = 0; Counter < Expression.length(); Counter++)
		{
			/*if (clsValidateData::_IsEmptySpace(Expression[Counter]))
			{
				if (Postfix != "")
				{
					if (!clsValidateData::_IsEmptySpace(Postfix[Postfix.length() - 1]))
						Postfix += Expression[Counter];
				}
			}*/

			if (clsValidateData::_IsBracket(Expression[Counter]))
			{
				if (clsValidateData::_IsOpenBracket(Expression[Counter]))
					stack.Push(Expression[Counter]);

				else if (clsValidateData::_IsCloseBracket(Expression[Counter]))
					_PopUntilOpenBracket(Postfix, stack);
			}

			else if (clsValidateData::_IsOperand(Expression[Counter]))
			{
				Postfix += Expression[Counter];
			}

			else if (_HasHigherPrecedence(Expression[Counter], stack.Peek()))
			{
				_PopWhileHigherOrEqualPrecedence(Postfix, stack, Expression[Counter]);

				if (!clsValidateData::_IsEmptySpace(Postfix[Postfix.length() - 1]))
					Postfix += ' ';
			}

			else if (clsValidateData::_IsOperator(Expression[Counter]))
			{
				stack.Push(Expression[Counter]);
				if (!clsValidateData::_IsEmptySpace(Postfix[Postfix.length() - 1]))
					Postfix += ' ';
			}
		}
		Size = stack.Count();
		while (Size--)
		{
			if (!clsValidateData::_IsEmptySpace(Postfix[Postfix.length() - 1]))
				Postfix += ' ';

			Postfix += stack.Peek();
			stack.Pop();
		}
		return Postfix;
	}
};