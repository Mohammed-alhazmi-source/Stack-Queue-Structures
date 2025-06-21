#pragma once
#include <iostream>
#include "ContantPatients.h"
using namespace std;

class clsReturnPatientCaseType
{
public:
	static string TextPatientCaseType(enPatientCases PatientCase)
	{
		switch (PatientCase)
		{
		case General:  return "General";
		case Simple:   return "Simple";
		case Medium:   return "Medium";
		case Hight:    return "Hight";
		}
	}
};


class clsPatientCase
{
public:
	static enPatientCases Type(enPatientCases PatientCase)
	{
		switch (PatientCase)
		{
		 case General:  return General;
		 case Simple:   return Simple;
		 case Medium:   return Medium;
		 case Hight:    return Hight;
		}
	}
};
