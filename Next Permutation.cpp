class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // https://www.cnblogs.com/grandyang/p/4428207.html
        // 通過觀察原數組可以發現
        // 如果從末尾往前看，數字逐漸變大，到了2時才減小的
        // 然後再從後往前找第一個比2大的數字，是3
        // 那麼我們交換2和3，再把此時3後面的所有數字轉置一下即可

        // 1　　2　　7　　4　　3　　1
        // find 2
        // find 3
        // swap(2, 3)
        // 1　　3　　7　　4　　2　　1
        // reverse
        // 1　　3　　1　　2　　4　　7
        int i, j, n = nums.size();
        for (i = n - 2; i >= 0; --i) {
            if (nums[i + 1] > nums[i]) {
                for (j = n - 1; j > i; --j) {
                    if (nums[j] > nums[i]) break;
                }
                swap(nums[i], nums[j]);
                reverse(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        reverse(nums.begin(), nums.end());
    }
};