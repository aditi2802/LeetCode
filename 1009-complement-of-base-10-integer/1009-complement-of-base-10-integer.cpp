class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0){
          return 1;
        }
        vector<int> temp;
        while(n!=0){
            int r = n%2;
            temp.push_back(r);
            n/=2;
        }
        
        for(int i=0;i<temp.size();i++){
          if(temp[i]==0){
            temp[i]=1;
          }
            else{
             temp[i] = 0;
            }
        }
        
        int res = 0;
        for(int i=temp.size()-1;i>=0;i--){
          res = res*2 + temp[i];
        }
        return res;
    }
        
};