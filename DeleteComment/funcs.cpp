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

	//Для каждой строчки пока не конец текста или не нашлась нужная лексема 
	while (*y < lengthOfText && found == 0)
	{
		//Если лексема находится в текущей строке, то
		if (strstr(text[*y], symbolInput))
		{
			//запомнить её координату
			*x = strstr(text[*y], symbolInput) - text[*y];
			found = 1;
		}
		//Иначе
		else
			//Перейти на следующую строку
			(*y)++;
	}

	//Если лексемы нет в тексте, то  передаём соответствующие значения
	if (found == 0) {
		*x = -1;
		*y = -1;
	}

	return found;
}

bool cmpCoordinate(const int x1, const int y1, const int x2, const int y2)
{
	bool resault;

	//если первого символа нет, то
	if (y1 == -1)
		resault = 1;//считаем что второй символ ближе к началу текста 
	//иначе, если второго символа нет, то
	else if (y2 == -1)
		resault = 0;//считаем что первый символ ближе к началу текста 
	//если координаат "y" меньше у первой точки, то
	else if (y1 < y2)
		resault = 0;//считаем что первый символ ближе к началу текста 
	//иначе если координаат "y" больше у первой точки, то
	else if (y1 > y2)
		resault = 1;//считаем что второй символ ближе к началу текста 
	//иначе если "y" координаты равны, а координата "x" меньше у первого, то
	else if (x1 < x2)
		resault = 0;//считаем что первый символ ближе к началу текста 
	//иначе 
	else
		resault = 1;//считаем что второй символ ближе к началу текста

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


