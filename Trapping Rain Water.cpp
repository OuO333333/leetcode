class Solution {
public:
    int trap(vector<int>& height){
        // https://medium.com/@bill800227/leetcode-42-trapping-rain-water-d821bc134cf7
        stack<int> s;
        int i = 0, res = 0;
        while(i < height.size()){
            if(s.empty() || height[i] <= height[s.top()]){
                s.push(i);
                i++;
            }
            else{
                int minIdx1 = s.top();
                s.pop();
                if(!s.empty()){
                    int minIdx2 = s.top();
                    res += (min(height[minIdx2], height[i]) - height[minIdx1]) * (i - minIdx2 - 1);
                }       
            }
        }
        return res;
    }
};
