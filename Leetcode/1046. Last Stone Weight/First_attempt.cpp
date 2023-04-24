class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        multiset<int> store;

        for(int i :stones)
           store.insert(-i);

        while(store.size() > 1)
        {  
            int first =  -1 * (*store.begin());
            store.erase(store.begin());
            
            int second =  -1 * (*store.begin());
            store.erase(store.begin());
           
            int now = first - second;
            if(now != 0)
              store.insert(-now);

        }
         
        return  store.size() == 0 ? 0 :  -*store.begin();  
    }
};