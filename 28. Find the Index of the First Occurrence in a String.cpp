// Problem Link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/
// Solution Link : https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/solutions/3998382/kmp-algorithm/

class Solution {
public:
    void calculateLPS(string &needle,vector<int> &lps){
        lps[0] = 0;
        int i = 1 , len = 0;
        while(i<needle.size()){
            if(needle[i] == needle[len]){
                len++;
                lps[i++] = len;
            }else{
                if(len==0)  i++;
                else len = lps[len-1];
            }
        }
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m,0);
        calculateLPS(needle,lps);

        int i = 0 , j = 0;
        while(n-i>=m-j){
            if(haystack[i] == needle[j]){
                i++;j++;
                if(j==m)    return i - m ;
            }else{
                if(j==0)    i++;
                else j = lps[j-1];
            }
        }

        return -1;
    }
};