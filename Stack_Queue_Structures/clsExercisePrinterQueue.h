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

// ŞÇáÈ ØÇÈæÑ ÇáØÈÇÚÉ
template <typename T>
class clsExercisePrinterQueue : public ILinearStructure<T>
{
private:
	Node<T>* _Front; // ãÄÔÑ áÈÏÇíÉ ÇáØÇÈæÑ ááÍĞİ ãäå
	Node<T>* _Rear; // ãÄÔÑ áäåÇíÉ ÇáØÇÈæÑ ááÇÖÇİÉ ãäå
	int _CountItems; // ÚÏÇÏ áÚÏÏ ÇáÚäÇÕÑ ÇáãæÌæÏÉ İí ÇáØÇÈæÑ

	// ÊÚííä ÇáŞíã ááÚŞÏÉ
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

	// ÍĞİ ÚŞÏÉ 
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

	// ÈÍË Úä ÚŞÏÉ ÊÍãá ÈíÇäÇÊ ãÚíäÉ
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

	// ÇáãŞÇÑäÉ Èíä ÇãÇßä ßÇÆäíä İí ÇáĞÇßÑÉ 
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
	// ßæäÓÊÑßÊÑ ÇİÊÑÇÖí áÊåíÆÉ ÇÚÖÇÁ ÇáßáÇÓ
	clsExercisePrinterQueue() : _Front(nullptr), _Rear(nullptr), _CountItems(0) {}

	// Deep Copy ßæäÓÊÑßÊÑ áäÓÎ ãÍÊæì ßÇÆä Çáì ßÇÆä ÇÎÑ
	clsExercisePrinterQueue(const clsExercisePrinterQueue<T>& Other) : _Front(nullptr), _Rear(nullptr), _CountItems(0)
	{
		Node<T>* Temp = Other._Front;

		while (Temp != nullptr)
		{
			Push(Temp->Data);
			Temp = Temp->Next;
		}
	}

	// ÚÇãá ÇáãÓÇæÇÉ áÇÓäÇÏ ãÍÊæì ßÇÆä ãæÌæÏ ãä ŞÈá Çáì ßÇÆä ÇÎÑ ãæÌæÏ ãä ŞÈá
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

	// ÇáÊÍŞŞ ããÇ ÇĞÇ ßÇä ÇáØÇÈæÑ İÇÑÛ Çæ áÇ
	bool IsEmpty() const override
	{
		return (_Front == nullptr && _Rear == nullptr);
	}

	// ÇÖÇİÉ ÈíÇäÇÊ ÚŞÏÉ ááØÇÈæÑ
	void Push(T Data) override
	{
		Node<T>* NewNode = new Node<T>();
		_LinkNewNode(NewNode , Data);
		_CountItems++;
	}

	// ÍĞİ ÈíÇäÇÊ ÚŞÏÉ ãä ÇáØÇÈæÑ
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

	// ÇÑÌÇÚ ÈíÇäÇÊ Çæá ÚŞÏÉ İí ÇáØÇÈæÑ
	T Front() { return (IsEmpty() ? T() : _Front->Data); }

	// ÇÑÌÇÚ ÈíÇäÇÊ ÇÎÑ ÚŞÏÉ İí ÇáØÇÈæÑ
	T Rear() { return (IsEmpty() ? T() : _Rear->Data); }

	// ÇáÈÍË Úä ÈíÇäÇÊ ÚŞÏÉ İí ÇáØÇÈæÑ
	T Search(T Data) const override { return (IsEmpty() ? T() : _FindData(Data)); }

	// ÇÑÌÇÚ ÚÏÏ ÇáÚäÇÕÑ Çæ ÇáÚŞÏ İí ÇáØÇÈæÑ
	int Count() const override { return (IsEmpty() ? 0 : _CountItems); }

	// ÍĞİ ÇáÚŞÏ ãä ÇáØÇÈæÑ Çæ ãÓÍ ÇáØÇÈæÑ ÈÇáßÇãá
	void Clear() override
	{
		while (!IsEmpty())
			Pop();
	}

	// ØÈÇÚÉ ãáİ ãÚíä 
	void PrintFile(T Data)
	{
		if (IsEmpty()) { cout << QueueErrors::QueueEmpty << endl; return; }

		cout << "\nName : " << Data.Name << ", Size : " << Data.Size << endl;
	}

	// ØÈÇÚÉ ÌãíÚ ÇáãáİÇÊ
	void PrintFiles()
	{
		Node<T>* Temp = _Front;
		while (Temp != nullptr)
		{
			PrintFile(Temp->Data);
			Temp = Temp->Next;
		}
	}

	// ÏÇáÉ ÇáåÏã .. áÊÍÑíÑ ĞÇßÑÉ ÇáßÇÆä ãä ÇáĞÇßÑÉ ŞÈá ÇáÇäÊåÇÁ ãä ÇáÈÑäÇãÌ
	~clsExercisePrinterQueue() override
	{
		Clear();
	}
};