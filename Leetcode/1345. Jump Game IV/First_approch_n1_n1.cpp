class Solution 
{   public:
    int minJumps(vector<int>& arr) 
    {
        unordered_map<int,vector<int>> graph;
        
        for(int i = 0 ; i < arr.size() ; i++ )
        {
            
            if( graph.find(arr[i]) == graph.end())
            {    vector<int> now;
                 now.push_back(i);
                 graph.insert({arr[i],now});     
            }
            else
            {  
                graph[arr[i]].push_back(i);
                 
            }    
        }
        
        vector<bool> visited( arr.size(), false);
        queue<int> layer;
        int step = 0;
        
        layer.push(0);
        visited[0]=false;
        
        while(!layer.empty())
        {  
            step++;
            int size = layer.size();

            for(int j = 0 ; j < size ; j++)
            {
                int now = layer.front();
                layer.pop();
            
                if( now == arr.size()-1)
                {     
                   return --step;
                }
                
                 for(int i = 0 ; i < graph[arr[now]].size() ; i++)
                 { 
                    if( !visited[graph[arr[now]][i]])
                    {      visited[now]=true;
                           layer.push(graph[arr[now]][i]);
                     }
                     
                  }
                  // WITHOUT THIS TLE IS COMMING 
                  // MOST IMP STEP
                  graph.erase(arr[now]);
                
                  if(now + 1 < arr.size() && !visited[now+1])
                  {  visited[now+1]=true;
                     layer.push(now + 1);   
                  }
                    
                  if( now - 1 >= 0   && !visited[now-1])
                  {   visited[now-1]=true;
                      layer.push(now-1);
                  }
              }
            }
         return --step;   
    }
        
};