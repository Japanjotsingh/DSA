class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        int max_len  = min(word1.size() , word2.size());
        
        string ans = "";
        int i = 0;
        for( ; i < max_len ; i++)
        {
             ans.push_back(word1[i]);
             ans.push_back(word2[i]);
        }
        

        while( i < word1.size() )
           ans.push_back(word1[i++]);

        while( i < word2.size() )
           ans.push_back(word2[i++]);

        return ans;     
    }
};