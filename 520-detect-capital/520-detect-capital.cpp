class Solution {
public:
    bool detectCapitalUse(string word) {
        if(!word.length())
            return false;
        bool firstCap = (word[0]-'A')<26, allCap=true, allSmall=true;
        for(int i=1; i<word.length(); i++)
        {
            if(word[i]-'A'<26)
                allSmall = false;
            else if(word[i]-'A'>=32)
                allCap = false;
        }
        return (firstCap&&allCap)||allSmall;

    }
};