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
    
private: 
     void solve(TreeNode* root,int level,vector<int>&res) {
        
        if(root==nullptr)return;
         
         if(level==res.size()) res.push_back(root->val);
         
         solve(root->right,level+1,res);
         
         solve(root->left,level+1,res);
         
        }
      
public:
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>res;
        
        int level=0;
        
        solve(root,level,res);
        
        return res;
        
    }
        
};