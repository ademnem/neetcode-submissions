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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root)
            return res;
        
        queue<pair<TreeNode*, int>> q; 
        q.push({root, 0});

        while (!q.empty()) {
            int level = q.front().second;

            vector<int> vals;
            while (!q.empty() && q.front().second == level) { 
                TreeNode* n = q.front().first;
                vals.push_back(n->val);

                if (n->left)
                    q.push({n->left, level + 1});
                if (n->right)
                    q.push({n->right, level + 1});

                q.pop();
            }
            res.push_back(vals);
        }
        return res;
    }
};
