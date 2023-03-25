class Solution {
public:
    void dfs(unordered_map<int,vector<int>> & graph , int node , int & count , vector<bool> & visited)
    {  visited[node] = true;
       count++;
       
       for(int i = 0 ;  i < graph[node].size() ; i++)
       {
           if(!visited[graph[node][i]])
           {
             dfs(graph , graph[node][i] , count , visited);   
           }
       } 
    }    
    long long countPairs(int n, vector<vector<int>>& edges) 
    { 
        unordered_map<int,vector<int>> graph;

        for(int i = 0 ; i < edges.size() ; i++)
        {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        vector<long long> ans_arr;
        vector<bool> visited(n , 0 );
        for(int i = 0  ; i < visited.size() ; i++)
        {
            if(visited[i] == false)
            {   int count = 0; 
                dfs(graph , i  , count , visited);
                ans_arr.push_back(count);
            }
        }
        long long sum = 0  , sq_sum = 0 ;

        for(int i = 0 ; i < ans_arr.size() ; i++)
        {  
            sum += ans_arr[i];
            sq_sum+= ans_arr[i]*ans_arr[i];
        }
         
        return ( (sum*sum) - sq_sum ) / 2 ;
    }
};