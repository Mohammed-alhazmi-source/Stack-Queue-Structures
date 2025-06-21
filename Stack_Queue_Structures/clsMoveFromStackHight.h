#pragma once
#include <iostream>
#include "ConstantsCases.h"
#include "Global.h"
using namespace std;

class clsMoveFromStackHight
{
public:
	static void MoveFromStackHightTo(string& OldCaseType, string& NewCaseType)
	{
		if (OldCaseType == NewCaseType)
			return;

		else if (OldCaseType == ConstantsCases::Hight && NewCaseType == ConstantsCases::General)
		{
			Queue_General.Push(Stack_Hight.Peek());
			Stack_Hight.Pop();
		}

		else if (OldCaseType == ConstantsCases::Hight && NewCaseType == ConstantsCases::Simple)
		{
			Stack_Low.Push(Stack_Hight.Peek());
			Stack_Hight.Pop();
		}

		else if (OldCaseType == ConstantsCases::Hight && NewCaseType == ConstantsCases::Medium)
		{
			Stack_Mid.Push(Stack_Hight.Peek());
			Stack_Hight.Pop();
		}
	}
};