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
    ListNode* swapPairs(ListNode* head) {
        ListNode* help = new ListNode(0);
        ListNode* now = help;
        help->next = head;
        ListNode* second;
        ListNode* first;
        while(now->next && now->next->next){
            first = now->next;
            second = now->next->next;
            first->next = second->next;
            now->next = second;
            second->next = first;
            now = first;
        }
        return help->next;
    }
};
