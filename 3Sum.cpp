class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // https://ithelp.ithome.com.tw/articles/10240671
        int target = 0;
        set<vector<int>> s;
        vector<vector<int>> output;

        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            int k = nums.size() - 1;
            while(j < k){
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == target){
                    s.insert({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                }
                else if(sum < target){
                    j++;
                }
                else{
                    k--;
                }
            }
        }
        for(vector<int> item : s)
            output.push_back(item);
        return output;
    }
};