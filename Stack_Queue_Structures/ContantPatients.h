#pragma once
#include <iostream>
using namespace std;

enum enPatientCases { General = 1, Simple = 2, Medium = 3, Hight = 4 };

struct stPatientInformation
{
	string PatientName;
	enPatientCases PatientCase;
	bool MarkedDeleted = false;
};