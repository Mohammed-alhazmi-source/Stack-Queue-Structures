#pragma once
#include <iostream>
#include "ConstantsCases.h"
#include "Global.h"
using namespace std; 

class clsRebuildDataStructure
{
public:
	static void RebuildQueue
	(
		QueueUsingLinkedList<stPatientInformation>& SourceQueue, 
		StackUsingLinkedList<stPatientInformation>& DestinationStack 
	)
	{
		QueueUsingLinkedList<stPatientInformation> TempQueue;

		while (SourceQueue.FirstNode() != nullptr)
		{
			if (SourceQueue.Front().MarkedDeleted != true)
			{
				TempQueue.Push(SourceQueue.Front());
				SourceQueue.Pop();
			}
			else
			{
				SourceQueue.FirstNode()->Data.MarkedDeleted = false;
				DestinationStack.Push(SourceQueue.Front());
				SourceQueue.Pop();
			}
		}
		SourceQueue = TempQueue;
	}

	static void RebuildQueue(QueueUsingLinkedList<stPatientInformation>& SourceQueue)
	{
		QueueUsingLinkedList<stPatientInformation> TempQueue;

		while (SourceQueue.FirstNode() != nullptr)
		{
			if (SourceQueue.Front().MarkedDeleted != true)
			{
				TempQueue.Push(SourceQueue.Front());
				SourceQueue.Pop();
			}
			else
			{
				SourceQueue.Pop();
			}
		}
		SourceQueue = TempQueue;
	}

	static void RebuildStack
	(
		StackUsingLinkedList<stPatientInformation>& SourceStack,  // 1
		StackUsingLinkedList<stPatientInformation>& DestinationStack   // 2
	)
	{
		StackUsingLinkedList<stPatientInformation> TempStack;

		while (SourceStack.FirstNode() != nullptr)
		{
			if (SourceStack.Peek().MarkedDeleted != true)
			{
				TempStack.Push(SourceStack.Peek());
				SourceStack.Pop();
			}
			else
			{
				SourceStack.FirstNode()->Data.MarkedDeleted = false;
				DestinationStack.Push(SourceStack.Peek());
				SourceStack.Pop();
			}
		}

		SourceStack = TempStack;
	}


	static void RebuildStack(StackUsingLinkedList<stPatientInformation>& SourceStack)
	{
		StackUsingLinkedList<stPatientInformation> TempStack;

		while (SourceStack.FirstNode() != nullptr)
		{
			if (SourceStack.Peek().MarkedDeleted != true)
			{
				TempStack.Push(SourceStack.Peek());
				SourceStack.Pop();
			}
			else
			{
				SourceStack.Pop();
			}
		}

		SourceStack = TempStack;
	}
};

