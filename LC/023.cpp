/*

Use priority queue get O(nklogk)

*/

struct compare{
    public:
       bool operator()(ListNode*a, ListNode*b){
           return a->val > b->val;
       }
};


class Solution {
public:
   ListNode* mergeKLists(vector<ListNode*>& lists) {
       priority_queue<ListNode*, vector<ListNode*>, compare> pq;
       ListNode* help = new ListNode(0);
       ListNode* now = help;
       ListNode* temp;
       for(auto x: lists){if(x) pq.push(x);}
       while(!pq.empty()){
           temp = pq.top();
           now->next = temp;
           now = now->next;
           pq.pop();
           if(temp->next){
               pq.push(temp->next);
           }
       }
       return help->next;
   }
};
