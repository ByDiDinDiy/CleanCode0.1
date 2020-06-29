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
	int singleLine_x = -1, singleLine_y = -1;
	int multiLineBegin_x = -1, multiLineBegin_y = -1;
	int multiLineEnd_x = -1, multiLineEnd_y = -1;

	int countOfStrings = lengthOfText;

	//���� ������ ������������� ����������� � ������, � ���������� ��� ����������
	bool comment = findStrInText(text, countOfStrings, "/*", &multiLineBegin_x, &multiLineBegin_y);

	//���� � ������ ����������� �����������
	while (comment) {
		//���� ������ ����������� ������������� �����������
		findStrInText(text, lengthOfText, "*/", &multiLineEnd_x, &multiLineEnd_y);
		//������� �����������
		countOfStrings = deleteText(text, countOfStrings, multiLineBegin_x, multiLineBegin_y, multiLineEnd_x + 1, multiLineEnd_y);

		//���� ������ ������������� ����������� � ������, � ���������� ��� ����������
		comment = findStrInText(text, countOfStrings, "/*", &multiLineBegin_x, &multiLineBegin_y);
	}

	return countOfStrings;
}

int  deleteText(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfTextInput, const int beginX, const int beginY, const int endX, const int endY)
{
	int lengthOfText = *const_cast<int*>(&lengthOfTextInput);

	int beginStr; //������ ������ ��� ��� ���������
	int quantityStr; //���������� ����� ��� �������� 

	//���� ��������� ����� ��������� �� ����� ������, �� 
	if ((beginY) == (endY)) {
		//������� ����� 
		strcpy(text[beginY] + beginX, text[beginY] + endX + 1);
		//���� � ������� ������ ��� ��������, ��
		if (text[beginY][0] == '\0')
			//������� �������
			lengthOfText = deletingRows(text, lengthOfText, beginY, 1);

	}
	else {

		//������ ����������� �� ������ ������ ��� ��������� 
		strcpy(text[beginY] + beginX, "\0");
		//���� ������ �������� ������ �� �����������, �� ���������� � ��� ������ ���������, ����� ��������� 
		(text[beginY][0] == '\0') ? beginStr = beginY : beginStr = (beginY)+1;

		//������ ����������� �� ��������� ������ ��� ��������� 
		strcpy(text[endY], text[endY] + (endX)+1);
		//���� ������� ������ �������� ������ �� �����������, �� ���������� ���������� ���������� ����� ��� ������� ��������� ������ � ������ ���������
		(text[endY][0] == '\0') ? quantityStr = (endY)-beginStr + 1 : quantityStr = (endY)-beginStr;

		//������� ������ �� ���������� �� ��������� ������ ������   
		lengthOfText = deletingRows(text, lengthOfText, beginStr, quantityStr);

	}

	return lengthOfText;
}

int deletingRows(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], int lengthOfTextInput, const int beginStr, const int quantityStr)
{
	//��� ������ ��������� ������ ������� � beginStr
	for (int i = 0; i < lengthOfTextInput - quantityStr - beginStr; i++)
	{
		//��������� ��� ������� ������, ������ ������� ����������� ����� quantityStr ��� 
		strcpy(text[beginStr + i], text[beginStr + i + quantityStr]);
	}

	//��������� ����� ������ ������ 
	return lengthOfTextInput - quantityStr;
}
