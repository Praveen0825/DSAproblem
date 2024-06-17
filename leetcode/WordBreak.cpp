class DictNode {
public:
    bool isWord = false;
    DictNode *next[26] = {0};
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        buildDict(wordDict);
        int len = s.length();
        bool *dp = new bool[len + 1]{0};
        dp[0] = 1;
        for(int i = 0; i < len; ++i) {
            if(!dp[i]) continue;
            DictNode* p = dict;
            int j = i;
            while(j < len && p -> next[s[j] - 'a']) {
                p = p -> next[s[j++] - 'a'];
                if(p -> isWord) dp[j] = 1;
            }
            if(dp[len]) return true;
        }
        return false;
    }
    
private:
    DictNode *dict;
    
    void buildDict(vector<string>& wordDict) {
        dict = new DictNode();
        DictNode* p;
        for(auto &w : wordDict) {
            p = dict;
              for(auto &c : w) {
                auto &next = p -> next[c - 'a'];
                if(!next) next = new DictNode();
                p = next;
            }
            p -> isWord = true;
        }
    }
};