class Solution {
public:

	int primeshu(int a)
	{
		int i = 0;
		if(a < 2) return 1;
		for(i = 2; i <= (int)(sqrt(a)); i++)
		{
			if(a % i == 0) return 1;
		}

		return 0;
	}

    int countPrimeSetBits(int L, int R) {
        
        int i = 0;
        int result = 0;
        int count = 0;
        int digit = 0;

        for(i = L; i <= R; i++)
        {
        	digit = i;

        	while(digit!=0)
        	{
        		if(digit&1 == 1) count++;
        		digit = digit >> 1;
        	}

        	if(primeshu(count) == 0) result++;

        }
        return result;
    }
};