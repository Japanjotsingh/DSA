typedef unsigned long long int ll;

class Solution {
public:
    
    bool is_possible(vector<int> & time , int &totalTrip , ll time_now)
    {
        ll total = 0 ;
        for(int i = 0 ; i < time.size() ; i++)
        {
            total +=  time_now / (ll)time[i];
        }
        
        return total >=  (ll) totalTrip;
        
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) 
    {
        ll start = 0 , end = LLONG_MAX/time.size() ,  ans = LLONG_MAX/time.size() ;// IMP / TIME.SIZE() OPTIMSED 
         
        while(start <= end)
        {
            ll mid = start + ( end - start )/2 ;
          
            if( is_possible(time , totalTrips , mid ))
            {
                ans = min(ans , mid);
                end = mid-1;
            }    
            else
            {
                start = mid+1;
            }    
            
        }    
        return ans ; 
    }
};