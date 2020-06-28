#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(CMPCoordinate)
	{
	public:
		//1 Существование 
		///1.1 Первой точки не существует
		TEST_METHOD(firstСharacterIsNotPresent)
		{
			int x1 = -1, y1 = -1;
			int x2 = 0, y2 = 0;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		///1.2 Второй точки не существует
		TEST_METHOD(secondСharacterIsNotPresent)
		{
			int x1 = 0, y1 = 0;
			int x2 = -1, y2 = -1;

			bool resault = 0;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		///1.3 Обоих точек нет
		TEST_METHOD(bothCharactersAreNotPresent)
		{
			int x1 = -1, y1 = -1;
			int x2 = -1, y2 = -1;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		//2 на нахождение в тексте 
		///2.1 первый символ встречается раньше второго
		////2.1.1 на разныx строчках
		TEST_METHOD(firstCharacterIsCloser)
		{
			int x1 = 2, y1 = 3;
			int x2 = 0, y2 = 5;

			bool resault = 0;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		////2.1.2 на одной строчке
		TEST_METHOD(secodCharacterIsCloser)
		{
			int x1 = 2, y1 = 3;
			int x2 = 3, y2 = 3;

			bool resault = 0;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		///2.2 второй символ встречается раньше первого
		////2.2.1 на разныx строчках
		TEST_METHOD(firstCharacterIsCloser1)
		{
			int x1 = 0, y1 = 5;
			int x2 = 0, y2 = 3;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		////2.1.2 на одной строчке
		TEST_METHOD(secodCharacterIsCloser1)
		{
			int x1 = 7, y1 = 3;
			int x2 = 5, y2 = 3;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
	};
}
