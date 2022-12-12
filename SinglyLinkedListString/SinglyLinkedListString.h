#pragma once

#include <stdlib.h>

typedef struct _SL_Node {
	char cmd;

	struct {
		size_t number;
		struct _SL_Node* point;
	} str1;

	struct {
		size_t number;
		struct _SL_Node* point;
	} str2;

	struct _SL_Node* next;
} SL_Node;

// Инициализация списка
SL_Node* SL_Init(char cmd, size_t num1, size_t num2);

// Уничтожение списка
void SL_Destroy(void);

// Добавление новго узла в конец списка
SL_Node* SL_AddBack(char cmd, size_t num1, size_t num2);

// Оптимизация списка
void SL_Optimizat(void);

// Получение указателя на начало списка
SL_Node* SL_GetHead(void);