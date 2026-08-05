class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj,
             vector<int>& vis) {

        vis[node] = 1;

        for (int nxt : adj[node]) {
            if (!vis[nxt]) {
                dfs(nxt, adj, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k,
                                 vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        for (auto& edge : invocations) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(n, 0);

        dfs(k, adj, vis);

        for (auto& edge : invocations) {
            int u = edge[0];
            int v = edge[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;

                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }

                return ans;
            }
        }

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna