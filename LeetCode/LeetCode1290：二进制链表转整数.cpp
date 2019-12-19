/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
/*
	解法一：直接模拟法
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head) {
            res = res * 2 + head->val;
            head = head->next;
        }
        return res;
    }
};

/*
	解法二：位运算法：
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
    int getDecimalValue(ListNode* head) {
        int res = 0;
        while(head) {
            res = (res << 1) | head->val;
            head = head->next;
        }
        return res;
    }
};