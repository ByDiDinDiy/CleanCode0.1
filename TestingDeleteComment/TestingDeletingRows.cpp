#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(DeletingRows)
	{
	private: 
		
		//Проверка текстов 
		void cmptext(char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], int countOfStrings, char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], int countOfStrings_resault) {
			Assert::AreEqual(countOfStrings, countOfStrings_resault);
			if (countOfStrings == countOfStrings_resault) {
				for (int i = 0; i < countOfStrings; i++) {
					Assert::AreEqual(strcmp(programmText_resault[i], programmText[i]), 0);
				}
			}
		}


		//1 Нахождение удаляемых строк:

		///1.1 Удалить первые строки
	public:TEST_METHOD(deleteFirstLines)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
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


			countOfStrings = deletingRows(programmText, countOfStrings, beginRows, quantityStr);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}

		///1.2 Удалить последнии строки
	public:TEST_METHOD(delLaldl)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 3;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"//	if (a > b)"
			};

			int beginRows = 3, quantityStr = 2;


			countOfStrings = deletingRows(programmText, countOfStrings, beginRows, quantityStr);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);

		}

		///1.3 Удалить строки по середине
	public:TEST_METHOD(deleteMiddleLines)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 3;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"return a;",
				"}"
			};

			int beginRows = 1, quantityStr = 2;


			countOfStrings = deletingRows(programmText, countOfStrings, beginRows, quantityStr);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
		//2. Количество удаляемых строк:
		///2.1 Весь текст 
	public:	TEST_METHOD(deleteAllText)
		{
			int countOfStrings = 5;
			char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				"int functionName (int a, int b)",
				"{",
				"//	if (a > b)",
				"return a;",
				"}"
			};
			int countOfStrings_resault = 0;
			char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
			{
				""
			};

			int beginRows = 0, quantityStr = 5;


			countOfStrings = deletingRows(programmText, countOfStrings, beginRows, quantityStr);

			cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
		}
	
	///2.2 одна строка 
	public:	TEST_METHOD(deleteOneLine)
	{
		int countOfStrings = 5;
		char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
		{
			"int functionName (int a, int b)",
			"{",
			"//	if (a > b)",
			"return a;",
			"}"
		};
		int countOfStrings_resault = 4;
		char programmText_resault[MAX_SIZE_STRING][MAX_SIZE_SYMBOL] =
		{
			"int functionName (int a, int b)",
			"{",
			"//	if (a > b)",
			"}"
		};

		int beginRows = 3, quantityStr = 1;


		countOfStrings = deletingRows(programmText, countOfStrings, beginRows, quantityStr);

		cmptext(programmText, countOfStrings, programmText_resault, countOfStrings_resault);
	}
	};


}
