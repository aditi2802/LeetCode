class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int,int>> v;
        for(int i=0;i<s.size();i++){
            if(v.empty()) v.push_back({s[i],1});
            else if(v.back().first!=s[i]) v.push_back({s[i],1});
            else{
                v.back().second++;
                if(v.back().second==k) v.pop_back();
            }
        }
        
        string ans = "";
        for(int i=0;i<v.size();i++){
            ans.append(v[i].second,v[i].first);
        }
        return ans;
    }
};