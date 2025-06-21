#pragma once
#include <iostream>
#include "QueueUsingLinkedList.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "ContantPatients.h"
using namespace std;

class clsSearchPatientsCases
{
public:
	template <typename T> static bool FindPatientCaseByName(T& QueuePatientsInformations, string& PatientName, stPatientInformation &PatientInformation)
	{
		Node<stPatientInformation>* Temp = QueuePatientsInformations.FirstNode();

		while (Temp != nullptr)
		{
			if (Temp->Data.PatientName == PatientName)
			{
				PatientInformation = Temp->Data;
				return true;
			}
			Temp = Temp->Next;
		}
		return false;
	}
};