#include <iostream>
using namespace std;

//uxxdlselxmwyiguugtpsypfudffswvwyswyyiiyywsywvsffdufpysptguugiywmxlesldxxu

int palindromeIndex(string s){
    // Complete this function
    int i = 0;
    for(i = 0; i <= s.length()/2; i++)
    {
        if(s.at(i) != s.at(s.length() - i -1))
        {
            //cout <<s.length() <<' ' <<i <<' ' <<s.at(i) <<' ' <<s.length() - i -1 <<' ' <<s.at(s.length() - i -1) <<endl;
            if(s.at(i) == s.at(s.length() - i - 2) && s.at(i + 1) == s.at(s.length() - i - 3)) return s.length() - i -1;
            else return i; 
        }
    }
    return -1;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
