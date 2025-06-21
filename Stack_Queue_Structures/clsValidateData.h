#pragma once
class clsValidateData
{
public:
	enum enSpaces { Space = ' ' };
	enum enOperands { Zero = '0', Nine = '9' };
	enum enOperators { Additional = '+', Subtract = '-', Multiply = '*', Divide = '/' };
	enum enCharacters { A = 65, Z = 90, a = 97, z = 122 };
	enum enBrackets
	{
		OpenParenthesis = '(', CloseParenthesis = ')',
		OpenSquareBracket = '[', CloseSquareBracket = ']',
		OpenCurlyBrace = '{', CloseCurlyBrace = '}'
	};

	static bool  _IsEmptySpace(char Space)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		return (Space == clsValidateData::enSpaces::Space);
	}

	static bool _IsDigit(char Digit)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		return (Digit >= enOperands::Zero && Digit <= enOperands::Nine);
	}

	static bool _IsCharacter(char Character)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		return ((Character >= A && Character <= Z) ? true :
			(Character >= a && Character <= z) ? true : false);
	}

	static bool _IsOperand(char Operand)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		return (_IsDigit(Operand) ? true : _IsCharacter(Operand) ? true : false);
	}

	static bool _IsOperator(char Operator)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		return (Operator >= enOperators::Multiply) && (Operator <= enOperators::Divide);
	}

	static bool _IsCloseBracket(char Bracket)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		return (Bracket == CloseParenthesis || Bracket == CloseSquareBracket || Bracket == CloseCurlyBrace);
	}

	static bool _IsBracket(char Bracket)
	{
		return (_IsOpenBracket(Bracket) || _IsCloseBracket(Bracket));
	}

	static bool _IsOpenBracket(char Bracket)
	{
		// Space Complexity O(1) & Time Complexity O(1)
		return (Bracket == OpenParenthesis || Bracket == OpenSquareBracket || Bracket == OpenCurlyBrace);
	}
};

