class Solution {
private:
int f(int i, int n, int k, vector<int>&arr, vector<int> &dp){
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];
    int len = 0;
    int maxEle = INT_MIN;
    int maxSum= INT_MIN;
    
    for(int j=i;j<min(i+k,n);j++){
        len++;
        maxEle = max(maxEle, arr[j]);
        int sum = len*maxEle + f(j+1, n, k, arr, dp);
        maxSum = max(maxSum, sum);
    }
    return dp[i]=maxSum;
}
    
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> dp(n, -1);
        return f(0, n, k, arr, dp);
    }
};