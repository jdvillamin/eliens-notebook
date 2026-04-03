vector<pair<int, int>> terms;
auto dfs = [&](int idx, ll prod, int cnt, auto dfs) -> void {
  for (int i = idx; i < (int)prime.size(); i++) {
    if (prod > X / prime[i]) break;
    ll nxt = prod * prime[i];
    int sign = (cnt + 1) & 1 ? +1 : -1;
    terms.push_back({(int)nxt, sign});
    dfs(i + 1, nxt, cnt + 1, dfs);
  }
};