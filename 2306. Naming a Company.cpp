// Problem Link :  https://leetcode.com/problems/naming-a-company/
// Solution Link : https://leetcode.com/problems/naming-a-company/solutions/4006981/dp-based-solution-with-hashmap-ds/

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        set<string> words(ideas.begin(),ideas.end());

        int dp[26][26];
        memset(dp,0,sizeof(dp));

        for(auto word:ideas){
            char ch1 = word[0];
            for(int i=0;i<26;i++){
                char ch2 = i + 'a'; 
                if(ch1 == ch2)    continue;
                word[0] = ch2;
                if(words.find(word) == words.end()){
                   dp[ch1-'a'][ch2-'a']++;
                }
            }
            word[0] = ch1;
        }

        long long int count = 0;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                count += dp[i][j] * dp[j][i];
            }
        }

        return count;
    }
};