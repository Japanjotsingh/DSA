class Solution {
public:
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();

        int dp[1001][2001] = {0};
 
        
        for(int i = 0 ; i < piles.size() ; i++)
        {
            for(int j = 1 ; j < piles[i].size() ; j++)
                piles[i][j]+= piles[i][j-1];

        }
        

        for(int i = 0 ; i < piles[n-1].size() ; i++)
           dp[n-1][i+1] = piles[n-1][i];


        
        for(int i = n-2 ; i >= 0 ; i--)
        {
            for(int j = 1 ; j <= k ; j++ )
            {  
                
                for(int x = 1; x <= j  ; x++)
                {   

                    if( x <= piles[i].size() )
                    {   
                        dp[i][j] = max ( { dp[i][j] , dp[i+1][j] , piles[i][x-1] + dp[i+1][j-x] });
                
                    }
                    else
                    {
                        dp[i][j] = max (  { dp[i][j] , dp[i+1][j] ,  dp[i+1][j-piles[i].size()] + piles[i][piles[i].size()-1] } ) ;
                        break;  
                    }
                }         
            }

        }


        return dp[0][k];
        
    }
};