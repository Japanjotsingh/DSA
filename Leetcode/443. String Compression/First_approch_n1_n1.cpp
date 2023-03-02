class Solution {
public:
    
    void get_done(string & ans , vector<char> & chars , int i , int j )
    {
        string  now = to_string( j - i );
        
        ans.push_back(chars[i]); 
        
        if( j - i > 1)
        {  
            for(int k = 0 ; k < now.size() ; k++)
                 ans.push_back( now[k] );
        }
    }    
        
        
    int compress(vector<char>& chars) 
    { 
        
      int i, j ;
      string ans="";
        
      for(i=0 , j = 0 ; j < chars.size() ; j++ )
      { 
          if( chars[i] != chars[j] )
          {   
              get_done(ans , chars , i , j);
              i = j;
          }   
       } 
        
       get_done(ans , chars , i , j);
        
       for( i = 0 ; i < ans.size() ; i++ )
       {  
           chars[i] = ans[i];
       }
        
       return ans.size(); 
    }
};

