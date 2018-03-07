#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
    	int marker = 0;

    	int left = tx;
    	int right = ty;

    	while(left > 0 && right >0)
    	{
    		if(left == sx && right == sy)
    		{
    			marker = 1;
    			break;
    		}
    		if(left > right)
    		{
    			left = left -right;
    		}
    		else
    		{
    			right = right - left;
    		}
    	}

    	if(marker == 1) return true;
    	return false;

    }
};


int main(int argc, char const *argv[])
{
	Solution s;
	cout <<s.reachingPoints(9,5,12,18);
	return 0;
}