#pragma once
#include <iostream>
#include "ILinearStructure.h"
#include "StackErrors.h"
using namespace std;

template <typename T>
class SmartStack : public ILinearStructure<T>
{
private:
	int _Top;
	int _Capacity;
	T* Stack;

	void _PushItem(T Item)
	{
		if (IsEmpty())
			Stack = new T[_Capacity];

		else if (IsFull())
			_StackExpansion();
	}

	T _FindItem(T Item)const 
	{
		for (short i = _Top; i >= 0; i--)
		{
			if (Stack[i] == Item)
				return Item;
		}
		return T();
	}	
	
	void _CopyToNewArray(T* StackOld)
	{
		for (short i = 0; i <= _Top; i++)
			Stack[i] = StackOld[i];
	}
	
	void _DeleteTempSpace(T* StackOld)
	{
		delete[] StackOld;
		StackOld = nullptr;
	}
	
	void _StackExpansion()
	{
		T* Temp = Stack;
		_Capacity *= 2;
		Stack = new T[_Capacity];
		_CopyToNewArray(Temp);
		_DeleteTempSpace(Temp);
	}
	
	void _StackReduction()
	{
		T* Temp = Stack;
		Stack = new T[_Capacity];
		_Top--;

		_CopyToNewArray(Temp);
		_DeleteTempSpace(Temp);
	}
	
	bool _ReferencesEquals(SmartStack<T>& Other)
	{
		if (this != &Other)
		{
			if (this->Stack != nullptr)
			{
				delete[] Stack; 
				Stack = nullptr;
			}
			return true;
		}
		return false;
	}
public:

	SmartStack() :_Top(-1), _Capacity(3), Stack(nullptr) {}

	SmartStack(int Size) : _Top(-1), _Capacity(Size), Stack(new T[Size]) {}

	// Copy Constructor (Deep Copy)
	SmartStack(const SmartStack<T>& Other) :_Top(-1), _Capacity(3), Stack(nullptr)
	{
		for (short Top = Other._Top; Top >= 0; Top--)
			Push(Other.Stack[Top]);
	}

	// Assignment Operator (Deep Copy)
	SmartStack&	operator= (SmartStack<T>& Other)
	{
		if (this->_ReferencesEquals(Other))
		{
			_Top = -1; _Capacity = 3;
			for (short Top = Other._Top; Top >= 0; Top--)
				Push(Other.Stack[Top]);
		}
		return *this;
	}

	int Capacity() { return _Capacity; }

	bool IsFull() { return (_Top == _Capacity - 1); }

	//string Object() const override { return "SmartStack"; }

	bool IsEmpty() const override { return (_Top == -1); }

	bool HasData() { return  !IsEmpty(); }

	int Count() const override { return (IsEmpty() ? 0 : _Top + 1); }

	T Peek() { return (IsEmpty() ? T() : Stack[_Top]); }

	T Search(T Item) const override { return (IsEmpty() ? T() : _FindItem(Item)); }

	void Push(T Item) override
	{
		_PushItem(Item);
		Stack[++_Top] = Item;
	}

	void Pop() override
	{
		(IsEmpty() ? void(cout << StackErrors::UnderFlow << endl) : _StackReduction());
	}

	void Clear() override
	{
		while (!IsEmpty())
			Pop();
	}

	void Display()
	{
		if (IsEmpty())
		{
			cout << StackErrors::UnderFlow;
			return;
		}

		for (short i = _Top; i >= 0; i--)
			cout << Stack[i] << " ";
	}

	void Reverse()
	{
		T* Temp = new T[_Capacity];

		for (short i = 0; i <= _Top; i++)
			Temp[i] = Stack[_Top - i];

		delete[] Stack;
		Stack = nullptr;
		Stack = Temp;
	}

	void SwapWith(SmartStack<T>& OtherStack)
	{
		SmartStack<T> TempStack = *this;
		*this = OtherStack;
		OtherStack = TempStack;
		Reverse();

		/*while (!IsEmpty())
		{
			TempStack.Push(Peek());
			Pop();
		}
		while (!OtherStack.IsEmpty())
		{
			this->Push(OtherStack.Peek());
			OtherStack.Pop();
		}
		this->Reverse();

		while (!TempStack.IsEmpty())
		{
			OtherStack.Push(TempStack.Peek());
			TempStack.Pop();
		}*/
	}

	~SmartStack() override
	{
		delete[] this->Stack;
		this->Stack = nullptr;
	}
};