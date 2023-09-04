// Probelm Link : https://leetcode.com/problems/longest-repeating-character-replacement/description/
// Solution Link : https://leetcode.com/problems/longest-repeating-character-replacement/solutions/4002496/sliding-window-apporach/

class Solution {
public:
    int findMaxlen(string& s,int k,char ch){
        int len = 0 , n = s.size();
        int i = 0 , j = 0;
        while(true){
            bool flag = true;
            while(i<n){
                flag = false;
                if(s[i]!=ch){
                    if(k==0)    break;
                    k--;
                }
                i++;
                len = max(len,i-j);
            }
            while(j<i && s[j]==ch){
                flag = false;
                j++;
            }
            j++;
            k++;
            if(flag)    break;
        }
     
        return len;
    }
    int characterReplacement(string s, int k) {
        vector<bool> freq(26,false);
        for(int i=0;i<s.size();i++) freq[s[i]-'A'] = true;
        
        int result = 0;
        for(int i=0;i<26;i++){
            if(freq[i]){
                result = max(result,findMaxlen(s,k,i+'A'));
            }
        }
        
        return result;
    }
};