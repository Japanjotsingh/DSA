 typedef unsigned long long ll;

class Solution {
public:
    
    void help(TreeNode* root , int level , ll val , unordered_map<int,vector<ll>> & store)
    {
         if(root == NULL)
           return;

          store[level].push_back(val);
          
          help(root->left , level+1 , val*2 - 1 , store);
          help(root->right , level+1 , val*2 , store);
       
    }

    int widthOfBinaryTree(TreeNode* root) 
    {
        unordered_map<int,vector<ll>> store;

        help(root , 0  , 1 , store);
        ll ans = 0;
        for(auto i : store)
        {  
            vector<ll> now = i.second;
            ans= max(ans , now[now.size()-1]-now[0]+1);
        }
        return ans;
    }
};