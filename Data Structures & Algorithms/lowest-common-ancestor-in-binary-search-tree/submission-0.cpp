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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root)
            return nullptr;

        if (isAncestor(root, p) && isAncestor(root, q)) {
            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right, p, q);
            if (left)  
                return left;
            else if (right)
                return right;
            else
                return root;
        }
        return nullptr;
    }

    bool isAncestor(TreeNode* anc, TreeNode* des) {
        if (!anc)
            return false;

        if (anc->val == des->val)
            return true;

        return isAncestor(anc->left, des) || isAncestor(anc->right, des);
    }
};
