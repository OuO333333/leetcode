class Solution {
public:
    int maxArea(vector<int>& height) {
        // 在計算面積時，高 h 的值會取決於兩塊隔板中較矮的一塊。因此當由外相內移動時，因為寬 w 縮短，會移動較短的隔板期望能獲取較高的 h 值，如此才有可能得到較大的容積。
        // https://cynthiachuang.github.io/LeetCode-0011-Container-With-Most-Water/
        int left = 0;
        int right = height.size() - 1;
        int area = 0;
        while(left < right){
            int w = right - left;
            int h = 0;
            if(height[left] < height[right]){
                h = height[left];
                left += 1;
            }
            else{
                h = height[right];
                right -= 1; 
            }           
            area = max(area, h*w);
        }
      return area;
    }
};