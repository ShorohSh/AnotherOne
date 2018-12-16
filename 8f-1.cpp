#include "8f-1.h"
#include <stdio.h> 
#include <string.h>
#include <conio.h> 

char* vvodstr()
{
	char *sf = new char[1];
	sf[0] = '\0';
	char simbol;

	simbol = getch();
	printf("%c", simbol);

	while (simbol != 13 && simbol != ' ')
	{
		if (simbol == 8 && strlen(sf) == 0) continue;

		if (simbol == 8)
		{
			printf(" ");
			printf("%c", 8);
			sf[strlen(sf) - 1] = '\0';
			continue;
		}

		char *news = new char[strlen(sf) + 2];

		strcpy(news, sf);
		news[strlen(sf)] = simbol;
		news[strlen(sf) + 1] = '\0';

		char* x;
		x = sf;
		delete[] x;

		sf = news;

		simbol = getch();
		printf("%c", simbol);
	}
	printf("\n");

	return sf;
}