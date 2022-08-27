#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1e9+7;

vector<int> dijkstra(int u, const vector<vector<int>>& a, const vector<vector<int>>& w) {
  int n = a.size();

  vector<int> d(n, MAX);
  d[u] = 0;

  queue<int> q;
  q.push(u);

  while(q.size()) {
    u = q.front();
    q.pop();

    for (int i = 0; i < a[u].size(); ++i) {
      int v = a[u][i];
      int c = w[u][i];

      if (d[v] > d[u] + c) {
        d[v] = d[u] + c;
        q.push(v);
      }
    }
  }
  return d;
}

int main() {
  freopen("dijkstra.inp", "r", stdin);
  int n, m, u, v, c, ori;

  cin >> n >> m >> ori;
  vector<vector<int>> a(n), w(n);

  for (int i=0; i<m;++i) {
    cin >> u >> v >> c;

    a[u].push_back(v);
    a[v].push_back(u);

    w[u].push_back(c);
    w[v].push_back(c);
  }

  vector<int> result = dijkstra(ori, a, w);
  for (auto x : result) cout << x << " ";
}