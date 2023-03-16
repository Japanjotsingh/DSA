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

// IN LEFT - MID  - RIGHT   ,  POST LEFT RIGHT MID 
class Solution {

    public:
    TreeNode* help(vector<int> &inorder , int in_start , int in_end , vector<int> &postorder , int post_start , int post_end) 
    {  
        if(in_start == in_end || post_start == post_end)
          return NULL;

        TreeNode* now = new TreeNode() ;
        int left_len = 0 , i = in_start ;
        
        while( i < in_end  )
        {   
            if( inorder[i++] == postorder[post_end - 1])
                break; 

            left_len++;
        }            
        now->val   = inorder[in_start+left_len];
        
        now->left  = help(inorder , in_start , in_start + left_len ,  postorder , post_start , post_start + left_len);
            
        now->right = help(inorder , in_start + left_len + 1 , in_end , postorder , post_start+left_len , post_end - 1 ); 
        
        return now;
        
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        
        return help(inorder , 0 , inorder.size(), postorder , 0 , postorder.size());    
    }
};