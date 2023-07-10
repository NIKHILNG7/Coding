class Solution {
private:
    int solve(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        // If one of the subtrees is empty, return the depth of the non-empty subtree plus 1    
    if (root->left == nullptr || root->right == nullptr) {
            return 1 + max(left, right);
        }
        
        return 1 + min(left, right);
    }

public:
    int minDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        return solve(root);
    }
};
