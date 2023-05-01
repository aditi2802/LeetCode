//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    private:
    bool f(int i, int j, string wild, string pattern){
        if(i<0 && j<0) return true;
        if(i<0 && j>=0) return false;
        if(i>=0 && j<0){
            for(int x=0;x<=i;x++){
                if(wild[x]!='*') return false;
            }
        }
        
        if(wild[i]==pattern[j] || wild[i]=='?') return f(i-1, j-1, wild, pattern);
        
        if(wild[i]=='*') return f(i-1, j, wild, pattern) || f(i, j-1, wild, pattern);
    }
    
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int m = wild.size();
        int n = pattern.size();
        
        return f(m-1, n-1, wild, pattern);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends