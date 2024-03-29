bool dfs(ll v) {
  color[v] = 1;
  for (ll u : adj[v]) {
    if (color[u] == 0) {
      parent[u] = v;
      if (dfs(u)) {
        return true;
      }
    } else if (color[u] == 1) {
      cycle_end = v;
      cycle_start = u;
      return true;
    }
  }
  color[v] = 2;
  return false;
}
void find_cycle() {
  color.assign(n, 0);
  parent.assign(n, -1);
  cycle_start = -1;
  for (ll v = 0; v < n; v++) {
    if (color[v] == 0 && dfs(v)) {
      break;
    }
  }
  if (cycle_start == -1) {
    cout << "Acyclic" << endl;
  } else {
    vector<ll> cycle;
    cycle.push_back(cycle_start);
    for (ll v = cycle_end; v != cycle_start; v = parent[v]) {
      cycle.push_back(v);
    }
    cycle.push_back(cycle_start);
    reverse(cycle.begin(), cycle.end());
    cout << "Cycle found: ";
    for (ll v : cycle) {
      cout << v << ' ';
    }
    cout << '\n';
  }
}