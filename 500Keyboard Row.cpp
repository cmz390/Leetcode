#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> result;
        int v;
        for(v=0;v<words.size();v++)
        {   string s=words[v];
            if(isOneLine(s))
                result.push_back(s);
            // cout <<s <<"\n";
        }

        return result;

    }

    bool isOneLine(string s)
    {
        
        string firstline="QWERTYUIOPqwertyuiop";
        string secondline="ASDFGHJKLasdfghjkl";
        string thirdline="ZXCVBNMzxcvbnm";
        int marker = 1;
        int stand = 0;
        int i;
        int base['z'-'A'+1];
         vector<char> ss(s.c_str(), s.c_str() + s.size());
        vector<char> s1(firstline.c_str(), firstline.c_str() + firstline.size());
        vector<char> s2(secondline.c_str(), secondline.c_str() + secondline.size());
        vector<char> s3(thirdline.c_str(), thirdline.c_str() + thirdline.size());

        for(i=0; i< 'z'-'A'+1; i++)
        {
            base[i]=0;
        }

        for(i=0;i<s1.size();i++)
        {
            //cout <<s1[i] <<"\n";
            base[s1[i]-'A']=1;
        }
        for(i=0;i<s2.size();i++)
        {
            base[s2[i]-'A']=2;
        }
        for(i=0;i<s3.size();i++)
        {
            base[s3[i]-'A']=3;
        }

        stand=base[ss[0]-'A'];

        for(i=1; i<ss.size();i++)
        {
            if(base[ss[i]-'A']!=stand) marker=0;
        }

        if(marker) return true;
        else 
        return false;

    }
};



int main()
{   
Solution a;
    int c;
    vector<string> v;
    v.push_back("qwertyuiop");
    //v.push_back("GhaK");
    vector<string> r;
    r=a.findWords(v);
    for(c=0;c<r.size();c++)
        {
            cout <<r[c] <<"\n";
        }


    return 0;
}