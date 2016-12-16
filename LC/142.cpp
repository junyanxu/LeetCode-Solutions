class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
 // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
         if(head == NULL || head->next == NULL)return NULL;
        ListNode *fast = head, *low = head;
        while(fast != NULL && fast->next != NULL)
         {
            low  = low->next;
            fast = fast->next->next;
             if(low == fast)break;
            }
       if(low == fast)
        {//寻找环的起点
            fast = head;
            while(fast != low)
            {
             fast = fast->next;
                low = low->next;
            }
            return low;
         }
       else return NULL;
    }
};
