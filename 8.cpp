#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <locale.h> 
#include <conio.h> 
#include <time.h> 
#include <fstream>
#include <windows.h>

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

using namespace std;

#include "8f-1.h"
#include "8f-2.h"
#include "8f-3.h"
#include "8f-4.h"
#include "8f-5.h"
#include "8f-6.h"
#include "struct.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//setlocale(0, "");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	srand(time(0));

	int raz1;
	int flag = 0;
	int c;
	int vrem1 = 0;
	int vrem2 = 2019;
	int pos = 0;
	int c1;

	muz* array = NULL;
	char *s;

	int vib = 0, vibp = 0;
	int el;

	while (vib != 7) {

		printf("������� 1, ����� ������ ������ � ����������� �������������\n");
		printf("������� 2, ����� ������� ������ � ����������� �������������\n������� 3, ����� ������� ������� �������\n������� 4,");
		printf(" ����� ������������� ������ ����������� ������������ �� ������ �� �����\n������� 5, ����� ��������� ������� ���������� ");
		printf(" � ����������� ������������� � ����\n������� 6, ����� ��������� ������ � ����������� �������������");
		printf("�� �����\n������� 7, ����� ��������� ���������\n");

		s = vvodstr();
		vib = atoi(s);
		delete[] s;

		switch (vib)
		{
		case 1:
		{
			printf("������� ���������� ����������� ������������(�����, ������������� �����): ");

			s = vvodstr();

			while (checkchisl(s) == 0 || atoi(s) <= 0)
			{
				printf("������� ���������� ������\n");
				delete[] s;
				s = vvodstr();
			}

			raz1 = atoi(s);
			delete[] s;

			delete[] array;
			array = new muz[raz1];

			for (c = 0; c < raz1; c++)
			{
				vrem2 = 2019;
				pos = 0;

				printf("������� �����������: \n");
				s = vvodstr();
				strcpy(array[c].isp, s);
				delete[] s;

				printf("������� ������������ ������������ ������������: \n");
				s = vvodstr();
				strcpy(array[c].naim, s);
				delete[] s;

				printf("������� ���� ������� � ������� \"�� ����\": \n");
				while (vrem2>2018)
				{
					s = vvodstr();
					while (checkchisl(s) == 0 || atoi(s) > 13 || atoi(s) < 0)
					{
						printf("������� ���������� �����!\n");
						delete[] s;
						s = vvodstr();
					}

					vrem1 = atoi(s);
					delete[] s;

					s = vvodstr();
					while (checkchisl(s) == 0 || atoi(s) > 2018)
					{
						printf("������� ���������� ���!\n");
						delete[] s;
						s = vvodstr();
					}
					vrem2 = atoi(s);
					delete[] s;
				}
				array[c].date = vrem1 + vrem2 * 12;		

				printf("������� ������� � ��������: \n");
				array[c].pos = 0;
				while (array[c].pos == 0)
				{
					s = vvodstr();
					while (checkchisl(s) == 0 || atoi(s) <= 0)
					{
						printf("������� ���������� �������!\n");
						delete[] s;
						s = vvodstr();
					}

					pos = atoi(s);
					delete[] s;

					for (c1 = 0; c1<c; c1++)
					{
						if (pos == array[c1].pos)
						{
							printf("%d ������� ��� ������ ������������� %s!\n", pos, array[c1].naim);
							pos = 0;
							continue;
						}
					}
					array[c].pos = pos;
				}
				flag++;
			}
		}
		break;
		case 2:
		{
			if (flag == 0)
			{
				printf("����������� ����������� ������������!\n");
				continue;
			}

			if (raz1 == 0)
			{
				printf("�� �������� ����������� ������������, ������ ��������!\n\n");
				continue;
			}
			for (c = 0; c<raz1; c++)
			{

				if (array[c].date % 12 == 0) printf("%d)�����������: %s\n%d)������������: %s\n%d)���� ������: %d.%d\n%d)������� � ��������: %d\n%d)������ \"�������� ����\": ", c + 1, array[c].isp, c + 1, array[c].naim, c + 1, 12, array[c].date / 12, c + 1, array[c].pos, c + 1); else
					printf("%d)�����������: %s\n%d)������������: %s\n%d)���� ������: %d.%d\n%d)������� � ��������: %d\n%d)������ \"�������� ����\": ", c + 1, array[c].isp, c + 1, array[c].naim, c + 1, array[c].date % 12, array[c].date / 12, c + 1, array[c].pos, c + 1);
				if (array[c].pos <= 20 && 24226 - array[c].date > 3) printf("��\n\n"); else
					printf("���\n\n");
			}
		}
		break;
		case 3:
		{
			if (flag == 0)
			{
				printf("����������� ����������� ������������!\n");
				continue;
			}

			if (raz1 == 0)
			{
				printf("�� �������� ����������� ������������, �������� ����������!\n\n");
				continue;
			}

			printf("������� ����� ��������, ������� ���������� �������:\n");

			s = vvodstr();

			while (checkchisl(s) == 0 || atoi(s) > raz1 || atoi(s) < 1)
			{
				printf("������� ���������� �����!\n");
				delete[] s;
				s = vvodstr();
			}

			el = atoi(s);
			delete[] s;

			deleteel(array, el, raz1);
			raz1--;
		}
		break;
		case 4:
		{
			if (flag == 0)
			{
				printf("����������� ����������� ������������!\n");
				continue;
			}

			printf("������� 1, ����� ������������� �� ���� \"�����������\"\n������� 2, ����� ������������� �� ���� \"��������\"\n������� 3, ����� ������������� �� ���� \"���� ������\"\n������� 4, ����� ������������� �� ���� \"������� � ��������\"\n������� 5, ����� ������������� �� ���� \"������� ���\"\n");

			s = vvodstr();
			while (checkchisl(s) == 0 || atoi(s) < 1 || atoi(s) > 5)
			{
				printf("������� ���������� ������\n");
				delete[] s;
				s = vvodstr();
			}

			vibp = atoi(s);
			delete[] s;

			switch (vibp)
			{
			case 1:
			{
				for (int k = 0; k < raz1; k++)
					for (int l = k + 1; l < raz1; l++)
						if (sortstr(array[k].isp, array[l].isp) == 1) swap(array[k], array[l]);
			}
			break;
			case 2:
			{
				for (int k = 0; k < raz1; k++)
					for (int l = k + 1; l < raz1; l++)
						if (sortstr(array[k].naim, array[l].naim) == 1) swap(array[k], array[l]);
			}
			break;
			case 3:
			{
				for (int k = 0; k < raz1; k++)
					for (int l = k + 1; l < raz1; l++)
						if (array[k].date > array[l].date) swap(array[k], array[l]);
			}
			break;
			case 4:
			{
				for (int k = 0; k < raz1; k++)
					for (int l = k + 1; l < raz1; l++)
						if (array[k].pos > array[l].pos) swap(array[k], array[l]);
			}
			break;
			case 5:
			{

				for (int k = 0; k < raz1; k++)
					for (int l = k + 1; l < raz1; l++)
						if (array[c].pos <= 20 && 24226 - array[c].date > 3 && array[c].pos > 20 && 24226 - array[c].date <= 3) swap(array[k], array[l]);
			}
			break;
			}
		}
		break;

		case 5:
		{
			if (flag == 0)
			{
				printf("����������� ����������� ������������!\n");
				continue;
			}

			winfile(raz1, array);
		}
		break;

		case 6:
		{
			delete[] array;
			array = rfromfile(raz1);
			flag++;
		}
		break;

		case 7:
		{
			delete[] array;
		}
		break;
		default: {
			printf("\n������� ���������� ��������\n\n");
		}
		}
	}

	return 0;
}
