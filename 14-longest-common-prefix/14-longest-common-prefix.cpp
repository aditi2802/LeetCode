class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str = strs[0];
        string finl="";
        
        for(int i = 0; i < str.size(); i++)
        {
             char currentChar = str[i];
            for(int j = 1; j < strs.size(); j++)
            {
                if(strs[j][i] != currentChar){
                    return finl;
                }
                
            }
            finl += currentChar;
        }
        return finl;
    }
};
