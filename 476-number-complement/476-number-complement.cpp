class Solution {
public:
    int findComplement(int num) {
        int n = num;
        vector<int> binary;
        int rem = 0;
        
        while(n>0){    //decimal to binary
            rem = n%2;
            binary.push_back(rem);
            n /= 2;
        }
        
        for(int i=0;i<binary.size();i++){
            if(binary[i]==0) binary[i] = 1;
            else binary[i] = 0;
        }
        
        int ans = 0;   //binary to decimal
        for(int i=0;i<binary.size();i++){
            ans += binary[i]*pow(2,i);
        }
        return ans;
    }
};