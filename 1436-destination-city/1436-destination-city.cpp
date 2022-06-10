class Solution {
public:
    string destCity(vector<vector<string>>& paths){
            set<string> s;
    
    for(int i=0;i<paths.size();i++){
        s.insert(paths[i][0]); // inserting the src
    }
    
    for(int i=0;i<paths.size();i++){
        if(s.find(paths[i][1]) == s.end())   // checking for dest in set
            return paths[i][1];
    }
    
    return "";

    }
};