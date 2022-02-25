class Solution {
public:
    int compareVersion(string v1, string v2) {
        int n1 = v1.size(), n2 = v2.size();
        int i = 0, j = 0;                       //to traverse v1 & v2
        
        while(i<n1 || j<n2){
           int num1 = 0, num2 = 0;
            
           while(i<n1 && v1[i]!='.'){
               num1 = num1*10 + (v1[i]-'0');    //v1[i]-'0' to convert string to number
               i++;
           }
            while(j<n2 && v2[j]!='.'){
                num2 = num2*10 + (v2[j]-'0');    //ex-'1'-'0' = 1
                j++;
            }
            if(num1>num2) return 1;
            else if(num1<num2) return -1;
            i++;
            j++;
        }
        return 0;
    }
};