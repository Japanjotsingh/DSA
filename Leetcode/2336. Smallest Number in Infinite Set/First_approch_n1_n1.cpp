class SmallestInfiniteSet {
public:
    set<int> store;
    int numb = 0 ;
    SmallestInfiniteSet() {
         
        numb = 1;
    }
    
    int popSmallest() {
         if(!store.empty() && numb <= *store.begin())
         {   
             if( numb == *store.begin())
               store.erase(store.begin());

             int val = numb++;
             return val;
         }
         else if (!store.empty() && numb > *store.begin())
         { 
             int val = *store.begin();
             store.erase(store.begin());
             return val;
         }
         else return numb++;

    }
    
    void addBack(int num) {

        if(store.find(num) == store.end())
          store.insert(num);
    }
};
