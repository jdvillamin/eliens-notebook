struct Edge {
  int u, v, weight;
  bool operator<(Edge const& other) {
    return weight < other.weight;
  }
};
int n;
vector<Edge> edges;
int cost = 0;
vector<Edge> result;
DSU dsu = DSU(n);
sort(edges.begin(), edges.end());
for (Edge e : edges) {
  if (dsu.find_set(e.u) != dsu.find_set(e.v)) {
    cost += e.weight;
    result.push_back(e);
    dsu.union_sets(e.u, e.v);
  }
}