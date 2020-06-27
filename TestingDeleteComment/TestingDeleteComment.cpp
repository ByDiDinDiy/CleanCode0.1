#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(TestingDeleteComment)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int WaitingResult = 0;
			Assert::AreEqual(WaitingResult, SomeFunc());
		}
	};
}
