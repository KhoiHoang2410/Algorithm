#include <iostream>
#include <vector>
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

void DFS(int u, const vector<vector<int>>& graph, vector<bool>& check) {
    cout << u << " ";
    check[u] = true;
    for (int i = 0; i < graph[u].size(); ++i)
        if (graph[u][i] == 1 && !check[i])
            DFS(i, graph, check);
}

int main() {
    freopen("dfs.inp", "r", stdin);

    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n, 0));
    vector<bool> check(n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> graph[i][j];
        }
    }

    DFS(0, graph, check);
}

