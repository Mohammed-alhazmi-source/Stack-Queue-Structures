#pragma once
#include <iostream>
#include "QueueUsingLinkedList.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "ContantPatients.h"
#include "clsReturnPatientCaseType.h"
#include "clsMovePatient.h"
using namespace std;

class clsUpdatePatientsCases
{
	template <typename T>
	static bool _Update(T& QueuePatientsInformations, string& PatientName, enPatientCases UpdatePatientCase)
	{
		Node<stPatientInformation>* Temp = QueuePatientsInformations.FirstNode();

		while (Temp != nullptr)
		{
			if (Temp->Data.PatientName == PatientName)
			{
				string OldCaseType = clsReturnPatientCaseType::TextPatientCaseType(Temp->Data.PatientCase);
				string NewCaseType = clsReturnPatientCaseType::TextPatientCaseType(UpdatePatientCase);

				Temp->Data.PatientCase = UpdatePatientCase;
				Temp->Data.MarkedDeleted = true;

				clsMovePatient::MoveTo(OldCaseType, NewCaseType);

				return true;
			}
			Temp = Temp->Next;
		}
		return false;
	}

public:
	template <typename T>
	static bool UpdatePatientCase(T& QueuePatientsInformations, string& PatientName, int PatientCase)
	{
		return _Update(QueuePatientsInformations, PatientName, enPatientCases(PatientCase));
	}
};