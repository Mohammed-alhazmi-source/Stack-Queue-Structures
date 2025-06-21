#pragma once
#include <iostream>
using namespace std;

template <typename T>
class ILinearStructure
{
public:
	virtual bool IsEmpty() const = 0;
	virtual int Count() const = 0;
	virtual T Search(T Item) const = 0;
	virtual void Clear() = 0;
	virtual void Push(T Item) = 0;
	virtual void Pop() = 0;
	//virtual string Object() const = 0;
	virtual ~ILinearStructure() = default;
};

