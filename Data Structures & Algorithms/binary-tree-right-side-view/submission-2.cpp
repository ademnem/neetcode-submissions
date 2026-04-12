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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;

        if (!root)
            return res;

        queue<pair<TreeNode*, int>> nodes;
        nodes.push({root, 0});

        while (!nodes.empty()) {
            res.push_back(nodes.front().first->val);
            int level = nodes.front().second; 
            while(!nodes.empty() && nodes.front().second == level) {
                TreeNode* tmp = nodes.front().first;
                if (tmp->right)
                    nodes.push({tmp->right, level + 1});
                if (tmp->left)
                    nodes.push({tmp->left, level + 1});
                nodes.pop();
            }
        }

        return res;
    }
};
