#pragma once
#include <iostream>
#include "SmartStack.h"
#include "StackUsingLinkedList.h"
#include <string>
#include "clsConvertFromInfixToPostfix.h"
#include "clsValidateData.h"
using namespace std;

class clsEvaluatePostfixExpression
{
private:

	template <typename T> static T Revers(T& StackOther)
	{
		T NewStack;

		while (!StackOther.IsEmpty())
		{
			NewStack.Push(StackOther.Peek());
			StackOther.Pop();
		}
		return NewStack;
	}

	static float CalculatorOperations(float Value1, float Value2, clsValidateData::enOperators Operator)
	{
		switch (Operator)
		{
		case clsValidateData::Additional:	return (Value1 + Value2);
		case clsValidateData::Subtract:		return (Value1 - Value2);
		case clsValidateData::Multiply:		return (Value1 * Value2);
		case clsValidateData::Divide:	    return (Value1 / Value2);
		}
	}

public:
	static float GetEvaluatePostfixExpression(string Postfix)
	{
		StackUsingLinkedList<float> operands;
		float FirstOperand = 0, SecondOperand = 0;

		string Value = "";

		for (short i = 0; i < Postfix.length(); i++)
		{
			if (clsValidateData::_IsOperator(Postfix[i]))
			{
				SecondOperand = operands.Peek();
				operands.Pop();
				FirstOperand = operands.Peek();
				operands.Pop();
				operands.Push(CalculatorOperations(FirstOperand, SecondOperand, clsValidateData::enOperators(Postfix[i])));
			}

			else if (!clsValidateData::_IsEmptySpace(Postfix[i]))
				Value += Postfix[i];

			else if (Value != "")
			{
				if (clsValidateData::_IsEmptySpace(Postfix[i]))
				{
					operands.Push(stof(Value));
					Value = "";
				}
			}
		}

		float Result = operands.Peek();
		operands.Pop();
		return Result;

		//if (operands.Count() == 1)
		//{
		//	float Result =  operands.Peek();
		//	operands.Pop();
		//	return Result;
		//}

		//return 0;
	}
};