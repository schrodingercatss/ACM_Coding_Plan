/*
因为链表是排好序的，遍历查找插入位置，然后新建节点插入即可。
*/

/**
 * Definition of singly-linked-list:
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param val: An integer.
     * @return: The head of new linked list.
     */
    ListNode * insertNode(ListNode * head, int val) {
        ListNode *Node = new ListNode(0);
        Node->next = head;
        ListNode *p = Node;
        while(p) {
            ListNode *next = p->next;
            if(next && next->val < val) {
                p = p->next;
            } else {
                ListNode *q = new ListNode(val);
                q->next = next;
                p->next = q;
                break;
            }
        }
        return Node->next;
    }
};