/*
我们对树进行深度优先搜索，对于当前节点 node，如果 node.val 小于等于 L，那么只需要继续搜索它的右子树；
如果 node.val 大于等于 R，那么只需要继续搜索它的左子树；如果 node.val 在区间 (L, R) 中，则需要搜索它的所有子树。

我们在代码中用递归和迭代的方法分别实现了深度优先搜索。


*/



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans;
    int rangeSumBST(TreeNode* root, int L, int R) {
        ans = 0;
        dfs(root, L, R);
        return ans;
    }
    void dfs(TreeNode* node, int L, int R) {
        if(node == nullptr) return ;
        if(L <= node->val && node->val <= R) ans += node->val;
        if(L < node->val) 
            dfs(node->left, L, R);
        if(R > node->val) 
            dfs(node->right, L, R);
    }
};