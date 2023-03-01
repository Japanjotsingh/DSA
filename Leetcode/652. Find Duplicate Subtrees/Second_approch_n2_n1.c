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
    string transverse(vector<TreeNode*> & ans , unordered_map<string , int> & collect , TreeNode* root )
    {  
        if(root == NULL)
            return "";
        
        
        string now = "("+transverse(ans , collect , root->left)+")"+ to_string(root->val) + "(" + transverse(ans , collect , root->right) + ")";
        
        
        if(collect.find(now) != collect.end())
        {
            collect[now]++;
        }
        else
        {
           collect.insert({now , -1});   
        }
        
        
        if(collect[now] == 0 )
            ans.push_back(root);
        
        return now;
    }    

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
          unordered_map<string , int> collect;
          vector<TreeNode*> ans;
          
          transverse(ans , collect , root);
          
          return ans;
    } 
};