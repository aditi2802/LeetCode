class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        q.push({beginWord, 1});
        s.erase(beginWord);
        
        while(!q.empty()){
            string word = q.front().first;
            int level = q.front().second;
            q.pop();
            
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i] = ch;
                    
                    if(s.find(word)!=s.end()){
                        q.push({word, level+1});
                        s.erase(word);
                    }
                }
                word[i] = original;
            }
            if(word==endWord) return level;
        }
        return 0;
    }
};