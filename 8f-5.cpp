#include "8f-5.h"
#include "struct.h"
#include <stdio.h> 
#include <stdlib.h>

muz* rfromfile(int &razf)
{
	FILE *fl = fopen("test.txt", "r");
	fread(&razf, sizeof(int), 1, fl);
	muz* arrayf = new muz[razf];
	for (int cf = 0; cf<razf; cf++)
		fread(&arrayf[cf], sizeof(muz), 1, fl);
	fclose(fl);

	return arrayf;
}