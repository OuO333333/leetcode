/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Floyd Cycle Detection Algorithm
        // https://medium.com/@orionssl/%E6%8E%A2%E7%B4%A2-floyd-cycle-detection-algorithm-934cdd05beb9
        // 使用快慢指針來偵測是否有環
        // 快指針一次動兩格, 慢指針一次動一格
        // 若快指針或慢指針走到了終點都還沒相交, 則沒有環
        // 若相交了, 則必有環

        // 假設它們第一次在第k步相遇, 環的長度為r
        // 第一次相遇時 fast 比 slow 在環中多走了 n 圈，2k - k = nr, 解得k = nr
        // 鏈表的起始節點到環的起點的距離為s
        // 鏈表的起始節點到第一次相遇的節點的距離為k(每次走一步的指針走了k步)
        // 環的起點到第一次相遇的節點的距離為m。因此，s = k - m
        // 將k的表達式代入s的表達式中得到 s = nr - m = (n-1)r + (r-m)
        // 在這里我們取 n = 1, 所以, s = r - m
        // n = 其他時同理, fast 必定會從第一次相遇點走到環的起始點
        // slow 也會從鏈表的起始節點走到環的起始點
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && slow != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow){
                slow = head;
                while(slow != fast){
                    fast = fast -> next;
                    slow = slow -> next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};
