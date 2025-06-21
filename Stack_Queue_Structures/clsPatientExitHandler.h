#pragma once
#include <iostream>
#include "ContantPatients.h"
#include "Global.h"
#include "clsRebuildDataStructure.h"
using namespace std;

class clsPatientExitHandler
{
private:
	template <typename T>
	static void _SetMarkedDeleted(T& Source, stPatientInformation &PatientInfo)
	{
		Node<stPatientInformation>* SourceTemp = Source.FirstNode();
		while (SourceTemp != nullptr)
		{
			if (
				SourceTemp->Data.PatientName == PatientInfo.PatientName && 
				SourceTemp->Data.PatientCase == PatientInfo.PatientCase
				)
			{
				SourceTemp->Data.MarkedDeleted = true;
			}
			SourceTemp = SourceTemp->Next;
		}
	}

public:
	static void PatientExitHandler(stPatientInformation & PatientInfo)
	{
		switch (PatientInfo.PatientCase)
		{
		  case enPatientCases::General:
		  {
		  	_SetMarkedDeleted(Queue_General, PatientInfo);
		  	clsRebuildDataStructure::RebuildQueue(Queue_General);
		  	break;
		  }
		  
		  case enPatientCases::Simple:
		  {
		  	_SetMarkedDeleted(Stack_Low, PatientInfo);
		  	clsRebuildDataStructure::RebuildStack(Stack_Low);
		  	break;
		  }
		  
		  case enPatientCases::Medium:
		  {
		  	_SetMarkedDeleted(Stack_Mid, PatientInfo);
		  	clsRebuildDataStructure::RebuildStack(Stack_Mid);
		  	break;
		  }
		  
		  case enPatientCases::Hight:
		  {
		  	_SetMarkedDeleted(Stack_Hight, PatientInfo);
		  	clsRebuildDataStructure::RebuildStack(Stack_Hight);
		  	break;
		  }
		}
	}
};