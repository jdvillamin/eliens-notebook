vector<vector<int>> up(K + 1, vector<int>(n));
vector<int> depth(n);
up[0][0] = 0;
depth[0] = 0;
for (int i = 1; i < n; i++) {
  up[0][i] = p[i];
}
for (int i = 1; i <= K; i++)
  for (int j = 0; j < n; j++) 
    up[i][j] = up[i - 1][up[i - 1][j]];
for (int i = 1; i < n; i++) 
  depth[i] = depth[up[0][i]] + 1;
auto anc = [&](int x, int k) {
  int res = x;
  for (int i = 0; (1 << i) <= k; i++)
    if (k & (1 << i)) res = up[i][res];
  return res;
};
auto lca = [&](int a, int b) {
  if (depth[a] < depth[b]) swap(a, b);
  a = anc(a, depth[a] - depth[b]);
  if (a == b) {
    return a;
  }
  for (int i = K; i >= 0; i--) {
    if (up[i][a] != up[i][b]) {
      a = up[i][a];
      b = up[i][b];
    }
  }
  return up[0][a];
}