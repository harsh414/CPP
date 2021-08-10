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
    // MS is the max straight pat
    // MB is the max bent path
    int maxPathSum(TreeNode* root, int &result)
    {
        if(!root) return 0;
        int l=maxPathSum(root->left,result);
        int r=maxPathSum(root->right,result);
        
        int MS= max(max(l,r)+root->val , root->val);
        int MB= max(l+r+root->val , MS);
        result=max(result,MB);
        
        return MS;
    }
    
    int maxPathSum(TreeNode* root) {
        int result= INT_MIN;
        maxPathSum(root,result);
        return result;
    }
};