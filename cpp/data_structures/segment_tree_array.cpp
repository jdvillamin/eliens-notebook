struct SegTree {
  int n;
  vector<int> t;
  SegTree(const vector<int>& a) : n(a.size()), t(2 * n) {
    for (int i = 0; i < n; i++) {
      t[n + i] = a[i];
    }
    for (int i = n - 1; i > 0; i--) {
      t[i] = min(t[i << 1], t[(i << 1) + 1]);
    }
  }
  void set(int k, int x) {
    for (t[k += n] = x; k > 1; k >>= 1) {
      t[k >> 1] = min(t[k], t[k ^ 1]);
    }
  }
  int query(int a, int b) { // [a, b)
    int mn = INF;
    for (a += n, b += n; a < b; a >>= 1, b >>= 1) {
      if (a & 1) mn = min(mn, t[a++]);
      if (b & 1) mn = min(mn, t[--b]);
    }
    return mn;
  }
};