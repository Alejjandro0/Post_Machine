#include "SinglyLinkedListString.h"
#include <stdlib.h>
#include <stdio.h>

static SL_Node* head = NULL;
static SL_Node* tail = NULL;

// Создание узла
static SL_Node* _CreatNode(char cmd, size_t num1, size_t num2) 
{
    SL_Node* node = (SL_Node*)malloc(sizeof(SL_Node));
    if (node == NULL) {
        printf("ERROR: Stack overflow.");
        exit(1);
    }

    node->cmd = cmd;
    node->str1.number = num1;
    node->str1.point = NULL;
    node->str2.number = num2;
    node->str2.point = NULL;
    node->next = NULL;

    return node;
}

// Нахождение узла по номеру индекс 
static SL_Node* _FindNodeForIndex(size_t index) {
    SL_Node* node = head;

    for (size_t i = 1; i < index && node != NULL; i++) {
        node = node->next;
    }

    return node;
}

SL_Node* SL_Init(char cmd, size_t num1, size_t num2)
{
    SL_Node* node = _CreatNode(cmd, num1, num2);

    head = tail = node;

    return node;
}

void SL_Destroy(void)
{
    SL_Node* node = head;
    SL_Node* nodeDel;

    while (node != NULL)
    {
        nodeDel = node;
        node = node->next;
        free(nodeDel);
    }
}

SL_Node* SL_AddBack(char cmd, size_t num1, size_t num2)
{
    if (head == NULL && tail == NULL) {
        return SL_Init(cmd, num1, num2);
    }

    SL_Node* node = _CreatNode(cmd, num1, num2);   

    tail->next = node;
    tail = node;

    return node;
}

void SL_Optimizat(void)
{
    SL_Node* node = head;

    while (node != NULL)
    {
        if (node->str1.number > 0) {
            SL_Node* pointNode = _FindNodeForIndex(node->str1.number);
            if (pointNode == NULL) {
                printf("ERROR: The string was not found");
                exit(1);
            }
            node->str1.point = pointNode;

            if (node->str2.number > 0) {
                SL_Node* pointNode = _FindNodeForIndex(node->str2.number);
                if (pointNode == NULL) {
                    printf("ERROR: The string was not found");
                    exit(1);
                }
                node->str2.point = pointNode;
            }
        }
        node = node->next;
    }
}

SL_Node* SL_GetHead(void)
{
    return head;
}
