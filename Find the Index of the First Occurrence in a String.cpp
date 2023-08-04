class Solution {
public:
    int strStr(string haystack, string needle) {

        // 若haystack長度<needle長度，return -1
        if(haystack.length() < needle.length())
            return -1;

        // 若haystack長度==needle長度，return -1 if not equal，return 0 if equal
        if(haystack.length() == needle.length()){
            if(haystack == needle)
                return 0;
            return -1;
        }

        // i為比對起始點
        // j為比對的位置
        for(int i = 0; i <= haystack.length() - needle.length(); i++){
            bool flag = true;
            for(int j = 0; j < needle.length(); j++){
                if(haystack[i + j] != needle[j]){
                    flag = false;
                    break;
                }
            }
            if(flag)
                return i;
        }
        return -1;
    }
};