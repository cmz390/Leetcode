#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        int b[N][N];
        int i = 0;
        int j = 0;

        for(i = 0; i < N; i++)
        {
        	for(j = 0; j < N; j++)
        	{
        		b[i][j] = 1;
        	}
        }

        for(i = 0; i < mines.size(); i++)
        {
        	b[mines[i][0]][mines[i][1]] = 0;
        }


        for(i = 0; i < N; i++)
        {
        	for(j = 0; j < N; j++)
        	{
        		b[i][j] = 1;
        	}
        }
    }
};