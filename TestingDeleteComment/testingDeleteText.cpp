#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(DeleteCommentsInCode)
	{
	public:

		//�������� ������� 
		void cmptext(char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], int countOfStrings, char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], int countOfStrings_resault) {
			Assert::AreEqual(countOfStrings, countOfStrings_resault);

			if (countOfStrings == countOfStrings_resault) {
				for (int i = 0; i < countOfStrings; i++) {
					Assert::AreEqual(strcmp(programmText_resault[i], programmText[i]), 0);
				}
			}
		}

		//1 ���������� �����
		///1.1 ���� ������ 
		TEST_METHOD(oneLine)
		{
			int beginX = 0, beginY = 0;
			int endX = 1, endY = 1;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 4;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		///1.2 ���� ����� 
		TEST_METHOD(allLine)
		{
			int beginX = 0, beginY = 0;
			int endX = 1, endY = 4;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 0;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"",
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		///1.3 �������� ������
		////1.3.1 � ������ 
		TEST_METHOD(firstHalfText)
		{
			int beginX = 0, beginY = 0;
			int endX = 9, endY = 1;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 3;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////1.3.2 � ��������
		TEST_METHOD(middleHalfText)
		{
			int beginX = 0, beginY = 1;
			int endX = 8, endY = 3;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 2;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////1.3.3 � ����� ������ 
		TEST_METHOD(endtHalfText)
		{
			int beginX = 0, beginY = 3;
			int endX = 0, endY = 4;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 3;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		//2 �� ��������� � ������
		///2.1 �������� ������ 
		////2.1.1 � ������
		TEST_METHOD(firstHalfStr)
		{
			int beginX = 0, beginY = 2;
			int endX = 4, endY = 2;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				" (a > b)",
				"return a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.1.2 � �������� ������
		TEST_METHOD(middleHalfStr)
		{
			int beginX = 3, beginY = 2;
			int endX = 4, endY = 2;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	 (a > b)",
				"return a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.1.3 � �������� ������
		TEST_METHOD(endHalfStr)
		{
			int beginX = 6, beginY = 2;
			int endX = 12, endY = 2;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if ",
				"return a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		///2.2 ������� ������
		////2.2.1 ����� � ����� ������
		TEST_METHOD(tailFirstStr)
		{
			int beginX = 0, beginY = 2;
			int endX = 3, endY = 3;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 4;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"rn a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.2.2 ����� � ������ ������
		TEST_METHOD(tailMiddleStr)
		{
			int beginX = 3, beginY = 2;
			int endX = 3, endY = 3;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	",
				"rn a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.2.3 ��� ������ �� �������� ������
		TEST_METHOD(tailEndStr)
		{
			int beginX = 5, beginY = 1;
			int endX = 12, endY = 2;
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 4;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int",
				"return a;",
				"}"
			};
			int beginRows = 0, quantityStr = 2;
			countOfStrings = deleteText(programmText, countOfStrings, beginX, beginY, endX, endY);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
	};
}