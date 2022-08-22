#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

/*
    Duyệt đồ thị theo ma trận kề
    N là số lượng đỉnh và ma trận kề, ví dụ:

    5

    0 1 0 0 1
    1 0 1 1 1
    0 1 0 1 0
    0 1 1 0 1
    1 1 0 1 0
*/

void BFS(int u, const vector<vector<int>>& graph) {
    vector<bool> check(graph[u].size(), false);
    queue<int> q;

    q.push(u);
    check[u] = true;

    while (q.size()) {
        u = q.front();
        cout << u << " ";
        q.pop();

        for (int v = 0; v < graph[u].size(); ++v)
            if (graph[u][v] == 1 && !check[v]) {
                check[v] = true;
                q.push(v);
            }
    }

}

int main() {
    freopen("bfs.inp", "r", stdin);

    int n, x;
    cin >> n;
    cout << n << endl;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> x;
            cout << x;
            graph[i][j] = x;
        }
        cout << "==" << endl;

    }

    cout << "=====" << endl;

    BFS(0, graph);
}

