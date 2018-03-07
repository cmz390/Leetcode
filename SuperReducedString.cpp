#include <iostream>
#include <vector>
#include <string>

using namespace std;

string super_reduced_string(string s){
    // Complete this function
    int i = 0;
    int marker = 1;
    

    while(marker == 1)
    {
        marker = 0;
        
        for(i = 0; i < s.length()-1; i++)
        {
            if(s.at(i) == s.at(i+1)) 
            {
                marker = 1;
                if(s.length()>2) s.erase(i, 2);
                else return "Empty String";

            }
        }

    }

    if(s.length()==0) return "Empty String";
    return s;
       
}

int main() {
    string s;
    cin >> s;
    string result = super_reduced_string(s);
    cout << result << endl;
    return 0;
}
