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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // https://www.cnblogs.com/grandyang/p/4606710.html
        // devide and conquer
        if(lists.empty() == true)
            return NULL;
        int n = lists.size();
        while(n > 1){
            int k = (n + 1) / 2;
            for(int i = 0; i < n / 2; i++)
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            n = k;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        ListNode* res = new ListNode();
        ListNode* temp = res;
        while(list1 && list2){
            if(list1 -> val > list2 -> val){
                temp -> next = list2;
                list2 = list2 -> next; 
            }
            else{
                temp -> next = list1;
                list1 = list1 ->next;
            }
            temp = temp -> next;
        }
        if(list1){
            temp -> next = list1;
        }
        else{
            temp -> next = list2;
        }
        return res -> next;

    }
};