// Problem Link : https://leetcode.com/problems/length-of-the-longest-valid-substring/
// Solution Link : https://leetcode.com/problems/length-of-the-longest-valid-substring/solutions/4000805/sliding-window-and-set-approach-in-c/ 
class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        int n = word.size();
        set<string> forbiddenWords(forbidden.begin(),forbidden.end());

        string curr;
        int ans = 0;
        for(int i=0,j=0;i<n;i++){
            string s;
            for(int k=i;k>=j && k>(i-10);k--){
                s=word[k]+s;
                if(forbiddenWords.find(s)!=forbiddenWords.end()){
                    j = k + 1;
                    break;
                }
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};