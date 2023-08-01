class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // https://www.cnblogs.com/grandyang/p/4444160.html
        // 類似暴搜
        // 如果在某次遞歸時，左括號的個數大於右括號的個數，說明此時生成的字符串中右括號的個數大於左括號的個數，即會出現')(' 這樣的非法串，所以這種情況直接返回，不繼續處理
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }

    void generate(int left, int right, string out, vector<string> &res){
        if(left > right)
            return;
        if(left == 0 && right == 0)
            res.push_back(out);
        if(left > 0)
            generate(left - 1, right, out + "(", res);
        if(right > 0)
            generate(left, right - 1, out + ")", res);
    }
};