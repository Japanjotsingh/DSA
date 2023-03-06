class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) 
    {
        int start = 0 , end = arr.size()-1  , ans = -1;
        
        while(start <= end )
        {
            int mid = (start+ end) / 2; 
            
            if(arr[mid] - (mid+1) < k )
            {
                ans = max( ans , mid);
                start = mid+1; 
            }
            else 
            {  
                end = mid - 1; 
            }  
            
        }
        
        return  k+(ans+1) ;
        
    }
};