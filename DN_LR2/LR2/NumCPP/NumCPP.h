// NumCPP.h

#pragma once
#include <iostream>

using namespace System;

namespace NumCPP 
{
	public ref class NumCPP
	{
	public:int EnterNum()
		{
			int x;
			Console::Write("Enter first number: ");
			std::cin >> x;
			return x;
		}
	};
}
