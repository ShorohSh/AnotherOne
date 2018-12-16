#include "8f-2.h"
#include <string.h>

int checkchisl(char* array)
{
	int check = 1;
	for (int i = 0; i < strlen(array); i++)
	{
		if (array[i]<'0' || array[i]>'9') check = 0;
	}
	return check;
}