#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
	int a[28] = {0};
	int b[28] = {0};
	int result = 0;
	int i , j , k;

	//first three digits
	for(i = 1; i < 10; i++)
		for(j = 0; j < 10; j++)
			for(k = 0; k < 10; k++)
				a[i + j + k]++;

	//last three digits
	for(i = 0; i < 10; i++)
		for(j = 0; j < 10; j++)
			for(k = 0; k < 10; k++)
				b[i + j + k]++;

	for(i = 0; i < 28; i++)
		result +=(a[i] * b[i]);

	printf("%d\n", result);

	return 0;
}