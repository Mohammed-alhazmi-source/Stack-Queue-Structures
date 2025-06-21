#pragma once
#include <iostream>
#include "clsScreen.h"
#include <thread>
#include <chrono>
#include "clsUtil.h"
#include "Global.h"

class clsShowProcessPatientsCasesScreen : protected clsScreen
{
private:
    static void _LoadingBar(const string& PatientName)
    {
        cout << "\nProcessing A Patient : " << PatientName << endl;
        for (short i = 0; i <= 100; i += 9)
        {
            cout << "\rProgress " << i + 1 << "%";
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
        cout << "  ...Processed\n";
    }

    template <typename T>
    static void _ExecuteProcessing(T& Object,const string &PatientsCasesStructure)
    {
        if (Object.IsEmpty())
            return;

        clsUtil::PrintMessage("   " + PatientsCasesStructure);
        do
        {
            _LoadingBar(Object.FirstNode()->Data.PatientName);
            Object.Pop();

        } while (!Object.IsEmpty());
        system("cls");
        _DrawHeaderScreen("\t Processing Patients Cases Screen");
    }

    static void _Processing()
    {
        _ExecuteProcessing(Stack_Hight, "Patients Cases Hight  Stack");
        _ExecuteProcessing(Stack_Mid, "Patients Cases Medium Stack");
        _ExecuteProcessing(Stack_Low, "Patients Cases Simple Stack");
        _ExecuteProcessing(Queue_General, "Patients Cases General Queue");
        clsUtil::PrintMessage("Processed All Patients Cases....");
    }

public:
    static void ShowProcessPatientsCasesScreen()
    {
        system("cls");
        _DrawHeaderScreen("\tProcessing Patients Cases Screen");
        _Processing();
    }
};