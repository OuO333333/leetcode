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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        ListNode* temp = head;

        // 計算list長度
        int size = 0;
        while(temp){
            temp = temp -> next;
            size++;
        }
        return Kreverse(head, k, size);
    }
    ListNode* Kreverse(ListNode* head, int k, int n){

        // 若list長度小於需反轉數量，則不反轉
        if(n < k)
            return head;
        ListNode* next = NULL;
        ListNode* curr = head;
        ListNode* prev = NULL;
        int count = 0;

        // 1. 記下next node
        // 2. 將curr node指向prev node
        // 3. curr node, prev node前進
        while(count < k && curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // 將原本的head(反轉後的末端)的next指向下一個的head
        if(next != NULL)
            head -> next = Kreverse(next, k, n - k);
        // 回傳反轉後的head
        return prev;
    }
};