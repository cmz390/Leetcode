#include <iostream>
#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
		vector<int> partitionLabels(string S) {
        
        int character[26];
        int i = 0;
        int now = 0;
        int end = 0;
        int part = 0;
        std::vector<int> result;

        for(i = 0; i < S.length(); i++)
        {
        	character[S.at(i) - 'a'] = i;
        }

        now = 0;
        end = character[S.at(now) - 'a'];

        while(now < S.length())
        {
        	part = 0;
        	end = character[S.at(now) - 'a'];
			while(now <= end)
			{
				if(character[S.at(now) - 'a'] > end) end = character[S.at(now) - 'a'];
				part++;
				now++;
			}   
			 result.push_back(part);     	
        }

        return result;

    }
};

int main(int argc, char const *argv[])
{
	/* code */
	Solution s;
	string a = "ababcbacadefegdehijhklij";
	cout <<s.partitionLabels(a)[0] <<'\n';

	return 0;
}