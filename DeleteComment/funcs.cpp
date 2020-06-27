//#include "stdafx.h"
#include "funcs.h"
#include <stdio.h>
#include <string.h>
#include <cctype>

bool findStrInText(const char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfText, const char* symbolInput, int* x, int* y)
{
	bool found = 0;
	*x = 0;
	*y = 0;

	//��� ������ ������� ���� �� ����� ������ ��� �� ������� ������ ������� 
	while (*y < lengthOfText && found == 0)
	{
		//���� ������� ��������� � ������� ������, ��
		if (strstr(text[*y], symbolInput))
		{
			//��������� � ����������
			*x = strstr(text[*y], symbolInput) - text[*y];
			found = 1;
		}
		//�����
		else
			//������� �� ��������� ������
			(*y)++;
	}

	//���� ������� ��� � ������, ��  ������� ��������������� ��������
	if (found == 0) {
		*x = -1;
		*y = -1;
	}

	return found;
}

bool cmpCoordinate(const int x1, const int y1, const int x2, const int y2)
{
	bool resault;

	//���� ������� ������� ���, ��
	if (y1 == -1)
		resault = 1;//������� ��� ������ ������ ����� � ������ ������ 
	//�����, ���� ������� ������� ���, ��
	else if (y2 == -1)
		resault = 0;//������� ��� ������ ������ ����� � ������ ������ 
	//���� ���������� "y" ������ � ������ �����, ��
	else if (y1 < y2)
		resault = 0;//������� ��� ������ ������ ����� � ������ ������ 
	//����� ���� ���������� "y" ������ � ������ �����, ��
	else if (y1 > y2)
		resault = 1;//������� ��� ������ ������ ����� � ������ ������ 
	//����� ���� "y" ���������� �����, � ���������� "x" ������ � �������, ��
	else if (x1 < x2)
		resault = 0;//������� ��� ������ ������ ����� � ������ ������ 
	//����� 
	else
		resault = 1;//������� ��� ������ ������ ����� � ������ ������

	return resault;
}

int deleteCommentsInCode(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfText)
{
	return 0;
}

int deletingRows(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], int lengthOfTextInput, const int beginStr, const int quantityStr)
{
	return 0;
}

int  deleteText(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfTextInput, const int beginX, const int beginY, const int endX, const int endY)
{
	return 0;
}


