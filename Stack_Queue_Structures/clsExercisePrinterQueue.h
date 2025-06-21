#pragma once
#include <iostream>
#include "Node.h"
#include "ILinearStructure.h"
#include "QueueErrors.h"
using namespace std;

struct stFile
{
	string Name;
	int Size;
};

// ���� ����� �������
template <typename T>
class clsExercisePrinterQueue : public ILinearStructure<T>
{
private:
	Node<T>* _Front; // ���� ������ ������� ����� ���
	Node<T>* _Rear; // ���� ������ ������� ������� ���
	int _CountItems; // ���� ���� ������� �������� �� �������

	// ����� ����� ������
	void _LinkNewNode(Node<T> * NewNode, const T &Data)
	{
		NewNode->Data.Name = Data.Name;
		NewNode->Data.Size = Data.Size;

		if (IsEmpty())
			_Front = _Rear = NewNode;

		else
		{
			_Rear->Next = NewNode;
			_Rear = NewNode;
		}
	}

	// ��� ���� 
	void _DeleteLinkNode(Node<T>* Node)
	{
		if (_Front->Next == nullptr)
		{
			delete Node;
			_Front = _Rear = nullptr;
		}

		else
		{
			_Front = _Front->Next;
			delete Node;
		}
	}

	// ��� �� ���� ���� ������ �����
	T _FindData(T Data) const
	{
		Node<T>* Temp = _Front;

		while (Temp != nullptr)
		{
			if (Temp->Data.Name == Data.Name && Temp->Data.Size == Data.Size)
				return Temp->Data;

			Temp = Temp->Next;
		}

		return T();
	}

	// �������� ��� ����� ������ �� ������� 
	bool _ReferencesEquals(const clsExercisePrinterQueue<T>& Other)
	{
		if (this != &Other)
		{
			if (!IsEmpty())
			{
				while (!IsEmpty())
					Pop();
			}
			return true;
		}
		return false;
	}

public:
	// ��������� ������� ������ ����� ������
	clsExercisePrinterQueue() : _Front(nullptr), _Rear(nullptr), _CountItems(0) {}

	// Deep Copy ��������� ���� ����� ���� ��� ���� ���
	clsExercisePrinterQueue(const clsExercisePrinterQueue<T>& Other) : _Front(nullptr), _Rear(nullptr), _CountItems(0)
	{
		Node<T>* Temp = Other._Front;

		while (Temp != nullptr)
		{
			Push(Temp->Data);
			Temp = Temp->Next;
		}
	}

	// ���� �������� ������ ����� ���� ����� �� ��� ��� ���� ��� ����� �� ���
	clsExercisePrinterQueue& operator =(const clsExercisePrinterQueue<T>& Other)
	{
		if (this->_ReferencesEquals(Other))
		{
			_Front = _Rear = nullptr; _CountItems = 0;
			Node<T>* Temp = Other._Front;
			while (Temp != nullptr)
			{
				Push(Temp->Data);
				Temp = Temp->Next;
			}
		}
		return *this;
	}

	// ������ ��� ��� ��� ������� ���� �� ��
	bool IsEmpty() const override
	{
		return (_Front == nullptr && _Rear == nullptr);
	}

	// ����� ������ ���� �������
	void Push(T Data) override
	{
		Node<T>* NewNode = new Node<T>();
		_LinkNewNode(NewNode , Data);
		_CountItems++;
	}

	// ��� ������ ���� �� �������
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

	// ����� ������ ��� ���� �� �������
	T Front() { return (IsEmpty() ? T() : _Front->Data); }

	// ����� ������ ��� ���� �� �������
	T Rear() { return (IsEmpty() ? T() : _Rear->Data); }

	// ����� �� ������ ���� �� �������
	T Search(T Data) const override { return (IsEmpty() ? T() : _FindData(Data)); }

	// ����� ��� ������� �� ����� �� �������
	int Count() const override { return (IsEmpty() ? 0 : _CountItems); }

	// ��� ����� �� ������� �� ��� ������� �������
	void Clear() override
	{
		while (!IsEmpty())
			Pop();
	}

	// ����� ��� ���� 
	void PrintFile(T Data)
	{
		if (IsEmpty()) { cout << QueueErrors::QueueEmpty << endl; return; }

		cout << "\nName : " << Data.Name << ", Size : " << Data.Size << endl;
	}

	// ����� ���� �������
	void PrintFiles()
	{
		Node<T>* Temp = _Front;
		while (Temp != nullptr)
		{
			PrintFile(Temp->Data);
			Temp = Temp->Next;
		}
	}

	// ���� ����� .. ������ ����� ������ �� ������� ��� �������� �� ��������
	~clsExercisePrinterQueue() override
	{
		Clear();
	}
};