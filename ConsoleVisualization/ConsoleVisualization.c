#include "ConsoleVisualization.h"
#include <stdlib.h>
#include <stdio.h>

const size_t length_visible_part = 21;
const char filled_label = '1';
const char empty_label = '0';
const char pointer_label = 'V';

void CS_Init(DL_Node* pTape)
{
	size_t shift = (length_visible_part - 1) / 2;
	for (int i = 0; i < shift; i++)
		putchar(' ');

	putchar(pointer_label);

	for (int i = 0; i < shift; i++)
		putchar(' ');

	putchar('\n');
	CS_Show(pTape);
}

void CS_Show(DL_Node* pTape)
{
	size_t shift = (length_visible_part - 1) / 2;
	for (int i = 0; i < shift; i++)
		pTape = DL_Prev(pTape);

	putchar('\r');
	for (int i = 0; i < length_visible_part; i++) {
		if (pTape->date == 0) {
			putchar(empty_label);
		}
		else
		{
			putchar(filled_label);
		}
		pTape = DL_Next(pTape);
	}
}
