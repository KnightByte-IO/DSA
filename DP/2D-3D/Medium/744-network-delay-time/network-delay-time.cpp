class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Create adjacency list
        vector<pair<int, int>> adj[n + 1];

        for (auto& it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Step 2: Distance array
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        // Step 3: Min Heap
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;

        pq.push({0, k});

        // Step 4: Dijkstra
        while (!pq.empty()) {
            auto [dis, node] = pq.top();
            pq.pop();

            if (dis > dist[node])
                continue;

            for (auto [adjNode, wt] : adj[node]) {
                if (dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Step 5: Find answer
        int ans = 0;

        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9)
                return -1;

            ans = max(ans, dist[i]);
        }

        return ans;
    }
};