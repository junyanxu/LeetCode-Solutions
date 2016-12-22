class Solution {
public:
    /*
    题意：删除链表中倒数第n个结点，尽量只扫描一遍。
    使用两个指针扫描，当第一个指针扫描到第N个结点后，
    第二个指针从表头与第一个指针同时向后移动，
    当第一个指针指向空节点时，另一个指针就指向倒数第n个结点了
    */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *tmp = res;
        for (int i = 0; i < n; i++) {
            head = head->next;
        }
        while (head != NULL) {
            head = head->next;
            tmp = tmp->next;
        }
        tmp->next = tmp->next->next;
        return res->next;
    }
};
