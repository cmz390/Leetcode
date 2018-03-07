#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();        
        string rev(s);
        reverse(rev.begin(), rev.end());

        string a = s + "*" +rev;

        int m = a.size();
        int val, i;
        vector<int> v(m, 0);
        for(i = 1; i < m; i++)
        {
            val = v[i - 1];
            while(val > 0 && a[i] != a[val])
            {
                 val = v[val - 1];
            }
            
            if(a[i] == a[val]) ++val;
            
            v[i] = val;
        }
        
        return rev.substr(0, n - v[m - 1]) + s;
    }

};

class Solution {
public:
    int isPalindrome(string s, int j)
    {
        //cout <<"dafads" <<endl;
        int i = 0;
        int k = j;
        for(i = 0; i <= k/2; i++)
        {
            //cout <<s[i] <<' ' <<s[j] <<endl;
            if(s[i] != s[j]) return 0;
            //cout <<s[i] <<' ' <<s[j] <<endl;
                j--;
        }
        
        return 1;
    }
    string shortestPalindrome(string s) {
        
        int i , j ;
        
        for(j = s.length() - 1; j >=0; j--)
        {
            if(s[0]!= s[j]) continue;
            if(isPalindrome(s,j) == 1) break;
        }
        
       // cout <<j <<endl;
        std::string remaining = s.substr(j + 1, s.length() - j - 1);
        std::reverse(remaining.begin(), remaining.end());
        return remaining + s;
    }
};


int main(int argc, char const *argv[])
{
    Solution s;
    cout <<s.shortestPalindrome("abbabaab") <<endl;
    return 0;
}