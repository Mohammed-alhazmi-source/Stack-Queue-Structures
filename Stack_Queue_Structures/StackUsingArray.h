#pragma once
#include <iostream>
#include "ILinearStructure.h"
#include "StackErrors.h"
using namespace std;

template <typename T>
class StackUsingArray : public ILinearStructure<T>
{
private:
	int _Top;
	int _Size;
	T* _Stack;

	void _NewItem(T Item)
	{
		if (IsEmpty())
		{
			_Stack = new T[_Size];
			_Stack[++_Top] = Item;
		}

		else if (IsFull())
			cout << StackErrors::OverFlow << endl;

		else
		{
			_Stack[++_Top] = Item;
		}
	}

	T _FindItem(T Item) const
	{
		for (short Top = _Top; Top >= 0; Top--)
		{
			if (_Stack[Top] == Item)
				return Item;
		}
		return T();
	}

	bool _ReferencesEquals(const StackUsingArray<T>& Other)
	{
		if (this != &Other)
		{
			if (this->_Stack != nullptr)
			{
				delete[] _Stack; 
				_Stack = nullptr;
			}
			return true;
		}
		return false;
	}

public:

	StackUsingArray(int SizeArray) : _Top(-1), _Size(SizeArray), _Stack(new T[SizeArray]) {}

	StackUsingArray(): _Top(-1), _Size(0), _Stack(nullptr) {}

	StackUsingArray(const StackUsingArray<T>& Other) : _Top(-1), _Size(0), _Stack(nullptr)
	{
		_Size = Other._Size;
		for (short Top = Other._Top; Top >= 0; Top--)
			Push(Other._Stack[Top]);
	}

	StackUsingArray& operator=(const StackUsingArray<T>& Other)
	{
		if (this->_ReferencesEquals(Other))
		{
			_Top = -1; _Size = Other._Size;
			for (short Top = Other._Top; Top >= 0; Top--)
				Push(Other._Stack[Top]);
		}
		return *this;
	}

	void SetSize(int Size)
	{
		_Size = Size;
	}
	int Size()
	{
		return _Size;
	}

	bool IsFull() { return (_Top == _Size - 1); }

	//string Object() const override { return "StackUsingArray"; }

	bool IsEmpty() const override { return (_Top == -1); }

	void Push(T Item) override 
	{
		_NewItem(Item);
	}

	void Pop() override { (IsEmpty() ? T() : _Stack[_Top--]); }

	T Peek() { return (IsEmpty() ? T() : _Stack[_Top]); }

	T Search(T Item) const override { return (IsEmpty() ? T() : _FindItem(Item)); }

	int Count() const override { return (IsEmpty() ? 0 : _Top + 1); }

	void Display()
	{
		if (IsEmpty())
		{
			cout << StackErrors::UnderFlow << endl;
			return;
		}

		for (short Top = _Top; Top >= 0; Top--)
			cout << _Stack[Top] << "\n";
	}

	void Clear() override
	{
		while (!IsEmpty())
			Pop();
	}

	void Reverse()
	{
		T* Temp = new T[_Size];

		for (short i = 0; i < _Size; i++)
			Temp[i] = _Stack[_Top - i];

		delete[] _Stack;
		_Stack = nullptr;
		_Stack = Temp;
	}

	void SwapWith(StackUsingArray<T>& Other)
	{
		StackUsingArray<T> Temp = *this;
		*this = Other;
		Other = Temp;
		Reverse();
	}

	~StackUsingArray() override
	{
		delete[] _Stack;
		_Stack = nullptr;
	}
};