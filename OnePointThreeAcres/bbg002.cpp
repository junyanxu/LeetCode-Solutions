/*

leetcode, linked list intersection. 一个fast一个slow指针秒,
follow up是如果两个list都可能有环, 该怎么做? 傻了几分钟, 回答hashset, 秒写

*/
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <climits>
#include <stdexcept>
#include <random>

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int la = 0, lb=0;
        ListNode *now = headA;
        ListNode *then;
        while(now){
            la++;
            now = now->next;
        }
        ListNode* laEnd = now; now = headB;
        while(now){
            lb++;
            now=now->next;
        }
        if(now != laEnd){
            return NULL;
        }
        if(la > lb){
            now = headA;
            for(int i=0; i<la-lb; i++){
                now = now->next;
            }
            then = headB;
        }
        else{
            now = headB;
            for(int i=0; i<lb-la; i++){
                now = now->next;
            }
            then = headA;
        }
        while(now!=then){
            now=now->next;
            then=then->next;
        }
        return now;
    }
};
