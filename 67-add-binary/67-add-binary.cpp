class Solution {
public:
    string addBinary(string a, string b) {
    if(a.size() < b.size()) return addBinary(b, a);
    int n = 0;
    for(int i=a.size()-1, j=b.size()-1; i>=0; i--, j--) {
        if(n == 0 && j < 0) break;
        if(a[i] == '1') n++;
        if(j >= 0 && b[j] == '1') n++;
        a[i] = (n%2 == 0 ? '0' : '1');
        n /= 2;
    }
    if(n) a = "1" + a;
    return a;
    }

};