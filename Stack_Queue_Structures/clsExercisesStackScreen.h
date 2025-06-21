#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsExerciseConvertExpressionFromInfixToPostfixScreen.h"
#include "clsExerciseEvaluatePostfixExpressionScreen.h"
#include "clsExerciseBalancedParenthesesScreen.h"
#include "clsExerciseUndoAndRedoScreen.h"
using namespace std;

class clsExercisesStackScreen : protected clsScreen
{
private:
	enum enExercisesMenuOptions
	{
		ExerciseConvertExpressionFromInfixToPostfix = 1, ExerciseEvaluatePostfixExpression = 2,
		ExerciseBalancedParentheses = 3, ExerciseUndoAndRedo = 4, Back = 5
	};

	static short _ReadExercisesMenuOption()
	{
		return clsUtil::ReadOption(1, 5);
	}

	static void _ShowExerciseConvertExpressionFromInfixToPostfixScreen()
	{
		clsExerciseConvertExpressionFromInfixToPostfixScreen::ShowExerciseConvertExpressionFromInfixToPostfixScreen();
	}

	static void _ShowExerciseEvaluatePostfixExpressionScreen()
	{
		clsExerciseEvaluatePostfixExpressionScreen::ShowExerciseEvaluatePostfixExpressionScreen();
	}

	static void _ShowExerciseBalancedParenthesesScreen()
	{
		clsExerciseBalancedParenthesesScreen::ShowExerciseBalancedParenthesesScreen();
	}

	static void _ShowExerciseUndoAndRedoScreen()
	{
		clsExerciseUndoAndRedoScreen::ShowShowExerciseUndoAndRedoScreen();
	}

	static void _GoBackToExercisesMenu()
	{
		system("pause");
		ShowExercisesStackScreen();
	}

	static void _ExecuteTheSelectedOption(enExercisesMenuOptions ExerciseOption)
	{
		switch (ExerciseOption)
		{
		case clsExercisesStackScreen::ExerciseConvertExpressionFromInfixToPostfix:
		{
			system("cls");
			_ShowExerciseConvertExpressionFromInfixToPostfixScreen();
			_GoBackToExercisesMenu();
			break;
		}
		case clsExercisesStackScreen::ExerciseEvaluatePostfixExpression:
		{
			system("cls");
			_ShowExerciseEvaluatePostfixExpressionScreen();
			_GoBackToExercisesMenu();
			break;
		}
		case clsExercisesStackScreen::ExerciseBalancedParentheses:
		{
			system("cls");
			_ShowExerciseBalancedParenthesesScreen();
			_GoBackToExercisesMenu();
			break;
		}
		case clsExercisesStackScreen::ExerciseUndoAndRedo:
		{
			system("cls");
			_ShowExerciseUndoAndRedoScreen();
			_GoBackToExercisesMenu();
			break;
		}
		case clsExercisesStackScreen::Back:
		{
			break;
		}
		}
	}

	static void _PrintExercisesStackMenu()
	{
		cout << "\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n"   << setw(42) << left << "" << "[1] Convert Infix To Postfix.";
		cout << "\n"   << setw(42) << left << "" << "[2] Evaluate Postfix.";
		cout << "\n"   << setw(42) << left << "" << "[3] Balanced Parentheses.";
		cout << "\n"   << setw(42) << left << "" << "[4] Undo/Redo.";
		cout << "\n"   << setw(42) << left << "" << "[5] Back.";
		cout << "\n"   << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowExercisesStackScreen()
	{
		system("cls");
		_DrawHeaderScreen("\tExercises Stack");
		_PrintExercisesStackMenu();
		_ExecuteTheSelectedOption((enExercisesMenuOptions)_ReadExercisesMenuOption());
	}
};

