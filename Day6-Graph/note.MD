# DFS / BFS

- Với mỗi đỉnh, mình duyệt các đỉnh lân cận và đi tiếp

## Ma Trận Kề

O(n^2)

## Danh sách kề

O(m) : số lượng cạnh

## Danh sách cạnh

O(m^2)

=> Danh sách kề -> Ma trận kề -> Danh sách cạnh

# Dijkstra
https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#:~:text=Dijkstra's%20algorithm%20(%2F%CB%88da%C9%AA,and%20published%20three%20years%20later.

u = origin
D[i]: khoảng cách ngắn nhất đi từ u tới i
- Khởi tạo
  - D[u] = 0
  - D[i] = oo

d[u][v] = min(d[u][v], d[u][k] + d[k][v])

```
for (int i = 0; i < n; ++i)
  for (int j = 0; j < n; ++j) if (a[i][j]) // Nếu có tồn tại cạnh i, j
    for (int k = 0; k < n; ++k) if (a[i][k] && a[k][j]) { // Nếu có tồn tại cạnh (i,k) và (k,j)
      d[j] = min(d[j], d[i] + a[i][j]) // Tối ưu d[i][j]
    }
```