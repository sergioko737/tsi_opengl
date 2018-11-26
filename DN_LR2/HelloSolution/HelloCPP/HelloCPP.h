// HelloCPP.h

#pragma once

using namespace System;

namespace HelloCPP {

	public ref class HelloCPP
	{
		HelloCPP(int x){
			Console::WriteLine("Hello from C++++++");
		}

		public:virtual void Hello()
		{
			Console::WriteLine("Hello from C++");
		}
	};
}
