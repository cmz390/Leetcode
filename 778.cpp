#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	int mone(vector<vector<int>>& grid, int marker[], int N, int row, int col, int limit)
	{

		if(row < 0 || row >= N || col < 0 || col >= N) return 0;
		if(marker[row * N + col] == 1 ) return 0;
		if(grid[row][col] <= limit)
		{
			marker[row * N + col] = 1;
			mone(grid, marker, N, row-1, col, limit);
			mone(grid, marker, N, row+1, col, limit);
			mone(grid, marker, N, row, col-1, limit);
			mone(grid, marker, N, row, col+1, limit);

		} 

		return 0;
	}

	int reset(int marker[], int N)
	{
		int i = 0;
		for(i = 0; i < N*N -1; i++)
			marker[i] = 0;
		return 0;
	}
    
    int swimInWater(vector<vector<int>>& grid) {
     
    int N = grid.size();

    int marker[50*50] = {0};  
    int i = 0;
    int j = 0;

    int result = grid[N-1][N-1];

    int limit = N * N - 1;


    while(result < limit)
    {

    	reset(marker, N);

    	mone(grid, marker, N, 0, 0, result);

    	if(marker[N*N-1] == 1) return result;
    	else result++;
    }



    return result;

    }
};




int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	vector<vector<int>> grid = {{0,1,2,3,4},{24,23,22,21,5},{12,13,14,15,16},{11,17,18,19,20},{10,9,8,7,6}};
	cout << s.swimInWater(grid) <<'\n';
	return 0;
	return 0;
}