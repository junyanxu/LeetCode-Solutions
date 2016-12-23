class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* help = new ListNode(0);
        ListNode* now = help;
        while(l1&& l2){
            if(l1->val < l2->val){
                now->next = l1;
                l1 = l1->next;
            }
            else{
                now->next = l2;
                l2=l2->next;
            }
            now = now->next;
        }
        while(l1){
            now->next = l1;
            l1 = l1->next;
            now = now->next;
        }

        while(l2){
            now->next = l2;
            l2 = l2->next;
            now = now->next;
        }
        return help->next;
    }
};
