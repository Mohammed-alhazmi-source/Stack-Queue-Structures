#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "clsExercisePrinterQueue.h"
#include "clsScreen.h"
using namespace std;

class clsExercisePrinterQueueScreen : protected clsScreen
{
private:
    static void _ReadFileInfo(clsExercisePrinterQueue<stFile> &queue)
    {
        stFile File;
        char Answer = 'n';

        do
        {
            cout << "\nPlease Enter File Name : ";
            getline(cin >> ws, File.Name);
            cout << "Please Enter File Size : ";
            cin >> File.Size;

            queue.Push(File);

            cout << "\nDo you want to start printing the files? y/n : ";
            cin >> Answer;
        } while (Answer != 'Y' && Answer != 'y');        
    }

    static void _LoadingBar(const string &FileName)
    {
        cout << "\nPrinting File : " << FileName << endl;
        for (short i = 0; i <= 100; i += 9)
        {
            cout << "\rProgress " << i + 1 << "%";
            std::this_thread::sleep_for(std::chrono::milliseconds(400));
        }
        cout << "  ...Completed\n";
    }

    static void _PrintingFilesExecution(clsExercisePrinterQueue<stFile> &queue)
    {
        int Count = queue.Count();

        while (Count > 0)
        {
            _LoadingBar(queue.Front().Name);
            queue.PrintFile(queue.Front());
            queue.Pop();
            --Count;
        }
    }

public:
    static void ShowExercisePrinterScreen()
    {
        _DrawHeaderScreen("\tPrinter Queue");
        
        clsExercisePrinterQueue<stFile> queue;
        
        _ReadFileInfo(queue);
        
        system("cls");
        _DrawHeaderScreen("Printer Queue");

        _PrintingFilesExecution(queue);
    }
};