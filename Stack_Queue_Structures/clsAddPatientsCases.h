#pragma once
#include <iostream>
#include "QueueUsingLinkedList.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "ContantPatients.h"
#include "ConstantsCases.h"
#include "clsReturnPatientCaseType.h"
#include "Global.h"

using namespace std;

// „”∆Ê·Ì Â «÷«›… „⁄·Ê„«  «·„—Ì÷ «·Ï «·„ﬂœ” «Ê «·ÿ«»Ê— Õ”» «Ê·ÊÌ… Õ«·… «·„—Ì÷

class clsAddPatientsCases
{
private:
	static void _Add(stPatientInformation& PatientInformation)
	{
		switch (PatientInformation.PatientCase)
		{
		  case General:  Queue_General.Push(PatientInformation); break;
		  case Simple :  Stack_Low.Push(PatientInformation);     break;
		  case Medium :  Stack_Mid.Push(PatientInformation);     break;
		  case Hight  :  Stack_Hight.Push(PatientInformation);   break;
		}		
	}

public:
	static void AddPatientCase(stPatientInformation& PatientInformation)
	{
		_Add(PatientInformation);
	}
};