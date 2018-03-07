class Solution {
public:
    bool canTransform(string start, string end) {
        
        int i = 0;
        int j = 0;

        for(i = 0; i < start.length(); i++)
        {
        	if(start.at(i) == 'X') continue;
        	else
        	{
        		while(j < end.length() && end.at(j) == 'X') j++;
        		if(j == end.length()) return false;
        		if(start.at(i) != end.at(j)) return false;
        	}
        }
        j++;
        if(j < end.length())
        {
        	while(j < end.length() && end.at(j) == 'X') j++;
        	if(j == end.length()) return true;
        	else return false;
        }
        return true;
    }
};