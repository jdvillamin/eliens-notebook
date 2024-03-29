void topo_sort(int u, vector<vector<int>>& adj, vector<bool>& vis, stack<int>& stk) {
  vis[u] = true;
  for (int v : adj[u]) {
    if (!vis[v]) {
      topo_sort(v, adj, vis, stk);
    }
  }
  stk.push(u);
}

vector<vector<int>> transpose(int n, vector<vector<int>>& adj) {
  vector<vector<int>> adj_t(n);
  for (int u = 0; u < n; u++) {
    for (int v : adj[u]) {
      adj_t[v].push_back(u);
    }
  }
  return adj_t;
}

void get_scc(int u, vector<vector<int>>& adj_t, vector<bool>& vis, vector<int>& scc) {
  vis[u] = true;
  scc.push_back(u);
  for (int v : adj_t[u]) {
    if (!vis[v]) {
      get_scc(v, adj_t, vis, scc);
    }
  }
}

void kosaraju(int n, vector<vector<int>>& adj, vector<vector<int>>& sccs) {
  vector<bool> vis(n, false);
  stack<int> stk;
  for (int u = 0; u < n; u++) {
    if (!vis[u]) {
      topo_sort(u, adj, vis, stk);
    }
  }
  vector<vector<int>> adj_t = transpose(n, adj);
  for (int u = 0; u < n; u++) {
    vis[u] = false;
  }
  while (!stk.empty()) {
    int u = stk.top();
    stk.pop();
    if (!vis[u]) {
      vector<int> scc;
      get_scc(u, adj_t, vis, scc);
      sccs.push_back(scc);
    }
  }
}