class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // https://www.cnblogs.com/grandyang/p/4510984.html
        int closet = nums[0] + nums[1] + nums[2];
        int diff = abs(closet - target);

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < diff){
                    closet = sum;
                    diff = abs(sum - target);
                }
                if(sum == target){
                    return sum;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }

        return closet;
        
    }
};