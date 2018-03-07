#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class WordFilter {
public:

	std::map<string, int> mymap;

    WordFilter(vector<string> words) {

    	int i = 0;
    	int j = 0;

    	for(i = 0; i < words.size(); i++)
    	{
    		for(j = 0; j < words[i].length(); j++)
    		{
    			string temp = words[i].substr() + "#" + words[i];
    			mymap[] = i;
    		}
    	}
        
    }
    
    int f(string prefix, string suffix) {
        
    }
};
