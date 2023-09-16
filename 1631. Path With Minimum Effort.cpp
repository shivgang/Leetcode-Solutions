// Problem Link : https://leetcode.com/problems/path-with-minimum-effort/
// Solution Link : https://leetcode.com/problems/path-with-minimum-effort/solutions/4051228/binary-search-dfs-solution/

class Solution {
public:
    vector<int> dx = {-1, 1, 0, 0};
    vector<int> dy = { 0, 0,-1, 1};
    bool check(vector<vector<bool>>& visited,int i,int j){
        if(i>=0 && i<visited.size() && j>=0 && j<visited[0].size() && !visited[i][j]) return true;
        return false;
    }

    bool minimumEffortPath(vector<vector<int>>& heights,vector<vector<bool>>& visited,int i,int j,int effort) {
        if(i==0 && j==0)    
            return true;
        
        visited[i][j] = true;
        for(int k=0;k<4;k++){
            int newx = dx[k] + i;
            int newy = dy[k] + j;
            if(check(visited,newx,newy) && effort >= abs(heights[i][j] - heights[newx][newy])){
                if(minimumEffortPath(heights,visited,newx,newy,effort)){
                    return true;
                }
            }
        }

        return false;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() , m = heights[0].size();

        int low = 0 , high = 1e6 , ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            vector<vector<bool>> visited(n,vector<bool>(m,false));
            if(minimumEffortPath(heights,visited,n-1,m-1,mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }

        return ans;
    }
};
