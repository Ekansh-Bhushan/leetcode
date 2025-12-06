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
    TreeNode* findParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parentMap, int start){
        TreeNode* target = new TreeNode(-1);

        if(!root)
            return target;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start)
                target = node;

            if(node->left){
                parentMap[node->left] = node;
                q.push(node->left);
            }

            
            if(node->right){
                parentMap[node->right] = node;
                q.push(node->right);
            }
        }
        return target;
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> parentMap;
        TreeNode* startNode = findParent(root, parentMap, start);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;

        visited.insert(startNode);

        q.push(startNode);
        int time = 0;
        bool check = false;
        while(!q.empty()){
            int size = q.size();

            for(int i = 0; i < size ; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left && visited.find(node->left) == visited.end()) {
                    q.push(node->left);
                    visited.insert(node->left);
                    check = true;
                }

                if(node->right && visited.find(node->right) == visited.end()) {
                    q.push(node->right);
                    visited.insert(node->right);
                    check = true;
                }

                if(parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()) {
                    q.push(parentMap[node]);
                    visited.insert(parentMap[node]);
                    check = true;
                }
            }

            if(check) time++;
            check = false;
        }
        return time;
    }
};