#include "8f-3.h"
#include <stdio.h> 
#include <stdlib.h>
#include "struct.h"

void deleteel(muz *array, int pos, int raz)
{
	for (int i = pos; i < raz - 1; i++)
	{
		array[i] = array[i + 1];
	}
}