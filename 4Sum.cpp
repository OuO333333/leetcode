class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        // 1. 將kSum問題轉換成2Sum問題
        // 每次固定一個數，將kSum轉成(k-1)Sum
        // 2. 解決2Sum問題
        // https://juejin.cn/post/6844903785752428552
        sort(begin(nums), end(nums));
        return kSum(nums, target, 0, 4);
        
    }

    vector<vector<int>> twoSum(vector<int>& nums, long long target, int start){
        vector<vector<int>> res;
        int left = start;
        int right = nums.size() - 1;
        while(left < right){
            int curr_sum = nums[left] + nums[right];
            // 重複的可跳過
            if(curr_sum < target || (left > start && nums[left] == nums[left - 1]))
                left++;
            else if(curr_sum > target || (right < nums.size() - 1 && nums[right] == nums[right + 1]))
                right--;
            else{
                res.push_back({nums[left], nums[right]});
                left++;
                right--;
            }
        }
        return res;
    }

    vector<vector<int>> kSum(vector<int>& nums, long long target, int start, int k){
        vector<vector<int>> res;

        // If we have run out of numbers to add, return res.
        if (start == nums.size()) {
            return res;
        }

        // There are k remaining values to add to the sum. The 
        // average of these values is at least target / k.
        long long average_value = target / k;
        
        // We cannot obtain a sum of target if the smallest value
        // in nums is greater than target / k or if the largest 
        // value in nums is smaller than target / k.
        if  (nums[start] > average_value || average_value > nums.back()) {
            return res;
        }

        if (k == 2) {
            return twoSum(nums, target, start);
        }

        for(int i = start; i < nums.size(); i++){
            // 重複的跳過
            if(i > start && nums[i] == nums[i - 1])
                continue;
            vector<vector<int>> ksumRes = kSum(nums, target - nums[i], i + 1, k - 1);
            for(vector<int> item : ksumRes){
                res.push_back(item);
                res.back().push_back(nums[i]);
            }
        }
        return res;
    }
};