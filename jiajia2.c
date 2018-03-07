#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * solution(char * S)
{

	int digit[4] = {0};
	int result[4] = {0};
	int temp[4] = {0};

	digit[0] = S[0] - '0';
	digit[1] = S[1] - '0';
	digit[2] = S[3] - '0';
	digit[3] = S[4] - '0';	

	int i = 0;
	int j = 0;
	int hour = digit[0] * 10 + digit[1];
	int min = digit[2] * 10 + digit[3];
	int allmin = hour * 60 + min;
	int h = 0;
	int m = 0;
	int allm = 0;
	int minn = 24*60 + 1;
	int tm = 0;

				result[0] = digit[0];
				result[1] = digit[1];
				result[2] = digit[2];
				result[3] = digit[3];


	int all[6][4] = {0, 1, 2, 3,
				   	 0, 2, 1, 3,
				   	 0, 2, 3, 1,
				   0, 1, 3, 2,
				   0, 3, 1, 2,
				   0, 3, 2, 1};

	for( i = 0; i < 4; i++)
	{

		for(j = 0; j < 6; j++)
		{
			temp[0] = digit[(all[j][0] + i) % 4];
			temp[1] = digit[(all[j][1] + i) % 4];
			temp[2] = digit[(all[j][2] + i) % 4];
			temp[3] = digit[(all[j][3] + i) % 4];
			h = temp[0]*10 + temp[1];
			m = temp[2]*10 + temp[3];

			allm = h*60 + m;

			if( h > 23 ||  m > 59) continue;

			if(allm - allmin <= 0)
			{
				tm = allm + 24*60 - allmin;

			}
			else
			{
				tm = allm- allmin;
			}

			if(tm < minn)
			{
				result[0] = temp[0];
				result[1] = temp[1];
				result[2] = temp[2];
				result[3] = temp[3];
				minn = tm;

			}


		}
	}

	char * final = malloc(sizeof(char)*6);
	final[0] = result[0] + '0';
	final[1] = result[1] + '0';
	final[2] = ':';
	final[3] = result[2] + '0';
	final[4] = result[3] + '0';
	final[5] = '\0';
	return final;

}


int main(int argc, char const *argv[])
{
	/* code */
	char* s = "23:59";
	char *r = solution(s);
	printf("%s\n", r);
	return 0;
}