#pragma once
#include <iostream>
#include "SmartStack.h"
using namespace std;


template <typename T>
class clsUndoAndRedo
{
private:
	SmartStack<T> _UndoStack;
	SmartStack<T> _RedoStack;

public:

	clsUndoAndRedo() = default;

	SmartStack<T> UndoStack() const
	{
		return _UndoStack;
	}

	SmartStack<T> RedoStack() const
	{
		return _RedoStack;
	}

	bool IsEmptyUndoStack()
	{
		return (_UndoStack.IsEmpty());
	}

	bool IsEmptyRedoStack()
	{
		return (_RedoStack.IsEmpty());
	}

	bool IsEmpty()
	{
		return(_UndoStack.IsEmpty() && _RedoStack.IsEmpty());
	}

	void Add(T Item)
	{
		if (_UndoStack.IsEmpty() && !_RedoStack.IsEmpty())
		{
			_RedoStack.Clear();
			_UndoStack.Push(Item);
		}

		else if (_UndoStack.IsEmpty())
			_UndoStack.Push(Item);

		else if (_UndoStack.HasData())
		{
			if (_RedoStack.IsEmpty())
				_UndoStack.Push(Item);

			else
			{
				_RedoStack.Clear();
				_UndoStack.Push(Item);
			}
		}
	}

	void Clear()
	{
		if (!_UndoStack.IsEmpty())
			_UndoStack.Clear();

		if (!_RedoStack.IsEmpty())
			_RedoStack.Clear();
	}

	T Undo()
	{
		T UndoValue;

		if (_UndoStack.IsEmpty())
			return T{ "Undo Stack Is Empty" };

		else
		{
			UndoValue = _UndoStack.Peek();
			_UndoStack.Pop();
			_RedoStack.Push(UndoValue);
		}
		return UndoValue;
	}

	T Redo()
	{
		T RedoValue;

		if (_RedoStack.IsEmpty())
			return T{ "Undo Stack Is Empty" };

		else
		{
			RedoValue = _RedoStack.Peek();
			_RedoStack.Pop();
			_UndoStack.Push(RedoValue);
		}
		return RedoValue;
	}
};