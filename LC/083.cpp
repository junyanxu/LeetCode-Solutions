class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* h1 = new ListNode(INT_MIN);
        ListNode* h = h1;
        while(head){
            if(head->val != h->val){
                h->next = head;
                h = h->next;
            }
            head = head->next;
        }
        h->next = NULL;
        return h1->next;
    }
};
