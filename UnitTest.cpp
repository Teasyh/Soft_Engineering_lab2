#include "pch.h"
#include "CppUnitTest.h"
#include "../Project1/demo.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		demo d;
		TEST_METHOD(Search_word)
		{
			string str = "test.c";
			int result = d.Search_word(str);
			Assert::AreEqual(35, Search_word(str));
		}

		TEST_METHOD(Judge_ifelse)
		{
			string str = "test.c";
			int result = d.Judge_ifelse;
			Assert::AreEqual(2, Judge_ifelse(str));
		}
	};
}

