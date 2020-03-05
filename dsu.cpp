
struct DSU {

  vector<int> p, sz;

  DSU(int n) {
    p.assign(n, 0);
    iota(p.begin(), p.end(), 0);
    sz.assign(n, 1);
  }

  int find(int v) {
    return v == p[v] ? v : p[v] = find(p[v]);
  }

  void join(int u, int v) {
    v = find(v);
    u = find(u);
    if (u == v) {
      return;
    }
    if (sz[u] > sz[v]) {
      swap(u, v);
    }
    p[u] = v;
    sz[v] += sz[u];
  }

};
