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

/* QUES LINK:- https://www.hackerrank.com/contests/projecteuler/challenges/euler001/problem?isFullScreen=true*/

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        unsigned long int val = n-1  , ans = 0 ;
        ans =   3 *( ( (val/3) * ( (val/3) + 1 ) ) / 2 )
              + 5 *( ( (val/5) * ( (val/5) + 1 ) ) / 2 )
              - 15 *( ( (val/15) * ( (val/15) + 1 ) ) / 2 );
              
       cout<<ans<<endl;  
    }
    return 0;
}
