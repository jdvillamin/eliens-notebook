struct SegTreeNode {
  int l, r, val;
  SegTreeNode *lc, *rc;
  SegTreeNode(const vector<int>& a, int l, int r) : l(l), r(r) {
    if (r - l == 1) {
      val = a[l];
      lc = rc = nullptr;
      return;
    }
    int m = (l + r) / 2;
    lc = new SegTreeNode(a, l, m);
    rc = new SegTreeNode(a, m, r);
    val = min(lc->val, rc->val);
  }
  void set(int k, int x) {
    if (k < l || r <= k) return;
    if (r - l == 1) {
      val = x;
      return;
    }
    lc->set(k, x);
    rc->set(k, x);
    val = min(lc->val, rc->val);
  }
  int query(int a, int b) {
    if (a <= l && r <= b) return val;
    if (r <= a || b <= l) return INF;
    return min(lc->query(a, b), rc->query(a, b));
  }
};
struct SegTree {
  SegTreeNode root;
  SegTree(const vector<int>& a) : root(a, 0, a.size()) {}
  void set(int k, int x) { return root.set(k, x); }
  int query(int a, int b) { return root.query(a, b); }
};