class Solution {
public:
    int ans = 0 ;

    pair<int,int> help (TreeNode* root )
    {
        if(root == NULL)
         return { 0 , 0 } ;

      pair<int,int> left = help(root->left);
      pair<int,int> right = help(root->right);

      int max_left  = left.second + 1 ;
      int max_right = right.first + 1 ; 

      ans = max( { ans ,  max_left ,  max_right } );

      return {max_left , max_right};

    }
    int longestZigZag(TreeNode* root) 
    {
        if(root == NULL)
          return 0;

        help(root);
        return ans - 1;
    }
};