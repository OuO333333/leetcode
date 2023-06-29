class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];

        // initialize DP
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                dp[i][j] = false;
            }
        }

        // base condtion for 1 length of substring always a Palindromic
        for(int i = 0; i < n; i++){
            dp[i][i] = true;
        }

        // base condtion for 2 length of substring is Palindromic if s[i]==s[i+1]
        for(int i = 0; i < n - 1; i++){
            if(s[i] == s[i + 1]){
                dp[i][i + 1] = true;
            }
        }

        // for k length of substring is Palindromic if dp[i + 1][j - 1]==1 && s[i] == s[j]
        for(int k = 3; k <= n; k++){
            for(int i = 0; i < n - k + 1; i++){
                int j = i + k - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1]){
                    dp[i][j] = true;
                }
            }
        }

        // find the max length substring
        int ans = 0;
        string str;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j] == true){
                    int length = j - i + 1;
                    if(length > ans){
                        ans = length;
                        str = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return str;
        
    }
};