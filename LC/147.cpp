class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* newHead = new ListNode(0);
        ListNode* now = newHead;
        ListNode* buff;
        while(head){
            buff = head;
            head = head->next;
            now = newHead;
            while(now->next && buff->val > now->next->val){
                now = now->next;
            }
            buff->next = now->next;
            now->next = buff;
        }
        return newHead->next;
    }
};
