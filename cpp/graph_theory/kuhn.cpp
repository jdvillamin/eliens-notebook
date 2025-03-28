int n, k;
vector<vector<int>> g;
vector<int> mt;
vector<bool> used;
bool try_kuhn(int v) {
  if (used[v]) return false;
  used[v] = true;
  for (int to : g[v]) {
    if (mt[to] == -1 || try_kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}
int main() {
  mt.assign(k, -1);
    vector<bool> used1(n, false);
    for (int v = 0; v < n; ++v) {
      for (int to : g[v]) {
        if (mt[to] == -1) {
          mt[to] = v;
          used1[v] = true;
          break;
        }
      }
    }
    for (int v = 0; v < n; ++v) {
      if (used1[v]) continue;
      used.assign(n, false);
      try_kuhn(v);
    }
    for (int i = 0; i < k; ++i)
      if (mt[i] != -1)
        printf("%d %d\n", mt[i] + 1, i + 1);
}