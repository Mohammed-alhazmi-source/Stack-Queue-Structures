#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsUndoAndRedo.h"
using namespace std;

class Print
{
public:
	static void _ExecutePrintValues(const clsUndoAndRedo<string>& Undo_Redo, string StackName = "Undo")
	{
		if (StackName == "Undo" || StackName == "undo")
			Undo_Redo.UndoStack().Display();

		else if (StackName == "Redo" || StackName == "redo")
			Undo_Redo.RedoStack().Display();
	}

	static void _PrintValues(const clsUndoAndRedo<string>& Undo_Redo)
	{
		cout << "\nUndo["; _ExecutePrintValues(Undo_Redo); cout << "]";
		cout << "\nRedo["; _ExecutePrintValues(Undo_Redo, "Redo"); cout << "]\n";
	}

};

class ClearUndoAndRedo
{
public:
	static void Clear(clsUndoAndRedo<string>& Undo_Redo)
	{
		char Answer = clsUtil::DoYouWantToContinue("\nDo You Want Execute Clear Undo And Redo? y/n? ");
		if (Answer == 'Y' || Answer == 'y')
		{
			Undo_Redo.Clear();
			Print::_PrintValues(Undo_Redo);
		}
	}
};

class clsExerciseUndoAndRedoScreen : protected clsScreen
{
private:
	static void _ExecuteProcessUndo(clsUndoAndRedo<string>& Undo)
	{
		while (!Undo.IsEmptyUndoStack())
		{
			char Answer = clsUtil::DoYouWantToContinue("\nDo You Want Execute Process Undo? y/n? ");

			if (Answer == 'Y' || Answer == 'y')
			{
				Undo.Undo();
				Print::_PrintValues(Undo);
			}
			else
			{
				Print::_PrintValues(Undo);
				break;
			}
		}
	}

	static void _ExecuteProcessRedo(clsUndoAndRedo<string>& Redo)
	{
		while (!Redo.IsEmptyRedoStack())
		{
			char Answer = clsUtil::DoYouWantToContinue("\nDo You Want Execute Process Redo? y/n? ");
			if (Answer == 'Y' || Answer == 'y')
			{
				Redo.Redo();
				Print::_PrintValues(Redo);
			}
			else
			{
				Print::_PrintValues(Redo);
				break;
			}
		}
	}

	static void _ExecuteProcessUndoAndRedo()
	{
		clsUndoAndRedo<string> Undo_Redo;		
		cout << "\n\nExit[0].\n";
				
		do
		{	
			cout << "\n\nPlease Enter Value : ";
			string Value = clsInputValidate::ReadString();


			if (Value == "0")
				break;

			Undo_Redo.Add(Value);
			_ExecuteProcessUndo(Undo_Redo);
			_ExecuteProcessRedo(Undo_Redo);

			if (!Undo_Redo.IsEmptyUndoStack() && !Undo_Redo.IsEmptyRedoStack())
			{
				ClearUndoAndRedo::Clear(Undo_Redo);
				//return;
			}
		} while (true);
	}

public:
	static void ShowShowExerciseUndoAndRedoScreen()
	{
		system("cls");
		_DrawHeaderScreen("Exercise Undo/Redo Screen");
		_ExecuteProcessUndoAndRedo();
	}
};