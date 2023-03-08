class Solution {
    public:
    bool is_possible(vector<int> & piles , int h , int val)
    {
        int total_h = 0;
            
        for(int i=0 ; i < piles.size() ; i++)
        {
            total_h += ( piles[i] / val ) + ( piles[i]%val != 0 ) ;
        }    
        
        return total_h <= h ;
    }
    
    int minEatingSpeed(vector<int>& piles, int h)
    {  
       int start = 1  , end = INT_MAX , ans = INT_MAX;
      
       while(start <= end )
       {
           int mid = start + (end - start)/2;
           
           if(is_possible(piles , h , mid))
           {  
               ans = min(ans , mid);
               end = mid-1;    
           }
           else
           {   
               start = mid + 1;
           }    
           
           //cout<<start<<" " <<mid<<" "<<end<<" "<<endl; 
       }
        
       return ans; 
    }
};