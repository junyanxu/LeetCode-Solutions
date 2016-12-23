/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        ListNode *help = new ListNode(0);
        help->next = head;
        ListNode *now = help;
        ListNode *end;
        int i;
        while(now->next){
            end = now;
            i = 0;
            for(i=0; i<k; i++){
                if(!end->next){
                    break;
                }
                else{
                    end = end->next;
                }
            }
            if(i==k)
                now = re(now, end);
            else
                now = end;
        }
        return help->next;
    }

    ListNode* re(ListNode* help, ListNode* end){
        ListNode* nextAfterEnd = end->next;
        ListNode* nextHelp = help->next;
        ListNode* prev = help;
        ListNode* curr = help->next;
        ListNode* temp;
        while(prev!=end){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        help->next->next = nextAfterEnd;
        help->next = prev;
        return nextHelp;
    }
};
