# Cách lưu trữ graph
## Ma trận kề

![drawing](undirectedgraph.png)

Có 5 đỉnh, tạo ma trận connect[i][j]
- 1: i nối với j
- 0: i không nối với j

|0|1|2|3|4|
|-|-|-|-|-|
|0|1|0|0|1|
|1|0|1|1|1|
|0|1|0|1|0|
|0|1|1|0|1|
|1|1|0|1|0|



## Danh sách kề

0: 1 4

1: 0 2 3 4 

2: 1 3

3: 1 2 4

4: 0 1 3


### Đồ thị không có trọng số
input
```
5
0 1 0 0 1
1 0 1 1 1
0 1 0 1 0
0 1 1 0 1
1 1 0 1 0
```

Read input
```
cin >> n;
vector<vector<int>> a(n);
for (int i = 0; i < n; ++i)
for (int j = 0; j < n; ++j) {
  cin >> x;
  if (x == 1) a[i].push_back(j);
}
```

DFS
```
void DFS(int u) {
  check[u] = true;
  for (int i = 0; i < a[u].size(); ++i) {
    int v = a[u][i];
    if (!check[v]) DFS(v);
  }
}
```

### Đồ thị có trọng số
input
```
3
0 10 0
10 0 3
0 3 0
```

Read input
```
cin >> n;
vector<vector<int>> a(n);
vector<vector<int>> c(n);
for (int i = 0; i < n; ++i)
for (int j = 0; j < n; ++j) {
  cin >> x;
  if (x != 0) {
    a[i].push_back(j);
    c[i].push_back(x);
  }
}
```

### Danh sách cạnh