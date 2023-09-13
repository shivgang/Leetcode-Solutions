// Problem Link : https://leetcode.com/problems/candy/
// Solution Link : https://leetcode.com/problems/candy/solutions/4038915/easy-o-n-solution-using-greedy-approach/


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        
        vector<int> candy(n,1);
        for(int i=1;i<n;i++){
            if(ratings[i] > ratings[i-1]){ // if the current student has higher rating than the previous(on its left)  student
                candy[i] = candy[i-1]+1;  // than giving him more candies
            }
        }

        for(int i=n-2;i>=0;i--){        // doing the above process from right
            if(ratings[i] > ratings[i+1] && candy[i]<=candy[i+1]){    // if the current student has more rating than the right student and we have given him less candies during the first itieration
                candy[i] = candy[i+1]+1;  // than giving him more candies
            }
        }

        int candies = 0;
        for(int i=0;i<n;i++){
            candies += candy[i];
        }
        
        return candies;
    }
};