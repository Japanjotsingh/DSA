class Solution {
public:
    int dfs(unordered_map<int,vector<int>> & graph  , string &color , int node , vector<bool> & visited , vector<bool>&visited_now  , vector<vector<int>> & count)
    {
          if(visited_now[node])
            return INT_MAX;
          
          if(visited[node])
             return count[node][color[node] - 'a'];


          visited[node]=true;
          visited_now[node] = true;

          for(int i = 0 ; i < graph[node].size() ; i++)
          {

              if(dfs(graph , color , graph[node][i] ,visited , visited_now , count ) == INT_MAX)
                 return INT_MAX;

             for(int j = 0 ;  j < 26 ; j++)
              count[node][j] = max( count[node][j] ,  count[graph[node][i]][j]);    
          }   
          
          count[node][color[node]-'a']++;
          visited_now[node] = false;

          return  count[node][color[node]-'a'];
    }

    int largestPathValue(string colors, vector<vector<int>>& edges) 
    {
        unordered_map<int, vector<int>> graph;
        int n = colors.size();

        for(int i = 0 ; i < edges.size() ; i++)
          graph[edges[i][0]].push_back(edges[i][1]);

        vector<bool> visited( n , false);
        vector<bool> visited_now( n  , false);
        vector<vector<int>> count(n , vector<int>(26 , 0));


        int ans = 0 ; 

        for(int i = 0 ; i < n ; i++)
        {
            ans = max( ans , dfs(graph , colors , i , visited , visited_now  , count));
        }  

        return ans == INT_MAX ? -1 : ans;
    }
};