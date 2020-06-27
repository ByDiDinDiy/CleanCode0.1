#pragma once

#define MAX_SIZE_STRING 20
#define MAX_SIZE_SYMBOL 81

/*!
* Поиск первого вхождения символов(symbolInput) в текстe(text)
*  \param [in] text текст для поиска
*  \param [in] lengthOfText количество строк в тексте
*  \param [in] symbolInput символы для поиска
*  \param [out] x координата найженного символа в строке(возвращает -1, если не найдены)
*  \param [out] y координата найженного символа в столбце(возвращает -1, если не найдены)
*  return - true, если найдено или false, если не найдено
*/
bool findStrInText(const char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfText, const char* symbolInput, int* x, int* y);

/*!
* Сравнение координат двух символов:Если первый символ ближе к началу, то функция возвращает 0, иначе 1.
*  \param [in] x1 координата x для первой точки
*  \param [in] y1 координата y для первой точки
*  \param [in] x2 координата x для второй точки
*  \param [in] y2 координата y для второй точки
*  return - 0, eсли первая точка ближе к центру координат, 1 если наоборот
*/
bool cmpCoordinate(const int x1, const int y1, const int x2, const int y2);

/*!
* Удалить из текста  quantityStr строк начиная с beginStr.
*  \param [in] text текст для удаления строк
*  \param [in] lengthOfTextInput длина текста
*  \param [in] beginStr начальная строка для удаления
*  \param [in] quantityStr количетсво строк
*  return - количество строк в новом тексте
*/
int deletingRows(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], int lengthOfTextInput, const int beginStr, const int quantityStr);

/*!
* Удалить часть текста от строки beginY символа beginX до строки endY символа endX.
*  \param [in|out] text текст для удаления строк
*  \param [in] lengthOfTextInput длина текста
*  \param [in] beginX номер символа в строке первого удаляемового символа последновательности
*  \param [in] beginY  номер строки первого удаляемового символа последновательности
*  \param [in] endX  номер символа в строке последнего удаляемового символа последновательности
*  \param [in] endY номер строки последнего удаляемового символа последновательности
*  return - количество строк в тексте
*/
int  deleteText(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfTextInput, const int beginX, const int beginY, const int endX, const int endY);

/*!
* Удалить все комментарии из текста
*  \param [in|out] text текст для обработки
*  \param [in] lengthOfTextInput длина текста
*  return - количество строк в тексте
*/
int deleteCommentsInCode(char text[MAX_SIZE_STRING][MAX_SIZE_SYMBOL], const int lengthOfText);