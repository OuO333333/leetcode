class Solution {
public:
    bool isPalindrome(int x) {
        int ans = x;
        long int y = 0;
        if(x < 0){
            return false;
        }
        else{
            while(x){
                y = y * 10;
                y = y + x % 10;
                x = x / 10;
            }
        }
        if(y == ans)
            return true;
        return false;
    }
};