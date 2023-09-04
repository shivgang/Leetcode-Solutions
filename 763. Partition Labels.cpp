// Problem Link : https://leetcode.com/problems/partition-labels/
// Solution Link : https://leetcode.com/problems/partition-labels/solutions/3999613/c-solution-by-updating-the-range/
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> index(26,0);  
        for(int i=0;i<s.size();i++){
            index[s[i]-'a'] = i;
        }
        vector<int> result;
        int farthest = 0;
        for(int i=0,j=0;i<s.size();i++){
            farthest = max(index[s[i]-'a'],farthest);
            if(i==farthest){
                result.push_back(i-j+1);
                j = i+1;
            }
        }        
        return result;
    }
};