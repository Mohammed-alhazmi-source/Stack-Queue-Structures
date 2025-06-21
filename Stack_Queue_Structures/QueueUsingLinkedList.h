#pragma once
#include <iostream>
#include "ILinearStructure.h"
#include "Node.h"
#include "QueueErrors.h"

using namespace std;

template <typename T>
class QueueUsingLinkedList : public ILinearStructure<T>
{
private:

	Node<T>* _Front;
	Node<T>* _Rear;
	int _CountItems;

	//T _FindItem(T Item) const
	//{
	//	//Node<T>* Temp = _Front;
	//	//while (Temp != nullptr)
	//	//{
	//	//	if (Temp->Data == Item)
	//	//		return Item;

	//	//	Temp = Temp->Next;
	//	//}

	//	return T();
	//}
	
	bool _ReferencesEquals(const QueueUsingLinkedList<T>& Other)
	{
		if (this != &Other)
		{
			if (!IsEmpty())
			{
				delete _Front, _Rear; _Front = _Rear = nullptr;
			}
			return true;
		}
		return false;
	}

protected:
	void _LinkNewNode(Node<T>* NewNode)
	{
		if (IsEmpty())
			_Front = _Rear = NewNode;

		else
		{
			_Rear->Next = NewNode;
			_Rear = NewNode;
		}
	}
	void _DeleteLinkNode(Node<T>* Temp)
	{
		if (_Front->Next == nullptr && _Rear->Next == nullptr)
		{
			delete  Temp;
			_Front = _Rear = Temp = nullptr;
		}

		else
		{
			_Front = _Front->Next;
			delete Temp;
			Temp = nullptr;
		}
	}

public:
	QueueUsingLinkedList() : _Front(nullptr), _Rear(nullptr), _CountItems(0) {}

	QueueUsingLinkedList(const QueueUsingLinkedList<T>& Other) : _Front(nullptr), _Rear(nullptr), _CountItems(0)
	{
		Node<T>* Temp = Other._Front;
		while (Temp != nullptr)
		{
			Push(Temp->Data);
			Temp = Temp->Next;
		}
	}

	QueueUsingLinkedList& operator=(const QueueUsingLinkedList<T>& Other)
	{		
		if (this->_ReferencesEquals(Other))
		{
			_CountItems = 0;
			Node<T>* Temp = Other._Front;
			while (Temp != nullptr)
			{
				Push(Temp->Data);
				Temp = Temp->Next;
			}
		}
		return *this;
	}

	Node<T>* FirstNode()
	{
		return _Front;
	}
	Node<T>* LastNode()
	{
		return _Rear;
	}

	bool IsEmpty() const override { return (_Front == nullptr && _Rear == nullptr); }

	void Push(T Item) override
	{
		Node<T>* NewNode = new Node<T>();
		NewNode->Data = Item;
		_CountItems++;
		_LinkNewNode(NewNode);
	}

	void Pop() override
	{
		if (IsEmpty())
		{
			cout << QueueErrors::QueueEmpty << endl; return;
		}

		Node<T>* Temp = _Front;
		_DeleteLinkNode(Temp);
		_CountItems--;
	}

	T Front() { return (IsEmpty() ? T() : _Front->Data); }

	T Rear() { return (IsEmpty() ? T() : _Rear->Data); }

	int Count() const override { return (IsEmpty() ? 0 : _CountItems); }

	void Clear() override
	{
		while (!IsEmpty())
			Pop();
	}

	T Search(T Item) const override { return (IsEmpty() ? T() : T()); }

	void Display()
	{
		if (IsEmpty())
		{
			cout << QueueErrors::QueueEmpty << endl; return;
		}

		Node<T>* Temp = _Front;
		while (Temp != nullptr)
		{
			cout << Temp->Data << " ";
			Temp = Temp->Next;
		}
	}



	void SwapWith(QueueUsingLinkedList<T>& Other)
	{
		QueueUsingLinkedList<T> Temp = *this;
		*this = Other;
		Other = Temp;
	}

	~QueueUsingLinkedList() override
	{
		Clear(); 
	}
};