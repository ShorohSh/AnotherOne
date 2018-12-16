#include "8f-6.h"
#include <string.h>

int sortstr(char* array1, char* array2)
{
	int min = 0;
	if (strlen(array1) < strlen(array2)) min = strlen(array1); else
		min = strlen(array2);

	for (int i = 0; i < min; i++)
	{
		char a;
		char b;
		if (array1[i] < 'Z' && array1[i] > 'A') a = char(array1[i] + 32); else a = char(array1[i]);
		if (array2[i] < 'Z' && array2[i] > 'A') b = char(array2[i] + 32); else b = char(array2[i]);

		if (a > b) return 1;
		if (a < b) return 2;
	}
	return 0;
}