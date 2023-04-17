class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        int max_candy = INT_MIN;

        for(int i : candies)
           max_candy = max(i , max_candy);


        vector<bool> ans;

        for(int i = 0 ;  i < candies.size() ; i++)
        {
           ans.push_back(  candies[i] + extraCandies >= max_candy );

        }   
        
        return ans;
    }
};