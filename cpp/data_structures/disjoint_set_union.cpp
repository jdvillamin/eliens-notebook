struct DSU {
  vector<int> par, sz;
  DSU(int n) : par(n), sz(n, 1) { iota(par.begin(), par.end(), 0); }
  int find_set(int v) { return v == par[v] ? v : par[v] = find_set(par[v]); }
  void unite(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
      if (sz[a] < sz[b]) swap(a, b);
      par[b] = a;
      sz[a] += sz[b];
    }
  }
};