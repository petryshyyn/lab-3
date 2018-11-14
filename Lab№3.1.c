#include<stdio.h>
#define n 5

void starterArray(int array[n][n]);
void sortedArray(int array[n][n]);
void selectionSort(int* array, int length_array);
void dobutokColUnderHelperDiagonal(int array[n][n]);
main(void)
{
	int Rows, Column;
	static int array[n][n];
	printf("Matrix coordinates\n");
	for (Rows = 0; Rows < n; Rows++)
	{
		for (Column = 0; Column < n; Column++)
		{
			printf("a[%d][%d] = ", Rows + 1, Column + 1);
			scanf("%d", &array[Rows][Column]);
		}

	}
	starterArray(array);
	sortedArray(array);
	dobutokColUnderHelperDiagonal(array);
}
void starterArray(int array[n][n])
{
	int Rows, Column;
	printf("old array\n");
	for (Rows = 0; Rows < n; Rows++)
	{
		for (Column = 0; Column < n; Column++)
			printf("%5d", array[Rows][Column]);
		printf("\n");
	}
}
void sortedArray(int array[n][n])
{
 int mas[n];
 int Rows, Column;
 printf("new array\n");
 for (int Rows = 0; Rows < n; Rows++)
	{
	 for (int Column = 0; Column < n; Column++)
		{
		 mas[Column] = array[Rows][Column];
		}
	 selectionSort(mas,n);
	}
}


void selectionSort(int* array, int length_array)
{
	for (int Rows = 0; Rows < length_array; Rows++)
	{
		int temp = array[0]; // тимчасова зміна для зберігання значеня перестановки
		for (int Column = Rows + 1; Column < length_array; Column++)
		{
			if (array[Rows] < array[Column])
			{
				temp = array[Rows];
				array[Rows] = array[Column];
				array[Column] = temp;
			}
		}
	}
	for (int Rows = 0; Rows < n; Rows++)
	{
		printf("%5d", array[Rows]);
	}
	printf("\n");
}
void dobutokColUnderHelperDiagonal(int array[n][n])
{
	double sum, arrayValue;
	int dobutok = 1;
	for (int Column = 0; Column < 4; Column++)
	{
		sum = 0.0;
		for (int Rows = 0; Rows < 4 - Column; Rows++)
		{
			sum += array[Rows][Column];
		}
		arrayValue = sum / (4 - Column);
		printf("\n average value is %lf \n", arrayValue);
		dobutok *= (sum / (4 - Column));
	}
	printf("\nDobutok value is %d", dobutok);
}