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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL){
            curr = curr -> next;
            count++;
        }
        int position = count - n + 1;
        return deleteNth(head, position);
    }

    ListNode* deleteNth(ListNode* head, int position){
        if(position == 1){
            head = head -> next;
            return head;
        }

        // remove nth position, need to move (n - 1)th node, move (n-2)times
        ListNode* flag = head;
        int move = position - 2;
        for(int i = 0; i < move; i++)
            flag = flag -> next;
        flag -> next = flag -> next -> next;
        return head;
    }
};