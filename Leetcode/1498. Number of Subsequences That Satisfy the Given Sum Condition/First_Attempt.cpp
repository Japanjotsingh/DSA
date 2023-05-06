
typedef long long ll;


class Solution {
public:

    ll expo(int a , int n)
    {  
       if( n <= 0)
         return 1;

       if( a == 0)
          return 0;

        ll ans = expo(a , n/2);
        ans = ans * ans;

        if( n%2 == 1)
          ans = ans *  ( long long )a;  
         

         return ans %  (  long long )(1e9+7);
     }

    int numSubseq(vector<int>& nums, int target) 
    {

        sort(nums.begin() , nums.end());


        long long ans = 0;


        for(int i = 0  , j = nums.size() - 1 ;  i <= j ; )
        {  
             if( nums[i] + nums[j] <= target)
             {    
                  
                  ans = ( ans + expo( 2 , j - i) ) %  ( long long ) (1e9+7) ;
                  i++;
             }
             else
             {   
                 j --;
             }
 


        }        

        return  ans;
    }
};