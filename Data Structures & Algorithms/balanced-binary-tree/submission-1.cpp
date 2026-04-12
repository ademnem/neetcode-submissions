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
public:
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true; 
  
        bool balanced = true;
        getBalance(root, balanced);

        return balanced;   
    }

    int getBalance(TreeNode* root, bool& balanced) {
        if (!root)  
            return 0;
        
        int left = getBalance(root->left, balanced); 
        int right = getBalance(root->right, balanced);

        if (balanced && abs(left - right) > 1) 
            balanced = false;
        
        return max(left, right) + 1;
    }
};
