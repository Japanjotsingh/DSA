class Solution {
public:
    int longestCycle(vector<int>& edges) 
    { 
        int n =  edges.size();
        vector<int> end_at(n , 0);

        for(int i : edges)
        {  if( i >= 0 )
             end_at[i]++;
        } 

        queue<int> q;
       
        for(int i = 0 ; i < end_at.size() ; i++)
        {  if(end_at[i] == 0)
              q.push(i);
           
        }

        vector<bool> visited(n , false);
        
        while(!q.empty())
        {
            int now = q.front();
            q.pop();  
            visited[now] =  true ;
            
           
            if(edges[now] == -1)
              continue;

            end_at[edges[now]]--;
            if(end_at[edges[now]] == 0)
            {
                q.push(edges[now]);
            }

        }
        int  ans = -1;

        for(int i = 0 ; i < visited.size() ; i++)
        {
             if( !visited[i] )
             {  int now = 0 ;
                int index = i ;
                 while( !visited[index] )
                 {
                     now++;
                     visited[index] = true;
                     index = edges[index];

                 }
                 ans = max ( ans , now); 
             }
        }
        return ans;

    }
};