class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while(x != 0){
            int pop = x % 10;
            x = x / 10;

            // INT_MAX = 2147483647
            // INT_MIN = -2147483648
            // result = result * 10 + pop can cause overflow
            // 比較 INT_MAX 和 INT_MIN 少一位數的大小（若相同時，則再比較個位數）
            if(result > INT_MAX / 10 || (result == INT_MAX / 10 && pop > 7))
                return 0;
            if(result < INT_MIN / 10 || (result == INT_MIN / 10 && pop < -8))
                return 0;
            result = result * 10 + pop;
            
        }
        return result;
    }
};