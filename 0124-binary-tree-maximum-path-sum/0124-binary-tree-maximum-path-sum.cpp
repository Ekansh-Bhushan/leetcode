/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int findHeight(TreeNode* node, int& maxi) {
        if(node == NULL) return 0;

        int l = max(0,findHeight(node -> left,maxi));
        int r = max(0,findHeight(node -> right,maxi));

        maxi = max(maxi, l + r + node -> val);
        return node->val + max(l,r);
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        findHeight(root,maxi);
        return maxi;
    }
};