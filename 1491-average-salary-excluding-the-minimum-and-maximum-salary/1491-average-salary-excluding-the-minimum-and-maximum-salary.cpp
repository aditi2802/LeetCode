class Solution {
public:
    double average(vector<int>& salary) {
        int minn = INT_MAX;
        int maxx = INT_MIN;
        double sum = 0;
        for(int i=0;i<salary.size();i++){
            minn = min(minn, salary[i]);
            maxx = max(maxx, salary[i]);
            sum += salary[i];
        }
        
        return (sum-minn-maxx)/(salary.size()-2);
        
    }
};