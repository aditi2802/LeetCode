// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    int index = 0;
		    helper(S, ans, index);
		    sort(ans.begin(), ans.end());
		    return ans;
		}
		
		void helper(string S, vector<string>& ans, int index){
		    if(index==S.size()){
		        ans.push_back(S);
		        return;
		    }
		    for(int i = index;i<S.size();i++){
		        swap(S[index], S[i]);
		        helper(S, ans, index+1);
		        swap(S[index], S[i]);
		    }
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends