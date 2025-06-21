#pragma once
#include <iostream>
#include "ConstantsCases.h"
#include "clsMoveFromQueueGeneral.h"
#include "clsMoveFromStackSimple.h"
#include "clsMoveFromStackMedium.h"
#include "clsMoveFromStackHight.h"
using namespace std;

class clsMovePatient
{
private:
	static void _Move(string& OldCaseType, string& NewCaseType)
	{		

		if (OldCaseType == ConstantsCases::General)
			clsMoveFromQueueGeneral::MoveFromQueueGeneralTo(OldCaseType, NewCaseType);

		else if (OldCaseType == ConstantsCases::Simple)
			clsMoveFromStackSimple::MoveFromStackSimpleTo(OldCaseType, NewCaseType);

		else if (OldCaseType == ConstantsCases::Medium)
			clsMoveFromStackMedium::MoveFromStackMediumTo(OldCaseType, NewCaseType);

		else if (OldCaseType == ConstantsCases::Hight)
			clsMoveFromStackHight::MoveFromStackHightTo(OldCaseType, NewCaseType);
	}

public:
	static void MoveTo(string& OldCaseType, string& NewCaseType)
	{
		_Move(OldCaseType, NewCaseType);
	}
};