class Solution {
public:
    int lpsub(string s) 
    {  int n = s.size();
       vector<vector<int>> dp( n , vector<int> (n , 0));

       for(int i = 0 ; i < n ; i++)
         dp[i][i] = 1;

       
       for(int i = 1 ; i < n ; i++)
       {

            for(int row = 0 , col = i ; col < n ; col++ , row++)
            {  
            

                if( s[row] == s[col])
                   dp[row][col] = max (dp[row+1][col-1] + 2, dp[row][col]);
                else
                   dp[row][col] = max( dp[row + 1][col] , dp[row][col-1] );

            }
       }  
 
       return dp[0][n-1];
    }

    int minInsertions(string s) 
    {
         return s.size() - lpsub(s);
    }
};