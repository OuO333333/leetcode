class Solution {
public:
    int divide(int dividend, int divisor) {

        //https://medium.com/@ChYuan/leetcode-29-divide-two-integers-%E5%BF%83%E5%BE%97-medium-91e5fccb29fa

        // 處理overflow
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = ((dividend >= 0 && divisor >= 0) || (dividend <= 0 && divisor <= 0))?1:-1;
        long long int quotient = 0;
        long long int sum = 0;
        long long int dividendL = dividend;
        dividendL = abs(dividendL);
        long long int divisorL = divisor;
        divisorL = abs(divisorL);
        
        // sum為目前累加
        // quotient為商
        // 每次盡可能的取最大的除數位移量
        for (int i = 31; i >= 0; i--)
        {
            if (sum + (divisorL << i) <= dividendL)
            {
                sum += (divisorL << i);
                quotient += (1LL << i);
            }
        }
        
        if (sign * quotient > INT_MAX)
            return INT_MAX;
            
        
        return sign * quotient;    
    }
};