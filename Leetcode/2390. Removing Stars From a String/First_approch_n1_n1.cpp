class Solution {
public:
    string removeStars(string s) 
    {    int count = 0;
         string ans;

         for(int i =  s.size() - 1  ; i >= 0  ; i--)
         { 
             if( s[i]=='*' )
               count++;
             else if(count > 0)
                count--;
             else
             {
                 ans.push_back(s[i]);
             }        

         }
         reverse(ans.begin() , ans.end());
         return ans;
        
    }
};