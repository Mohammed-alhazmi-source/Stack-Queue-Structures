#pragma once
#include <iostream>
#include "clsScreen.h"
#include "ContantPatients.h"
#include "Global.h"
#include "clsInputValidate.h"
#include "clsSearchPatientsCases.h"
#include "clsPatientExitHandler.h"
#include "clsUtil.h"

class clsShowDeletePatientCaseScreen : protected clsScreen
{
private:       
    static short _ReadPatientCaseType()
    {
        string Message = "\nPlease Enter PatientCase :\n[1] General, [2] Simple, [3] Medium, [4] Hight ? ";
        return clsInputValidate::ReadNumberBetween(Message, 1, 4);
    }

    template <typename T>
    static void _ExecuteDelete(T& Object)
    {
        if (Object.IsEmpty())
        {
            clsUtil::PrintMessage("Empty");
            return;
        }

        stPatientInformation PatientInformation;
        string PatientName = "";
        string Message = "\nChoose Case To Exit PatientCase :\n[1] General, [2] Simple, [3] Medium, [4] Hight ? ";
        char Answer = ' ';

        do
        {
            PatientName = clsInputValidate::ReadString("\nPlease Enter Patient Name : ");

            if (clsSearchPatientsCases::FindPatientCaseByName(Object, PatientName, PatientInformation))
            {
                clsUtil::PrintPatientCaseCard(PatientInformation);

                Answer = clsUtil::DoYouWantToContinue("\nAre You Sure Exit This Patient Case y/n ? ");
                if (Answer == 'Y' || Answer == 'y')
                {
                    clsPatientExitHandler::PatientExitHandler(PatientInformation);
                    cout << "\nDeleted Successfully...\n";
                }

                Answer = clsUtil::DoYouWantToContinue("\nDo You Want More Execute y/n ? ");
                if (Answer == 'Y' || Answer == 'y')
                {
                    system("cls");
                    _DrawHeaderScreen("\t Delete Patient Case Screen");
                    if (Object.IsEmpty())
                    {
                        clsUtil::PrintMessage("Empty");
                        return;
                    }
                }
            }
            else
            {               
                cout << "\nNot Found The PatientName : ";
                break;
            }

        } while (Answer == 'Y' || Answer == 'y');
    }

    static void _Delete()
    {      
        int PatientCaseType = _ReadPatientCaseType();

        if (PatientCaseType == enPatientCases::General)
            _ExecuteDelete(Queue_General);

        else if (PatientCaseType == enPatientCases::Simple)
            _ExecuteDelete(Stack_Low);

        else if (PatientCaseType == enPatientCases::Medium)
            _ExecuteDelete(Stack_Mid);

        else if (PatientCaseType == enPatientCases::Hight)
            _ExecuteDelete(Stack_Hight);
    }

public:
    static void ShowDeletePatientCaseScreen()
    {
        system("cls");
        _DrawHeaderScreen("\t Delete Patient Case Screen");
        _Delete();
    }
};

