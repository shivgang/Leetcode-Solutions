// Problem Link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
// Solution Link : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/solutions/4034110/c-solution-using-hashmap-and-priority-queue/

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        
        priority_queue<int> pq;
        for(int i=0;i<26;i++){
            if(freq[i]>0)
                pq.push(freq[i]);
        }

        int result = 0;
        int prev = INT_MAX;
        while(!pq.empty()){
            int fre = pq.top();pq.pop();
            if(prev==0){
                result += fre;
                continue;
            }
            if(prev <= fre){
                result += abs(prev-fre) + 1;
                fre = prev - 1;   
            }
            prev = fre;                
        }
        return result;
    }
};