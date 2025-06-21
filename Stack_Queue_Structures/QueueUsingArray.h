#pragma once
#include <iostream>
#include "ILinearStructure.h"
#include "QueueErrors.h"
using namespace std;

template <typename T>
class QueueUsingArray : public ILinearStructure<T>
{
private:
	int _Front, _Rear, _Size;
	T* _QueueArray;

	// ���� ��� �� ���� ����� �� �������
	T _FindItem(T Item) const
	{
		// Space O(1) && Time O(n)
		for (int i = _Front; i <= _Rear; i++)
		{
			if (_QueueArray[i] == Item)
				return Item;
		}
		return T();
	}

	// ���� ����� ���� ����
	void _NewItem(T Item)
	{
		// Space O(1) && Time O(1)
		if (IsEmpty())
		{
			_QueueArray = new T[_Size];
			_Front = _Rear = 0;
			_QueueArray[_Rear] = Item;
		}

		else if (IsFull())
			cout << QueueErrors::QueueFull << endl;
		
		else
			_QueueArray[++_Rear] = Item;
	}

	// ���� ��� ����
	void _DeleteItem()
	{
		// Space O(1) && Time O(1)
		if (IsEmpty())
			cout << QueueErrors::QueueEmpty << endl;

		else if (_Front == _Rear)
			_Front = _Rear = -1;

		else
			++_Front;
	}

	// ���� ������� ����� ������ �� �������
	bool ReferencesEquals(const QueueUsingArray<T>& Other)
	{
		if (this != &Other)
		{
			if (this->_QueueArray != nullptr)
			{
				delete[] _QueueArray; _QueueArray = nullptr;
			}	

			return true;
		}

		return false;
	}

public:
	// properties set , get
	void SetSize(int Size)
	{
		_Size = Size;
	}
	int Size()
	{
		return _Size;
	}

	// Constructor default
	QueueUsingArray(): _Size(0), _Front(-1), _Rear(-1), _QueueArray(nullptr) {}

	// Constructor Parametrized
	QueueUsingArray(int Size): _Size(Size), _Front(-1), _Rear(-1), _QueueArray(new T[_Size]) {}	

	// Deep Copy => Copy Constructor
	QueueUsingArray(const QueueUsingArray<T>& Other): _Size(3), _Front(-1), _Rear(-1), _QueueArray(new T[_Size])
	{	
		for (short Front = Other._Front; Front <= Other._Rear; Front++)
			Push(Other._QueueArray[Front]);
	}

	// (Deep Copy) Copy Assignment Operator
	QueueUsingArray& operator=(const QueueUsingArray<T>& Other)
	{		
		if (this->ReferencesEquals(Other))
		{
			_Front = _Rear = -1;
			_Size = Other._Size;
			_QueueArray = new T[Other._Size];
			for (short Front = Other._Front; Front <= Other._Rear; Front++)
				Push(Other._QueueArray[Front]);
		}

		return *this;
	}

	//string Object() const override { return "QueueUsingArray"; }

	// ���� ������ �� ���� ������� �� ���� �� �� 
	bool IsEmpty() const override
	{
		// Space O(1) && Time O(1)
		return (_Front == -1 && _Rear == -1);
	}

	// ���� ������ �� ���� ������� �� ����� �� ��
	bool IsFull()
	{
		// Space O(1) && Time O(1)
		return (_Rear == _Size - 1);
	}

	// ���� ���� ������ ��� �������
	void Push(T Item) override
	{
		_NewItem(Item);
	}

	// ���� ���� ���� �� �������
	void Pop() override
	{
		_DeleteItem();
	}

	// ����� ��� ���� �� ������� 
	T Front()
	{
		// Space O(1) && Time O(1)
		return (IsEmpty() ? T() : _QueueArray[_Front]);
	}

	// ����� ��� ���� �� �������
	T Rear()
	{
		// Space O(1) && Time O(1)
		return (IsEmpty() ? T() : _QueueArray[_Rear]);
	}

	// ����� ��� ������� �� �������
	int Count() const override
	{
		// Space O(1) && Time O(1)
		return (IsEmpty() ? 0 : _Rear - _Front + 1);
	}

	// ���� ���� �� ���� �� �������
	T Search(T Item) const override
	{
		// Space O(1) && Time O(n)
		return (IsEmpty() ? T() : _FindItem(Item));
	}

	// ���� ���� ����� ������� �������
	void Clear() override
	{
		if (IsEmpty())
		{
			cout << QueueErrors::QueueEmpty << endl;
			return;
		}

		_Front = _Rear = -1;
	}

	// ���� ������ ��� �������
	void Display()
	{
		if (IsEmpty())
		{
			cout << QueueErrors::QueueEmpty << endl;
			return;
		}

		for (short i = _Front; i <= _Rear; i++)
			cout << _QueueArray[i] << " ";

		cout << endl;
	}
	
	void SwapWith(QueueUsingArray<T>& Other)
	{
		QueueUsingArray<T> Temp = *this;
		*this = Other;
		Other = Temp;
	}

	// ����� ����� �������� �� ����� ���� ����� ������ �������
	~QueueUsingArray() override
	{
		delete[] _QueueArray;
		_QueueArray = nullptr;
		_Front = -1;
		_Rear = -1;
	}
};