class Solution {
public:
    bool isValid(string s) {
        
        int *a = new int[s.length()];
        
        int i = 0;
        int j = 0;
        
        for(i = 0; i < s.length(); i++)
        {
            a[i] = 0;
            if(s.at(i) == ')' || s.at(i) == ']' || s.at(i) == '}')
            {
                a[i] = 1;
                j = i;
                while(a[j] == 1 && j >0)
                {                   
                    j--;
                }
                
                if(s.at(i) == ')' && s.at(j) == '(') a[j] = 1;
                else if(s.at(i) == ']' && s.at(j) == '[') a[j] = 1;
                else if(s.at(i) == '}' && s.at(j) == '{') a[j] = 1;
                else return false;
            }
        }
        
    
        
        for(i = 0; i < s.length(); i++)
        {
            if(a[i] == 0) return false;
        }
        delete [] a;
        
        return true;
    }
};