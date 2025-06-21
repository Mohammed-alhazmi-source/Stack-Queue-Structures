#pragma once
#include <iostream>
using namespace std;

class StackErrors
{
public:
	static string UnderFlow;
	static string OverFlow;
};

string StackErrors::UnderFlow = "Empty";
string StackErrors::OverFlow  = "Stack OverFlow";