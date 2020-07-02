#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"


int main()
{
	int countOfStrings = 0;
	char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL];
	
	//������ ���������� ����� ������
	printf("Enter count of text's strings:\n");
	scanf_s("%d", &countOfStrings);
	getchar();

	if (countOfStrings < 1 || countOfStrings > 500)
	{
		printf("invalid range");
		return 0;
	}

	//������ �����	
	printf("Enter Text:\n");
	for (int i = 0; i < countOfStrings; i++)
		gets_s(programmText[i]);

	//������� ������� �����
	countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

	//������� ��� ��� ������������
	for (int i = 0; i < countOfStrings; i++)
		printf("%s\n", programmText[i]);
	return 0;
}