#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1e9+7;

int main() {
  freopen("floyd.inp", "r", stdin);
  int n, m, u, v, c;

  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(n, 0));
  vector<vector<int>> floyd(n, vector<int>(n, MAX));

  for (int i=0; i<m;++i) {
    cin >> u >> v >> c;
    a[u][v] = c;
    a[v][u] = c;
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) if (i != j) {
      if (a[i][j]) floyd[i][j] = a[i][j];

      for (int k = 0; k < n; ++k) if (a[i][k] && a[k][j]) {
        floyd[i][j] = min(floyd[i][j], a[i][k] + a[k][j]);
      }
    }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (floyd[i][j] == MAX) cout << "- ";
      else cout << floyd[i][j] << " ";
    }
    cout << endl;
  }
}