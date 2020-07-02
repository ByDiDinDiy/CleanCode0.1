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

		//2.������������� ����������� 
		///2.1 ���������� � ������� ��������� �������� 
		////2.1.1 � ������ ������
		TEST_METHOD(multilineCommentBeginningOfline)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"/*int*/ functionName (int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				" functionName (int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);
			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.1.2 � �������� ������
		TEST_METHOD(multilineCommentMiddleOfline)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int /*functionName*/ (int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int  (int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.1.3 � ����� ������
		TEST_METHOD(multilineCommentEndOfline)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName /*(int a, int b)*/",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName ",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		///2.2 ���������� � ������
		////2.2.1 ������� ������� � ������� � ������ ������
		TEST_METHOD(oneAndHalfLinesBeginning)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"/*int functionName (int a, int b)",
				"{ int*/ i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 4;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				" i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.2.2 ������� ������� � ������� � ����� ������
		TEST_METHOD(oneAndHalfLinesEnd)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName /*(int a, int b)",
				"{ int i=0;*/",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 4;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName ",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.2.3 ������� ������� � �������� � �������� �����
		TEST_METHOD(oneAndHalfLinesMiddle)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName /*(int a, int b)",
				"{ int*/ i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName ",
				" i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		///2.3 ������ ����������� 
		////2.3.1 ���� ������
		TEST_METHOD(one�haracter)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName /*(*/int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.3.2 �������� ������
		TEST_METHOD(halfLine)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName /*(int a, int b)*/",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName ",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.3.4 ���� �������
		TEST_METHOD(oneLine)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"/*int functionName (int a, int b)*/",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 4;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.3.5 �������� ������
		TEST_METHOD(halfText)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"/*int functionName (int a, int b)",
				"{ int i=0;",
				"*/if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 3;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.3.6 ���� �����
		TEST_METHOD(allText)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"/*int functionName (int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}*/"
			};
			int countOfStrings_resault = 0;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		////2.3.7 ������ ����������� 
		TEST_METHOD(blank�omment)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"/**/int functionName (int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 5;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{ int i=0;",
				"if (a > b)",
				"return a;",
				"}"
			};

			countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
	};


}
