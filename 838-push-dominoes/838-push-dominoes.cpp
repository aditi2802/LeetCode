class Solution {
public:
    
// if (dominoes[i] == ch) { count = 1; prev = ch; } \
// else if (dominoes[i] != '.') prev = dominoes[i]; \
// if (prev == ch && dominoes[i] == '.') arr[i] = count++;
    
    string pushDominoes(string dom) {
        int n=dom.size();
        vector<int> right(n,0);
        vector<int> left(n,0);
        int count=1;
        char prev;
        for(int i=0;i<n;i++){
            if(dom[i]=='R'){
                count=1;
                prev='R';
            }
            else if(dom[i] != '.'){
                prev=dom[i];
            }
            if(prev=='R' && dom[i]=='.')
                right[i]=count++;
            
        }
        prev='.';
        for(int i=n-1;i>=0;i--){
            if(dom[i]=='L'){
                count=1;
                prev='L';
            }
            else if(dom[i] != '.'){
                prev=dom[i];
            }
            if(prev=='L' && dom[i]=='.')
                left[i]=count++;
        }
        string res="";
        for (int i = 0; i < n; i++) {
            if (!left[i] && !right[i]) res += dom[i];
            else if (!left[i]) res += 'R';
            else if (!right[i]) res += 'L';
            else if (left[i] == right[i]) res += '.';
            else if (left[i] < right[i]) res += 'L';
            else res += 'R';
        }
        
        return res;
    }
};