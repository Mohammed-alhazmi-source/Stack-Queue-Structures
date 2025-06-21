#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "ContantPatients.h"
#include "clsAddPatientsCases.h"
using namespace std;

class clsAddPatientCaseScreen : protected clsScreen
{
private:
	static void _AddPatientCase()
	{
        stPatientInformation PatientInformation;
        char AddMore = 'n';
        string Message = "\nPlease Enter PatientCase :\n[1] General, [2] Simple, [3] Medium, [4] Hight ? ";

        do
        {
            cout << "\n\n\nEnter <0> Exit.\n";

            PatientInformation.PatientName = clsInputValidate::ReadString("\nPlease Enter Patient Name : ");

            if (PatientInformation.PatientName == "0")
                break;

            PatientInformation.PatientCase = (enPatientCases)clsInputValidate::ReadNumberBetween(Message, 1, 4);
            

            clsAddPatientsCases::AddPatientCase(PatientInformation);

            AddMore = clsUtil::DoYouWantToContinue("\nDo You Want To Add More Patient Case ? y/n ? ");

            if (AddMore == 'y' || AddMore == 'Y')
            {
                system("cls");
                _DrawHeaderScreen("\t  Add Patient Case Screen");
            }

        } while (AddMore == 'y' || AddMore == 'Y');        
	}

public:
    static void ShowAddPatientCaseScreen()
    {
        system("cls");
        _DrawHeaderScreen("\t  Add Patient Case Screen");
        _AddPatientCase();
    }
};

