//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here
        int zeroes = 0;
        int ones = 0;
        int twos = 0;
        for(int i=0;i<n;i++){
            if(a[i]==0) zeroes++;
            if(a[i]==1) ones++;
            if(a[i]==2) twos++;
        }
        for(int i=0;i<zeroes;i++) a[i] = 0;
        for(int i=zeroes;i<zeroes+ones;i++) a[i] = 1;
        for(int i=zeroes+ones;i<zeroes+ones+twos;i++) a[i] = 2;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends