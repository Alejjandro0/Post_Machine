#include "DoublyLinkedListBool.h"
#include <stdlib.h>
#include <stdio.h>

static DL_Node* head = NULL;
static DL_Node* tail = NULL;

static DL_Node* _CreatNode(void) 
{
    DL_Node* node = (DL_Node*)malloc(sizeof(DL_Node));
    if (node == NULL) {
        printf("ERROR: Stack overflow.");
        exit(1);
    }

    node->date = false;
    node->next = NULL;
    node->prev = NULL;

    return node;
}


DL_Node* DL_Init(void)
{
    DL_Node* node = _CreatNode();

    head = tail = node;

    return node;
}

void DL_Destroy(void)
{
    DL_Node* node = head;
    DL_Node* nodeDel;

    while (node != NULL)
    {
        nodeDel = node;
        node = node->next;
        free(nodeDel);
    }
}

DL_Node* DL_Next(DL_Node* node)
{
    if (node->next == NULL) {
        node->next = _CreatNode();
        node->next->prev = node;
        tail = node->next;
    }

    return node->next;
}

DL_Node* DL_Prev(DL_Node* node)
{
    if (node->prev == NULL) {
        node->prev = _CreatNode();
        node->prev->next = node;
        head = node->prev;
    }

    return node->prev;
}

void DL_Print(void) {
    DL_Node* pTapeHead = head;
    DL_Node* pTapeTail = tail;

    while (pTapeHead != NULL)
    {
        if (pTapeHead->date == 1) {
            break;
        }
        pTapeHead = pTapeHead->next;
    }

    if (pTapeHead != NULL) {
        while (pTapeHead != NULL)
        {
            if (pTapeTail->date == 1) {
                break;
            }
            pTapeTail = pTapeTail->prev;
        }

        while (pTapeHead != pTapeTail) {
            printf("%i", pTapeHead->date);
            pTapeHead = pTapeHead->next;
        }
        printf("%i", pTapeHead->date);
    }
    else
    {
        printf("0");
    }
}
