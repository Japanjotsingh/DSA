typedef long long ll;

class Solution {
public:
    int memo[101][2001][101];
   

    int help ( int num , int profit_left , vector<int> &group , vector<int> &profit , int start )
    {    
         if(start == profit.size())
         {
              return profit_left-1500 <= 0 ? 1 : 0;
         }  

         if(memo[num][profit_left][start] != -1)
            return  memo[num][profit_left][start];

         ll ans = 0;

         ans+= help(num ,  profit_left , group , profit , start+1);

         if(num - group[start] >= 0)
           ans+=help( num-group[start] , profit_left - profit[start] , group , profit , start + 1 );

          memo[num][profit_left][start] =  (int) ( ( ans +  (ll)1e9+7 ) % (ll)(1e9 + 7));
          
          return memo[num][profit_left][start]; 
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) 
    {
          memset(memo , -1 , sizeof(memo));
          
          return help( n , minProfit+1500 , group , profit , 0);
        
    }
};