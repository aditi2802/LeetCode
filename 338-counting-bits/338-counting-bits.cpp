class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        ans.push_back(0);
        int temp;
        for(int i=1;i<=n;i++){
           if(i%2==0){
               temp = ans[i/2];
           }
           else{
               temp = ans[i/2]+1;
           }
            
           ans.push_back(temp);
        }
        return ans;
    }
};

/*
if the number is even then the number of ones is same as that when we right shift that number.
since division by 2 is same as right shift we divide the number by two to get the answer

When number is odd, then while performing rigth shift the rightmost bit (which is one) is lost, therefore we add one to the answer.

*/