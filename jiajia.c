#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * solution(char *S, int K)
{
	int N = strlen(S);
	int gg = N/K;

	char *result = malloc(sizeof(char) * (N + gg + 10));

	int i = 0;
	int j = 0;
	int k = 1;

	for(i = 0; i < N; i++)
	{
		if(S[N - 1 - i] != '-')
		{
			if(k%(K+1) == 0) 
			{
				result[j] = '-';
				k++;
				j++;
			}
			if(S[N - 1 - i] >= 'a' && S[N - 1 - i] <='z') result[j] = S[N - 1 - i] - 32;
			else result[j] = S[N - 1 - i]; 

			j++;
			k++;
		}

	}

	result[j] = '\0';

	N = strlen(result);
	char *final = malloc(sizeof(char) * (N+1));

	for(i = 0; i < N; i++)
	{
		final[i] = result[N - 1 -i];
	}

	final[i] = '\0';
	free(result);
	return final;

}

int main(int argc, char const *argv[])
{
	/* code */
	char* s = "r";
	char *r = solution(s, 1);
	printf("%s\n", r);
	return 0;
}