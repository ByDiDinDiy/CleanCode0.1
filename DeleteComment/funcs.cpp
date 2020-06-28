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
	int singleLine_x = -1, singleLine_y = -1;
	int multiLineBegin_x = -1, multiLineBegin_y = -1;
	int multiLineEnd_x = -1, multiLineEnd_y = -1;

	int countOfStrings = lengthOfText;

	//Ищем первый встречающийся комментарий в тексте, и запоминаем его координаты
	bool comment = findStrInText(text, countOfStrings, "/*", &multiLineBegin_x, &multiLineBegin_y);

	//Пока в тексте встречаются комментарии
	while (comment) {
		//Ищем сиволы закрывающий многострочный комментарий
		findStrInText(text, lengthOfText, "*/", &multiLineEnd_x, &multiLineEnd_y);
		//Удаляем комментарии
		countOfStrings = deleteText(text, countOfStrings, multiLineBegin_x, multiLineBegin_y, multiLineEnd_x + 1, multiLineEnd_y);

		//Ищем первый встречающийся комментарий в тексте, и запоминаем его координаты
		comment = findStrInText(text, countOfStrings, "/*", &multiLineBegin_x, &multiLineBegin_y);
	}

	return countOfStrings;
}

int  deleteText(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfTextInput, const int beginX, const int beginY, const int endX, const int endY)
{
	int lengthOfText = *const_cast<int*>(&lengthOfTextInput);

	int beginStr; //первая строка для для затирания
	int quantityStr; //количество строк для удаления 

	//Если удаляемый текст находится на одной строке, то 
	if ((beginY) == (endY)) {
		//Удаляем текст 
		strcpy(text[beginY] + beginX, text[beginY] + endX + 1);
		//Если в строчке больше нет символов, то
		if (text[beginY][0] == '\0')
			//удаляем строчку
			lengthOfText = deletingRows(text, lengthOfText, beginY, 1);

	}
	else {

		//удалим комментарий на первой строке его вхождения 
		strcpy(text[beginY] + beginX, "\0");
		//если строка состояла только из комментария, то запоминаем её как начало затирания, иначе следующую 
		(text[beginY][0] == '\0') ? beginStr = beginY : beginStr = (beginY)+1;

		//удалим комментарий на последней строке его вхождения 
		strcpy(text[endY], text[endY] + (endX)+1);
		//если текущая строка состояла только из комментария, то запоминаем количество затираемых строк как разницу последней строки и начала затирания
		(text[endY][0] == '\0') ? quantityStr = (endY)-beginStr + 1 : quantityStr = (endY)-beginStr;

		//Удаляем строки от начального до конечного номера строки   
		lengthOfText = deletingRows(text, lengthOfText, beginStr, quantityStr);

	}

	return lengthOfText;
}


