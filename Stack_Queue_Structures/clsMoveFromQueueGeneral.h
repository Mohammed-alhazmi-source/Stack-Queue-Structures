#pragma once
#include <iostream>
#include "ConstantsCases.h"
#include "Global.h"
#include "clsRebuildDataStructure.h"
using namespace std;

class clsMoveFromQueueGeneral
{
	
public:
	static void MoveFromQueueGeneralTo(string& OldCaseType, string& NewCaseType)
	{
		if (OldCaseType == NewCaseType)
			return;

		else if (OldCaseType == ConstantsCases::General && NewCaseType == ConstantsCases::Simple)
			clsRebuildDataStructure::RebuildQueue(Queue_General, Stack_Low);

		else if (OldCaseType == ConstantsCases::General && NewCaseType == ConstantsCases::Medium)
			clsRebuildDataStructure::RebuildQueue(Queue_General, Stack_Mid);

		else if (OldCaseType == ConstantsCases::General && NewCaseType == ConstantsCases::Hight)
			clsRebuildDataStructure::RebuildQueue(Queue_General, Stack_Hight);
	}
};