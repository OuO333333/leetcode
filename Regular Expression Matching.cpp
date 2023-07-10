class Solution {
public:
    bool isMatch(string s, string p) {
        // https://knightzone.studio/2018/09/30/3644/leetcode%EF%BC%9A10-regular-expression-matching/

        //  dp[i][j]為s[1...i] 與 p[1...j]比較結果
        int m = s.size(), n = p.size();
        bool dp[m + 1][n + 1];

        for(int i = 0; i < m + 1; i++)
            for(int j = 0; j < n + 1; j++)
                dp[i][j] = false;
                
        /* Empty String */
        // i 與 j 都為 0 ，兩邊都是空字串自然是個完美比對，故為 true
        dp[0][0] = true;

        /* "" v.s. X*X*X*..... */
        // i = 0 而 j > 0 ，則若正規表達式的前端皆為某個東西接 * 的話，則在為 * 的那時比對會是 true ，若中間出現了一個不是 * 的 pattern ，則就無法與空字串比對為成功，從那之後不管正規表達式裡有什麼就皆為 false 
        for(int i = 2 ; i <= p.length() && p[i-1] == '*' ; i += 2){
            dp[0][i] = true;
        }

        /* s[0...i-1] v.s. p[0...j-1] */
        for(int i = 1 ; i <= s.length() ; ++i){
            for(int j = 1 ; j <= p.length() ; ++j ){

                // 實際上s & p的index
                int sIndex = i-1;
                int pIndex = j-1;

                // s[i] == p[j] || p[j] == '.' ，則表示兩字比對成功，則結果就取決於將兩邊比對成功的這組拿掉後的結果，故 dp[i][j] = dp[i-1][j-1]
                if(p[pIndex] == '.' || s[sIndex] == p[pIndex]){
                dp[i][j] = dp[i-1][j-1];
                }

                // p[j] == '*'，則有兩種可以的方式比對，將兩種方式的結果 OR 起來即是 dp[i][j] 的結果
                // 1. * 可以為 0 ，則表示結果可以取決於這組 * 不在的狀況，也就是 dp[i][j-2]
                // 2. 若這組所選的字剛好可以跟 s[i] 比對，也就是 s[i] == p[j-1] || p[j-1] == '.' ，則結果也可以取決於將 s[i] 吃掉後的結果，也就是 dp[i-1][j] 
                else if(p[pIndex] == '*'){
                    dp[i][j] = dp[i][j-2] || ((s[sIndex] == p[pIndex-1] || p[pIndex-1] == '.')                  && dp[i-1][j]);
                }
            }   
        }

    return dp[s.length()][p.length()];
        
    }
}; 