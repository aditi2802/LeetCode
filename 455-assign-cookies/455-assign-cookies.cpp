class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        
        int n=g.size();
        int m = s.size();
        int i=0, j=0,ans=0;
               
        sort(s.begin(), s.end(), greater<int>());
        sort(g.begin(), g.end(), greater<int>());
        
        
        while(i<n and j<m){
            if(g[i]<= s[j]){
                ans++;
                i++; j++;
            }else{
                i++;
            }
        }
        return ans;
    }
};
