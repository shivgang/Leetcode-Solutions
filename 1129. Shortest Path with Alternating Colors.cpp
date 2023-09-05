// Problem Link : https://leetcode.com/problems/shortest-path-with-alternating-colors/
// Solution Link : https://leetcode.com/problems/shortest-path-with-alternating-colors/solutions/4006052/bfs-traversal-in-c/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto edge:redEdges){
            graph[edge[0]].push_back({edge[1],0});
        }
        for(auto edge:blueEdges){
            graph[edge[0]].push_back({edge[1],1});
        }

        queue<vector<int>> q;
        vector<vector<bool>> distance(n,vector<bool>(2,false));
        vector<int> result(n,-1);
        
        result[0] = 0;
        distance[0][0] = true;
        distance[0][1] = true;
        q.push({0,0,-1});
        while(!q.empty()){
            auto front = q.front();q.pop();
            int node = front[0];
            int dist = front[1];
            int color = front[2];

            for(auto& [neighbour,newColor]:graph[node]){
                if(!distance[neighbour][newColor] && newColor!=color){
                    distance[neighbour][newColor] = true;                    
                    q.push({neighbour,dist+1,newColor});
                    if(result[neighbour]==-1)   result[neighbour] = dist + 1;
                }
            }
        }
        return result;
    }
};