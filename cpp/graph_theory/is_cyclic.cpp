bool dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> &rec) {
  vis[u] = true;
  rec[u] = true;
  for(auto v : adj[u]) {
    if (!vis[v] && dfs(v, adj, vis, rec)) return true;
    else if (rec[v]) return true;
  }
  rec[u] = false;
  return false;
}
bool is_cyclic(int n, vector<vector<int>> &adj) {
  vector<bool> vis(n, false), rec(n, false);
  for (int i = 0; i < n; i++)
    if (!vis[i] && dfs(i, adj, vis, rec)) return true;
  return false;
}