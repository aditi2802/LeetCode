class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        set<string> s1(words.begin(),words.end());
        //set<string> s2(words.begin(), words.end());
        
        for(auto it : s1){
            //time
            for(int i=1;i<it.size();i++){
                s1.erase(it.substr(i));  //ime me e
            }
        }
        
        int ans = 0;
        for(auto it : s1){
            ans += it.size()+1;
        }
        return ans;
    }
};