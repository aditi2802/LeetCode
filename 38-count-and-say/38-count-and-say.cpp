class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        if(n==2) return "11";
        string curr = "11";
        int count = 1;
        
        for(int i=3;i<=n;i++){
            string ans = "";
            for(int j=1;j<=curr.size();j++){
                if(curr[j-1]!=curr[j]){
                    ans += to_string(count);
                    ans += curr[j-1];
                    count = 1;
                }
                else{
                    count++;
                }
            }
            curr = ans;
        }
        return curr;
    }
};