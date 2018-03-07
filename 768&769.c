#include <stdio.h>
#include <stdlib.h>

int maxChunksToSorted(int* arr, int arrSize) {
    

    int i = 0;

    int result = 1;

	//find the min beind him

	int * min_n = malloc(sizeof(long long) * arrSize);

	long long min_each = *(arr + arrSize - 1);

	*(min_n + arrSize - 1) = *(arr + arrSize - 1);

    for(i = arrSize - 1; i >= 0; i--)
    {
    	if(*(arr+i) <= min_each)
    	{
    		min_each = *(arr+i);
    	}

    	*(min_n + i) = min_each;
    }



    //find the max before him


    int * max_n = malloc(sizeof(long long) * arrSize);

	long long max_each = *arr;

	*(max_n + 0) = *(arr + 0);

    for(i = 0; i < arrSize; i++)
    {
    	if(*(arr+i) >= max_each)
    	{
    		max_each = *(arr+i);
    	}

    	*(max_n + i) = max_each;

    }


    //find the split number
    for(i = 0; i < arrSize-1; i++)
    {
    	if( *(max_n + i) <= *(min_n + i + 1))
    	{
    		result++;
    	}
    }


    return result;
}

int main(int argc, char const *argv[])
{
	/* code */
	int a[] = {2,1,3,4,4};
	int b[] = {5,4,3,2,1};
	int c[] = {1,0,1,3,2};	
	int d[] = {0, 0, 1, 1, 1};
	int e[] = {1, 1, 0, 0, 1};
	int f[] = {0,3,0,3,2};

	printf("%d\n", maxChunksToSorted(a, 5));
	printf("%d\n", maxChunksToSorted(b, 5));
	printf("%d\n", maxChunksToSorted(c, 5));	
	printf("%d\n", maxChunksToSorted(d, 5));
	printf("%d\n", maxChunksToSorted(e, 5));
	printf("%d\n", maxChunksToSorted(f, 5));
	return 0;
}