class Solution {
public:
    map<char, string> data;

    void fillData(){
        data['2'] = "abc";
        data['3'] = "def";
        data['4'] = "ghi";
        data['5'] = "jkl";
        data['6'] = "mno";
        data['7'] = "pqrs";
        data['8'] = "tuv";
        data['9'] = "wxyz";
    }

    void dfs(string digits, int depth, string& cur, vector<string>& ans){
        if(depth == digits.length()){
            ans.push_back(cur);
            return;
        }
        for(char c : data[digits[depth]]){
            cur.push_back(c);
            dfs(digits, depth + 1, cur, ans);
            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        // using dfs
        // 第幾個digits = 第幾層dfs
        // cur紀錄當前dfs經過的digits
        if(digits.empty())
            return {};
        fillData();
        vector<string> ans;
        string cur = "";
        dfs(digits, 0, cur, ans);
        return ans;
    }
};