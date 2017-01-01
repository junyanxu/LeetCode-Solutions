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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = getLength(l1);
        int len2 = getLength(l2);
        ListNode * help = new ListNode(0);
        ListNode * h =  help;
        if(len1 < len2){
            for(int i=0; i<len2 - len1; i++){
                h->next = new ListNode(l2->val);
                h = h->next;
                l2 = l2->next;
            }
        }
        else{
            for(int i=0; i<len1 - len2; i++){
                h->next = new ListNode(l1->val);
                h = h->next;
                l1 = l1->next;
            }
        }
        for(int i=0; i<min(len1, len2); i++){
            h->next = new ListNode(l1->val + l2->val);
            h=h->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        h = help;
        ListNode* q;
        print(h);

        while(h){
            q = h->next;
            while(q && q->val == 9){
                q = q->next;
            }
            if(q && q->val > 9){
                while(h!=q){
                    h->val += 1;
                    h = h->next;
                    h->val -= 10;
                }
            }
            else{
                h=q;
            }
        }
        return help->val? help: help->next;

    }

    void print(ListNode *x){
        while(x){
            cout << x->val << " ";
            x = x->next;
        }
    }

    int getLength(ListNode* x){
        if(!x){return 0;}
        else{
            int count=1;
            while(x->next){count++;
                x = x->next;
            }
            return count;
        }
    }
};
