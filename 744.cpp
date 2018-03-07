class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        int minn = 27;
        char result = target;
        int i = 0;
        int distance = 0;

        while(i < letters.size())
        {
        	if(letters[i] - target <= 0) distance = 26 + letters[i] - target;
        	else distance = letters[i] - target;

        	if(distance < minn)
        	{
        		minn = distance;
        		result = letters[i];
        	}

        	i++;
        }

        return result;

    }
};