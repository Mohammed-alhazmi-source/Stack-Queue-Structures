#pragma once
#include <iostream>
#include "Node.h"
#include "ILinearStructure.h"
#include "StackErrors.h"
using namespace std;


template <typename T>
class StackUsingLinkedList : public ILinearStructure<T>
{
private:
	Node<T>* _Top;
	int _CountItems;

	T _FindItem(T Item) const
	{
		/*Node<T>* Temp = _Top;
		while (Temp != nullptr)
		{
			if (Temp->Data == Item)
				return Item;

			Temp = Temp->Next;
		}*/
		return T();
	}
	
	void _LinkNewNode(Node<T> * NewNode)
	{
		if (IsEmpty())
			_Top = NewNode;

		else
		{
			NewNode->Next = _Top;
			_Top = NewNode;
		}
	}
	void _DeleteLinkNode()
	{
		if (IsEmpty())
			cout << StackErrors::UnderFlow << endl;

		else
		{
			Node<T>* Temp = _Top;
			_Top = _Top->Next;
			delete Temp;
			Temp = nullptr;
		}
	}

	bool _ReferencesEquals(const StackUsingLinkedList<T>& Other)
	{
		if (this != &Other)
		{
			if (this->_Top != nullptr)
			{
				Clear(); _Top = nullptr;
			}

			return true;
		}
		return false;
	}

public:

	StackUsingLinkedList() : _Top(nullptr), _CountItems(0) {}

	StackUsingLinkedList(const StackUsingLinkedList<T>& Other)
	{
		Node <T>* Temp = Other._Top;
		while (Temp != nullptr)
		{
			Push(Temp->Data);
			Temp = Temp->Next;
		}
	}

	StackUsingLinkedList& operator=(const StackUsingLinkedList<T>& Other)
	{
		if (this->_ReferencesEquals(Other))
		{
			Node <T>* Temp = Other._Top;
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
		return _Top;
	}

	//string Object() const override { return "StackUsingLinkedList"; }

	bool IsEmpty() const override
	{
		return (_Top == nullptr);
	}

	void Push(T Item) override
	{
		Node<T>* NewNode = new Node<T>();
		NewNode->Data = Item;
		_CountItems++;
		_LinkNewNode(NewNode);
	}

	void Pop() override
	{
		_DeleteLinkNode();
		_CountItems--;
	}

	T Peek()
	{
		return (IsEmpty() ? T() : _Top->Data);
	}

	int Count() const override
	{
		return (IsEmpty() ? 0 : _CountItems);
	}

	T Search(T Item) const override
	{
		return (IsEmpty() ? T() : _FindItem(Item));
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
			cout << StackErrors::UnderFlow << endl;
			return;
		}

		Node<T>* Temp = _Top;
		while (Temp != nullptr)
		{
			cout << Temp->Data << "\n";
			Temp = Temp->Next;
		}
	}

	void Reverse()
	{
		Node<T>* Top = _Top;
		Node<T>* Temp = Top;

		_Top = nullptr;

		while (Temp != nullptr)
		{
			Push(Temp->Data);
			Temp = Temp->Next;
		}

		delete Top;
		Top = nullptr;
	}

	void SwapWith(StackUsingLinkedList<T>& Other)
	{
		StackUsingLinkedList<T> Temp = *this;
		*this = Other;
		Other = Temp;

		Reverse();
	}

	~StackUsingLinkedList() override
	{
		Clear();
	}
};