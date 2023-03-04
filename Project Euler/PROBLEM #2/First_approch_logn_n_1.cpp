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

typedef unsigned long long int ull;

/*Question link :- https://www.hackerrank.com/contests/projecteuler/challenges/euler002/problem?isFullScreen=true */

// C++ program to find first element that
// is strictly smaller than given target.
#include<bits/stdc++.h>
using namespace std;

int b_search(ull target , vector<ull> &arr, int end = 100 )
{
    if(end == 0) return -1;
    if (target > arr[end - 1]) return end-1;

    int start = 0;

    int ans = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (arr[mid] >= target)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}


int main(){
    int t;
    cin >> t;
    vector<ull> fibb_100;
    vector<ull> sum_fibb_100;
        
    fibb_100.push_back(1);
    fibb_100.push_back(2);
    sum_fibb_100.push_back(2);
           
    for(int i = 2 ; i < 100 ; i++)
    {
        fibb_100.push_back( fibb_100[i-1]+fibb_100[i-2]);
            
        if( ( (i-1) % 3 ) == 0)
        {
              
            sum_fibb_100.push_back(fibb_100[i]  +    sum_fibb_100[sum_fibb_100.size()-1]);
        }
    }
    
    for(int a0 = 0; a0 < t; a0++){
        long n;
        cin >> n;
        ull input = n;
        
        int index_in_fibb = b_search(input , fibb_100);
        int index_in_sum_fibb = ( (index_in_fibb - 1 ) / 3);
        
        cout<<sum_fibb_100[index_in_sum_fibb]<<endl;
        
    }
    return 0;
}
