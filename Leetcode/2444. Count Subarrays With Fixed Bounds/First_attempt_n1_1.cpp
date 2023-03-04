typedef long long int  ll;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) 
    { 
        int pivot= - 1 , max_in = -1 , min_in = -1;
        
        ll ans = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++)
        { 
             if(nums[i] < minK || nums[i] > maxK)
                 pivot  =  i;
             if (nums[i] == minK)
                 min_in = i;
             if (nums[i] == maxK)
                 max_in = i ;
            
             ans += (ll) ( min(max_in , min_in) - pivot  < 0 ? 0 : min(max_in , min_in) - pivot);
             
        }
        
        return ans;
    }
};