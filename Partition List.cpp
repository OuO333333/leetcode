/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // 將 list 分成兩塊
        ListNode* smaller = new ListNode();
        ListNode* ss = smaller;
        ListNode* bigger = new ListNode();
        ListNode* sb = bigger;
        while(head != nullptr){
            if(head -> val < x){
                smaller -> next = head;
                smaller = smaller -> next;
            }
            else{
                bigger -> next = head;
                bigger = bigger -> next;
            }
            head = head -> next;
        }
        // smaller list 指向 bigger list
        smaller -> next = sb -> next;
        // bigger list 指向 nullptr
        bigger -> next = nullptr;
        return ss -> next;
    }
};
