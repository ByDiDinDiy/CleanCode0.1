#include "pch.h"
#include "CppUnitTest.h"
#include "../DeleteComment/funcs.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestingDeleteComment
{
	TEST_CLASS(CMPCoordinate)
	{
	public:
		//1 ������������� 

		///1.1 ������ ����� �� ����������
		TEST_METHOD(TestMethod11)
		{
			int x1 = -1, y1 = -1;
			int x2 = 0, y2 = 0;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		///1.2 ������ ����� �� ����������
		TEST_METHOD(TestMethod12)
		{
			int x1 = 0, y1 = 0;
			int x2 = -1, y2 = -1;

			bool resault = 0;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		///1.3 ����� ����� ���
		TEST_METHOD(TestMethod13)
		{
			int x1 = -1, y1 = -1;
			int x2 = -1, y2 = -1;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		//2 �� ���������� � ������ 

		///2.1 ������ ������ ����������� ������ �������

		////2.1.1 �� �����x ��������
		TEST_METHOD(TestMethod211)
		{
			int x1 = 2, y1 = 3;
			int x2 = 0, y2 = 5;

			bool resault = 0;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		////2.1.2 �� ����� �������
		TEST_METHOD(TestMethod212)
		{
			int x1 = 2, y1 = 3;
			int x2 = 3, y2 = 3;

			bool resault = 0;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		///2.2 ������ ������ ����������� ������ �������

		////2.2.1 �� �����x ��������
		TEST_METHOD(TestMethod221)
		{
			int x1 = 0, y1 = 5;
			int x2 = 0, y2 = 3;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
		////2.1.2 �� ����� �������
		TEST_METHOD(TestMethod222)
		{
			int x1 = 7, y1 = 3;
			int x2 = 5, y2 = 3;

			bool resault = 1;
			bool expected = cmpCoordinate(x1, y1, x2, y2);

			Assert::AreEqual(resault, expected);
		}
	};
}
