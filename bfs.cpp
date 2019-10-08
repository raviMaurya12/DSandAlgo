const int n=10; // number of nodes
vector<vector<int>> adj(n);  
vector<bool> used(n);
vector<int> d(n), p(n);

void bfs(int s){
    queue<int> q;
    q.push(s);
    used[s] = true;
    p[s] = -1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adj[v]) {
            if (!used[u]) {
                used[u] = true;
                q.push(u);
                d[u] = d[v] + 1;
                p[u] = v;
            }
        }
    }
}

