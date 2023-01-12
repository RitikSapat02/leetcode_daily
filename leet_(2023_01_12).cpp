class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<pair<char, vector<int>>> adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            int a = edges[i][0];
            int b = edges[i][1];
            adj[a].second.push_back(b);
            adj[b].second.push_back(a);
        }

        for(int i = 0 ; i < n ; i++)    adj[i].first = labels[i];

        vector<int> freq(26, 0);
        dfs(adj, -1, 0, ans, freq);
        return ans;
    }

    void dfs(vector<pair<char, vector<int>>>& adj, int parent, int ind, vector<int>& ans, vector<int>& freq){
        
        // Store the frequency of label that might noe be zero before 
        //visiting this node
        int prev = freq[adj[ind].first-97];

        for(auto it : adj[ind].second){
            if(it != parent){
                dfs(adj, ind, it, ans, freq);
            }
        }

        freq[adj[ind].first-97]++;

        //Subtract the previous count if any
        ans[ind] = freq[adj[ind].first - 97]-prev;
    }
};