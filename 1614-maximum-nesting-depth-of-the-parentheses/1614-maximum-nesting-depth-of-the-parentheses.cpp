class Solution {
public:
    int maxDepth(string s) {
        int open = 0;
        int ans = 0;
        stack<int>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(s[i]);
                open++;   //count the number of open brackets 
                ans = max(open, ans); //save the max count of open brackets 
            }
            if(s[i]==')'){
                st.pop();
                open--;  //reduce the count as you close them
            }
        }
        return ans;
    }
};