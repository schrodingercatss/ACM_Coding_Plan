/*
	因为需要倒序，所以我们写一个递归即可，也可以遍历一遍再把vector给reverse。
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
    vector<int> reversePrint(ListNode* head) {
        vector<int> ans;
        print(head, ans);
        return ans;
    }
    void print(ListNode* head, vector<int> &ans) {
        if(!head) return;
        print(head->next, ans);
        ans.push_back(head->val);
    }
};