#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
  freopen("inp", "r", stdin);
  freopen("out", "w", stdout);

  vector<pair<int, int> > q;
  vector<int> arr;
  int n, m, x, y;

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> x;
    arr.push_back(x);
  }
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    q.push_back({x - 1, y - 1});
  }

  vector<int> sum = {arr[0]}, result = {};

  for (int i = 1; i < arr.size(); ++i) {
    sum.push_back(sum[i-1] + arr[i]);
  }

  for (int i = 0; i < m; ++i) {
    if (q[i].first == 0) {
      result.push_back(sum[q[i].second]);
    } else {
      result.push_back(sum[q[i].second] - sum[q[i].first - 1]);
    }
  }

  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << endl;
  }
}
