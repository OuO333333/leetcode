class Solution {
public:
    
    bool checkSubstring(unordered_map<string, int> wordCount, string s, int wordLen) {
        // 每次取長度為wordLen的string做檢查
        for(int j = 0; j < s.size(); j += wordLen) {
            string w = s.substr(j, wordLen);
            if(wordCount.count(w) != 0) {
                if(--wordCount[w] == -1) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int wordLen = words[0].size();
        int sLen = s.size();
        int wordsWindow = words.size() * wordLen;
        
        // 計算word數量
        unordered_map<string, int> wordCount;
        for(int i = 0; i < words.size(); i++) {
            if(wordCount.count(words[i]) == 0)
                wordCount[words[i]] = 1;
            else{
                wordCount[words[i]] += 1;
            }
        }
        
        // 起始點i,將每個長度為wordsWindow的string丟進去檢查
        int i = 0;
        while(i + wordsWindow <= sLen) {
            if(checkSubstring(wordCount, s.substr(i, wordsWindow), wordLen)) {
                res.push_back(i);
            }
            i++;
        }
        return res;
    }
};