class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        map<int, long long int> mp;  //to map arr elements with no of bt they can form
        sort(arr.begin(), arr.end());
        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = 1;             //each element will have one bt
        }
        
        for(int i=1;i<arr.size();i++){    
            long long int count = 0;
            auto parent = mp.find(arr[i]);
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    auto child1 = mp.find(arr[j]);
                    auto child2 = mp.find(arr[i]/arr[j]);
                    
                    if(child2!=mp.end()){    //if child2 is present in map
                        count += (child1->second) * (child2->second);
                    }
                }
            }
            parent->second += count;
        }
        
        long long totalSum = 0;
        for(auto x : mp){
            totalSum += x.second;
        }
        return totalSum%(1000000007);
    }
};