#include <cmath>
#include <cerrno>
#include <cfenv>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        
        int an[1001] = {0};
        int i = 0;
        int sum = 0;
        for( i = 0; i < answers.size(); i++)
        {
            if(answers[i] == 0 ) 
            {sum++;
            continue;}
            else
            {
                if(an[answers[i]] == 0)
                {
                    an[answers[i]] = answers[i];
                    sum += (answers[i] + 1);
                }
                else
                {
                   an[answers[i]] --; 
                }
            }
        }
            
        return sum;
        
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    std::vector<int> v = {0,0,1,1,1};
    cout <<s.numRabbits(v);
    return 0;
}