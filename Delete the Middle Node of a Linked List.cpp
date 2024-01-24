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
    ListNode* deleteMiddle(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return nullptr;
        ListNode* temp = head;
        int size = 0;
        while(temp != nullptr){
            size++;
            temp = temp -> next;
        }
        temp = head;
        for(int i = 0; i < size / 2 - 1; i++){
            temp = temp -> next; 
        }
        /*
        * 在刪除中間節點時, 需要確保要刪除的節點存在, 否則可能導致空指針引用錯誤（Null Pointer Dereference）。
        * 在代碼中, 刪除中間節點的邏輯是通過 temp->next = temp->next->next; 實現的。
        * 這行代碼的含義是將 temp->next 跳過, 直接指向下一個節點。如果 temp->next 為 null, 那麽 temp->next->next 就會產生空指針引用錯誤, 因為不能在 null 上執行成員訪問。
        * 因此, 為了避免這種潛在的錯誤, 需要在刪除中間節點之前檢查 temp->next 是否為 null。這樣可以確保在進行指針操作時, 你操作的對象是有效存在的, 從而避免了潛在的運行時錯誤。
        */
        if (temp != nullptr && temp->next != nullptr) {
            temp->next = temp->next->next;
        }
        return head;
    }
};
