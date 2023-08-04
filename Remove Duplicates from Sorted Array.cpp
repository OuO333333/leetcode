class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        // 這題指定要用in-place algorithm
        // in-place algorithm: 除了一些計數用的變數外，基本上都在原先的資料結構內解決
        // i為遍歷到哪
        // j儲存記錄到哪個位置

        int j = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] != nums[i - 1]){
                nums[j] = nums[i];
                j++;
            }
        }
        return j;
    }
};