#define _CRT_SECURE_NO_WARNINGS
#include "post.h"
#include "DoublyLinkedListBool/DoublyLinkedListBool.h"
#include "SinglyLinkedListString/SinglyLinkedListString.h"
#include "ConsoleVisualization/ConsoleVisualization.h"
#include <stdbool.h>
#include <stdio.h>
#include <windows.h>

DL_Node* pTape; // указатель на ленту

// Сдвиг на ленте вправо
void RightShift() {
	pTape = DL_Next(pTape);
}

// Сдвиг на ленте влево
void LeftShift() {
	pTape = DL_Prev(pTape);
}

// Поставить метку на указывающее место в ленте
void PutLabel() {
	pTape->date = true;
}

// Убрать метку на указывающее место в ленте
void RemoveLabel() {
	pTape->date = false;
}

// Условие Если пустая, то N, иначе M
bool Condition() {
	return !(pTape->date);
}

// Выполнение комады. Возвращает следующую строчку
SL_Node* ExecuteCMD(SL_Node* cmd) {
	switch (cmd->cmd)
	{
	case '>':	// Сдвиг вправо
	{
		RightShift();
		return cmd->str1.point;
	}
	case '<':	// Сдвиг влево
	{
		LeftShift();
		return cmd->str1.point;
	}
	case '1':	// Поставить метку
	{
		PutLabel();
		return cmd->str1.point;
	}
	case '0':	// Убрать метку
	{
		RemoveLabel();
		return cmd->str1.point;
	}
	case '?':	// Условие
	{
		if (Condition() == true) {
			return cmd->str1.point;
		}
		else
		{
			return cmd->str2.point;
		}
	}
	case '!':	// Завершение скрипта
	{
		return NULL;
	}
	default:
		break;
	}
	return NULL;
}

// Запуск Машины Поста с интерпертатором
void Post_Run(void)
{
	char cmd;
	pTape = DL_Init(); // Инициализация ленты

	while (scanf("%c", &cmd) != EOF && cmd != 'S')
	{
		switch (cmd)
		{

		case '>':	// Сдвиг вправо
		case '<':	// Сдвиг влево
		case '1':	// Поставить метку
		case '0':	// Убрать метку
		{
			int numStr;
			scanf("%i", &numStr);
			SL_AddBack(cmd, numStr, 0);
			getchar();
			break;
		}
		case '?':	// Условие
		{
			int numStr1 , numStr2;
			scanf("%i, %i", &numStr1, &numStr2);
			SL_AddBack(cmd, numStr1, numStr2);
			getchar();
			break;
		}
		case '!':	// Завершение скрипта
		{
			SL_AddBack(cmd, 0, 0);
			getchar();
			break;
		}
		case 'V':	// Перемешение указателя на ленту
		{
			int shift;
			scanf("%i", &shift);
			if (shift > 0) {
				while (shift != 0)
				{
					RightShift();
					shift--;
				}
			}
			else if(shift < 0)
			{
				while (shift != 0)
				{
					LeftShift();
					shift++;
				}
			}
			getchar();
			break;
		}
		case 'P':	// Первоначальные настройки ленты
		{
			DL_Node* pTapeSave = pTape;
			char ch = getchar();
			while (ch != '\n')
			{
				
				if (ch == '0') {
					RemoveLabel();
					RightShift();
				}
				else if (ch == '1')
				{
					PutLabel();
					RightShift();
				}

				ch = getchar();
			}
			pTape = pTapeSave;
			break;
		}
		case 'S':	// Запуск скрипта
		{
			getchar();
			break;
		}
		default:
			break;
		}
	}

	SL_Optimizat(); // Оптимизация списка строк
	SL_Node* listStr = SL_GetHead();
	
	CS_Init(pTape); // Инициализация визуала ленты
	while (listStr)
	{
		Sleep(500);	// Пауза на 0.5 секунд
		listStr = ExecuteCMD(listStr);
		CS_Show(pTape);
	}
	putchar('\n');
	DL_Print(); // Печать данных с ленты

	SL_Destroy();
	DL_Destroy();
}
