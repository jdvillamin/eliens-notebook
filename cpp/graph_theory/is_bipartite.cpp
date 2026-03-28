bool is_bipartite(vector<ll>& col, vector<vector<ll>>& adj, ll n) {
  queue<ll> q;
  for (ll i = 0; i < n; i++) {
    if (col[i] == -1) {
      q.push(i);
      col[i] = 0;
      while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v : adj[u]) {
          if (col[v] == -1) {
            col[v] = col[u] ^ 1;
            q.push(v);
          } else if (col[u] == col[v]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}