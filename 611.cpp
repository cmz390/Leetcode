class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        
        int a[1001] = {0};
        int b[1001]= {0};
        int i, j;
        int result = 0;
        
        for(i = 0; i < nums.size(); i++)
            a[nums[i]]++;
        
        b[0] = a[0];
        for(i = 1; i < 1001; i++)
            b[i] += (b[i-1] + a[i]);
        
        sort(nums.begin(), nums.end());
        
        for(i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 1) continue;
            for(j = i + 1; j < nums.size(); j++)
            {
                if(nums[i] + nums[j] > 1000) 
                    result += ( b[1000]- j - 1);
                else
                    result += ( b[nums[i] + nums[j] -  1]- j - 1);                
            }
        }

        return result;        
    }
};