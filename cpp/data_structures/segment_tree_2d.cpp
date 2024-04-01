template<typename T, typename InType = T>
class SegTree2dNode {
public:
  int i, j, tree_size;
  SegTree<T, InType>* seg_tree;
  SegTree2dNode<T, InType>* lc, * rc;
  SegTree2dNode() {}
  SegTree2dNode(const vector<vector<InType>>& a, int i, int j) : i(i), j(j) {
    tree_size = a[0].size();
    if (j - i == 1) {
      lc = rc = nullptr;
      seg_tree = new SegTree<T, InType>(a[i]);
      return;
    }
    int k = (i + j) / 2;
    lc = new SegTree2dNode<T, InType>(a, i, k);
    rc = new SegTree2dNode<T, InType>(a, k, j);
    seg_tree = new SegTree<T, InType>(vector<T>(tree_size));
    operation_2d(lc->seg_tree, rc->seg_tree);
  }
  ~SegTree2dNode() {
    delete lc;
    delete rc;
  }
  void set_2d(int kx, int ky, T x) {
    if (kx < i || j <= kx) return;
    if (j - i == 1) {
      seg_tree->set(ky, x);
      return;
    }
    lc->set_2d(kx, ky, x);
    rc->set_2d(kx, ky, x);
    operation_2d(lc->seg_tree, rc->seg_tree);
  }
  T range_query_2d(int lx, int rx, int ly, int ry) {
    if (lx <= i && j <= rx) return seg_tree->range_query(ly, ry);
    if (j <= lx || rx <= i) return -INF;
    return max(lc->range_query_2d(lx, rx, ly, ry), rc->range_query_2d(lx, rx, ly, ry));
  }
  void operation_2d(SegTree<T, InType>* x, SegTree<T, InType>* y) {
    for (int k = 0; k < tree_size; k++) {
      seg_tree->set(k, max(x->range_query(k, k + 1), y->range_query(k, k + 1)));
    }
  }
};
template<typename T, typename InType = T>
class SegTree2d {
public:
  SegTree2dNode<T, InType> root;
  SegTree2d() {}
  SegTree2d(const vector<vector<InType>>& mat) : root(mat, 0, mat.size()) {}
  void set_2d(int kx, int ky, T x) { root.set_2d(kx, ky, x); }
  T range_query_2d(int lx, int rx, int ly, int ry) { return root.range_query_2d(lx, rx, ly, ry); }
};