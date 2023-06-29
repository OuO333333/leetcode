class Solution {
public:
	// https://zhuanlan.zhihu.com/p/55666669
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int left = (n + m + 1) / 2;
        int right = (n + m + 2) / 2;
        // 將偶數和奇數的情況合並，如果是奇數，會求兩次同樣的 k 。
        return (getKth(nums1, 0, n - 1, nums2, 0, m - 1, left) +
        getKth(nums1, 0, n - 1, nums2, 0, m - 1, right)) * 0.5;
    }

    int getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int len1 = end1 - start1 + 1;
        int len2 = end2 - start2 + 1;
        // 讓 len1 的長度小於 len2，這樣就能保證如果有數組空了，一定是 len1 
        if (len1 > len2) return getKth(nums2, start2, end2, nums1, start1, end1, k);
        if (len1 == 0) return nums2[start2 + k - 1];

        if (k == 1) return min(nums1[start1], nums2[start2]);

        int i = start1 + min(len1, k / 2) - 1;
        int j = start2 + min(len2, k / 2) - 1;

        if (nums1[i] > nums2[j]) {
            return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
        }
        else {
            return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
        }
    }
};