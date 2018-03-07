class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {

    	int * p = new int[N];
    	int modified = 1;
    	int i = 0;
    	int newvalue;

    	for(i = 0; i < N; i++)
    	{
    		p[i] = 1000000;
    	}

    	p[K - 1] = 0;

    	while(modified == 1)
    	{
    		modified = 0;

    		for( i = 0; i < times.size(); i++)
    		{
    			newvalue =  p[times[i][0] - 1] + times[i][2]; 
    			if(newvalue < p[times[i][1] - 1])
    			{
    				p[times[i][1] - 1] = newvalue;	
    				modified = 1;
    			}
    		}

    	}


    	int maxv = 0;

    	for( i = 0; i < N; i++)
    	{
    		if(p[i] > maxv) maxv = p[i];
    	}
        
        if(maxv == 1000000) return -1;
    	return maxv;
        
    }
};