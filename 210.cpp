class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        map<int, vector<int>> mymap;
        vector<int> v(numCourses, 0);
        vector<int> result;
        vector<int> empty;
        int i = 0;
        int j = 0;
        for(i = 0; i < prerequisites.size(); i++)
        {
            mymap[prerequisites[i].second].push_back(prerequisites[i].first);
            v[prerequisites[i].first]++;
        }
        
        
        for(i = 0; i < numCourses; i++)
        {
            auto it = find(v.begin(), v.end(), 0);
            if(it != v.end())
            {
                int t = it-v.begin();

                result.push_back(t);
                for(j = 0; j < mymap[t].size(); j++)
                {
                    v[mymap[t][j]]--;
                }
                v[t] = -1;
            }
            else
            {
                return empty;   
            }
        }       
        return result;
    }
};