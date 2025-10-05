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
    int findHeight(TreeNode* node, int& diameter) {
        if(node == NULL) return 0;

        int l = findHeight(node -> left,diameter);
        int r = findHeight(node -> right,diameter);

        diameter = max(diameter, l + r);
        return 1 + max(l,r);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        findHeight(root,diameter);
        return diameter;
    }
};