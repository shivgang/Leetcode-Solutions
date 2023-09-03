// Probelm Link : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/
// Solution Link : https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/solutions/3998265/stack-solution-in-c/

class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> alphabets(26,0),seen(26,0);
        for(int i=0;i<s.size();i++)
            alphabets[s[i]-'a']++;

        stack<char> stk;
        for(int i=0;i<s.size();i++){
            alphabets[s[i]-'a']--;
            if(seen[s[i]-'a'])  continue;

            while(!stk.empty() && stk.top()>s[i] && alphabets[stk.top()-'a']!=0){
                seen[stk.top()-'a']=0;      // remove those characters which are bigger than our current 
                stk.pop();              // character and we can get them again in the later string
            }
            stk.push(s[i]);
            seen[s[i]-'a']=1;
        }

        string ans;
        while(!stk.empty()){
            ans+=stk.top();stk.pop();   
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};