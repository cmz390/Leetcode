class Solution {
public:
	int check(vector<int>& b)
	{
		int i = 0;
		int j = 0;
		int count = 0;
		int tempory = 0;

		for(i = 0; i < b.size(); i++)
		{
			if(b[i]!=0)
			{
				tempory = b[i];
				for(j = i; j < b.size(); j++ )
				{
					if(b[j] < tempory && b[j]!=0) count++;
				}
			}
		}

		return count%2;
	}

    int slidingPuzzle(vector<vector<int>>& board) {

    	//I am familar with one dimentional vector, I modify the input into one dimentional vector
    	std::vector<int> b = {board[0][0], board[0][1], board[0][2],board[1][0], board[1][1],board[1][2] };

    	//0 : up, 1 : down, 2 : left, 3 : right;
    	std::vector<int> fobidden;

    	//used to record the step;
    	std::vector<int> step;

    	//used to record the board status for each step;
    	std::vector<vector<int>> status;

    	//zero position
    	std::vector<int> position;

    	// check if it has possible solutions
    	if(check(b) == 1) return -1;

    	//Initial.
    	std::vector<int> v0 = {1,2,3,4,5,0};
    	status.push_back(v0);
    	step.push_back(0);
    	fobidden.push_back(1);
    	position.push_back(5);

    	int i = 0;
    	int row = 0;
    	int col = 0;
    	int newr = 0;
    	int newc = 0;

    	while(i < 10000)
    	{	//avoid infint loop
    		
    		if(status[i] == b) return step[i];

    		row = position[i]/3;
    		col = position[i]%3;

    		//up
    		if(row == 1 && fobidden[i] != 0)
    		{
    			newr = 0;
    			newc = col;

    			vector<int> v1 = status[i];
    			v1[row*3+col] = v1[newr*3+newc];
    			v1[newr*3+newc] = 0;
    			//update
    			status.push_back(v1);
    			step.push_back(step[i]+1);
    			fobidden.push_back(1);
    			position.push_back(newr*3+newc);
    		}

    		//down
    		if(row == 0 && fobidden[i] != 1)
    		{
    			newr = 1;
    			newc = col;

    			vector<int> v1 = status[i];
    			v1[row*3+col] = v1[newr*3+newc];
    			v1[newr*3+newc] = 0;
    			//update
    			status.push_back(v1);
    			step.push_back(step[i]+1);
    			fobidden.push_back(0);
    			position.push_back(newr*3+newc);
    		}

    		//left
    		if(col != 0 && fobidden[i] != 2)
    		{
    			newr = row;
    			newc = col - 1;

    			vector<int> v1 = status[i];
    			v1[row*3+col] = v1[newr*3+newc];
    			v1[newr*3+newc] = 0;
    			//update
    			status.push_back(v1);
    			step.push_back(step[i]+1);
    			fobidden.push_back(3);
    			position.push_back(newr*3+newc);
    		}

    		//right
    		if(col != 2 && fobidden[i] != 3)
    		{
    			newr = row;
    			newc = col+1;

    			vector<int> v1 = status[i];
    			v1[row*3+col] = v1[newr*3+newc];
    			v1[newr*3+newc] = 0;
    			//update
    			status.push_back(v1);
    			step.push_back(step[i]+1);
    			fobidden.push_back(2);
    			position.push_back(newr*3+newc);
    		}

    		i++;


    	}

    	return -1;
        
    }
};