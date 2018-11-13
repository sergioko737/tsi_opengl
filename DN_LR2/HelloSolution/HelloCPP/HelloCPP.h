// HelloCPP.h

#pragma once

using namespace System;

namespace HelloCPP {

	public ref class HelloCPP
	{
		public:virtual void Hello()
		{
			Console::WriteLine("Hello from C++");
		}
	};
}
