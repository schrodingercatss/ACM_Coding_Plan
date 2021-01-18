/*
	定义一个prev指针存储逆置后的链表，一个curr存储当前节点，在循环中为了防止下一个节点丢失，定义一个next
	存储curr的下一个节点，然后使用链表的头插法将当前节点插入curr即可。
*/



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
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while(curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};