class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> um;
        RandomListNode* chelp = new RandomListNode(0);
        RandomListNode* curr = head;
        RandomListNode* ccurr = chelp;
        while(curr){
            ccurr->next = new RandomListNode(curr->label);
            um[curr] = ccurr->next;
            curr = curr->next;
            ccurr = ccurr->next;
        }
        curr = head;
        while(curr){
            cout << curr->label << endl;
            if(curr->random == NULL)
                um[curr]->random = NULL;
            else
                um[curr]->random = um[curr->random];
            curr = curr->next;
        }
        return chelp->next;
    }
};
