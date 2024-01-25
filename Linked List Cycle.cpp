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
    bool hasCycle(ListNode *head) {
        // Floyd Cycle Detection Algorithm
        // https://medium.com/@orionssl/%E6%8E%A2%E7%B4%A2-floyd-cycle-detection-algorithm-934cdd05beb9
        // 使用快慢指針來偵測是否有環
        // 快指針一次動兩格, 慢指針一次動一格
        // 若快指針或慢指針走到了終點都還沒相交, 則沒有環
        // 若相交了, 則必有環
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && slow != nullptr && fast -> next != nullptr){
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow)
                return true;
        }
        return false;
    }
};
