class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        int count = 0;
        ListNode* help = new ListNode(0);
        help->next = head;
        ListNode*init = help;
        while(init->next!=NULL){ count++; init=init->next; }
        if(count == 0)
            return head;
        ListNode*end = init;
        int shift = count-k%count;
        init = help;
        for(int i=0; i<shift; i++){
            init = init->next;
        }

        end->next = help->next;
        help->next = init->next;
        init->next=NULL;
        return help->next;
    }
};
