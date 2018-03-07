#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
    int kthGrammar(int N, int K) {
        
    	int i = N - 1;
    	int now = pow(2, i);
    	int result = 0;

    	if(N ==1) return 0;
    	if(K > now/2)
    	{
    		result = 1;

    		K = K - now/2;
    	}
    	else
    	{
    		result = 0;
    		K = K;
    	}

    	i--;

		//cout << now <<' ' << i <<' ' <<K <<'\n';
    	while(i > 0)
    	{
    		now = pow(2, i);
    		if(K > now/2)
    		{
    			if(result == 1) result = 0;
    			else result = 1;


    			K = K - now/2;
    		}
    		else
    		{
    			if(result == 1) result = 1;
    			else result = 0;
    			K = K;
    		}

    	i--;

    	}

    	// if( i == 1)
    	// {
    	// 	if(K == 1) return 0;
    	// 	else return 1;
    	// }

    	return result;


    }
};

int main(int argc, char const *argv[])
{
	Solution s;
	cout << s.kthGrammar(3, 4) <<'\n';
	return 0;
}