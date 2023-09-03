//  Problem Link : https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/
//  Solution Link : https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/solutions/3996811/dfs-solution-using-bitmasking-and-map/

class Solution {
    unordered_map<int,int> map;         // map for storing all the masks
    vector<int> xr;         // stores xor of all the nodes
    vector<vector<pair<int,char>>> graph;   // represents our tree structure
public:
    void dfs(int node,int mask){    
        map[mask]++;        // storing all the mask and storing for each particular node
        xr[node] = mask;

        for(auto neighbour:graph[node]){
            int color = neighbour.second - 'a';
            int newNode = neighbour.first;
            dfs(newNode,mask^(1<<color));
        }
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();

        graph.resize(n);
        xr.resize(n);
        for(int i=1;i<parent.size();i++){   // building the graph
            graph[parent[i]].push_back({i,s[i]});
        }
        dfs(0,0);

        long long count = 0;
        for(int i=0;i<n;i++){       // checking for each node with all the possible resultant masks (only 1 bit set or 1 character mask)
            for(int j=0;j<26;j++){
                count += map[(1<<j)^xr[i]]; // if the mask exists or we can say we have a mask which is the result of (1<<j)^xr[i] our count will get incremented
            }
            count+=map[xr[i]]-1; // if mask is already zero meaning all characters in our path has even frequency 
        }
        return count/2;     // returning count/2 as we do same operation for each node and we include a every path twice
    }
};
