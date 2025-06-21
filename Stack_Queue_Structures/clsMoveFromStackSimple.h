#pragma once
#include <iostream>
#include "ConstantsCases.h"
#include "Global.h"
using namespace std;

class clsMoveFromStackSimple
{
public:
	static void MoveFromStackSimpleTo(string OldCaseType, string NewCaseType)
	{
		if (OldCaseType == NewCaseType)
			return;

		else if (OldCaseType == ConstantsCases::Simple && NewCaseType == ConstantsCases::General)
		{
			Queue_General.Push(Stack_Low.Peek());
			Stack_Low.Pop();
		}

		else if (OldCaseType == ConstantsCases::Simple && NewCaseType == ConstantsCases::Medium)
		{
			Stack_Mid.Push(Stack_Low.Peek());
			Stack_Low.Pop();
		}
		else if (OldCaseType == ConstantsCases::Simple && NewCaseType == ConstantsCases::Hight)
		{
			Stack_Hight.Push(Stack_Low.Peek());
			Stack_Low.Pop();
		}
	}
};