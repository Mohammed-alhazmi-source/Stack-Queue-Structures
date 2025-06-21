#pragma once
#include <iostream>
#include "ConstantsCases.h"
#include "Global.h"
using namespace std;

class clsMoveFromStackMedium
{
public:
	static void MoveFromStackMediumTo(string& OldCaseType, string& NewCaseType)
	{
		if (OldCaseType == NewCaseType)
			return;

		else if (OldCaseType == ConstantsCases::Medium && NewCaseType == ConstantsCases::General)
		{
			Queue_General.Push(Stack_Mid.Peek());
			Stack_Mid.Pop();
		}

		else if (OldCaseType == ConstantsCases::Medium && NewCaseType == ConstantsCases::Simple)
		{
			Stack_Low.Push(Stack_Mid.Peek());
			Stack_Mid.Pop();
		}
		else if (OldCaseType == ConstantsCases::Medium && NewCaseType == ConstantsCases::Hight)
		{
			Stack_Hight.Push(Stack_Mid.Peek());
			Stack_Mid.Pop();
		}
	}
};