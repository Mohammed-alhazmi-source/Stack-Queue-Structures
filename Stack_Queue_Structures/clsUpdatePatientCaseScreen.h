#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "ContantPatients.h"
#include "clsUpdatePatientsCases.h"
#include "clsSearchPatientsCases.h"
#include "clsUtil.h"
using namespace std; 

class clsUpdatePatientCaseScreen : protected clsScreen
{
private:
    static short _ReadPatientCaseType()
    {
        string Message = "\nPlease Enter PatientCase :\n[1] General, [2] Simple, [3] Medium, [4] Hight ? ";
        return clsInputValidate::ReadNumberBetween(Message, 1, 4);
    }

    template <typename T> 
    static void _ExecuteUpdate(T& Object)
    {               
        if (Object.IsEmpty())
        {
            clsUtil::PrintMessage("Empty");
            return;
        }

        stPatientInformation PatientInformation;
        string PatientName = "";
        string Message = "\nChoose Case To Updated PatientCase :\n[1] General, [2] Simple, [3] Medium, [4] Hight ? ";
        char Answer = ' ';

        do
        {
            PatientName = clsInputValidate::ReadString("\nPlease Enter Patient Name : ");

            if (clsSearchPatientsCases::FindPatientCaseByName(Object, PatientName, PatientInformation))
            {
                clsUtil::PrintPatientCaseCard(PatientInformation);

                int UpdateCase = clsInputValidate::ReadNumberBetween(Message, 1, 4);

                Answer = clsUtil::DoYouWantToContinue("\nAre You Sure Update This Patient Case y/n ? ");
                if (Answer == 'Y' || Answer == 'y')
                {
                    clsUpdatePatientsCases::UpdatePatientCase(Object, PatientName, UpdateCase);
                    cout << "\nUpdated Successfully...\n";
                }

                Answer = clsUtil::DoYouWantToContinue("\nDo You Want To Update More y/n ? ");
                if (Answer == 'Y' || Answer == 'y')
                {
                    system("cls");
                    _DrawHeaderScreen("\t Update Patient Case Screen");
                }
            }
            else
            {
                cout << "\nNot Found The PatientName : ";
                break;
            }

        } while (Answer == 'Y' || Answer == 'y');
    }
   
    static void _Update()
    {
        int PatientCaseType = _ReadPatientCaseType();

        if (PatientCaseType == enPatientCases::General)
            _ExecuteUpdate(Queue_General);

        else if (PatientCaseType == enPatientCases::Simple)
            _ExecuteUpdate(Stack_Low);

        else if (PatientCaseType == enPatientCases::Medium)
            _ExecuteUpdate(Stack_Mid);

        else if (PatientCaseType == enPatientCases::Hight)
            _ExecuteUpdate(Stack_Hight);
    }

public:
    static void ShowUpdatePatientCaseScreen()
    {
        system("cls");
        _DrawHeaderScreen("\t Update Patient Case Screen");
        _Update();
    }
};

