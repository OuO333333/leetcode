class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return NULL;
        return mergeKLists(lists, 0, lists.size() - 1);
    }

    // Divide and Conquer
    // https://hackmd.io/@sysprog/c-linked-list
    ListNode* mergeKLists(vector<ListNode*>& lists, int left, int right) {
        if (left == right) return lists[left];
        int mid = (left + right) / 2;
        ListNode* leftList = mergeKLists(lists, left, mid);
        ListNode* rightList = mergeKLists(lists, mid + 1, right);
        return mergeTwoLists(leftList, rightList);
    }

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode* res = new ListNode(0); // 使用0作为初始值
        ListNode* temp = res;
        while (list1 && list2) {
            if (list1->val > list2->val) {
                temp->next = list2;
                list2 = list2->next; 
            } else {
                temp->next = list1;
                list1 = list1->next;
            }
            temp = temp->next;
        }
        if (list1) {
            temp->next = list1;
        } else {
            temp->next = list2;
        }
        return res->next;
    }
};
