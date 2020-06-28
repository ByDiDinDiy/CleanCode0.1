#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(FindStrInText)
	{
	public:
		//1 �� ����������
		///1.1 � ������
		////1.1.1 � ������ ������
		TEST_METHOD(beginningOfTheLine)
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
		////1.1.2 � ����� ������
		TEST_METHOD(endOfTheLine)
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
		////1.1.3 � �������� ������
		TEST_METHOD(middleOfTheLine)
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
		///1.2 � �������
		////1.2.1 � ������ �������
		TEST_METHOD(beginningOfThe�olumn)
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
		////1.2.2 � ����� �������
		TEST_METHOD(endOfThe�olumn)
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
		////1.2.3 � �������� �������
		TEST_METHOD(middleOfThe�olumn)
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
		//2.�� �������
		///2.1 �������� ��� ������
		TEST_METHOD(allLine)
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
		///2.2 ���������� ��������� ���������� ��������
		TEST_METHOD(oneSymbol)
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
		//3 ����� �������� ���
		TEST_METHOD(noSymbol)
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
			char* symbol = "�+";
			int x = 0, y = 0;

			int x_resault = -1, y_resault = -1;
			bool resault = 0;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
	};
}
