class Solution {
public:

	int step(int a[], int N)
	{

		int i = 0;
		int major = 0;
		int sum = 0;
		int result = 0;

		for(i = 0; i < N; i++)
		{
			sum += a[i];
		}

		if(abs(N - sum - sum) >1) return -1;
		if(sum > N - sum) major = 1;

		sum = 0;

		for(i = 0; i < N; i++)
		{
			if(a[i] == major)
			{
				if(i % 2 == 1) result++;


			}
		}

		sum = 0;

		if( N % 2 == 0)
		{
			major = 1;

			for(i = 0; i < N; i++)
			{	
				if(a[i] == major)
				{
					if(i % 2 == 1) sum++;

				}
			}
            if( sum > result) return result;
		    else return sum;
		}
        
        return result;

		
	}




    int movesToChessboard(vector<vector<int>>& board) {

		//deal with row
		int N = board.size();
		int rows[N] = {0};
		int col[N] = {0};
		int i = 0;
		int j = 0;
		int marker = 0;
		for(i = 0; i < N; i++)
		{
			if(board[i] == board[0]) rows[i] = 0;
			else 
				{
					if(marker == 0) marker = i;
					if(board[i] == board[marker]) rows[i] = 1;
					else return -1;
				}
		}

		if(marker == 0) return -1;

		vector<vector<int>> v(N, vector<int>(N));

		for(i = 0; i < N; i++)
		{
			for(j = 0; j < N; j++)
			{
				v[i][j] = board[j][i];
			}
		}

		marker = 0;
		for(i = 0; i < N; i++)
		{
			if(v[i] == v[0]) col[i] = 0;
			else 
				{
					if(marker == 0) marker = i;
					if(v[i] == v[marker]) col[i] = 1;
					else return -1;
				}
		}
		
		if(marker == 0) return -1;

        i = step(rows, N);
        j = step(col, N);

        if(i < 0 || j < 0) return -1;

        return i + j;

    }
};