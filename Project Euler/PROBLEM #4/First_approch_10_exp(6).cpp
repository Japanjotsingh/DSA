#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


/*Question link :- https://www.hackerrank.com/contests/projecteuler/challenges/euler004/problem?isFullScreen=true*/

bool is_pal(int s){
     
    int num = 0;
    int org = s;
    while(s)
    {
        num*=10;
        num+= s%10;
        s/=10;
    }
    return  org == num;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        
        int till = 999;
        int ans = 0 ;
        
        for(int i = 100 ; i <= 999 ; i++)
        {  
           for(int j =  i ; j <= till ; j++)
           {   
               if(i*j < n && is_pal(i*j))
               {
                    ans= max(ans , i*j);
               }
           }
        }
        cout<<ans<<endl;   
    }
    return 0;
}
