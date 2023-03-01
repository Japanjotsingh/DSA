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


 
#include <bits/stdc++.h>

class Solution {
public:
    
    void transverse( unordered_map< int , vector< pair<TreeNode*,bool> > > & collect , TreeNode* root)
    {  
        if( root == NULL)
          return;
        
        if(collect.find(root->val) != collect.end())
        {
            collect[root->val].push_back({root,false}); 
        }
        else
        {
            vector<pair<TreeNode*,bool>> arr;
            arr.push_back({root,false});
            collect.insert({root->val , arr});  
        }
        
        transverse(collect , root->left);
        transverse(collect , root->right);
    }
    
    bool check(TreeNode* r , TreeNode* s)
    {  if(r == NULL && s == NULL)
           return true ;
       
     
       if( r != NULL && s!=NULL )
       {   if(r->val == s->val)
             return  check(r->left , s->left ) && check(r->right , s->right);
           else
             return false;  
       }
       else 
           return false;
          
    }
    
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {   vector<TreeNode*> ans;
     
        unordered_map<int,vector<pair<TreeNode*,bool>>> collect;
        transverse(collect , root);
        
        for(auto i = collect.begin() ; i != collect.end() ; i++)
        {   
            int len = i->second.size();
            
            for(int j = 0 ; j < len ; j++)
            {   
                bool flag = 1;
                
                for(int k = j+1 ; k < len ; k++)
                {   
                    if( i->second[k].second == false  && check(i->second[k].first , i->second[j].first) )
                    { 
                           i->second[k].second = true;
                           
                           if(flag)
                           {
                               ans.push_back(i->second[j].first);
                               flag=0;
                           }   
                        
                    }
                }
            }    
        }
        return ans;
    }
};