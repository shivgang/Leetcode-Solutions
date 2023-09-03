// Problem Link : https://leetcode.com/problems/repeated-string-match/
// Solution Link : https://leetcode.com/problems/repeated-string-match/solutions/3998664/solution-using-kmp-alogrithm/
class Solution {
public:
    int kmp(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        
        vector<int> lps(m,0);
        lps[0] = 0;
        int i = 1 , len = 0 , j = 0;
        while(i<m){
            if(needle[i] == needle[len]){
                len++;
                lps[i++] = len;
            }else{
                if(len==0)  i++;
                else len = lps[len-1];
            }
        }

        i = 0 , j = 0;
        while(n-i>=m-j){
            if(haystack[i] == needle[j]){
                i++;j++;
                if(j==m)    return true ;
            }else{
                if(j==0)    i++;
                else j = lps[j-1];
            }
        }

        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n = a.size() , m = b.size();

        int count = 1;
        string a_ = a;
        while(a_.size()<m){
            a_ += a;
            count++;
        }
        if(kmp(a_,b))   return count;
        a_ += a ;
        return kmp(a_,b) ? count+1 : -1;
        
    }
};
