class Solution {
public:
    vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
    int strStr(string haystack, string needle) {
       string now = needle+"#"+haystack;
       vector<int> pre_arr = prefix_function(now);
        
       for(int i = 0 ; i < (int) pre_arr.size() ; i++)
       {
           if(pre_arr[i] == needle.size() )
               return i- 2*needle.size();
       }
        
       return-1; 
    }
};