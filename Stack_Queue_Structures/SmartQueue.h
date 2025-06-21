#pragma once
#include <iostream>
#include "ILinearStructure.h"
#include "QueueErrors.h"
using namespace std;

template <typename T> 
class SmartQueue : public ILinearStructure<T>
{
private:
	int _Front, _Rear, _Capacity;
	T* _Queue;

	T _FindValue(T Item) const
	{
		int TempFront = 0;
		while (TempFront <= _Rear)
		{
			if (_Queue[TempFront++] == Item)
				return Item;
		}

		return T();
	}

	void _CopyToNewQueue(T* Temp)
	{
		int TempFront = 0;

		for (short Front = _Front; Front <= _Rear; Front++)
			_Queue[TempFront++] = Temp[Front];
	}

	void _DeleteTempAllocationMemory(T* Temp)
	{
		delete[] Temp;
		Temp = nullptr;
	}
	
	void _QueueExpansion()
	{
		T* Temp = _Queue;
		_Capacity *= 2;
		_Queue = new T[_Capacity];
		_CopyToNewQueue(Temp);
		_DeleteTempAllocationMemory(Temp);
	}

	void _UpdateFrontAndRearAfterReduction()
	{
		if ((_Rear - _Front + 1) == 0)
			_Front = _Rear = -1;

		else
		{
			_Front = 0;
			_Rear--;
		}
	}

	void _QueueReduction()
	{
		T* Temp = _Queue;
		_Queue = new T[_Capacity];
		
		++_Front;
		if (_Front <= _Rear)
			_CopyToNewQueue(Temp);

		_DeleteTempAllocationMemory(Temp);

		_UpdateFrontAndRearAfterReduction();
	}

	void _InitializtionOrExpansionQueue()
	{
		if (IsEmpty())
		{
			_Front = 0;			
			_Queue = new T[_Capacity];
		}

		else if (IsFull())
			_QueueExpansion();
	}

	void _DeleteQueueAllocationMemory()
	{
		delete[] _Queue;
		_Queue = nullptr;
		_Front = _Rear = -1;
		_Capacity = 0;
	}

	bool _ReferencesEquals(const SmartQueue<T>& Other)
	{
		if (this != &Other)
		{
			if (this->_Queue != nullptr)
			{
				delete[] _Queue; _Queue = nullptr;
			}
			return true;
		}
		return false;
	}

public:

	SmartQueue() : _Front(-1), _Rear(-1), _Capacity(3), _Queue(nullptr) {}

	SmartQueue(const SmartQueue<T>& Other):_Front(-1), _Rear(-1), _Capacity(3), _Queue(nullptr)
	{
		for (short Front = Other._Front; Front <= Other._Rear; Front++)
			Push(Other._Queue[Front]);
	}

	SmartQueue & operator =(const SmartQueue<T>& Other)
	{
		if(this->_ReferencesEquals(Other))
		{
			_Front = _Rear = -1;
			for (short Front = Other._Front; Front <= Other._Rear; Front++)
				Push(Other._Queue[Front]);
		}
		return *this;
	}

	bool IsFull() const { return (_Rear == _Capacity - 1); }

	//string Object() const override { return "SmartQueue"; }

	bool IsEmpty() const override { return (_Front == -1 && _Rear == -1); };

	int Count() const override { return (IsEmpty() ? 0 : _Rear - _Front + 1); }

	void Push(T Item) override 
	{		
		_InitializtionOrExpansionQueue();
		_Queue[++_Rear] = Item;
	}

	void Pop() override
	{
		(IsEmpty() ? void(cout << QueueErrors::QueueEmpty << endl) : _QueueReduction());
	};
	
	T Search(T Item) const override { return (IsEmpty() ? T() : _FindValue(Item)); }

	void Clear() override
	{
		if (IsEmpty())
			return;

		_DeleteQueueAllocationMemory();
	}

	void Display()
	{
		if (IsEmpty())
		{
			cout << QueueErrors::QueueEmpty << endl; return;
		}

		for (short Front = _Front; Front <= _Rear; Front++)
			cout << _Queue[Front] << " ";
	}	

	void SwapWith(SmartQueue<T>& Other)
	{
		SmartQueue<T> Temp = *this;
		*this = Other;
		Other = Temp;
	}

	~SmartQueue() { Clear(); }
};