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

/*Question link :- https://www.hackerrank.com/contests/projecteuler/challenges/euler003/problem?isFullScreen=true*/

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        long val = n;

        for(long i = 2 ; i <= sqrt(n)  ; i++ )
        {  
            while(val % i==0 && val > i){
                val = val/i; 
            }
            
        }
        
          
        cout<<val<<endl;  
    }
    return 0;
}