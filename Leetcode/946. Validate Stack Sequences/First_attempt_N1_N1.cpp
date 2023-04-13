class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> s ;
         
        int i = 0  , j = 0 ;
        
        while( j < pushed.size() )
        {  
            s.push(pushed[j++]);
            

            while(!s.empty() && s.top() == popped[i])
            {
                i++;
                s.pop();
                
            } 

        }
        return j == pushed.size()  && i == popped.size();  
    }
};