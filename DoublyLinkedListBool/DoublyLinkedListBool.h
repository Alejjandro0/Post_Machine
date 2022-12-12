#pragma once

#include <stdbool.h>

typedef struct _DL_Node {
	bool date;
	struct _DL_Node* next;
	struct _DL_Node* prev;
} DL_Node;

// Инициализация списка
DL_Node* DL_Init(void);

// Уничтожение списка
void DL_Destroy(void);

// Возвращает указатель на следующий узел
DL_Node* DL_Next(DL_Node* node);

// Возвращает указатель на предыдуший узел
DL_Node* DL_Prev(DL_Node* node);

// Печать данных с ленты
void DL_Print(void);