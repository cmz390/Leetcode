class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int M = matrix.size();
        int N = matrix[0].size();
        int i = 0;
        int j = 0;
        int k = 0;
        //from left to right

        for(k = 0; k < N; k++)
        {
        	i = 0;
        	j = k;

        	while(i < M && j < N)
        	{
        		if(matrix[i][j] != matrix[0][k]) return false;
        		i++;
        		j++;
        	}
        }


        //from up tp bottom

        for(k = 0; k < M; k++)
        {
        	i = k;
        	j = 0;

        	while(i < M && j < N)
        	{
        		if(matrix[i][j] != matrix[k][0]) return false;
        		i++;
        		j++;
        	}
        }

        return true;

    }
};