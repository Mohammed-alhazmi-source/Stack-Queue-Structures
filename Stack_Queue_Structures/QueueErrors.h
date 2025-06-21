#pragma once
#include <iostream>
using namespace std;

class QueueErrors
{
public:
	static string QueueEmpty;
	static string QueueFull;
};

string QueueErrors::QueueEmpty = "Queue Empty";
string QueueErrors::QueueFull = "Queue Full";
