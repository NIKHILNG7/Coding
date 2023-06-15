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
      int diff;
    int ans = INT_MAX;
    int x = 100000000;
    void helper(TreeNode* root) {
        if (root == NULL ) return;
        helper(root->left);
        diff = abs(root->val - x);
        ans = min(ans, diff);
        x = root->val;
        helper(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        if (root == NULL) return 0;
        helper(root);
        return ans;
    }
  
};
