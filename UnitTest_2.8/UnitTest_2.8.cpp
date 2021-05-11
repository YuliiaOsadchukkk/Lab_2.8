#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_2.8--/Bill.h"
#include "../Lab_2.8--/Bill.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest28
{
	TEST_CLASS(UnitTest28)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Bill B1;
			B1.SetSurname("Osadchuk");
			string surname = "Osadchuk";
			Assert::AreEqual(surname, B1.GetSurname());
		}
	};
}
