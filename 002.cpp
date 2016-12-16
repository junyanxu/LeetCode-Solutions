class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* x1=l1;
        ListNode* x2=l2;
        ListNode* help = new ListNode(-1);
        ListNode* now = help;
        int forward=0;
        while(x1 && x2){
            now->next = new ListNode((x1->val+x2->val+forward)%10);
            forward = (x1->val+x2->val+forward)/10;
            now = now->next;
            x1 = x1->next;
            x2 =x2->next;
        }
        while(x1){
            now->next = new ListNode((x1->val+forward)%10);
            forward = (x1->val+forward)/10;
            now = now->next;
            x1 = x1->next;
        }
        while(x2){
            now->next = new ListNode((x2->val+forward)%10);
            forward = (x2->val+forward)/10;
            now = now->next;
            x2 = x2->next;
        }
        if(forward!=0){
            now->next = new ListNode(forward);
        }
        return help->next;
    }
};
