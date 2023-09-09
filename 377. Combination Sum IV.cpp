// Problem Link : https://leetcode.com/problems/combination-sum-iv/
// Solution Link : https://leetcode.com/problems/combination-sum-iv/solutions/4022720/dp-solution-memorized-and-tabulated-with-1d-dp/

class Solution {
    long long int dp[1001];
public:
    
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        memset(dp,0,sizeof(dp));
        
        dp[0] = 1;
        for(int j=1;j<=target;j++){
            int count = 0;
            for(int i=0;i<nums.size();i++){
                if(nums[i] > j)    break;
                count += dp[j-nums[i]];
            }
            dp[j] = count;
        }
        
        return dp[target];
    }
};