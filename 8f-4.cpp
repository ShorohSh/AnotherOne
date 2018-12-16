#include "8f-4.h"
#include <stdio.h> 
#include <stdlib.h>
#include "struct.h"

void winfile(int &razf, muz* &arrayf)
{
	remove("test.txt");
	FILE *fl = fopen("test.txt", "w");
	fwrite(&razf, sizeof(int), 1, fl);
	for (int cf = 0; cf<razf; cf++)
		fwrite(&arrayf[cf], sizeof(muz), 1, fl);
	fclose(fl);
}