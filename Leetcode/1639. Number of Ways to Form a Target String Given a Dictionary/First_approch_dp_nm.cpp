typedef long long  ll;


class Solution {
    public:
    ll rec(vector<vector<ll>> &store , string &target , int s_start , int t_start ,   vector<vector<ll>> &dp , int size)
    {  
        if( dp[s_start][t_start] != -1 )
            return dp[s_start][t_start];
            

        if( t_start == target.size())
        {   dp[s_start][t_start] = 1 ;
            return 1;
        }   

        if( s_start == size)
        {   dp[s_start][t_start] = 0 ; 
            return 0;
        } 

        ll ans = 0;
        
        ans += rec(store , target , s_start+1 , t_start , dp , size) ;
        ans += store[s_start][target[t_start]-'a'] * rec(store , target , s_start+1 , t_start+1 , dp , size) ;;
        
        dp[s_start][t_start] =  ( ans +  (ll)( 1e9 + 7 )  ) % (ll)( 1e9 + 7 );
        return dp[s_start][t_start];
    }   

    int numWays(vector<string>& words, string target) 
    {
       vector<vector<ll>> store(words[0].size() , vector<ll> (26 , 0) );

       for(int i = 0 ; i < words[0].size() ; i++)
          for(int j = 0 ; j < words.size() ; j++)
              store[i][words[j][i] - 'a']++;


       vector<vector<ll>> dp( words[0].size() + 1 , vector<ll> ( target.size()+1 ,-1));

       return   rec(store , target ,  0 , 0  ,  dp , words[0].size()) ;
     
    }
};