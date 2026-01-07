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
    long long maxProd;
    long long sum;
    static const int MOD = 1e9 + 7;

    long long findMaxProd(TreeNode* root) {
        if(root == NULL) return 0;

        long long leftSum = findMaxProd(root->left);
        long long rightSum = findMaxProd(root->right);

        long long subTreeSum = root->val + rightSum + leftSum;

        long long sum2 = sum - subTreeSum;
        maxProd = max(maxProd, subTreeSum*sum2);

        return subTreeSum;
    }
    
public:
    int maxProduct(TreeNode* root) {
        if(root == NULL) return 0;
        
        sum = findMaxProd(root);

        maxProd = 0;

        findMaxProd(root);

        return maxProd%MOD;
    }
};