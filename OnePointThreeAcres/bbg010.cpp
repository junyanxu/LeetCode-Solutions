//
//  main.cpp
//  two ways of reverse linked list
//
//  Created by junyan on 12/14/16.
//  Copyright © 2016 junyan. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <unordered_map>
#include <list>

struct ListNode{
    ListNode(int val){
        this->val = val;
        this->next = NULL;
    }
    int val;
    ListNode* next;
};

using namespace std;

ListNode* createList(vector<int> nums){
    ListNode* help = new ListNode(0);
    ListNode* h = help;
    for(auto x: nums){
        h->next = new ListNode(x);
        h = h->next;
    }
    ListNode* ret = help->next;
    delete help;
    return ret;
}

void printList(ListNode* head){
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* temp;
    while (curr) {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

ListNode* reverseListRecur(ListNode* head){
    if(head && head->next){
        ListNode* nhead = reverseListRecur(head->next);
        head->next->next = head;
        head->next = NULL;
        return nhead;

    }
    else{
        return head;
    }
}

int main(){
    vector<int> a({1,2,3,4,5,6,7,8});
    ListNode* l = createList(a);
    printList(l);
    l = reverseListRecur(l);
    printList(l);
}
