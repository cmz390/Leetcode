
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int solution(int P[], int N, int K)
{
	int* A = malloc(sizeof(int)* N );
	int sum = 0;
	int i = 0;
	int j = 0;


	for(i = 0; i < N; i++)
	{
		A[i] = 1;
		
	}


	for(i = N - 1; i >=0; i--)
	{


		sum = 0;

		for(j = 0; j < N; j++)
		{
			if(A[j] == 1) sum++;
			else 
			{
				if(sum == K) return i+1;
				sum = 0;
			}

			//printf("%d %d\n",i, sum);


		}

		if(sum == K) return i+1;

		A[P[i]-1] = 0;
	}

	return -1;

}


int main(int argc, char const *argv[])
{
	/* code */
	int P[] = {3,1,5,4,2};
	int r = solution(P, 5, 5);
	printf("%d\n", r);
	return 0;
}