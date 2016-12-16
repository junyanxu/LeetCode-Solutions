
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* help = new ListNode(-1);
        help->next = head;
        ListNode* slow = help;
        ListNode* fast = help;
        while(fast->next && fast->next->next){
            if(fast->next == slow)
                return true;
            fast = fast->next->next;
            slow = slow->next;
        }
        return false;
    }
};
