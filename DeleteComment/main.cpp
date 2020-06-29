#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "funcs.h"


int main()
{
	int countOfStrings = 0;
	char programmText[MAX_SIZE_STRING][MAX_SIZE_SYMBOL];
	/*
	//Ввести количество строк текста
	printf("Enter count of text's strings:\n");
	scanf_s("%d", &countOfStrings);
	getchar();

	if (countOfStrings < 1 || countOfStrings > 20)
	{
		printf("invalid range");
		return 0;
	}

	//Ввести текст	
	printf("Enter Text:\n");
	for (int i = 0; i < countOfStrings; i++)
		gets_s(programmText[i]);

	//Удалить входной текст
	countOfStrings = deleteCommentsInCode(programmText, countOfStrings);

	//Вывести код без комментариев
	for (int i = 0; i < countOfStrings; i++)
		printf("%s\n", programmText[i]);
		*/
	return 0;
}