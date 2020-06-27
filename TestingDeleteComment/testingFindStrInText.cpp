#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(FindStrInText)
	{
	public:
		//1 �� ����������:

		///1.1 � ������

		////1.1.1 � ������ ������
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
		////1.1.2 � ����� ������
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
		////1.1.3 � �������� ������
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
		///1.2 � �������

		////1.2.1 � ������ �������
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
		////1.2.2 � ����� �������
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
		////1.2.3 � �������� �������
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
		//2.�� �������

		///2.1 �������� ��� ������
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
		///2.2 ���������� ��������� ���������� ��������
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
		//3 ����� �������� ���
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
			char* symbol = "�+";
			int x = 0, y = 0;

			int x_resault = -1, y_resault = -1;
			bool resault = 0;
			bool expected = findStrInText(programmText, countOfStrings, symbol, &x, &y);

			Assert::AreEqual(resault, expected);
		}
	};
}
