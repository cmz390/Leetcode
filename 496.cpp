#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        map<int, int> m;
        vector<int> v;
        int j, i,marker;
        for(i=0; i<nums.size(); i++)
        {   marker=1;
        	for(j=i+1; j<nums.size();j++)
        	{
        		if(nums[j]>nums[i])
        		{
        			m[nums[i]]=nums[j];
        			marker=0;
        			break;
        		}
        	}
        	if(marker) {m[nums[i]]=-1;}
        }

        for(i=0;i<findNums.size();i++)
        {
        	v.push_back(m[findNums[i]]);
        }
    
    return v;}
};