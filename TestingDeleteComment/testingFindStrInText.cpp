#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(FindStrInText)
	{
	public:
		//1 По нахождению:

		///1.1 В строке

		////1.1.1 В начале строки
		TEST_METHOD(TestMethod1)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"//	if (a > b)",
				"		return a;",
				"}"
			};
			char symbol[3] = "//";
			int x = 0, y = 0;

			int x_resault = 0, y_resault = 2;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		////1.1.2 В конце строки
		TEST_METHOD(TestMethod21)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"	if (a > b)//",
				"		return a;",
				"}"
			};
			char symbol[3] = "//";
			int x = 0, y = 0;

			int x_resault = 11, y_resault = 2;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		////1.1.3 В середине строки
		TEST_METHOD(TestMethod3)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"	if (a //> b)",
				"		return a;",
				"}"
			};
			char symbol[3] = "//";
			int x = 0, y = 0;

			int x_resault = 7, y_resault = 2;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		///1.2 В столбце

		////1.2.1 В начале столбца
		TEST_METHOD(TestMethod4)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"/*int functionName (int a, int b)",
				"{",
				"//	if (a > b)",
				"		return a;",
				"}"
			};
			char symbol[3] = "/*";
			int x = 0, y = 0;

			int x_resault = 0, y_resault = 0;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		////1.2.2 В конце столбца
		TEST_METHOD(TestMethod5)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"	if (a > b)//",
				"		return a;",
				"/*}"
			};
			char symbol[3] = "/*";
			int x = 0, y = 0;

			int x_resault = 0, y_resault = 4;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		////1.2.3 В середине столбца
		TEST_METHOD(TestMethod6)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"/*	if (a //> b)",
				"		return a;",
				"}"
			};
			char symbol[3] = "/*";
			int x = 0, y = 0;

			int x_resault = 0, y_resault = 2;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		//2.По размеру

		///2.1 Занимает всю строку
		TEST_METHOD(TestMethod7)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"///////////////////",
				"		return 0;",
				"}"
			};
			char* symbol = "///////////////////";
			int x = 0, y = 0;

			int x_resault = 0, y_resault = 2;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		///2.2 Минимально возможное количетсво символов
		TEST_METHOD(TestMethod8)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"sdsadsad /",
				"		return 0;",
				"}"
			};
			char* symbol = "/";
			int x = 0, y = 0;

			int x_resault = 9, y_resault = 2;
			bool resault = 1;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
		//3 Таких символов нет
		TEST_METHOD(TestMethod9)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"sdsadsad /",
				"		return 0;",
				"}"
			};
			char* symbol = "№+";
			int x = 0, y = 0;

			int x_resault = -1, y_resault = -1;
			bool resault = 0;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
	};
}
